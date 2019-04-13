#include <Ingredient.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 11
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

String inputString = "";         // a String to hold incoming data
bool stringComplete = false;  // whether the string is complete

int pinMotor = 13;


void setup(){
  Serial.begin(9600);
  sensors.begin();
  inputString.reserve(200);
  pinMode(pinMotor, OUTPUT);
  digitalWrite(pinMotor, LOW);
  }
  
//Variable Definition  
int Stopper1 = 1;
int Stopper2 = 1;
int Stopper3 = 1;
boolean splitter = true;
int i = 0;
long current; 
boolean flag = false;
long beginning;
long previousTime;
long interval = 20000;
int volume = 1000;
String refill = "refill";




//Create Ingredients Here
Ingredient peperoni("peperoni", 120, 5);
Ingredient macaroni("macaroni", 40, 30);
Ingredient cheese("cheese", 12, 47);
Ingredient noodles("noodles", 100, 12);
Ingredient sauce("sauce", 150, 37);
Ingredient meatballs("meatballs",50,45);
Ingredient parmesaen("cheese", 10, 55);
Ingredient rice("rice", 250, 3);
Ingredient peas("peas", 50, 15);
Ingredient corn("corn", 50, 25);
Ingredient zuccini("zuccini", 75, 35);
Ingredient saltpepper("salt and pepper", 5, 45);
Ingredient soysauce("soy sauce", 10, 50);

//Set Number of Ingredients and Add Ingredients to recipe here
Ingredient macNcheese[] = {peperoni, macaroni, cheese};
Ingredient spaghetti[] = {noodles, sauce, meatballs, parmesaen};
Ingredient stirfry[] ={rice,peas,corn,zuccini,saltpepper,soysauce};
String mactest = "macNcheese";
String spagtest = "spaghetti";
String stirtest = "stirfry";

