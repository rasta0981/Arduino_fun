// Transmitter code for ESP32
#include <Wire.h> // Required for I2C communication
#include <Adafruit_AHTX0.h> // Library for AHT20 sensor

#define LORA_RX_PIN 16 // Connect to LoRa TX pin
#define LORA_TX_PIN 17 // Connect to LoRa RX pin
#define TX_ADDRESS "2" // The address of the receiver module

// Create a HardwareSerial instance for the LoRa module using Serial2
HardwareSerial loraSerial(2); 
Adafruit_AHTX0 aht; // Create AHT20 sensor object

String mymessage;

// Function to convert Celsius to Fahrenheit
float convertCtoF(float c) {
  return (c * 1.8) + 32;
}

void setup() {
  // Initialize USB Serial for debugging (connected via USB port to PC)
  Serial.begin(115200);      
  
  // Initialize hardware serial for LoRa module (Serial2)
  loraSerial.begin(115200, SERIAL_8N1, LORA_RX_PIN, LORA_TX_PIN);  
  
  // Initialize I2C communication for the AHT sensor
  // ESP32 uses GPIO 21 and 22 by default for SDA and SCL respectively
  if (! aht.begin()) {
    Serial.println("Could not find AHT sensor? Check wiring");
    while (1) delay(10); // Halt if sensor is not found
  }

  delay(1000);
  Serial.println("Transmitter Ready on ESP32 with AHT Sensor");
}

void loop() {
  sensors_event_t humidity, temp;
  aht.getEvent(&humidity, &temp); // Get new sensor readings

  // --- Fahrenheit Conversion Added Here ---
  // Convert the temperature from Celsius to Fahrenheit
  //  float tempFahrenheit = convertCtoF(temp.temperature);
   float tempFahrenheit = (temp.temperature * 1.8) + 32;   // Convert to Fahrenheit
  // Format the sensor data into a message string
  // Use the new tempFahrenheit variable instead of temp.temperature
  String temperatureStr = String(tempFahrenheit, 1); // 1 decimal place
  String humidityStr = String(humidity.relative_humidity, 1); // 1 decimal place
  // Message format: "T:77.7,H:55.2" (Temperature in Fahrenheit, Humidity)
  String sensorData = "T:" + temperatureStr + ",H:" + humidityStr; 
  
  
  // Construct the AT command for the LoRa module
  // Format: AT+SEND=[Address],[Length],[Data]
  String commandToSend = "AT+SEND=" + String(TX_ADDRESS) + "," + String(sensorData.length()) + "," + sensorData;

  // Append the required Carriage Return and Line Feed to the command for the LoRa module
  commandToSend += "\r\n";

  // Send the command to the LoRa module via the dedicated hardware serial port (Serial2)
  loraSerial.print(commandToSend); 
  
  // Print to the debug serial monitor (PC connection)
  Serial.print("Sent: ");
  Serial.println(commandToSend);

  // Read response from Lora module if available (optional)
  if (loraSerial.available()) {
    Serial.print("LoRa response: ");
    while(loraSerial.available()) {
      Serial.write(loraSerial.read());
    }
  }

  // A reasonable delay for LoRa transmission and to avoid self-heating of the sensor
  delay(10000); 
}
