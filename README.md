# OVT13
Open-source thin-and-light 13" laptop
## Table of contents

1. Electronics
   - Keyboard PCB design data
   - Webcam PCB design data
2. Mechanical
   - Keyboard design data

4. Software
   - Keyboard firmware and source files

## Details of content

1. Electronics
   - Keyboard PCB: ![Render01](https://github.com/ThommyL34/OVT13/assets/140168168/397b6bca-a45f-4927-a19a-ad8bf5276440) This module is a separate standalone and thinly-designed electromechanical keyboard for the open-source laptop. It provides a distinct hardware abstraction via USB2.0 connectivity to simplify integration into a laptop or computer system. An RP2040 microcontroller constantly evaluates the states of the keyswitches and controls the lightning. Regarding the power supply only a voltage of 5V DC is needed to completly supply the electronics, all other voltages for digital logic and LED-driving are being generated on the PCB. Once connected to an USB Host in a computer system, the microcontroller acts as an USB Device and registers itself as an USB HID keyboard device. With this configuration no custom drivers are needed which contributes to an os-independend (Windows, Linux, etc.) and timeless integration concept. The firmware of the microcontroller is based on the open-source keyboard framework QMK. Once an USB-connection is established, standard scancodes are being transmitted to the computer system which then will be mapped into keycodes. The hardware connectivity to the mainboard of the laptop is realized over an spring-header connector which includes all electrical signals and the power supply. For the firmware to load onto the RP2040, only one pin of the spring header must change its logical state. The RP2040 register itself as an USB-memory device which then can be accessed via the os` filesystem. It is possible to load the firmware file per drag&drop onto the microcontroller. 
