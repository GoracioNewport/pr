#include "DHT.h"

#define DHTPIN 7
#define BUTTON1PIN 4

const int MAXSIZE = 12;
char keys[MAXSIZE];
float values[MAXSIZE];
int curInd = 0;

#define DHTTYPE DHT11   
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);

  pinMode(BUTTON1PIN, INPUT);

  dht.begin();
}

void measureDHT11() {
  
  float h = dht.readHumidity();  
  keys[curInd] = 'h';
  values[curInd] = h;
  curInd++;
  
  float t = dht.readTemperature();
  keys[curInd] = 't';
  values[curInd] = t;
  curInd++;
}

void measurePressure() {
  
  float p = 120;
  keys[curInd] = 'p';
  values[curInd] = p;
  curInd++;

  float d = 80;
  keys[curInd] = 'd';
  values[curInd] = d;
  curInd++;
}

void measurePulse() {
  float l = 60;
  keys[curInd] = 'l';
  values[curInd] = l;
  curInd++;
}

void measureAcceleration() {
  
  float dX = 0;
  keys[curInd] = 'x';
  values[curInd] = dX;
  curInd++;

  float dY = 0;
  keys[curInd] = 'y';
  values[curInd] = dY;
  curInd++;

  float dZ = 0;
  keys[curInd] = 'z';
  values[curInd] = dZ;
  curInd++;
}

void measureSaturation() {

  float s = 100;
  keys[curInd] = 's';
  values[curInd] = s;
  curInd++;
}

void measureButtons() {
  
  int button1State = digitalRead(BUTTON1PIN);
//  int button1State = LOW;
  keys[curInd] = '1';
  if (button1State == HIGH) values[curInd] = 1;
  else values[curInd] = 0;
  curInd++;

//  int button2State = digitalRead(BUTTON2PIN);
  int button2State = LOW;
  keys[curInd] = '2';
  if (button2State == HIGH) values[curInd] = 1;
  else values[curInd] = 0;
  curInd++;

//  int button3State = digitalRead(BUTTON3PIN);
  int button3State = LOW;
  keys[curInd] = '33';
  if (button3State == HIGH) values[curInd] = 1;
  else values[curInd] = 0;
  curInd++;
}

void sendStats() {
  Serial.print(F("{"));
  for(int i = 0; i < MAXSIZE; i++) {
     Serial.print(F("'"));
     Serial.print(keys[i]);
     Serial.print(F("':'"));
     Serial.print(values[i]);
     Serial.print(F("'"));
     if (i != MAXSIZE - 1) Serial.print(F(","));
  } Serial.println("}");
}

void loop() {
  
  delay(2000);
  curInd = 0;

  measureDHT11();
  measurePressure();
  measurePulse();
  measureAcceleration();
  measureSaturation();
  measureButtons();
 
  sendStats();
}
