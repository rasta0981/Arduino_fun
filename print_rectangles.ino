/*******************************************************************
    Print Rectangles for the ESP32 CYD. Red/Gold/Green :D
 *******************************************************************/

#include <TFT_eSPI.h>

TFT_eSPI tft = TFT_eSPI();

void setup()
{
  Serial.begin(115200);
  tft.begin();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK); // Clear the screen with black color
}

void loop()
{
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

  int x3 = 100;              // x-coordinate of the top-left corner of the rectangle
  int y3 = 100;              // y-coordinate of the top-left corner of the rectangle
  int w3 = 50;               // width of the rectangle
  int h3 = 20;               // height of the rectangle
  uint16_t color3 = TFT_RED; // color of the rectangle

  int x4 = 130;                 // x-coordinate of the top-left corner of the rectangle
  int y4 = 130;                 // y-coordinate of the top-left corner of the rectangle
  int w4 = 50;                  // width of the rectangle
  int h4 = 20;                  // height of the rectangle
  uint16_t color4 = TFT_YELLOW; // color of the rectangle

  int x5 = 160;                // x-coordinate of the top-left corner of the rectangle
  int y5 = 160;                // y-coordinate of the top-left corner of the rectangle
  int w5 = 50;                 // width of the rectangle
  int h5 = 20;                 // height of the rectangle
  uint16_t color5 = TFT_GREEN; // color of the rectangle

  int x6 = 190;              // x-coordinate of the top-left corner of the rectangle
  int y6 = 190;              // y-coordinate of the top-left corner of the rectangle
  int w6 = 50;               // width of the rectangle
  int h6 = 20;               // height of the rectangle
  uint16_t color6 = TFT_RED; // color of the rectangle

  int x7 = 220;                 // x-coordinate of the top-left corner of the rectangle
  int y7 = 220;                 // y-coordinate of the top-left corner of the rectangle
  int w7 = 50;                  // width of the rectangle
  int h7 = 20;                  // height of the rectangle
  uint16_t color7 = TFT_YELLOW; // color of the rectangle

  tft.fillRect(x, y, w, h, color);      // Draw a filled rectangle
  tft.fillRect(x1, y1, w1, h1, color1); // Draw a filled rectangle
  tft.fillRect(x2, y2, w2, h2, color2); // Draw a filled rectangle
  tft.fillRect(x3, y3, w3, h3, color3); // Draw a filled rectangle
  tft.fillRect(x4, y4, w4, h4, color4); // Draw a filled rectangle
  tft.fillRect(x5, y5, w5, h5, color5); // Draw a filled rectangle
  tft.fillRect(x6, y6, w6, h6, color6); // Draw a filled rectangle
  tft.fillRect(x7, y7, w7, h7, color7); // Draw a filled rectangle

  delay(1000); // wait for 1 second
}
