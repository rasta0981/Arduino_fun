# Arduino_fun

Arduino_fun provides a concise learning and experimentation environment designed to help me deepen my understanding of microcontrollers and embedded development. All code in this repository is free and publicly available for educational and experimental use.

---

Included example sketches:

1. temp_sensor.ino — Demonstrates the DHT11 temperature and humidity sensor and reports measurements via the serial console.
2. blink-2.ino — ESP32 example controlling three LEDs to illustrate basic GPIO operations.
3. OLED_TEMP_AHT21.ino — ESP32 connected to a 1-inch OLED display that shows temperature and humidity readings from an AHT21 sensor. This sketch includes code to render a bitmap temperature gauge. See the associated documentation for wiring and usage details.
4. aht_Sensor.ino — ESP32 sketch for interfacing with an improved AHT21 sensor implementation. Refer to the documentation for configuration and usage.
5. LoRa_radio.ino — LoRa transmitter sketch that sends sensor data from an AHT20 sensor. See the documentation for hardware and configuration notes.
6. LoRa_radio_receiver.ino — LoRa receiver sketch that displays incoming data on a 1-inch OLED display. See the documentation for setup instructions.

Getting started:

- Required hardware: an ESP32 (or compatible board), the sensors and displays referenced in the examples, and a USB connection for programming.
- To run an example: open the desired .ino file in the Arduino IDE, install any required libraries, upload to your board, and follow the serial or display output as described in the documentation.

Contributing:

Contributions, improvements, and bug reports are welcome. Please open issues or submit pull requests with clear descriptions of changes and testing steps.

License:

All code is provided without warranty; please refer to the repository for any licensing details or contact the maintainer for clarification.
