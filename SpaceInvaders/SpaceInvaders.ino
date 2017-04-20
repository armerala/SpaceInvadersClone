#include "include/Game.h"

using namespace space_invaders;

game* sp_invaders;

void setup() {
  // put your setup code here, to run once:
  pinMode(25, OUTPUT);
  digitalWrite(25, HIGH);
  Serial.begin(9600);
  Serial.println("LINK START! *music plays*");
  sp_invaders = new game();
}

void loop() {
  // put your main code here, to run repeatedly:
  sp_invaders->update();
}

