## Documentation for OLED_TEMP_AHT21.ino

### Overview
The code initializes and operates an OLED display (`Adafruit_SSD1306`) and an AHT21 temperature and humidity sensor. It continuously reads temperature and humidity values from the sensor and displays these values on the OLED screen, along with a custom bitmap image.

### Dependencies
This code requires several libraries that you must install via the Arduino Library Manager:
- **Adafruit GFX Library**: Provides graphics primitives for the OLED.
- **Adafruit SSD1306 Library**: Handles communication with the OLED screen.
- **Adafruit AHTX0 Library**: Provides an interface to the AHT21 temperature and humidity sensor.
- **Wire.h**: Provides I2C communication interface (already available in Arduino IDE).

### Hardware Setup

#### Components:
- AHT21 Temperature and Humidity Sensor
- OLED Display (128x64 resolution, I2C communication)
- Arduino Microcontroller

#### Wiring:
1. **OLED Display**:
- Connect `GND` to Arduino `GND`
- Connect `VCC` to Arduino `5V` or `3.3V`
- Connect `SCL` to Arduino `A5` (or the relevant I2C clock pin for your board)
- Connect `SDA` to Arduino `A4` (or the relevant I2C data pin for your board)

2. **AHT21 Sensor**:
- Connect `GND` to Arduino `GND`
- Connect `VCC` to Arduino `5V` or `3.3V`
- Connect `SCL` (Clock) to Arduino `A5` (or the board’s I2C pin for SCL)
- Connect `SDA` (Data) to Arduino `A4` (or the board’s I2C pin for SDA)

### Code Walkthrough

#### Constants
- `SCREEN_WIDTH`, `SCREEN_HEIGHT`: Defines the width and height of the OLED display.
- `OLED_RESET`: Defines the reset pin for the OLED display. A value of `-1` indicates no dedicated reset pin, where Arduino's reset pin will be shared.
- `OLED_I2C_ADDRESS`: The I2C address of the OLED. The default is `0x3C`; modify this based on your hardware.
- `rastatest[]`: A 32x32-pixel black-and-white bitmap to be displayed on the OLED. The image data is in PROGMEM (program memory) for space optimization.

#### Objects
- `Adafruit_SSD1306 display`: OLED display object with I2C communication.
- `Adafruit_AHTX0 aht`: AHT21 temperature and humidity sensor object.

#### setup()
The `setup` function initializes the serial interface, the AHT21 sensor, and the OLED display:
1. Checks if the AHT21 sensor is connected. If not, the code halts after printing an error message.
2. Checks if the OLED display is connected. If not, the code halts after printing an error message.
3. Clears the OLED display buffer and sets text size and color.

#### loop()
1. **Read sensor data**:
- Reads temperature (in Celsius) and humidity data from the AHT21 sensor.
- Converts the temperature from Celsius to Fahrenheit using the formula `tempF = (temp_event.temperature * 1.8) + 32`.

2. **Display data on the OLED**:
- Clears the display buffer.
- Prints a label "Rasta Sensor" at coordinates (0, 0).
- Displays the temperature in Fahrenheit (using `tempF`) at coordinates (0, 16).
- Displays the humidity percentage at coordinates (0, 32).

3. **Render bitmap**:
- Displays a pre-defined bitmap (`rastatest`) at coordinates (83, 13).

4. Displays all updated content on the OLED screen.

5. **Delay**:
- Pauses the program for 20 seconds (`20000 ms`) before starting the next iteration of the loop.

### Functionality Explanation

#### Sensor Operation
The AHT21 sensor provides temperature and humidity readings to be displayed on the OLED. These operations are facilitated by the `getEvent()` function of the Adafruit AHTX0 library, which updates the `sensors_event_t` objects for temperature and humidity.

#### OLED Functionality
- The OLED screen uses the Adafruit GFX library for graphics rendering and the SSD1306 library for communication.
- `setCursor(x, y)` specifies the display location, while `print()` and `println()` output text content.
- `clearDisplay()` clears all previous content, preparing the screen for refreshed data.
- `drawBitmap(x, y, bitmap, width, height, color)` renders the custom bitmap image defined in `rastatest[]`.

### Key Points
1. **Custom Bitmap Rendering**:
- `rastatest[]` is a bitmap rendered as a monochrome image. Ensure the dimensions and encoding match with your OLED resolution and configuration.

2. **Error Handling**:
- The program halts when unable to detect the AHT21 sensor or the OLED display, to prevent runtime errors.

3. **Refresh Interval**:
- The temperature and humidity data update every 20 seconds. You can modify this interval by changing the value of `delay(20000)`.

### Possible Enhancements
1. **Dynamic Message**:
- Add additional messages or dynamic alerts based on specific temperature or humidity thresholds.

2. **Celsius Support**:
- Keep a toggle for temperature in Celsius or Fahrenheit.

3. **Power Optimization**:
- Consider disabling the OLED or sensors during idle periods to reduce power consumption.

### Example Output

#### On the OLED Display:
``` 
Rasta Sensor
Temp: 72.5°F
Hum: 55.0%
[Bitmap Image] 
``` 
This output updates every 20 seconds.