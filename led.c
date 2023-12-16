#include <WiFi.h>
#include <HTTPClient.h>
#include "cJSON.h"


#define WIFI_SSID "Wokwi-GUEST" // Red
#define WIFI_PASSWORD "" // Contraseña
void setup(){ // funcion de configuracion inicial
  Serial.begin(115200);  // velocidad de trasmision en baudios
  pinMode(2, OUTPUT); // configuracion del LED
  
  Serial.print("Conectando a: ");
  Serial.println(WIFI_SSID);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD); // conexion
  // mientras el estado no sea conectado
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000); 
    Serial.print("."); // imprime puntos cada segundo
  }
  // Impresión de estado de conexión
  if (WiFi.status() == WL_CONNECTED) { 
    Serial.println("\nConexión exitosa");
  } else {
    Serial.println("\nError al conectar a la red WiFi");
  }
}
void loop(){
  HTTPClient http;
  const char *url = "https://esp32-api-2b745173c4b8.herokuapp.com/iot/1";
  
  // Enviar solicitud GET
  http.begin(url);
  int httpResponseCode = http.GET();
  
  // Manejo de respuesta
  if (httpResponseCode > 0) {
    String payload = http.getString();
    Serial.println("Respuesta de la API:");
    Serial.println(payload);
    //int index = payload.indexOf("\"valor\":\"0\"");
    int index = payload.indexOf("\"valor\":1");
    if (index != -1) {
      Serial.println("El valor de \"valor\" es 1");
      Serial.println("Encendiendo LED");
      digitalWrite(2, HIGH);

    }else{
      index = payload.indexOf("\"valor\":0");
      if (index != -1) {
        Serial.println("El valor de \"valor\" es 0");
        Serial.println("Apagando LED");
        digitalWrite(2, LOW);
      } 
    }
  } else {
    Serial.print("Error en la solicitud. Código de error: ");
    Serial.println(httpResponseCode);
  }
  http.end();
  delay(10);
}

