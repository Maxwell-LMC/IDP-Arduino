#include "header.h"

void navigateToBlock(){
  while(true){
    lineSensorsRead();
    if(!compare_array(orientation, previous_orientation)){
      for (int i = 0; i < 4; i++){
        previous_orientation[i] = orientation[i];
      }
      for (int i = 0; i < 4; i++){
        Serial.print(orientation[i]);
      }
      Serial.println(" ");
      lineFollowing();
    }
  }
}