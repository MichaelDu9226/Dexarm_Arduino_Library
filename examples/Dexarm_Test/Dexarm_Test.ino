#include "Dexarm_arduino.h"

//Dexarm connect to PORT1&SERIAL1
#define RXD1 26
#define TXD1 27

//PORT2&SERIAL2
#define RXD2 35
#define TXD2 23

Dexarm dexarm(&Serial1);

void setup()
{
  //Dexarm connect to PORT1&SERIAL1
  dexarm.begin(RXD1, TXD1);
  
}

void loop()
{
  dexarm.go_home();
  delay(5000);
  dexarm.go_to(0, 350, 0);
  delay(5000);
}