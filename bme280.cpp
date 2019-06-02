#include "bme280.h"

void BME280::init() {
  Serial.print("BME280: Initializing... ");

	if (!_bme.begin(DEFAULT_ADDRESS)) {
		Serial.println("BME280: Could not find a valid BME280 sensor, check wiring!");
		while (1);
	}

  Serial.println("DONE.");
}

float BME280::getTemperature() {
  return _bme.readTemperature();
}

float BME280::getPressure() {
  return _bme.readPressure() / 100.0F;
}

float BME280::getAltitude() {
  return _bme.readAltitude(SEALEVELPRESSURE_HPA);
}

float BME280::getHumidity() {
  return _bme.readHumidity();
}

BME280::Measurement BME280::getMeasuredData() {
  Measurement measurement;

  measurement.temperature = getTemperature();
  measurement.pressure = getPressure();
  measurement.altitude = getAltitude();
  measurement.humidity = getHumidity();

  return measurement;
}
