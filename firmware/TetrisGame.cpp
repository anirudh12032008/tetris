#include "TetrisGame.h"

void TetrisGame::begin(Adafruit_SSD1306* disp) {
  display = disp;
  display->clearDisplay();
  display->setTextSize(1);
  display->setTextColor(WHITE);
  display->setCursor(10, 20);
  display->println("Tiny Tetris!");
  display->display();
  delay(1000);
  display->clearDisplay();
  display->display();
}

void TetrisGame::update(bool left, bool right, bool rotate, bool drop) {
  if (left) x--;
  if (right) x++;
  y++;

  display->clearDisplay();
  display->fillRect(10 + x * 6, y * 4, 6, 4, WHITE);
  display->display();

  tick++;
  if (tick > 20) tick = 0;
}
