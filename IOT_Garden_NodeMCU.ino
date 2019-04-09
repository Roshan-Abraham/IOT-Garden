// This program is intend for the Lincon NodeMCU in assossiation with services provided by Blynk app for wifi connection purposes.
// this program is authored by Roshan Abraham for the IOT Garden project in the month of march 2019

#include <Adafruit_NeoPixel.h>
#include <SPI.h>
#include <BlynkSimpleEsp8266.h>
#include <ESP8266WiFi.h>
#include <DHT.h>

#define DHTPIN 0          // D3
#define DHTTYPE DHT11     // DHT 11

DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;
 
void sendSensor()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature();
 
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  // You can send any value at any time.
  // Don't send more that 10 values per second.
  Blynk.virtualWrite(V5, t);
  Blynk.virtualWrite(V6, h);
}  
#define PIN D2
#define NUMPIXELS 30
#define BLYNK_PRINT Serial
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup()
{
Serial.begin(9600);
Blynk.begin("61bf438236c644ad8c540178bcad0f37", "Hello darkness my old friend", "whygodwhy");
pixels.begin();

  dht.begin();
 
  // Setup a function to be called every second
  timer.setInterval(100L, sendSensor);
}
BLYNK_WRITE(V2)
{

int R = param[0].asInt();
int G = param[1].asInt();
int B = param[2].asInt();
Serial.println(R);
Serial.println(G);
Serial.println(B);
for(int i=0;i<NUMPIXELS;i++){

pixels.setPixelColor(i, pixels.Color(R,G,B));

pixels.show();
}
}

void loop()
{
Blynk.run();
timer.run();
}
