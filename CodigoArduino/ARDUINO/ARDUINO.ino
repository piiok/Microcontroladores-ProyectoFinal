#include <SoftwareSerial.h>
SoftwareSerial BT1(2,3); // RX | TX recuerda desconectar de pin 3 y RX al programar la placa de Nodemcu por el Arduino IDE
void setup()
{ Serial.begin(115200);
BT1.begin(115200);
}
void loop()
{

Serial.print("Estel string que se vera en el monitor serial de arduino uno (pueden ser variables)\n");
BT1.print("Este es el string que recibira nuestro nodemcu (pueden ser inclusive variables)\n"); //es importante colocar un \n al final de lo que se quiere mandar ya que en el nodem se indica el final
Serial.print("................\n");
Serial.flush();
delay(5000);
}
