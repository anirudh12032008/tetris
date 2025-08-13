#include <TinyWireM.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "TetrisGame.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &TinyWireM, -1);

#define BTN_LEFT   3 // PB3
#define BTN_RIGHT  4 // PB4
#define BUZZER_PIN 1 // PB1

TetrisGame game;

void setup() {
  TinyWireM.begin();
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.display();

  pinMode(BTN_LEFT, INPUT_PULLUP);
  pinMode(BTN_RIGHT, INPUT_PULLUP);
  pinMode(BUZZER_PIN, OUTPUT);

  game.begin(&display);
}

void loop() {
  game.update(
    !digitalRead(BTN_LEFT),
    !digitalRead(BTN_RIGHT),
    0, // rotate (can be added if another button available)
    0  // drop (optional)
  );
  delay(100);
}
