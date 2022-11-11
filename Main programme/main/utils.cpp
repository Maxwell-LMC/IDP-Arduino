#include "header.h"

bool compare_array(int a[4], int b[4]){
  for (int i = 0; i < 4; i++){
    if (a[i] != b[i]){
      return false;
    }
  }
  return true;
}

