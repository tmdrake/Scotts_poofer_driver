/*
Runs a Poofer Box for Scott
3/23/2025


*/

/*Control inputs*/
const int rx_5V = 13;
const int rx_VT = 8;
#include <YK04_Module.h>
#define A_PIN 12 // (D0)
#define B_PIN 11 // (D1)
#define C_PIN 10 // (D2)
#define D_PIN 9 // (D3)
YK04_Module* module; // C style

/*Relay output*/
const int relay_3 = A0;
const int relay_4 = A1;
const int relay_1 = A2;
const int relay_2 = A3;

/*Timer*/
#include "Timer.h"

Timer R1;
Timer R2;
Timer R3;
Timer R4;

void setup() {
  Serial.begin(115200);
  // Configuring the RF attached to the UNO
  pinMode(rx_5V, OUTPUT);
  digitalWrite(rx_5V, HIGH);
  module = new YK04_Module(A_PIN, B_PIN, C_PIN, D_PIN);

  //pinMode(rx_D0, INPUT);
  //pinMode(rx_D1, INPUT);
  //pinMode(rx_D2, INPUT);
  //pinMode(rx_D3, INPUT);
  pinMode(rx_VT, INPUT);

  // Configuring the RELAY attached to the UNO
  pinMode(relay_1, OUTPUT);
  pinMode(relay_2, OUTPUT);
  pinMode(relay_3, OUTPUT);
  pinMode(relay_4, OUTPUT);

  /*Active low to trigger output relays*/
  digitalWrite(relay_1, HIGH);
  digitalWrite(relay_2, HIGH);
  digitalWrite(relay_3, HIGH);
  digitalWrite(relay_4, HIGH);


}

void loop() {
  /*Updating timers*/
  R1.update();
  R2.update();
  R3.update();
  R4.update();

  /*Updating code*/
  if (module->isA())
  {
    digitalWrite(relay_1, LOW); //fires relays
    R1.after(50, r1After);
    Serial.println("Button B");
  } 



  if (module->isB())
  {
    digitalWrite(relay_3, LOW);
    R3.after(2000, r3After);    
    Serial.println("Button D");

  } 

  if (module->isC())
  {
    digitalWrite(relay_2, LOW);
    R2.after(50, r2After);
    Serial.println("Button A");

  } 


  if (module->isD())
  {
    digitalWrite(relay_4, LOW);
    R4.after(2000, r4After);
    Serial.println("Button C");
  } 
}

void r1After(){
  digitalWrite(relay_1, HIGH);
}

void r2After(){
  digitalWrite(relay_2, HIGH);
}

void r3After(){
  digitalWrite(relay_3, HIGH);
}

void r4After(){
  digitalWrite(relay_4, HIGH);
}
