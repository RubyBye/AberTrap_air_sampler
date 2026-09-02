# Test Run
Perform these basic checks before deploying the samplers in the field:

## **Check RPM with taco**
* Affix reflective strip to the underside of an AberTrap arm. 
* Secure a programmed AberTrap eg in a retort stand, with the Tacometer mounted below. Both devices must be completely stationary during tesing, otherwise erroneous readings will be obtained. 
* Connect AberTrap to power supply
* Record rotational speed (rpm) after 30seconds rotation. Divide this value by 2 to get the actual rpm. 

## **Draindown to check battery duration**
* Fully charge power supply. 
* Mount programed AberTrap, complete with paddles, in a retort stand. Connect to the power supply
* Record date and time of rotation start and stop. This is your runtime.  

# Troubleshooting

## **Trinket M0 package not available**

When just downloading a fresh version of the Arduino IDE, the package for the Trinket M0 isn't included so this needs to be installed for recognition by the software. 

- File > Preferences > Additional Boards Manager URLs: > Paste in this link: https://adafruit.github.io/arduino-board-index/package_adafruit_index.json
- Tools > Board > Board Manager > Install: Adafruit SAMD Board
- Select Adafruit Trinket M0 board
- Set up a new folder eg named AberTrap_prog and place all .ino files in this folder. Then New sketch > File Open > AberTrap_prog.ino
- Double click button then go to Tools > Port > Select correct USB port for Trinket (I have found when unplugging and plugging a new one in sometimes it wants to change the port number, so this is my solution)
- Then press the button once and click upload

## **Trinket bootloader update**
If you get this Error message:

"Sketch uses 19100 bytes (7%) of program storage space. Maximum is 262144 bytes. Device unsupported Failed uploading: uploading error: exit status 1"

Then for some reason the .uf2 file might be outdated on your trinket, which causes issues with the device being recognized. 

Fix this by:
 1. Download [an updated bootloader](https://github.com/adafruit/uf2-samdx1/releases/download/v3.16.0/update-bootloader-trinket_m0-v3.16.0.uf2) from the adafruit/uf2-samdx1 github page 
 2. Double clicking the trinket button to open the bootloader (window that pops up under the drive TRINKETBOOT).
 3. Upload the updated bootloader. If it loads correctly, it should close the window.
 4. Then press the trinket button once and sketch upload should work.
