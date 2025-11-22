# LoRa Radio README

## Functionality
This project utilizes an ESP32 microcontroller to transmit sensor data from the AHT20 temperature and humidity sensor using the LoRa (Long Range) communication protocol. The system efficiently sends sensor readings over long distances, making it ideal for remote monitoring applications.

## Setup

### Hardware Connections
- **ESP32**: Connect the ESP32 to your computer via USB.
- **AHT20 Sensor**: 
  - Connect VCC to the 3.3V pin on the ESP32.
  - Connect GND to the ground pin.
  - Connect the SDA pin to GPIO 21 (or the designated I2C SDA pin).
  - Connect the SCL pin to GPIO 22 (or the designated I2C SCL pin).
- **LoRa Module**:
  - Connect the LoRa module's VCC and GND to the ESP32.
  - Connect the LoRa's MOSI, MISO, and SCK pins to the respective GPIO pins on the ESP32 (SPI interface).
  - Ensure that the LoRa module's NSS pin is connected to a designated GPIO pin on the ESP32.

### Software Setup
1. Install the Arduino IDE.
2. Install the necessary libraries for LoRa and AHT20.
3. Load the provided example code onto the ESP32 using the Arduino IDE.

## Usage
Upon uploading the code to the ESP32, it will begin to read environmental data from the AHT20 sensor and transmit this information using the LoRa module. 

To modify the example code:
- Change the pin assignments according to your hardware setup.
- Adjust the transmission interval and sensor data processing methods as needed.
