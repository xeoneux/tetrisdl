#ifndef TETRISDL_TETRIMINOS_H
#define TETRISDL_TETRIMINOS_H

class Tetriminos {
public:
  int getTetriminoType(int tetrimino, int rotation, int x, int y);
  int getXInitialPosition(int tetrimino, int rotation);
  int getYInitialPosition(int tetrimino, int rotation);
};

#endif // TETRISDL_TETRIMINOS_H
