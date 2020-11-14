#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>
 
const char* ssid = "SSID";
const char* password =  "Password";
const char* mqttServer = "broker.imvvy.com";
const int mqttPort = 8883;
const char* mqttUser = "**";
const char* mqttPassword = "***";
 
WiFiClient espClient;
PubSubClient client(espClient);
 
void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  
  pinMode(D0, OUTPUT);
  digitalWrite(D0, LOW);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print("Connecting to WiFi..");
  }
  Serial.print("Connected to the WiFi network");
 
  client.setServer(mqttServer, mqttPort);
  client.setCallback(callback);
 
  while (!client.connected()) {
    Serial.print("Connecting to MQTT...");

    if (client.connect("ESP8266Client", mqttUser, mqttPassword )) {
 
      Serial.print("connected");  
 
    } else {

 
      Serial.print("failed with state ");
      Serial.print(client.state());
      delay(2000);
 
    }
  }
 char JSONMessage[] = "{\"Value\": 0}";
  client.publish("26e2c877627b88392823ab17c630815841", JSONMessage);
  client.subscribe("26e2c877627b88392823ab17c630815841/downlink");
 
}
 
void callback(char* topic, byte* payload, unsigned int length) {
 
  Serial.print("Message arrived in topic: ");
  Serial.println(topic);

  StaticJsonDocument<200> doc;

   char inData[80];

  Serial.print("Message:");
  for (int i = 0; i < length; i++) {
    inData[i]=(char)payload[i];
  }

   DeserializationError error = deserializeJson(doc, inData);
if (error) {
    Serial.print(F("deserializeJson() failed: "));
   // Serial.println(error.f_str());
    return;
  }

    long sensorval = doc["value"];
    if(sensorval==1){
      digitalWrite(D0, HIGH); // turn the LED on (HIGH is the voltage level)
    }else{
      digitalWrite(D0, LOW); // turn the LED off (low is the voltage level)
    }
    

  Serial.println();
  Serial.println("-----------------------");
 
}
 
void loop() {
  
  client.loop();
}
