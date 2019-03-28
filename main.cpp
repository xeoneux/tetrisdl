#include "Board.h"
#include "IO.h"
#include "Tetriminos.h"
#include <SDL.h>
#include <iostream>

auto randomColor() -> Uint8 { return random() % 255; }

auto main() -> int {

  if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    return EXIT_FAILURE;

  auto W = 640;
  auto H = 480;

  auto *window =
      SDL_CreateWindow("Welcome to TetriSDL", SDL_WINDOWPOS_CENTERED,
                       SDL_WINDOWPOS_CENTERED, W, H, SDL_WINDOW_OPENGL);

  if (window == nullptr)
    return EXIT_FAILURE;

  auto *renderer = SDL_CreateRenderer(
      window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

  if (renderer == nullptr) {
    return EXIT_FAILURE;
  }

  IO io(renderer);
  Tetriminos tetriminos;
  Board board(&tetriminos, H);

  SDL_Event event;
  auto running = true;

  while (running) {
    SDL_SetRenderDrawColor(renderer, randomColor(), randomColor(),
                           randomColor(), randomColor());
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    while (SDL_PollEvent(&event))
      if (event.type == SDL_QUIT)
        running = false;
  }

  SDL_DestroyWindow(window);

  SDL_Quit();

  return EXIT_SUCCESS;
}
