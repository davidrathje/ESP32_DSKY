#include <Arduino_GFX_Library.h>
#include "fonts/Zerlina36pt7b.h"
#include "fonts/Gorton11pt7b.h"

#define ESP32_4827A043_QSPI
#define GFX_DEV_DEVICE ESP32_4827A043_QSPI
#define GFX_BL 1
#define F(s) (s)

#define GRAY RGB565(100, 100, 100)

Arduino_DataBus *bus = new Arduino_ESP32QSPI(45, 47, 21, 48, 40, 39); /* CS, SCK, d0, d1, d2, d3 */
Arduino_GFX *g = new Arduino_NV3041A(bus, GFX_NOT_DEFINED, 3, true);  /* RST, ROATION, IPS */
Arduino_GFX *gfx = new Arduino_Canvas(272, 480, g);                   /* W, H */

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600, SERIAL_8N1, 18, 17);

  pinMode(GFX_BL, OUTPUT);
  digitalWrite(GFX_BL, HIGH);

  gfx->begin();
  delay(5);
}

void loop(void) {
  if (Serial1.available() > 0) {
    char key = Serial1.read();
    Serial.print(key);
    Serial1.print(key);
  }

  gfx->fillScreen(BLACK);
  gfx->setFont(&Gorton11pt7b);
  gfx->setTextColor(BLACK);

  gfx->fillRect(5, 10, 100, 95, GREEN);
  gfx->setCursor(23, 50);
  gfx->print("COMP");
  gfx->setCursor(23, 80);
  gfx->print("ACTY");

  gfx->fillRect(5, 119, 100, 32, GREEN);
  gfx->setCursor(23, 144);
  gfx->print("VERB");

  gfx->fillRect(162, 10, 99, 32, GREEN);
  gfx->setCursor(182, 35);
  gfx->print("PROG");

  gfx->fillRect(162, 119, 99, 32, GREEN);
  gfx->setCursor(182, 144);
  gfx->print("NOUN");

  gfx->setFont(&Zerlina36pt7b);
  gfx->setTextColor(GREEN);

  gfx->setCursor(5, 214);
  gfx->print("03");

  gfx->setCursor(161, 105);
  gfx->print("01");

  gfx->setCursor(161, 214);
  gfx->print("05");

  gfx->setCursor(3, 299);
  gfx->print("+46531");

  gfx->setCursor(3, 385);
  gfx->println("-79634");

  gfx->setCursor(3, 470);
  gfx->print("+85311");

  gfx->fillCircle(134, 11, 4, GRAY);
  gfx->fillCircle(134, 111, 4, GRAY);
  gfx->fillCircle(134, 198, 4, GRAY);

  gfx->fillRect(3, 220, 241, 7, GREEN);
  gfx->fillCircle(257, 223, 4, GRAY);

  gfx->fillRect(26, 305, 216, 7, GREEN);
  gfx->fillCircle(257, 308, 4, GRAY);
  gfx->fillCircle(9, 308, 4, GRAY);

  gfx->fillRect(26, 391, 216, 7, GREEN);
  gfx->fillCircle(9, 394, 4, GRAY);
  gfx->fillCircle(257, 394, 4, GRAY);

  gfx->flush();
}