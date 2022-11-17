#include "header.h"

ezButton toggleSwitch(7);  // create ezButton object that attach to pin 7;
int switch_state;


bool switch_pushed(){
  toggleSwitch.loop(); // MUST call the loop() function first
  switch_state = toggleSwitch.getState();
  if (switch_state == HIGH) return false; 
  else return true;
}
