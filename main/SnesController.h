#include <BleGamepad.h>
class SnesController {
  
  public:
    static const int buttonCount = 12;

  private:
    int latchPin;
    int clockPin;
    int dataPin;
    int buttons[buttonCount]={1};

  public:
    void init(int latch, int clock, int data){
      latchPin = latch;
      clockPin = clock;
      dataPin = data;
      pinMode(latchPin, OUTPUT);
      digitalWrite(latchPin, LOW);
      pinMode(clockPin, OUTPUT);
      digitalWrite(clockPin, HIGH);
      pinMode(dataPin, INPUT_PULLUP);
    }
    
    void poll(BleGamepad& bleGamepad){
      digitalWrite(latchPin, HIGH);
      delayMicroseconds(12);
      digitalWrite(latchPin, LOW);  
      delayMicroseconds(6);
      bool sendReport = false;
      for(int i = 0; i < buttonCount; i++){
        int value = digitalRead(dataPin); //0 = pressed, 1 = released
        if(buttons[i] != value){
          buttons[i]= value;
          sendReport = true; //Only report if a button state changes
          if(value == 0){
            bleGamepad.press(i + 1);
          }else{
            bleGamepad.release(i + 1);
          }
        }
        digitalWrite(clockPin, LOW);
        delayMicroseconds(6);
        digitalWrite(clockPin, HIGH);
        delayMicroseconds(6);
      }
      if(sendReport){
        bleGamepad.sendReport();
      }
    }
};

