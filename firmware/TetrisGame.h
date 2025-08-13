#ifndef TETRISGAME_H
#define TETRISGAME_H

#include <Adafruit_SSD1306.h>

class TetrisGame {
  public:
    void begin(Adafruit_SSD1306* disp);
    void update(bool left, bool right, bool rotate, bool drop);
  private:
    Adafruit_SSD1306* display;
    int x = 0;
    int y = 0;
    int tick = 0;
};

#endif
