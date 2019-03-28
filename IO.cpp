#include "IO.h"

IO::IO(SDL_Renderer *renderer) { this->renderer = renderer; }

void IO::drawRectangle(int x1, int y1, int x2, int y2, Color c) {
  SDL_Rect rectangle;

  rectangle.x = x1;
  rectangle.y = y1;
  rectangle.w = x2 - x1;
  rectangle.h = y2 - y1;
  SDL_RenderFillRect(renderer, &rectangle);
}
