#include <NewPing.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

Servo servoMotorMetal;
Servo servoMotorPlastico;
Servo servoMotorVidrio;

//Variables de echo
#define Pecho 50
#define Ptrig 52
#define sensor A0
#define led 48
#define servoN1 2 //Metal
#define servoN2 3 //Plastico
#define servoN3 4 //Vidrio




float metalDetected,duracion;
int monitoring,pausa,distancia,conteo,conteom;
int metalDetection = 1;

//Crear el objeto lcd  dirección  0x3F y 16 columnas x 2 filas
LiquidCrystal_I2C lcd(0x27,16,2);  

// Se crea un objeto con la libreria NewPing llamado sonar
NewPing sonar(Ptrig, Pecho, 200); // Each sensor's trigger pin, echo pin, and max distance to ping.

void setup(){
Serial.begin(9600);
// Inicializar el LCD
  lcd.init();
//Encender la luz de fondo.
  lcd.backlight();
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
}

void loop(){

//Ultrasonido detectando objeto
int distancia = sonar.ping_cm();
Serial.println(distancia);
if(distancia <= 5){ 
  
  //contador de la cantidad de basura ingresada
  int estado = analogRead(sensor);
  Serial.println("sensor ----------------");
  Serial.println(estado);
  conteo = conteo + 1;
  Serial.println(conteo); 
  //DELAY
  pausa = distancia*10;
  
  //Configuración de la pantalla
  lcd.setCursor(1, 0);
  lcd.println("Material detectado     ");
  Serial.println("Material detectado");
  
  //Detectando metal
  monitoring = analogRead(metalDetection);
  metalDetected = (float) monitoring*100/1024.0;
  //Serial.print(monitoring);
  // delay(1000);
  // Serial.print("Metal is Proximited = ");
  //Serial.print(metalDetected);
  // Serial.println("%");
  // delay(pausa);

  //ClASIFICANDO MATERIAL
  //si es metal 
  if (monitoring < 250){
      conteom = conteom +1;
      lcd.setCursor(0, 1);
      lcd.println("Es metal        ");
      Serial.println("Metal detectado");
      Serial.println(conteom);

      //Abre compuerta de metal
      servoMotorVidrio.write(0);
      servoMotorPlastico.write(0);
      servoMotorMetal.write(90);
      
      //delay(pausa);
   }
   else{
      digitalWrite(led, HIGH); 
      if(estado == 8 || estado == 9 || estado == 10){
         lcd.setCursor(0, 1);
         lcd.println("VIDRIO         ");

         //Abre compuerta Vidrio 
         servoMotorVidrio.write(180);
         servoMotorMetal.write(180);
         servoMotorPlastico.write(0);
         //delay(pausa);
      }
      else{
        if(estado == 6 || estado == 7){
          lcd.setCursor(0, 1);
          lcd.println("PLASTICO          ");

          //Abre compuerta Plastico
          servoMotorVidrio.write(0);
          servoMotorMetal.write(180);
          servoMotorPlastico.write(180);
         //delay(pausa);
        }else{
          lcd.setCursor(0, 1);
          lcd.println("ORDINARIO          ");

          //Abre compuerta Ordinario 
          servoMotorVidrio.write(0);
          servoMotorMetal.write(0);
          servoMotorPlastico.write(0);
         //delay(pausa); 
        }
      }
      /*lcd.setCursor(0, 1);
      lcd.println("No es metal         ");
      //delay(pausa);*/
   }
   delay(100);
 }
 //Cuando no hay basura
 else{
    servoMotorVidrio.write(0);
    servoMotorMetal.write(0); 
    servoMotorPlastico.write(0);
    digitalWrite(led, LOW);
    lcd.setCursor(1, 0);
    lcd.println("Vacio              ");
    lcd.setCursor(0, 1);
    lcd.println("                  ");
    delay(100);
 }
 
  
}
