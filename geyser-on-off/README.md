#  Control 220-240 Volt Electric Geyser | NodeMCU + 5V Relay + MQTT (Imvvy IoT Platform) + Arduino IDE 

### IoT (Internet of things) set-up to operate/control 220-240 Volt AC Geyser/Device

### Requirement 

1: NodeMCU 

2: 5V Relay 

3: MQTT Imvvy IoT Platform Account 

4: Arduino IDE 

5: MQTT.FX /IMVVY MOBILE APP


![alt text](https://imvvy.com/Untitleddesign.png)

Sample Code Link: <a href="https://github.com/Gausul/imvvyiotwithesp8266/blob/main/geyser-on-off/code.ino">click</a> 


Arduino IDE Instructions:

Download Code.ino file open in Arduino IDE 

Update SSID AND PASSOWRD

Create Account in Imvvy IOT PlatForm And New MQTT Type Device

Video How to ADD Device in Imvvy IoT PLATFORM

[![How to create a free account in Imvvy IoT Platform and how to add your first device ?](https://img.youtube.com/vi/Xmpbjg0zJjM/0.jpg)]
(https://www.youtube.com/watch?v=Xmpbjg0zJjM&t=29s "How to create a free account in Imvvy IoT Platform and how to add your first device ?")

Update MQTT username and password and publis and Subscribe Topic in code according Device Profile

uploaded code in to NodeMCU board <a href="https://www.youtube.com/watch?v=HhWT6fqeYvQ&t=12s"> More </a>

Open MQTT.fx send cmd

Example:

for ON :

`{"value":1}`

For OFF:

`{"value":0}`


#### WARNING!! – THIS PROJECT INVOLVES WORKING WITH HIGH VOLTAGES. PLEASE PROCEED WITH CAUTION, AND ALWAYS MAKE SURE CIRCUITS ARE UN-PLUGGED BEFORE WORKING ON THEM.
