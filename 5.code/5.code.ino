
#include <Arduino.h>
#include <Simple_HCSR04.h>
#include <FastLED.h>


#define NUM_LEDS 100
#define DATA_PIN 3
CRGB leds[NUM_LEDS];

int TrigPin = 8;
int EchoPin = 9;

#define PIN_GATE_IN 3
#define IRQ_GATE_IN  0
#define PIN_ANALOG_IN A0
int  sensorAnalogPin = A0;
int  sensorDigitalPin = 6;  
int  analogValue = 0;



void setup() {
  Serial.begin(9600);
  pinMode(TrigPin,OUTPUT);
  pinMode(EchoPin,INPUT);
  pinMode(sensorDigitalPin,INPUT);

  FastLED.addLeds<NEOPIXEL, DATA_PIN >(leds, NUM_LEDS);
  
}

void loop() {
  analogValue = analogRead(sensorAnalogPin);
  Serial.println(analogValue);
  Serial.println(analogValue);

  digitalWrite(TrigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(TrigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin,LOW);
  
  int dist=pulseIn(EchoPin,HIGH)/58.0;
  dist=(int(dist*100.0))/100.0;
  Serial.println(dist);
  Serial.println("cm");

  if(analogValue>520 && dist<=30 ){
     for(int i=0;i<100;i++){
       leds[i] = CHSV(75,255,255);
     }
  FastLED.show();
  delay(800);
  }else{
     for(int i=0;i<100;i++){
       leds[i] = CRGB::Black;
     }
  FastLED.show();
  //delay(800);
  }
}
