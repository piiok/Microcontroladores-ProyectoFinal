#include <ArduinoJson.h>
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Conexiones.
#define FIREBASE_HOST "smart-trahs.firebaseio.com"
#define FIREBASE_AUTH "cpeSboixPct7MnZofW3gu2OismxlGUyJuKxq9Vem"
#define WIFI_SSID "MICROMERCADO.FAMILIAR"
#define WIFI_PASSWORD "14152969"

//Prueba optica
//# define sensor A0

//Metal
#define Pecho 16
#define Ptrig 5
long duracion;
int distancia;

void setup() {
  Serial.begin(9600);

  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

  pinMode(Pecho,INPUT);
  pinMode(Ptrig,OUTPUT);

  //pinMode(sensor,INPUT);
}

int n = 0;

void loop() {

  //int value = 0;
  //value = analogRead(sensor);
  /*Firebase.setInt("prueba",  value);
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /prueba failed:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(100);

  Serial.print("Distancia: ");
  Serial.println(value);*/
  
  digitalWrite(Ptrig, LOW); //para generar un pulso limpio ponemos a LOW 4us
  delayMicroseconds(4);
  digitalWrite(Ptrig, HIGH); //generamos Trigger (disparo) de 10us
  delayMicroseconds(10);
  digitalWrite(Ptrig, LOW);
  
  duracion = pulseIn(Pecho, HIGH); //medimos el tiempo entre pulsos, en microsegundos
  
  distancia = duracion *0.017; //convertimos a distancia, en cm

  Firebase.setInt("nivelestrash/metal", distancia);
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /metal failed:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(100);

  Serial.print("Distancia: ");
  Serial.println(distancia);
  
  
  /*String prueba = Firebase.pushInt("distancia", n++);
  if (Firebase.failed()) {
      Serial.print("pushing /distancia failed:");
      Serial.println(Firebase.error());  
      return;
  }*/
  /*// set value
  Firebase.setInt("number", 42);
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /number failed:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(1000);
  
  // update value
  Firebase.setInt("number", 43);
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /number failed:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(1000);

  // get value 
  Serial.print("number: ");
  Serial.println(Firebase.getInt("number"));
  delay(1000);

  // remove value
  Firebase.remove("number");
  delay(1000);

  // set string value
  Firebase.setString("message", "hello world");
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /message failed:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(1000);
  
  // set bool value
  Firebase.setBool("truth", false);
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /truth failed:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(1000);

  // append a new value to /logs
  String name = Firebase.pushInt("Prueba", n++);
  // handle error
  if (Firebase.failed()) {
      Serial.print("pushing /Prueba failed:");
      Serial.println(Firebase.error());  
      return;
  }*/
  /*Serial.print("pushed: /prueba/");
  Serial.println(prueba);
  delay(1000);*/
}
