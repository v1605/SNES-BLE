#include "SnesController.h"
#include <BleGamepad.h>

///Pin Config
int latchPin = 16;
int clockPin = 17;
int dataPin = 18;
///

SnesController controller;
BleGamepad bleGamepad;
BleGamepadConfiguration bleGamepadConfig;
void setup() {
  controller.init(latchPin, clockPin, dataPin);
  bleGamepadConfig.setControllerType(CONTROLLER_TYPE_GAMEPAD); 
  bleGamepadConfig.setWhichAxes(false,false,false,false,false,false,false,false);
  bleGamepadConfig.setIncludeSelect(false);
  bleGamepadConfig.setIncludeStart(false);
  bleGamepadConfig.setButtonCount(SnesController::buttonCount);
  bleGamepadConfig.setAxesMin(0x0000);   
  bleGamepadConfig.setAxesMax(0x7FFF);  
  bleGamepadConfig.setAutoReport(false);
  bleGamepad.begin(&bleGamepadConfig);
}

void loop() {
  if(bleGamepad.isConnected()){
    controller.poll(bleGamepad);
    delay(1);
  }else{
    delay(1000);
  }
}

