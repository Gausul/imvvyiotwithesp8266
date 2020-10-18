#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>
 
const char* ssid = "[Wifi SSID]";
const char* password =  "WIFI Password";
const char* mqttServer = "broker.imvvy.com";
const int mqttPort = 8883;
const char* mqttUser = "[MQTT Username]";
const char* mqttPassword = "MQTT Passqord";
 
WiFiClient espClient;
PubSubClient client(espClient);
 
void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }
  Serial.println("Connected to the WiFi network");
 
  client.setServer(mqttServer, mqttPort);
  client.setCallback(callback);
 
  while (!client.connected()) {
    Serial.println("Connecting to MQTT...");
 
    if (client.connect("ESP8266Client", mqttUser, mqttPassword )) {
 
      Serial.println("connected");  
 
    } else {

 
      Serial.print("failed with state ");
      Serial.print(client.state());
      delay(2000);
 
    }
  }
 char JSONMessage[] = "{\"tag\":\"Temperature\", \"Value\": [20]}";
  client.publish("[Publish Topic ]", JSONMessage);
  client.subscribe("[Publish Topic ]/subscribe");
 
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
