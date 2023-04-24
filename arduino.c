//BIBLIOTECAS
#include <arduino.h>
#include <HardwareSerial.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
//DATOS DE RED WIFI 
const char* ssid = "TotalPlay-06AE";
const char* password = "eNPcxmYUHRtMDuq";
//DECLARACION DE VARIABLES GLOBALES
#define QR Serial1
HardwareSerial Serialport(2);
const uint8_t rx2Pin = 17;
const uint8_t tx2Pin = 18;
char jsonOutput[128];
uint8_t bandera = 0;
int LED1 = 4;
int LED2 = 5;
int LED3 = 6;
int LED4 = 2;
int BOTON1 = 7;
int BOTON2 = 1;
int BOTON3 = 9;
int CONTADOR = 0;

void setup()
{
  Serial.begin(115200);
  Serial1.begin(115200);
  QR.begin(9600, SERIAL_8N1, 15, 16);
  Serialport.begin(9600, SERIAL_8N1, rx2Pin, tx2Pin);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(BOTON1, INPUT);
  pinMode(BOTON2, INPUT);
  pinMode(BOTON3, INPUT);
  //CONEXION A RED WIFI
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(1000);
    Serial.println(".......................................................");
    Serial.println("              Conectando a la red wifi                 ");
  }
  Serial.println(".........................................................");
  Serial.println("                Conexión wifi establecida                ");
  Serial.println();
  Serial.println("*********************************************************");
  Serial.println("                    TERZETT TECHNOLOGIX                  ");
  Serial.println("*********************************************************");
  Serial.println();
}

void blink()   //FUNCION BLINK PARA INDICAR QUE EL DISPOSITIVO ESTA ENCENDIDO.
{
  digitalWrite(LED1, HIGH);
  delay(75);
  digitalWrite(LED1, LOW);
  delay(75);
}
void SCANQR()  //FUNCION DEDICADA A LECTRURA QR Y CODIGO DE BARRAS [ENVIANDO DATOS AL SERVIDOR]
{
  WiFiClient client;
  HTTPClient http;
  String input;
  if (QR.available())  
  { 
    Serial.println();
    while(QR.available())
    {
      input = QR.readString();
    }
    input.replace(" ","");
    input.substring(0,13);
    Serial.println(input);
    HTTPClient client;
    client.begin("https://servidordepruebacapufe-production.up.railway.app/api/capufe?qr="+ String(input));
    Serial.println("https://servidordepruebacapufe-production.up.railway.app/api/capufe?qr="+ String(input));
    int httpCode=client.GET();
    if(httpCode > 0)
    {
      String payload=client.getString();
      Serial.println("\nStatusCode: "+String(httpCode));
      Serial.println(payload); 
    }
    else
    {
      Serial.println("Error on HTTP request");
    }  
    digitalWrite(LED2, LOW);
    delay(100);
  }
}
void LECTURAUHF()   //FUNCION DEDICADA A LECTURA UHF.
{
   char dato; 
   if (Serialport.available())
  {
      dato = Serialport.read();
      if (dato == 0xFF)
      {
        Serial.println();   
        Serial.println("*** LECTURA UHF *** ");
        Serial.println();
        Serial.print(" Número de identificación:  ");
      }
      else if (dato == 0xFE)
      {
        Serial.println();
        Serial.println("*** LECTURA UHF *** ");
        Serial.println();
        Serial.print(" Número de identificación:  ");
      }
    else 
    {
     /* if (bandera == 0)
      {
        Serial.println();
        Serial.println("*** LECTURA UHF *** ");
        Serial.println();
        Serial.print(" Número de identificación:  ");
        bandera = 1;
      }*/
      Serial.print(dato, HEX);
      delay(200);  
    }
  }
}
void loop()
{
  blink();
  if(digitalRead(BOTON1) == HIGH)
  {
    digitalWrite((LED3), HIGH);
    SCANQR();
  }
  else
  {
    digitalWrite((LED3), LOW);
  }
  if(digitalRead(BOTON2) == HIGH)
  {
    digitalWrite((LED4), HIGH);   
    LECTURAUHF(); 
  }
  else 
  {
    digitalWrite((LED4), LOW);
  }
}