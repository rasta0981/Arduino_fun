#include <Wire.h>
#include <Adafruit_AHTX0.h> // Include the AHT21 sensor library

Adafruit_AHTX0 aht; // Create a sensor object instance

void setup() {
  Serial.begin(9600); // Initialize serial communication
  Serial.println("AHT21 Fahrenheit Conversion Test");

  if (!aht.begin()) {
    Serial.println("Could not find AHT? Check wiring");
    while (1); // Halt the program if the sensor isn't found
  }
  Serial.println("AHT21 sensor found!");
}

void loop() {
  // Read temperature and humidity from AHT21
  sensors_event_t humidity, temp;
  aht.getEvent(&humidity, &temp); // Populate temp and humidity objects with fresh data

  // The library usually provides the temperature in Celsius in temp.temperature
  float tempC = temp.temperature; 
  
  // *** PLACE YOUR CONVERSION CODE HERE ***
  float tempF = (tempC * 1.8) + 32;   // Convert to Fahrenheit
  
  // Print the results to the Serial Monitor
  //Serial.print("Temperature (C): ");
  //Serial.print(tempC);
  //Serial.println(" ° C");
  
  Serial.print("Temperature (F): ");
  Serial.print(tempF);
  Serial.println(" ° F");

  Serial.println();
  Serial.print("Humidity: ");
  Serial.print(humidity.relative_humidity);
  Serial.println(" % rH");

  delay(10000); // Wait 2 seconds before the next reading
}
