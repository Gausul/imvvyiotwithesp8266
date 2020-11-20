##  Control 220-240 Volt Electric Geyser | NodeMCU/D1 MINI + 5V Relay + MQTT (Imvvy IoT Platform) + Arduino IDE 

### IoT (Internet of things) set-up to operate/control 220-240 Volt AC Geyser/Device

### Requirement 

1: NodeMCU/D1 MINI 

2: 5V Relay 

3: MQTT Imvvy IoT Platform Account 

4: Arduino IDE 

5: MQTT.FX /IMVVY MOBILE APP


![alt text](https://imvvy.com/Untitleddesign.png)

Sample Code Link: 

<a href="https://github.com/Gausul/imvvyiotwithesp8266/blob/main/geyser-on-off/code.ino">`Download Sample Code`</a>`


### Arduino IDE Instructions:

1: Download Code.ino file open in Arduino IDE 

2: Update SSID AND PASSOWRD

3: Create Account in Imvvy IoT platform and new MQTT type device

[![How to create a free account in Imvvy IoT Platform and how to add your first device ?](https://img.youtube.com/vi/Xmpbjg0zJjM/0.jpg)](https://www.youtube.com/watch?v=Xmpbjg0zJjM "How to create a free account in Imvvy IoT Platform and how to add your first device?")

4: Update MQTT `username`,`password` in code according to device profile.

```const char* mqttServer = "broker.imvvy.com";
const int mqttPort = 8883;
const char* mqttUser = "**";
const char* mqttPassword = "***"; 
```

5: Update MQTT Topic `Publish topic`, `subscribe topic` in code according to device profile.

```//publish Topic
client.publish("26e2c877627b88392823ab17c630815841", JSONMessage);
//subscribe Topic
client.subscribe("26e2c877627b88392823ab17c630815841/downlink");
```

5: Upload code to NodeMCU/D1 MINI board 

[![How to create a free account in Imvvy IoT Platform and how to add your first device ?](https://img.youtube.com/vi/HhWT6fqeYvQ/0.jpg)](https://www.youtube.com/watch?v=HhWT6fqeYvQ "How to create a free account in Imvvy IoT Platform and how to add your first device?")

#### Open MQTT.fx send cmd

Example:

For ON :
`{"value":1}`

For OFF:
`{"value":0}`


#### WARNING!! – THIS PROJECT INVOLVES WORKING WITH HIGH VOLTAGES. PLEASE PROCEED WITH CAUTION, AND ALWAYS MAKE SURE CIRCUITS ARE UN-PLUGGED BEFORE WORKING ON THEM.


Create your free account.<a href="https://platform.imvvy.com/register" target="_blank"> `Click Here` </a>

MQTT Sample Code ESP8266 Code <a href="https://github.com/Gausul/imvvyiotwithesp8266/blob/main/nodemscu.ino">` Click Here` </a> 

MQTT PubSub Library For Imvvy <a href="https://github.com/knolleary/pubsubclient">`Click Here`</a>

### Important Links
1: https://www.arduino.cc/en/Reference/WiFiClient <br>

2: https://pubsubclient.knolleary.net/api.html

3: http://platform.imvvy.com

4: https://www.arduino.cc/reference/en/libraries/arduinojson

5: http://docs.imvvy.com

6: https://www.youtube.com/watch?v=Xmpbjg0zJjM

7: https://www.youtube.com/watch?v=HhWT6fqeYvQ&t=12s
