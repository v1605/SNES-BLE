# SNES-BLE

![PXL_20240320_140118943](https://github.com/v1605/SNES-BLE/assets/55302877/959ba961-3238-4682-997d-3d179af7a2f2)

This code is an example using an ESP32 and the ESP32-BLE-Gamepad libary to create a SNES to bluethooth adapter that has an average lag of 8.001405ms. The example code using the latch pin on 16, the clock on pin 17, and the data pin on 18. The ground pin s connected to the ground of the ESP32 and the 5v pin needs to be connected to a 5v source, which can be the VCC pin of the ESP32. SNES port pinout can be found [here](https://wiki.superfamicom.org/schematics-ports-and-pinouts#controller-ports-3).

## Hardware

This was tested using a alliexpress D1 Mini ESP32. Other hardware is not included (such as a LIPO battery charger pcb) since I'm not sure what are the best ones to recommend for longevity. My own implementation has shortcommings such as it can only charge using a A to C cable and cannot run the ESP32 via its 3.3v or VCC pins. If you can provide a good example circuit design, I'd welcome all suggestions.

## Lag Results

I've included my lag results that contain 2000 samples as well as some stats. These were tested using a Mister (eg. https://www.youtube.com/watch?v=6GGkVAi2db0) and a HORI Snes Fight Stick.


## Setup

### Ardunio Studio

1. Install Ardunio Studio (latest nightly at the time of writing was used)
2. Navigate to the menu "Tools | Board | Board Manager"
3. On the new left nav panel, search for "Esp32" and click to install "esp32 by Espressif Systems"
4. Navigate to the menu "Tools | Manage Libaries..."
5. Search for "ESP32-BLE-Gamepad" and click to install "ESP32-BLE-Gamepad by lemmingDev". If prompted, also install NimBLE.
6. Connect your ESP32 to the computer.
7. Select your board from the dropdown and under "Tools | Port" select your board's port.
8. Click the arrow to compile and flash your ESP32
