/*******************************************************************
    Print Rectangles for the ESP32 CYD. Red/Gold/Green :D
*******************************************************************/

#include <TFT_eSPI.h>

TFT_eSPI tft = TFT_eSPI();

void setup() {
  Serial.begin(115200);
  tft.begin();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK); // Clear the screen with black color
}

void loop() {
  int x = 10;               // x-coordinate of the top-left corner of the rectangle
  int y = 10;               // y-coordinate of the top-left corner of the rectangle
  int w = 50;               // width of the rectangle
  int h = 20;               // height of the rectangle
  uint16_t color = TFT_RED; // color of the rectangle

  int x1 = 40;                  // x-coordinate of the top-left corner of the rectangle
  int y1 = 40;                  // y-coordinate of the top-left corner of the rectangle
  int w1 = 50;                  // width of the rectangle
  int h1 = 20;                  // height of the rectangle
  uint16_t color1 = TFT_YELLOW; // color of the rectangle

  int x2 = 70;                 // x-coordinate of the top-left corner of the rectangle
  int y2 = 70;                 // y-coordinate of the top-left corner of the rectangle
  int w2 = 50;                 // width of the rectangle
  int h2 = 20;                 // height of the rectangle
  uint16_t color2 = TFT_GREEN; // color of the rectangle

  tft.fillRect(x, y, w, h, color);      // Draw a filled rectangle
  tft.fillRect(x1, y1, w1, h1, color1); // Draw a filled rectangle
  tft.fillRect(x2, y2, w2, h2, color2); // Draw a filled rectangle

  delay(1000); // wait for 1 second
}