void loop() {
current = millis();

 
 // Temperature Monitoring
  if (current - previousTime >= interval){  
  previousTime = current;
  // call sensors.requestTemperatures() to issue a global temperature 
  // request to all devices on the bus
  //Serial.println("Requesting temperatures...");
  sensors.requestTemperatures(); // Send the command to get temperatures
  
  // After we got the temperatures, we can print them here.
  // We use the function ByIndex, and as an example get the temperature from the first sensor only.
  float tempC = sensors.getTempCByIndex(0);

  // Check if reading was successful
  if(tempC != DEVICE_DISCONNECTED_C) 
  {
    

    if(tempC >= 5.0 || tempC <= 0.0){
      Serial.println();
      Serial.print("    Temperature is: ");
      Serial.println(tempC); //remove ln
      Serial.println("      WARNING: Temperature outside of critical zone");
      Serial.println();
      Serial.println();
   
    }
    else{
      Serial.println();
      Serial.print("    Temperature is: ");
      Serial.println(tempC);
      Serial.println();
      Serial.println();
      }
   
  } 
  else
  {
    Serial.println("    Error: Could not read temperature data");
    Serial.println();
  }
  
}
if(checkMystring(inputString, mactest)){
  inputString= "";
  Serial.println("Order Recieved!");
  Serial.println();
  Stopper1 =0;
  i = 0;
  
  beginning = millis();
}
if(checkMystring(inputString, spagtest)){
  inputString= "";
  Serial.println("Order Recieved!");
  Serial.println();
  Stopper2 =0;
  i = 0;
  
  beginning = millis();
}
if(checkMystring(inputString, stirtest)){
  inputString= "";
  Serial.println("Order Recieved!");
  Serial.println();
  Stopper3 =0;
  i = 0;
  
  beginning = millis();
}
if(checkMystring(inputString, refill)){
  inputString= "";
  Serial.println("Refilled!");
  Serial.println();
  volume = 1000;
}
if(Stopper1 < 1){



// Dispensing Functions;
  if(flag == false){
    
    Serial.print("Next to Dispense: Ingredient ");
    Serial.print(macNcheese[i].getName());
    Serial.print(" [");
    Serial.print(macNcheese[i].getVol());
    Serial.print(" ml at ");
    Serial.print(macNcheese[i].getWhen());
    Serial.println(" seconds]");
    Serial.println();
    flag = true;
    
  }

  if(current - beginning >= (macNcheese[i].getWhen() * 1000)){
    volume = volume - macNcheese[i].getVol();
    Serial.print("Now Dispensing: ");
    Serial.print(macNcheese[i].getVol());
    Serial.print(" ml of ");
    Serial.println(macNcheese[i].getName());
    Serial.println();
    volToTime(macNcheese[i].getVol());
    flag = false;
    i++;
    
    if(volume <= 250){
      Serial.println("Dispenser Contents Low, Refill");
      Serial.println();
    }
  }

  
  if(i == sizeof(macNcheese)/sizeof(*macNcheese)){
    Stopper1++;
    Serial.println("Enjoy!");
    Serial.println();
    Serial.println();
  }
  
}

if(Stopper2 < 1){



// Dispensing Functions;
  if(flag == false){
    
    Serial.print("Next to Dispense: Ingredient ");
    Serial.print(spaghetti[i].getName());
    Serial.print(" [");
    Serial.print(spaghetti[i].getVol());
    Serial.print(" ml at ");
    Serial.print(spaghetti[i].getWhen());
    Serial.println(" seconds]");
    Serial.println();
    flag = true;
    
  }

  if(current - beginning >= (spaghetti[i].getWhen() * 1000)){
    volume = volume - spaghetti[i].getVol();
    Serial.print("Now Dispensing: ");
    Serial.print(spaghetti[i].getVol());
    Serial.print(" ml of ");
    Serial.println(spaghetti[i].getName());
    Serial.println();
    volToTime(spaghetti[i].getVol());
    flag = false;
    i++;
    
    if(volume <=250){
      Serial.println("Dispenser Contents Low, Refill");
      Serial.println();
    }
  }

  
  if(i == sizeof(spaghetti)/sizeof(*spaghetti)){
    Stopper2++;
    Serial.println("Enjoy!");
    Serial.println();
    Serial.println();
  }
  
}
if(Stopper3 < 1){



// Dispensing Functions;
  if(flag == false){
    
    Serial.print("Next to Dispense: Ingredient ");
    Serial.print(stirfry[i].getName());
    Serial.print(" [");
    Serial.print(stirfry[i].getVol());
    Serial.print(" ml at ");
    Serial.print(stirfry[i].getWhen());
    Serial.println(" seconds]");
    Serial.println();
    flag = true;
    
  }

  if(current - beginning >= (stirfry[i].getWhen() * 1000)){
    volume = volume - stirfry[i].getVol();
    Serial.print("Now Dispensing: ");
    Serial.print(stirfry[i].getVol());
    Serial.print(" ml of ");
    Serial.println(stirfry[i].getName());
    Serial.println();
    volToTime(stirfry[i].getVol());
    digitalWrite(pinMotor, LOW);
    flag = false;
    i++;
    
    if(volume <= 250){
      Serial.println("Dispenser Contents Low, Refill");
      Serial.println();
    }
  }

  
  if(i == sizeof(stirfry)/sizeof(*stirfry)){
    Stopper3++;
    Serial.println("Enjoy!");
    Serial.println();
    Serial.println();
  }
  
}
}




//Reads input and updates inputString
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    
    // if the incoming character is a newline, set a flag so the main loop can
    // do something about it:
    if (inChar == '\n') {
     
      stringComplete = true;
      }
    else{
       // add it to the inputString:
    inputString += inChar;
    }
    }
}

// Tester function, checks input string against another string
 boolean checkMystring(String input, String Test) {
    // trim is a method of the String class that removes whitespace
    // including Newline and Carrriage return
    input.trim(); 
    // either of the following 2 commands is OK:
    if (input == Test) 
    //if (inputString.equalsIgnoreCase(Test))
      {return true; }
    else{
      return false;  
    }
}

void volToTime(int volume){
  long duration = current;
  digitalWrite(pinMotor, HIGH);
  while(volume/30 > ((current - duration)/1000)){
    current = millis();
}
digitalWrite(pinMotor, LOW);
}
