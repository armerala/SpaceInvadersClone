#include "include/Game.h"

using namespace space_invaders;

game* g;

void setup() {
  // put your setup code here, to run once:
  pinMode(25, OUTPUT);
  digitalWrite(25, HIGH);
  Serial.println("Setting up game");
  g = new game();
}

void loop() {
  // put your main code here, to run repeatedly:
  g->update();
}
