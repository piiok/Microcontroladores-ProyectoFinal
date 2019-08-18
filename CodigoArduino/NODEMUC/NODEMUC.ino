#include <SoftwareSerial.h>
void setup() {
Serial.begin(115200);
delay(100) ;
}
void loop() {
Serial.flush();
//desde aqui empieza a recibir el string:
String S = "" ;
if (Serial.available() )
{char c = Serial.read();
while ( c != '\n' ) //Hasta que el caracter sea intro != significa diferente a...
{ S = S + c ;
//delay(25) ;
c = Serial.read();
}
}else {return;}
delay(500);
Serial.println(String (S));
Serial.flush();
delay(5000);
}
