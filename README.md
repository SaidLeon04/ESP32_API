# ESP32_API

## Rama C x Arduino x SQLite3

|Archivo |Descripción|
|----------|----------|
| iot.db   |Base de datos con registro de cada sensor y su ID |
| main.py| API Rest para controlar los valores de los sensores  |
|Procfile|Comando Gunicorn para correr API en la nube|
|requirements.txt|Lista de librerias requeridas|
|runtime.txt|Versión del Python para correr la API|
|led.c|Código C para recibir datos desde la API|
|potenciometro.c|Código C para actualizar datos desde el sensor hacia la API|