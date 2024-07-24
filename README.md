# OVT13
Open-source thin-and-light 13" laptop
## Table of contents

1. Electronics
   - Keyboard PCB
   - Webcam PCB
   - Trackpad PCBs
2. Mechanical
   - Keyboard
3. Software
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

   - Trackpad PCBs:<br /> <br /> 
***General description:***<br /> <br /> The design of the trackpad module consists of two printed circuit boards. The first one consists of the touch-sensitive matrix which, can be influenced by the user. In order to keep variations and negative impact factors away from the matrix, the touch sensing IC and its digital communication partner are located on an evaluation board. Both boards are connected via an flex-pcb cable section so the touch IC can to read the sensing matrix.<br /> <br /> ![Trackpad_Sensor_Eval_assembled](https://github.com/user-attachments/assets/9d1d5c05-35d7-4686-83dc-7386bd986231)
<br /> <br />
__1. Trackpad sensor PCB electrical specification:__<br /> <br />
The top side of the PCB consists of touch-sensitive elements in the form of diamonds arranged in rows and columns. The gaps between the diamonds form capacitive elements that can be controlled and thus read by the touch IC. The capacitive elements generate an electric field, that is deflected when the user`s finger approaches. The change in the field and thus the resulting capacitance and charge can be measured and converted into a finger position sensor. <br /> <br />
![grafik](https://github.com/user-attachments/assets/e0cc8f8d-ebc5-42ae-a14e-358e26bcf648)
<br /> <br />
On the backside of the pcb a flex pcb connector and a snap dome are located. The flex connector is used to connect the board to another board on which a touch IC is located via a flex cable. The snap dome is being used to generate the function of a button press. When pressed, the entire row and colum is shorted and the rapid change in capacitance and therefore charge is recognised and interpreted as a button press. <br /> <br />
![grafik](https://github.com/user-attachments/assets/24326cf9-0dcd-4f91-86f4-e88f273a7210)
<br /> <br />__2. Trackpad evaluation PCB electrical specification:__<br /> <br />
This PCB is designed as a flex PCB with two stiffened sections. The section where all the components are located is fitted with a FR4-stiffener. The section designed as a flex cable contains no stiffeners in order to utilise the flexibility of a flex cable. The last section is the connector tongue itself and the stiffener is made out of polyimide to fulfil the thickness insertion requierements of the ffc-connector on the trackpad PCB.
<br /> <br /><img width="1172" alt="Trackpad Evalboard Board Section View" src="https://github.com/user-attachments/assets/adf7011b-0394-4372-af82-0d19c60697d6">
<br /> <br />
The evaluation board is used to collect trackpad touch data and turn it into an USB HID mouse. This level of integration abstracts the custom interface to a simple USB connection without the need for special drivers or hardware to utilise the touch data. The IQS9150 IC performs the sampling and processing of the trackpad touches and snapdome clicks and reports the data to an RP2040, which performs some further processing, such as interpreting a click event as a left or right mouse button click. The RP2040 streams the touch data in USB HID mouse format to an USB host and thus acts as an I2C USB bridge. Additional connections for programming and evaluating the two ICs and other devices such as test buttons are provided on the board for development purposes. The final board will contain only the two ICs, some necessary external circuitry and an USB connection. This makes integration into the laptop easy and follows the concept of a timeless and modular design.
<br /> <br />
<img width="1211" alt="Trackpad Evalboard Board 3D view" src="https://github.com/user-attachments/assets/686491d8-49a0-4ff7-8e8e-93cce139e63a"><br /> <br />

3. Mechanical
   - Keyboard: -

4. Software
   - Keyboard PCB: The firmware of the keyboard was created using the framework QMK. The framework provides all basic keyboard functions such as matrix scanning, USB communication, lightning and much more. Therefore, only one module of the keyboard project has been created for the specific design of the keyboard. Minor modifications were made to the QMK core to compile the firmware for the RP2040 microcontroller. A standard English keyboard layout (QWERTY) was used. Details of the code project can be found in the subfolder for the keyboard software.


