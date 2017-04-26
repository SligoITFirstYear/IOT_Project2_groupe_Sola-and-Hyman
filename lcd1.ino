#include "rgb_lcd.h"

rgb_lcd lcd;

int red = 6;
int blue = 4;
int green = 7;
int button = 8;
int buzzer = A0;

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
    
    pinMode(readyState,OUTPUT);
    digitalWrite(red, HIGH);
    lcd.begin(16,2);
    lcd.setCursor(0,0);
    lcd.print("LCD Started");
    
    

}

void loop() {
    //if (digitalRead(button) == HIGH){
        //delay(15); // software debounce
       // if (digitalRead(button) == HIGH) {
            // if the switch is HIGH, ie. pushed down - change the lights!
            //changeLights();
        //    delay(15000); // wait for 15 seconds
      //  }
    //}
    if(!digitalRead(readyState) == HIGH){
      digitalWrite(readyState,HIGH);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Ready..");
      lcd.setCursor(0,1);
      lcd.print("Push the button.");
       
    }
    
    
    if(digitalRead(button) == HIGH){
      buttonPressed =true;
    
    }

    if(buttonPressed == true){
      changeLights();
      
    }

    
    
}


void changeLights(){
    // green off, blue on for 3 seconds
    lcd.clear();
    buttonPressed = false;
    digitalWrite(readyState,LOW);
    
    digitalWrite(red, LOW);
    digitalWrite(blue, HIGH);
    lcd.setCursor(0,0);
    lcd.print("Wait to Green..");
    delay(3000);

    digitalWrite(blue,LOW);
    digitalWrite(green,HIGH);
    lcd.setCursor(0,0);
    lcd.clear();
    lcd.print("It is green..");
    lcd.setCursor(0,1);
    lcd.print("Cross now..");
    tone(buzzer,1000);

    delay(3000);
    noTone(buzzer);

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Wait..");
    lcd.setCursor(0,1);
    lcd.print("Careful..");
    digitalWrite(green,LOW);
    digitalWrite(blue,HIGH);
    delay(3000);

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("It is red..");
    lcd.setCursor(0,1);
    lcd.print("Dont cross..");
    digitalWrite(blue,LOW);
    digitalWrite(red,HIGH);
    
    delay(3000);
    
}

