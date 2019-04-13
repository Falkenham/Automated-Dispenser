/*
 *Ingredient.h - Library for creating Ingredient type objects
 *Created by Owen Falkenham, March 16th 2019
 *For GNG 1103 - C
 */

#ifndef Ingredient_h
#define Ingredient_h
#include "Arduino.h"
class Ingredient
{
  public:
  Ingredient(String title, long vol, long when);
  long getVol();
  long getWhen();
  String getName();
  
  private:
  long when;
  long vol;
  String title;
  
};
#endif