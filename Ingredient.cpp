/*
 *Ingredient.h - Library for creating Ingredient type objects
 *Created by Owen Falkenham, March 16th 2019
 *For GNG 1103 - C
 */

#include "Arduino.h"
#include "Ingredient.h"

Ingredient::Ingredient(String label, long amount, long dispense){
  title = label;
  vol = amount;
  when = dispense; 
}

long Ingredient::getWhen(){
  return when;
}

long Ingredient::getVol(){
  return vol;
}

String Ingredient::getName(){
  return title;
}

