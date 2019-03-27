#include <SDL.h>
#include <iostream>

auto randomColor() -> Uint8 { return random() % 255; };

auto main() -> int {

  if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    return EXIT_FAILURE;

  SDL_DisplayMode DM;
  SDL_GetCurrentDisplayMode(0, &DM);

  auto *window =
      SDL_CreateWindow("TetriSDL", 0, 0, DM.w, DM.h, SDL_WINDOW_OPENGL);

  if (window == nullptr)
    return EXIT_FAILURE;

  auto renderer = SDL_CreateRenderer(
      window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

  if (renderer == nullptr) {
    return EXIT_FAILURE;
  }

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
