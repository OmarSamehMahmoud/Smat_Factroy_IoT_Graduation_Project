#include <FirebaseArduino.h>
#include <ESP8266WiFi.h>

#include<SoftwareSerial.h> //Included SoftwareSerial Library
//Started SoftwareSerial at RX and TX pin of ESP8266/NodeMCU
SoftwareSerial s(3,1);
int incomingBytes[6];

#define FIREBASE_HOST "smart-factory-control.firebaseio.com"
#define FIREBASE_AUTH "ZrPLEH8G1pQvyGm44y2SjYiKx5xMKjEkwccXwcdn"

const char* ssid     = "HUAWEI MediaPad T3 7";
const char* password = "25121966";
const char* host = "egofactory.000webhostapp.com";
 
int ledPower = D8;
int MotorPower = D1;

void setup() {
   Serial.begin(9600);
//  Serial.println();
//  Serial.println();
//  Serial.print("Connecting to ");
//  Serial.println(ssid);
//  
//  WiFi.begin(ssid, password); 
//  while (WiFi.status() != WL_CONNECTED) {
//    delay(100);
//    Serial.print(".");
//  }
// 
//  Serial.println("");
//  Serial.println("WiFi connected");  
//  Serial.println("IP address: ");
//  Serial.println(WiFi.localIP());
//  Serial.print("Netmask: ");
//  Serial.println(WiFi.subnetMask());
//  Serial.print("Gateway: ");
//  Serial.println(WiFi.gatewayIP());
//
// Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
//  pinMode(ledPower, OUTPUT);
//  pinMode(MotorPower,OUTPUT);
}

void loop() {
 if(Serial.available()>0)
    { 
     for (int i=0; i<5; i++) {
      incomingBytes[i] = Serial.read(); 
     } 
    }  
 
  
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password); 
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print(".");
  }
 
  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.print("Netmask: ");
  Serial.println(WiFi.subnetMask());
  Serial.print("Gateway: ");
  Serial.println(WiFi.gatewayIP());

 Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  pinMode(ledPower, OUTPUT);
  pinMode(MotorPower,OUTPUT);
int ledStatus = Firebase.getInt("ledStatus");
  int MotorStatus = Firebase.getInt("MotorStatus");
 if(ledStatus == 1){
    digitalWrite(ledPower, HIGH);
    s.write(9);
    }
     if(ledStatus == 0){
    digitalWrite(ledPower, LOW);
    s.write(8);
    }
     if(MotorStatus == 1){
    digitalWrite(MotorPower, HIGH);
    }
     if(MotorStatus == 0){
    digitalWrite(MotorPower, LOW);
    }
   Serial.print("connecting to ");
  Serial.println(host);

  WiFiClient client;
  const int httpPort = 80;
 if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }
   
  Serial.println(incomingBytes[0]); //Read the serial data and store it
  Serial.println(incomingBytes[1]); //Read the serial data and store it
  Serial.println(incomingBytes[2]); //Read the serial data and store it
  Serial.println(incomingBytes[3]); //Read the serial data and store it
  Serial.println(incomingBytes[4]); //Read the serial data and store it
 
 delay(1000);
  //data = Serial.read(); //Read the serial data and store it
  String url = "/api/factory/insert.php?alldetect=" + String(1) + "&waterdetect="+ String(incomingBytes[0]) + "&colordetect="+ String(incomingBytes[1]) + "&weightdetect="+ String(incomingBytes[2])  + "&shapedetect="+ String(incomingBytes[3]) +"&qualifieddetect="+ String(incomingBytes[4]) + "&waterrejected="+ String(1) +"&colorrejected="+ String(1) + "&weightrejected="+ String(1) +"&shaperejected="+ String(1)  +"&qualified="+ String(1) +"&intencontrol="+ String(1) +"&flamedetect="+ String(1) + "&tempdetect="+ String(0) ;
  Serial.print("Requesting URL: ");
  Serial.println(url);


  
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: close\r\n\r\n");
  delay(1000);
  while(client.available()){
    String line = client.readStringUntil('\r');
   Serial.print(line);
   if(ledStatus == 1){
    digitalWrite(ledPower, HIGH);
    }
     if(ledStatus == 0){
    digitalWrite(ledPower, LOW);
    }
     if(MotorStatus == 1){
    digitalWrite(MotorPower, HIGH);
    }
     if(MotorStatus == 0){
    digitalWrite(MotorPower, LOW);
    }
  }
  
  Serial.println();
  Serial.println("closing connection");
  delay(1000);
}
