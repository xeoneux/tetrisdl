#include <SDL.h>
#include <iostream>

int main() {
  SDL_version version;
  SDL_GetVersion(&version);
  std::cout << "Running SDL version " << int(version.major) << "."
            << int(version.minor) << "." << int(version.patch) << std::endl;

  return 0;
}
