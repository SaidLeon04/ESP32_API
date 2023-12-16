#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "Wokwi-GUEST";
const char* password = "";

int pinPotenciometro = 13;
int ledPin = 14;

// URL de la API en Heroku
String serverName = "https://esp32-api-2b745173c4b8.herokuapp.com/iot";

unsigned long lastTime = 0;
unsigned long timerDelay = 500;
int lastValorPotenciometro = -1;

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);

  // Conectar a la red WiFi
  WiFi.begin(ssid, password);
  Serial.println("Conectando");
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print(".");
  }
}

void loop() {
  // Leer el valor del potenciómetro
  int valorPotenciometro = analogRead(pinPotenciometro);

  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;

    String serverPath = serverName + "/5/" + String(valorPotenciometro);

    // Iniciar la conexión HTTP para el potenciómetro
    http.begin(serverPath.c_str());
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");

    // Enviar una solicitud HTTP PUT con el valor del potenciómetro
    int httpResponseCode = http.PUT("");

    if (httpResponseCode > 0) {
      Serial.println(httpResponseCode);
      Serial.println(valorPotenciometro);
    } else {
      Serial.print("Código de error (Potenciómetro): ");
      Serial.println(httpResponseCode);
    }
    http.end();
  }
}

