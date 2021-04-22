#include <SoftwareSerial.h>
 // arduino Rx (pin 2) ----> ESP8266 pin Tx
 // arduino Tx (pin 3) ----> ESP8266 pin Rx
SoftwareSerial esp8266(3,2); 

void setup() // Configuracion con comandos AT para el modulo solo se ejecuta una vez 
{
 Serial.begin(9600);  // monitor serial del arduino
 esp8266.begin(9600); // baud rate del ESP8266 
 
 esp8266.print("AT+RST\r\n"); //Envia comando AT para reiniciar el modulo 
 delay(2000); // Tiempo de espera para realizar el reset del modulo 
 esp8266.print("AT+CIFSR\r\n"); //Envia comando AT para consultar la dirección ip estatica asignada
 delay(1000);// Tiempo de espera para la consulta de la ip estatica del modulo 
 esp8266.print("AT+CIPMUX=1\r\n");//Envia comando AT para configurar el modulo con multiples peticiones 
 delay(1000);// Tiempo de espera para la configuración 
 esp8266.print("AT+CIPSERVER=1,1234\r\n");//Envia comando AT para configurar el modulo como servidor y su puerto de conexión para este caso es el 1234
 delay(1000);
}

void loop()// loop infinito para leer la comunicación virtual del puerto serie 
{ 
  if (esp8266.available())
 
  { char c = esp8266.read();
    Serial.print(c);
    
  }
  if (Serial.available())
  { char c = Serial.read();
    esp8266.print(c);
  }
}
