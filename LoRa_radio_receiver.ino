// Receiver code for ESP32 with OLED support

#include <SPI.h>
#include <Wire.h> // Required for I2C communication
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h> // Library for the OLED display

#define LORA_RX_PIN 16 // Connect to LoRa TX pin
#define LORA_TX_PIN 17 // Connect to LoRa RX pin
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels (adjust to 32 if you have a 128x32 display)

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
// The ESP32 default I2C pins are 21 (SDA) and 22 (SCL) - we don't need to specify them here.
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Create a HardwareSerial instance for the LoRa module using Serial2
HardwareSerial loraSerial(2); 

void setup() {
  // Initialize USB Serial for debugging
  Serial.begin(115200);      
  
  // Initialize hardware serial for LoRa module (Serial2)
  loraSerial.begin(115200, SERIAL_8N1, LORA_RX_PIN, LORA_TX_PIN);  

  // Initialize the OLED display (address 0x3C is common)
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  
  // Display boot message on OLED
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);
  display.println("LoRa Receiver");
  display.println("Ready. Waiting...");
  display.display(); // Show initial text
  
  Serial.println("Receiver Ready on ESP32. Waiting for data...");
}

void loop() {
  if (loraSerial.available()) {
    String incomingMessage = "";
    while(loraSerial.available()) {
      char incomingChar = loraSerial.read();
      incomingMessage += incomingChar;
    }
    
    Serial.print("Received raw message: ");
    Serial.println(incomingMessage);

    // Parse the data and update the OLED display
    updateOLED(incomingMessage);
  }
  
  delay(100); 
}

// Function to parse the message and display cleanly on the OLED
void updateOLED(String rawMessage) {
    // The raw message from the LoRa module looks like: +RCV=2,17,T:25.4,H:55.2,-30\r\n
    // We only want the data part: T:25.4,H:55.2
    
    // Find where the actual sensor data starts (after the third comma)
    int firstComma = rawMessage.indexOf(',');
    int secondComma = rawMessage.indexOf(',', firstComma + 1);
    int thirdComma = rawMessage.indexOf(',', secondComma + 1);

    String dataString = rawMessage.substring(secondComma + 1, rawMessage.lastIndexOf(','));

    // Extract T and H values for clean display
    int tIndex = dataString.indexOf("T:");
    int hIndex = dataString.indexOf("H:");
    
    String tempStr = dataString.substring(tIndex + 2, hIndex - 1);
    String humStr = dataString.substring(hIndex + 2);

    // Update the OLED display
    display.clearDisplay();
    display.setTextSize(1); // Large text for main values
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.println("SKY FIRE LABS inc.:");

    display.setTextSize(1);
    display.setCursor(0, 20);
    display.print(tempStr );
    display.setTextSize(1);
    display.cp437(true); // Enable special characters (degree symbol)
    display.write(248); // Print degree symbol
    display.setTextSize(1);
    display.print("F");

    display.setCursor(0, 45);
    display.setTextSize(1);
    display.print(humStr);
    display.setTextSize(1);
    display.print("% RH");
    
    display.display(); // Push the buffer to the screen
}
