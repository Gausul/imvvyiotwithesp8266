
//ESP8266 https://github.com/esp8266/Arduino 
#include <ESP8266WiFi.h>

//MQTT PubSub Library https://github.com/imvvy/pubsubclient
#include <PubSubClient.h>

//Arduino Json Library----------
#include <ArduinoJson.h>
 
const char* ssid = "Wifi SSID";
const char* password =  "WIFI Password";

const char* mqttServer = "broker.imvvy.com";
const int mqttPort = 8883;
const char* mqttUser = "MQTT Username";
const char* mqttPassword = "MQTT Passqord";
 
WiFiClient espClient;
PubSubClient client(espClient);
 
void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print("Connecting to WiFi..");
    Serial.println();
  }
  Serial.print("Connected to the WiFi network");
  Serial.println();
 
  client.setServer(mqttServer, mqttPort);
  client.setCallback(callback);
 
  while (!client.connected()) {
    Serial.print("Connecting to MQTT...");
    Serial.println();
    if (client.connect("ESP8266Client", mqttUser, mqttPassword )) {
 
      Serial.print("connected");  
      Serial.println();
    } else {

 
      Serial.print("failed with state ");
      Serial.print(client.state());
      delay(2000);
 
    }
  }
 char JSONMessage[] = "{\"tag\":\"Temperature\", \"Value\": [20]}";
 
 // Publish Topic
  client.publish("[Publish Topic ]", JSONMessage);
 //subscribe Topic
  client.subscribe("[Subscribe Topic ]/subscribe");
 
}
 
void callback(char* topic, byte* payload, unsigned int length) {
 
  Serial.print("Message arrived in topic: ");
  Serial.println(topic);
 
  Serial.print("Message:");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
 
  Serial.println();
  Serial.println("-----------------------");
 
}
 
void loop() {
  client.loop();
}
