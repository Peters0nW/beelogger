/* 
    Arduino Beelogger from (beelogger.de)[http://beelogger.de]
*/

#include <Wire.h>
#include <HX711.h>
#include <DS3231.h>
//#include "DallasTemperature.h"
#include <DHT.h>
#include <SoftwareSerial.h>
#include </Users/peet/dev/arduino/beelogger/src/beelogger.h>
#include "src/beelogger.h"

#define DEBUG 0; // 1

HX711 scale;
DS3231(rtc);
TwoWire twi();
DHT dht1(DHT1_PIN, DHT1_TYPE, DHT1_NUM);
DHT dht2(DHT2_PIN, DHT2_TYPE, DHT2_NUM);

void setup()
{
    Serial.begin(115200);
    // *** Serial INFOS ***
    Serial.println("Opening Serial-Port /dev/tty.usbseria-***");
    scale.begin(HX711_DAT, HX711_SCK);

    rtc.getDate();
    dht1.begin();
    dht2.begin();
}

void loop()
{
    readScale();
}

void readScale()
{

    long ready = analogRead(scale.is_ready());
    if (ready)
    {
        Serial.println("Gerät bereit");
        Serial.println(scale.read());
    }
    else
    {
        Serial.println("kein gerät!");
    }

    //scale.power_down();
    delay(5000);
}