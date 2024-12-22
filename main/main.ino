#include "SnesController.h"
#include <BleGamepad.h>

///Pin and Mac Config
int latchPin = 16;
int clockPin = 17;
int dataPin = 18;
uint8_t newMACAddress[] = {0xA1, 0xB3, 0xC2, 0xD6, 0xEE, 0xFF - 0x02};
uint16_t pidValue= 0xa4c0;
///

SnesController controller;
BleGamepad bleGamepad("SNES Wireless Adapter", "v1605", 100);
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
  bleGamepadConfig.setVid(0xe5302);
  bleGamepadConfig.setPid(pidValue);
  bleGamepad.begin(&bleGamepadConfig);
  esp_base_mac_addr_set(&newMACAddress[0]);
}

void loop() {
  if(bleGamepad.isConnected()){
    controller.poll(bleGamepad);
    delay(1);
  }else{
    delay(1000);
  }
}
