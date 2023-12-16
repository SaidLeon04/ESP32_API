#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "Wokwi-GUEST";
const char* password = "";


int pinPotenciometro = 34;

String serverName = "https://esp32api-43c01-default-rtdb.firebaseio.com/iot/2/valor.json";

unsigned long lastTime = 0;
unsigned long timerDelay = 100;
int lastValorPotenciometro = -1;

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("Conectado");
}

void loop() {
  int valorPotenciometro = analogRead(pinPotenciometro);

  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    String valorPotStr = String(valorPotenciometro);

    http.begin(serverName.c_str());

    int httpResponseCodePotenciometro = http.PUT(valorPotStr);

    if (httpResponseCodePotenciometro > 0) {
      Serial.println(httpResponseCodePotenciometro);
      Serial.print("Valor: ");
      Serial.println(valorPotenciometro);
    } else {
      Serial.println(httpResponseCodePotenciometro);
    }
    http.end();
  }

  delay(timerDelay);
}
