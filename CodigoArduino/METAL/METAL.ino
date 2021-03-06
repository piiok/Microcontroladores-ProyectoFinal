//#include <NewPing.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

Servo servoMotorMetal;
Servo servoMotorPlastico;
Servo servoMotorVidrio;
Servo servoMotorClasif;
Servo servoMotorSeguro;

//Variables de echo
#define Pecho 50
#define Ptrig 52
#define sensor A0
#define led 48
#define servoN1 2 //Metal
#define servoN2 3 //Plastico
#define servoN3 4 //Vidrio
#define servoN4 5 //Servo Clasificador
#define servoN5 6 //Servo Asegurador

float metalDetected;
int monitoring,pausa,distancia,duracion,conteo,conteom;
int metalDetection = 1;
int tiempo = 500; //tiempo de caida

//Crear el objeto lcd  dirección  0x3F y 16 columnas x 2 filas
LiquidCrystal_I2C lcd(0x27,16,2);  

// Se crea un objeto con la libreria NewPing llamado sonar
//NewPing sonar(Ptrig, Pecho, 200); // Each sensor's trigger pin, echo pin, and max distance to ping.

void setup(){
  Serial.begin(9600);
  // Inicializar el LCD
  lcd.init();
  //Encender la luz de fondo.
  lcd.backlight();
  lcd.setCursor(1, 0);
  lcd.println("  SMART TRASH   ");
  lcd.setCursor(1, 1);
  lcd.println(" ¡ Bienvenido ! ");
  
  //echo
  pinMode(Pecho,INPUT);
  pinMode(Ptrig,OUTPUT);
  pinMode(led,OUTPUT);

  //servos
  servoMotorMetal.attach(servoN1);
  servoMotorMetal.write(0);
  servoMotorPlastico.attach(servoN2);
  servoMotorPlastico.write(0);
  servoMotorVidrio.attach(servoN3);
  servoMotorVidrio.write(0);
  servoMotorSeguro.attach(servoN5);
  servoMotorSeguro.write(0);
  servoMotorClasif.attach(servoN4);
  servoMotorClasif.write(100);
  servoMotorSeguro.write(100);
}

void loop(){

//Ultrasonido detectando objeto

digitalWrite(Ptrig,LOW);
delayMicroseconds(5);
digitalWrite(Ptrig,HIGH);
delayMicroseconds(10);
digitalWrite(Ptrig,LOW);

duracion = pulseIn(Pecho,HIGH);
distancia = duracion*0.017;
Serial.print("Distancia: ");
Serial.println(distancia);

if(distancia <= 9){ 
  //delay(200);
  Serial.println("----------- MATERIAL DETECTADO ----------------");
  
  //Configuración de la pantalla
  lcd.setCursor(1, 1);
  lcd.println("...Analizando...");
  Serial.println("Material detectado");
  
  //Detectando metal
  monitoring = analogRead(metalDetection);
  metalDetected = (float) monitoring*100/1024.0;

  //ClASIFICANDO MATERIAL
  //si es metal 
  if (monitoring < 250){
      conteom = conteom +1;
      lcd.setCursor(1, 1);
      lcd.println(" Metal detectado");
      Serial.print("Metal detectado: ");
      Serial.println(conteom);
      
      //Abre compuerta de metal
      servoMotorVidrio.write(0);
      servoMotorPlastico.write(0);
      servoMotorMetal.write(90);

      //Abre compuerta caja clasificadora
      servoMotorSeguro.write(0);
      servoMotorClasif.write(0);

      delay(tiempo);
      servoMotorClasif.write(100);
      delay(150);
      servoMotorSeguro.write(100);
      servoMotorMetal.write(0);
   }
   else{
      digitalWrite(led, HIGH); 
      int estado = analogRead(sensor);
      Serial.print("Fotosensor: ");
      Serial.println(estado);
      if(estado == 8 || estado == 9 || estado == 10){
        lcd.setCursor(1, 1);
        lcd.println("Vidrio detectado");
        Serial.print("Vidrio detectado.");
        
        servoMotorMetal.write(0);
        servoMotorPlastico.write(0);
        servoMotorVidrio.write(90);
  
        //Abre compuerta caja clasificadora
        servoMotorSeguro.write(0);
        servoMotorClasif.write(0);
 
        delay(tiempo);
        servoMotorClasif.write(100);  
        delay(150);        
        servoMotorSeguro.write(100);
        servoMotorVidrio.write(0);
      
      }else{
        if(estado == 6 || estado == 7){
          lcd.setCursor(1, 1);
          lcd.println("Plastico detectado");
          Serial.print("Plastico detectado.");

          //Abre compuerta Plastico
          servoMotorMetal.write(0);
          servoMotorVidrio.write(0);
          servoMotorPlastico.write(90);
    
          //Abre compuerta caja clasificadora
          servoMotorSeguro.write(0);
          servoMotorClasif.write(0);
    
          delay(tiempo);
          servoMotorClasif.write(100);
          delay(150);
          servoMotorSeguro.write(100);
          servoMotorPlastico.write(0);
          
        }else{
          lcd.setCursor(0, 1);
          lcd.println("Ordinario detectado");
          Serial.println("Ordinario detectado.");

          //Abre compuerta Ordinario 
          servoMotorMetal.write(0);
          servoMotorVidrio.write(0);
          servoMotorPlastico.write(0);
          
          //Abre compuerta caja clasificadora
          servoMotorSeguro.write(0);
          servoMotorClasif.write(0);
          
          delay(tiempo);         
          servoMotorClasif.write(100);
          delay(150);
          servoMotorSeguro.write(100);
        }
      }
   }
 }else{
    //Cuando no hay basura
    servoMotorVidrio.write(0);
    servoMotorMetal.write(0); 
    servoMotorPlastico.write(0);
    servoMotorClasif.write(100);
    delay(150);
    servoMotorSeguro.write(100);
    
    digitalWrite(led, LOW);
    lcd.setCursor(1, 0);
    lcd.println("  SMART TRASH   ");
    lcd.setCursor(1, 1);
    lcd.println(" ¡ Bienvenido ! ");
 }
 delay(200);
  
}
