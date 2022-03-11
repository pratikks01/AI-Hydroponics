#define BLYNK_TEMPLATE_ID "TMPLEkirbd5J"
#define BLYNK_DEVICE_NAME "Plant Monitor v1"
#define BLYNK_AUTH_TOKEN "co_yCEJQMxG6gQx4rxrxhlfWW3zyL15p"
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h> 
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "ASUS_X01BDA";  // type your wifi name
char pass[] = "Hello1234";  // type your wifi password

BlynkTimer timer;


#define DHTPIN 4 //Connect Out pin to D2 in NODE MCU
#define DHTTYPE DHT11  
DHT dht(DHTPIN, DHTTYPE);


void sendSensor()
{
  // Temperature and Humidity
  float h = dht.readHumidity();
  float t = dht.readTemperature(); // or dht.readTemperature(true) for Fahrenheit

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
    Blynk.virtualWrite(V0, t);
    Blynk.virtualWrite(V1, h);
    Serial.print("Temperature : ");
    Serial.print(t);
    Serial.print("    Humidity : ");
    Serial.println(h);
}
void setup()
{   
  
  Serial.begin(115200);

  Blynk.begin(auth, ssid, pass);
  dht.begin();
  timer.setInterval(1000L, sendSensor);
 
  }

void loop()
{
  Blynk.run();
  timer.run();
 }
