// Platform libraries.
#include <Arduino.h>  // To add IntelliSense for platform constants.

// Third-party libraries.

// My classes.
#include "bme280.h"
#include "status-led.h"

// Read configuration and secrets.
#include "config.h"

StatusLed led;
BME280 bme;

void setup() {
  initSerial();
  initLed();
  initSensor();

  Serial.println("Setup completed.");
}

void initSerial() {
  Serial.begin(115200);
  Serial.println();
  Serial.println("Initializing serial connection DONE.");
}

void initLed() {
  led.setPin(PIN_LED);
  led.turnOn();
  delay(1000);
  led.turnOff();
  delay(1000);
  led.turnOn();
  delay(1000);
  led.turnOff();
  delay(1000);
}

void initSensor() {
  bme.init();
}

void loop() {
  led.turnOn();

  BME280::Measurement measurement = bme.getMeasuredData();

  Serial.printf("Temperature: %.1f *C\n", measurement.temperature);
  Serial.printf("Pressure: %.1f hPa\n", measurement.pressure);
  Serial.printf("Altitude: %.1f m\n", measurement.altitude);
  Serial.printf("Humidity: %.1f %\n", measurement.humidity);
  Serial.println();

  led.turnOff();
  delay(2000);
}
