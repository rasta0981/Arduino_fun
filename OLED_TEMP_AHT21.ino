#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_AHTX0.h>

// Define the OLED display dimensions and I2C address
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define OLED_I2C_ADDRESS 0x3C
// The I2C address of the OLED display

// Create the SSD1306 display object
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Create the AHT21 sensor object
Adafruit_AHTX0 aht;

//Bitmap data
static const unsigned char PROGMEM rastatest[] = {
  0x00, 0x0e, 0x00, 0x00, 0x00, 0x19, 0x80, 0x00, 0x00, 0x30, 0x80, 0x00, 0x00, 0x30, 0x80, 0x00, 
  0x00, 0x30, 0x8f, 0x80, 0x00, 0x30, 0x80, 0x00, 0x00, 0x36, 0x80, 0x00, 0x00, 0x36, 0x8e, 0x00, 
  0x00, 0x36, 0x80, 0x00, 0x00, 0x36, 0x80, 0x00, 0x00, 0x36, 0x8f, 0x80, 0x00, 0x36, 0x80, 0x00, 
  0x00, 0x36, 0x80, 0x00, 0x00, 0x36, 0x8e, 0x00, 0x00, 0x36, 0x80, 0x00, 0x00, 0x36, 0x80, 0x00, 
  0x00, 0x36, 0x8f, 0x80, 0x00, 0x36, 0x80, 0x00, 0x00, 0x36, 0x80, 0x00, 0x00, 0x36, 0xc0, 0x00, 
  0x00, 0x66, 0x60, 0x00, 0x00, 0xdf, 0x30, 0x00, 0x01, 0xa3, 0x90, 0x00, 0x01, 0x07, 0xd0, 0x00, 
  0x01, 0x0f, 0xd8, 0x00, 0x01, 0x0f, 0xd8, 0x00, 0x01, 0x3f, 0xd8, 0x00, 0x01, 0xbf, 0x90, 0x00, 
  0x00, 0x9f, 0xb0, 0x00, 0x00, 0xc0, 0x60, 0x00, 0x00, 0x31, 0xc0, 0x00, 0x00, 0x1f, 0x00, 0x00
};

void setup() {
  Serial.begin(115200);
  //Wire.begin(21, 22);

  // Initialize the AHT21 sensor
  if (!aht.begin()) {
    Serial.println("AHT21 sensor not found. Check wiring.");
    while (1);
  }

  // Initialize the OLED display
  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_I2C_ADDRESS)) {
    Serial.println("OLED display not found. Check wiring and address.");
    while (1);
  }
  
  // Clear the display and set text settings
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
}

void loop() {
  // Read temperature and humidity from AHT21
  sensors_event_t humidity_event, temp_event;
  aht.getEvent(&humidity_event, &temp_event);

  // Clear the display buffer
  display.clearDisplay();
  
  // Set cursor position for temperature
  display.setCursor(0, 0);
  display.print("Rasta Sensor");
  //display.print(temp_event.temperature);
  display.println();

  // Set cursor position for Fahrenheit
  float tempF = (temp_event.temperature * 1.8) + 32;
  display.setCursor(0, 16);
  display.print("Temp: ");
  display.print(tempF);
  display.println("F");

  // Set cursor position for humidity
  display.setCursor(0, 32);
  display.print("Hum: ");
  display.print(humidity_event.relative_humidity);
  display.println(" %" );

  // Display bitmap
  // Display an 8x8 pixel bitmap at coordinates (10, 10) with the color WHITE
  display.drawBitmap(83, 13, rastatest, 25, 32, WHITE);
  display.display();

  // Display the buffer on the OLED
  display.display();

  // Wait before the next reading
  delay(20000);
}
