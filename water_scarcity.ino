//#include <ESP8266WiFi.h>
//#include <DHT.h>
//
//#define AO_PIN A0
//#define TRIG_PIN D5
//#define ECHO_PIN D6
//#define DHT_SENSOR_PIN D7
//#define DHT_SENSOR_TYPE DHT11
//
//DHT dht_sensor(DHT_SENSOR_PIN, DHT_SENSOR_TYPE);
//
//
//const char* ssid     = "wifi007";
//const char* password = "12345678";
//
//const char* host = "waterscarcity1.000webhostapp.com";
//const char* streamId   = "....................";
//const char* privateKey = "....................";
//
//WiFiServer server(80);
//
//void setup() {
//  Serial.begin(9600);
//  pinMode(TRIG_PIN, OUTPUT);
//  pinMode(ECHO_PIN, INPUT);
//  dht_sensor.begin();
//
//  
//  Serial.println();
//  Serial.println();
//  Serial.print("Connecting to ");
//  Serial.println(ssid);
//  
//  WiFi.begin(ssid, password);
//  
//  while (WiFi.status() != WL_CONNECTED) {
//    delay(500);
//    Serial.print(".");
//  }
//
//  Serial.println("");
//  Serial.println("WiFi connected");  
//  Serial.println("IP address: ");
//  Serial.println(WiFi.localIP());
//}
//
//void loop() {
//   {
//      int gasValue = analogRead(AO_PIN);
//      digitalWrite(TRIG_PIN, HIGH);
//      delayMicroseconds(10);
//      digitalWrite(TRIG_PIN, LOW);
//      float duration_us = pulseIn(ECHO_PIN, HIGH);
//      float distance_cm = 0.017 * duration_us;
//      float humi = dht_sensor.readHumidity();
//      float temperature_C = dht_sensor.readTemperature();
//  Serial.print("connecting to ");
//  Serial.println(host);
//  
//  // Use WiFiClient class to create TCP connections
//  WiFiClient client;
//  const int httpPort = 80;
//  if (!client.connect(host, httpPort)) {
//    Serial.println("connection failed");
//    return;
//  }
//
//  String url = "GET http://waterscarcity1.000webhostapp.com/template/update.php?temperature="; // Getting info from my online database through my online website
//  url+=temperature_C;
//  url+="&humidity=";
//  url+=humi;
//  url+="&air=";
//  url+=gasValue;
//  url+=" HTTP/1.1\r\nHost: waterscarcity1.000webhostapp.com\r\n\r\n";
//  url += "\r\n\r\n";
//  Serial.print("Requesting URL: ");
//  Serial.println(url);
//  
//  // This will send the request to the server
//  client.print(url);
//  unsigned long timeout = millis();
//  while (client.available() == 0) {
//    if (millis() - timeout > 5000) {
//      Serial.println(">>> Client Timeout !");
//      client.stop();
//      return;
//    }
//  }
//  
//  // Read all the lines of the reply from server and print them to Serial
//  while(client.available()){
//    char a=client.read();
//    Serial.print(a);
//    /*
//    if(a=='*')
//    {
//      a=client.read();
//    Serial.print(a);
//    if(a=='a')
//    {
//      a=client.read();
//      Serial.print(a);
//    if(a=='1')
//    {
//      digitalWrite(D8,LOW);
//      }
//      if(a=='0')
//    {
//      digitalWrite(D8,HIGH);
//      }  
//      
//    }  
//      }*/
//    //String line = client.readStringUntil('\r');
//    //Serial.print(line);
//   
//    Serial.print(a);
// 
//     
//    }
//    }
//  
//}







#include <ESP8266WiFi.h>
#include <DHT.h>

#define AO_PIN A0
#define TRIG_PIN D5
#define ECHO_PIN D6
#define DHT_SENSOR_PIN D7
#define DHT_SENSOR_TYPE DHT11

DHT dht_sensor(DHT_SENSOR_PIN, DHT_SENSOR_TYPE);

const char* ssid = "wifi007";
const char* password = "12345678";

const char* host = "waterscarcity1.000webhostapp.com";

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  dht_sensor.begin();

  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  int gasValue = analogRead(AO_PIN);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  float duration_us = pulseIn(ECHO_PIN, HIGH);
  float distance_cm = 0.017 * duration_us;
  float humi = dht_sensor.readHumidity();
  float temperature_C = dht_sensor.readTemperature();

  Serial.print("connecting to ");
  Serial.println(host);
  
  WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }

  String url = "/template/update.php?temperature=";
  url += String(temperature_C);
  url += "&humidity=";
  url += String(humi);
  url += "&air=";
  url += String(gasValue);

  Serial.print("Requesting URL: ");
  Serial.println(url);
  
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: close\r\n\r\n");

  unsigned long timeout = millis();
  while (client.available() == 0) {
    if (millis() - timeout > 5000) {
      Serial.println(">>> Client Timeout !");
      client.stop();
      return;
    }
  }
  
  while (client.available()) {
    String line = client.readStringUntil('\r');
    Serial.print(line);
  }
  
  Serial.println();
  Serial.println("closing connection");
  client.stop();
  
  delay(10000); // Interval between requests
}
