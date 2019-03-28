#ifndef TETRISDL_IO_H
#define TETRISDL_IO_H

#include <SDL.h>

enum Color { RED, GREEN, BLUE, CYAN, MAGENTA, YELLOW, BLACK, WHITE, COLOR_MAX };

class IO {
public:
  IO(SDL_Renderer *renderer);

  void drawRectangle(int x1, int y1, int x2, int y2, Color c);

private:
  SDL_Renderer *renderer;
};

#endif // TETRISDL_IO_H
