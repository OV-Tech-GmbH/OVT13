# OVT13
Open-source thin-and-light 13" laptop
## Table of contents

1. Electronics
   - Keyboard PCB
   - Webcam PCB
2. Mechanical
   - Keyboard

4. Software
   - Keyboard firmware and source files

## Details of content

1. Electronics
   - Keyboard PCB: ![Render01](https://github.com/ThommyL34/OVT13/assets/140168168/397b6bca-a45f-4927-a19a-ad8bf5276440)<br /> <br /> 
***General description:*** <br /> <br /> This module is a separate standalone and thinly-designed electromechanical keyboard for the open-source laptop. It provides a distinct hardware abstraction via USB2.0 connectivity to simplify integration into a laptop or computer system. An RP2040 microcontroller constantly evaluates the states of the keyswitches and controls the lightning. Regarding the power supply only a voltage of 5V DC is needed to completly supply the electronics, all other voltages for digital logic and LED-driving are being generated on the PCB. Once connected to an USB Host in a computer system, the microcontroller acts as an USB Device and registers itself as an USB HID keyboard device. With this configuration no custom drivers are needed which contributes to an os-independend (Windows, Linux, etc.) and timeless integration concept. The firmware of the microcontroller is based on the open-source keyboard framework QMK. Once an USB-connection is established, standard scancodes are being transmitted to the computer system which then will be mapped into keycodes. The hardware connectivity to the mainboard of the laptop is realized over an spring-header connector receptable which includes all electrical signals and the power supply. For the firmware to load onto the RP2040, only one pin of the spring header receptable must change its logical state. The RP2040 register itself as an USB-memory device which then can be accessed via the os` filesystem. It is possible to load the firmware file per drag&drop onto the microcontroller. <br /> <br /> 
***Electrical specification***<br /> <br /> 
__PCB front view__
![OV_Tech_KB-PCB-R02_3DFront](https://github.com/ThommyL34/OVT13/assets/140168168/f1b1a592-3846-4ebf-8436-de35b6c63b70)
The PCB-front consists of the keyswitches from the manufacturer Khail. The design integrates a complete set of keys without the numerical part. Keycaps can be assembled on top of the keyswitches.
Inside the keyswitches there is a transparent cabin to integrate LED components and other small components like the anti-ghosting diode. Per keyswitch a white LED and an RGB LED is placed to keep the option to build a keyboard with either white backlightning or RGB backlightning. ![OV_Tech_KB-PCB-R02_3DCutoutTopComponentPlacement](https://github.com/ThommyL34/OVT13/assets/140168168/7394540c-19d7-4eaf-bfcd-21e5769907ae)
<br /><br /> __PCB back view__ <br />
On the backside of the PCB there are all remaining components located. The remaing components include the microcontroller RP2040 and its peripheral circuitry, voltage generation, ESD-protection and other parts of the keyswitch matrix.
![OV_Tech_KB-PCB-R02_3DBack](https://github.com/ThommyL34/OVT13/assets/140168168/dd2595d6-0f6a-4b41-9bb5-3138ff860bca) <br />
<br /> __PCB layerstack and routing__ <br /> The Layerstack consists four layers of copper and it is taken from the 4-Layer JLCPCB stackup JLC04161H-7628. An impedance profile 90Ohms is included for the USB connection. The layerstack looks as follows: Top-layer: Signal, Mid1-layer: GND, Mid2-layer PWR/GND, Bottom-layer: Signal <img width="933" alt="OV_Tech_KB-PCB-LayerstackWithImpedanceProfile" src="https://github.com/ThommyL34/OVT13/assets/140168168/c46c7420-982a-45b3-bb85-4ff321c2bec7">
On the top layer all signals and power supplies regarding the LED-backlightning are routed:
![OV_Tech_KB-PCB-R02_TopLayer](https://github.com/ThommyL34/OVT13/assets/140168168/fcb6f3a5-00f5-4f1a-be04-c5fa4a6a91aa)
The Mid1-layer includes a continuous ground plane to provide good electrical characteristics. The Mid2-layer is a mix of power plane distribution and ground islands, especially for the dense placement of the microcontroller and surrounding circuitry:
![OV_Tech_KB-PCB-R02_MidLayer2PWRf](https://github.com/ThommyL34/OVT13/assets/140168168/20dcfa04-12ea-4e32-9b6a-598b67cc5c45)
On the bottom layer consist of the routing of the keyswitch matrix, the microcontroller and the remaining circuitry.
![OV_Tech_KB-PCB-R02_BottomLayer](https://github.com/ThommyL34/OVT13/assets/140168168/3546ab77-9cfc-49f5-a72f-db4143f34e5b)







