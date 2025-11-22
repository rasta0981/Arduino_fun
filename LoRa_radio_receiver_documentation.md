# LoRa Radio Receiver with OLED Display (ESP32)

## Overview

This document provides an overview and description of the LoRa radio receiver project for ESP32, featuring real-time data display on an OLED screen. The receiver reads sensor data (temperature and humidity) sent over LoRa and presents it visually for convenient monitoring.

The project's key capabilities:
- Receives data over LoRa using an ESP32 microcontroller.
- Parses messages with temperature and humidity readings.
- Displays these readings clearly on a 128x64 OLED (SSD1306) via I2C.
- Provides basic status and debugging output via serial.

---

## Hardware Requirements

- **ESP32** (any variety with at least 2 serial ports)
- **LoRa Module** wired to the ESP32 UART pins:
  - RX: GPIO 16 (receives TX from LoRa)
  - TX: GPIO 17 (transmits RX to LoRa)
- **OLED Display** (SSD1306, 128x64 pixels, I2C interface, commonly address `0x3C`)
  - Connected to ESP32's default I2C pins (SDA=21, SCL=22)
- Sufficient power supply for ESP32 and peripherals.

---

## Software Requirements

- **Arduino Core for ESP32**, set up via the Arduino IDE.
- Required libraries:
  - `SPI.h`
  - `Wire.h` (I2C communication)
  - `Adafruit_GFX.h`
  - `Adafruit_SSD1306.h` (OLED driver)

---

## Pin Configuration

```c++
#define LORA_RX_PIN 16 // LoRa TX connected to ESP32 RX
#define LORA_TX_PIN 17 // LoRa RX connected to ESP32 TX
#define SCREEN_WIDTH 128 // OLED width
#define SCREEN_HEIGHT 64 // OLED height
```

---

## Main Functional Blocks

### 1. **Setup**

- Initializes serial for debugging (`Serial`) and the LoRa communication port (`Serial2`).
- Sets up the OLED display. If the display initialization fails, the device halts.
- Displays a splash/boot message on the OLED.  
- Serial monitor outputs readiness status.

```c++
Serial.begin(115200);
loraSerial.begin(115200, SERIAL_8N1, LORA_RX_PIN, LORA_TX_PIN);
display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
```

### 2. **Receiving Data**

- The main loop listens for incoming data from the LoRa module via `loraSerial`.
- When data is available, it reads the message into a `String`.
- Prints out the raw message for debugging.
- Calls `updateOLED()` to process and display the data.

### 3. **Data Parsing and Display**

- Assumes LoRa module messages resemble:  
  `+RCV=2,17,T:25.4,H:55.2,-30\r\n`
- The function `updateOLED()` extracts the `T:xx.x` and `H:yy.y` portions representing temperature and humidity.
- Displays the following on the OLED:
  - **Lab title**: “SKY FIRE LABS inc.:”
  - **Temperature**: Value + degree symbol + 'F'
  - **Humidity**: Value + "% RH"

### 4. **Display Formatting**

- Uses text size `1` and sets cursor positions for clear presentation.
- Employs code page 437 characters for proper degree symbol rendering.
- After updating, calls `display.display()` to refresh the screen.

---

## Code Highlights

#### Reading and Parsing LoRa Messages

```c++
if (loraSerial.available()) {
  String incomingMessage = "";
  while (loraSerial.available()) {
    incomingMessage += (char) loraSerial.read();
  }
  updateOLED(incomingMessage);
}
```

#### OLED Display Formatting

```c++
display.clearDisplay();
display.setTextSize(1);
display.setTextColor(SSD1306_WHITE);

display.setCursor(0, 0);
display.println("SKY FIRE LABS inc.:);
display.setCursor(0, 20);
display.print(tempStr );
display.cp437(true);
display.write(248); // degree symbol
display.print("F");
display.setCursor(0, 45);
display.print(humStr);
display.print("% RH");
display.display();
```

---

## Message Format Assumptions

The LoRa receiver expects messages formatted as follows:  
`+RCV=<id>,<len>,T:<temperature>,H:<humidity>,<rssi>\r\n`  
- **Temperature** in Fahrenheit (e.g., T:25.4)
- **Humidity** as a percentage (e.g., H:55.2)
- The parser extracts the temperature/humidity values for display.

---

## Troubleshooting

- If the OLED fails to initialize, the system halts with a serial error.
- All received LoRa messages are printed to Serial for analysis.
- Confirm wiring of LoRa module and OLED display matches the pin definitions.

---

## Customization

- **OLED Size**: For 128x32 displays, adjust `SCREEN_HEIGHT`.
- **Pin Mapping**: Change `LORA_RX_PIN` and `LORA_TX_PIN` to match your hardware.
- **Message Format**: If your sensor data changes, modify the parser in `updateOLED()`.

---

## Example Output

**Serial Monitor**
```
Receiver Ready on ESP32. Waiting for data...
Received raw message: +RCV=2,17,T:25.4,H:55.2,-30
```
**OLED Display**
```
SKY FIRE LABS inc.:
25.4°F
55.2% RH
```

---

## License & Credits

- Utilizes Adafruit GFX and SSD1306 libraries.
- Designed for educational and prototyping purposes.
