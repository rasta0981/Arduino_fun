## Documentation for aht_Sensor.ino

### Overview
This code interfaces with the AHT21 temperature and humidity sensor using the Adafruit AHTX0 library. It reads the current temperature and humidity, converts the temperature data from Celsius to Fahrenheit, and outputs the results to the serial monitor.

---

### Dependencies
This code requires the following library:
- **Adafruit AHTX0 Library**: Provides an interface to the AHT21 sensor.

Additionally, the Arduino IDE must be installed, along with the `Wire.h` library, which is already included in the IDE.

---

### Hardware Setup
#### Components:
- AHT21 Temperature and Humidity Sensor
- Arduino Microcontroller

#### Wiring:
1. **AHT21 Sensor**:
   - Connect `GND` to Arduino `GND`
   - Connect `VCC` to Arduino `3.3V` or `5V` (depending on the sensor version).
   - Connect `SCL` (Clock) to Arduino I2C clock pin (e.g., `A5` for UNO or an alternative on other boards).
   - Connect `SDA` (Data) to Arduino I2C data pin (e.g., `A4` for UNO).

---

### Code Walkthrough

#### Objects
- `Adafruit_AHTX0 aht`: Creates an object instance to communicate with the AHT21 temperature and humidity sensor.

#### Functions

1. **`setup()`**:
   - Initializes the serial monitor and sets the baud rate to 9600.
   - Prints an initial message to confirm setup progress.
   - Attempts to detect and initialize the AHT21 sensor (`aht.begin()`) and halts execution if the sensor is not found.
   - Upon success, prints a confirmation message.

2. **`loop()`**:
   - Reads temperature and humidity data from the AHT21 sensor using `aht.getEvent()`.  
   - Converts the temperature from Celsius to Fahrenheit using the formula:
     ```
     float tempF = (tempC * 1.8) + 32;
     ``` 
   - Outputs the temperature (in Fahrenheit) and humidity percentage to the serial monitor.
   - Delays for 10,000 milliseconds (10 seconds) between readings.

---

### Example Output
When connected correctly, the serial monitor will display output similar to:
```plaintext
AHT21 Fahrenheit Conversion Test
AHT21 sensor found!

Temperature (F): 77.00 °F

Humidity: 50.00 % rH
```
This updates every 10 seconds.

---

### Key Points
- **Temperature Conversion**: The temperature in Celsius (`tempC`) is converted to Fahrenheit using the formula:
  ```
  float tempF = (tempC * 1.8) + 32;
  ```
- **Humidity Reporting**: The code directly reports the relative humidity percentage from the sensor.
- **Error Handling**: If the sensor is not detected during the setup, the program halts and prints an error message.
- **Delay**: The program waits 10 seconds between sensor readings; this can be adjusted by modifying the value in `delay(10000)`.

---

### Enhancements
1. **Celsius & Fahrenheit Toggle**:
   - Add a mechanism to toggle between Celsius and Fahrenheit outputs for temperature.

2. **Display or Logging Integration**:
   - Extend the code to display the readings on an external screen (like an OLED) or save data to an SD card.

3. **Adjustable Sampling Rate**:
   - Allow the user to configure the delay between readings instead of using a fixed delay.

---