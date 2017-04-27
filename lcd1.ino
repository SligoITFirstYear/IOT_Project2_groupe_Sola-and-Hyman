#include "rgb_lcd.h"

rgb_lcd lcd;

int red = 6;
int blue = 4;
int green = 7;
int button = 8;
int buzzer = A0;
const int DELAYTIME = 3000; // the amount of delay time each light will have to stay on.
                            //just to make things easier for us we put 3 seconds to make thngs faster and save alot of time working on this project.
 
int readyState = 5;
bool buttonPressed = false;
bool readyStateDisplayed = false;

void setup(){
    pinMode(red, OUTPUT);
    pinMode(blue, OUTPUT);
    pinMode(green, OUTPUT);
    pinMode(button, INPUT);
    pinMode(buzzer,OUTPUT);
    tone(buzzer,100,1000);
    
    pinMode(readyState,OUTPUT); //Shows state of kit functionality
    digitalWrite(red, HIGH);
    lcd.begin(16,2);
    lcd.setCursor(0,0);
    lcd.print("LCD Started");
    
    

}

void loop() { // start of loop
   
    if(!digitalRead(readyState) == HIGH){
      digitalWrite(readyState,HIGH);
      lcd.clear();                    ///To clear the screen from any msg
      lcd.setCursor(0,0);
      lcd.print("Ready..");//Will display on screen
      lcd.setCursor(0,1);// This is just how your msg will display on screen 0 as x co-ordinator and 1 is y co-ordinator.
      lcd.print("Push the button.");
       
    }
    
    
    if(digitalRead(button) == HIGH){
      buttonPressed =true;
    
    }

    if(buttonPressed == true){
      changeLights();////button pressed, lights will change 

      
    }

    
    
}


void changeLights(){
    // green off, blue on for 3 seconds
    //Will display the "Wait message" on the lcd board for Pedestrian to warn him for the right time to cross.
    lcd.clear();
    buttonPressed = false;
    digitalWrite(readyState,LOW);
    
    digitalWrite(red, LOW);
    digitalWrite(blue, HIGH);
    lcd.setCursor(0,0);
    lcd.print("Wait to Green..");
    delay(DELAYTIME);
     // Blue off, Green is on, then it write to the lcd board it will say 
     //"it is Green" "cross now" and also buzzer will buzz until the green is off.
    digitalWrite(blue,LOW);
    digitalWrite(green,HIGH);
    lcd.setCursor(0,0);
    lcd.clear();
    lcd.print("It is green..");
    lcd.setCursor(0,1);
    lcd.print("Cross now..");
    tone(buzzer,1000);

    delay(DELAYTIME);
    noTone(buzzer);
// when green is off. it will say "wait" "careful" and then blue will come on.
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Wait..");
    lcd.setCursor(0,1);
    lcd.print("Careful..");
    digitalWrite(green,LOW);
    digitalWrite(blue,HIGH);
    delay(DELAYTIME);
// when red is on. it will write to the lcd board saying "it is red", "dont cross"
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("It is red..");
    lcd.setCursor(0,1);
    lcd.print("Dont cross..");
    digitalWrite(blue,LOW);
    digitalWrite(red,HIGH);
    
    delay(DELAYTIME);
    
}

