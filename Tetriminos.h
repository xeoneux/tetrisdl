#ifndef TETRISDL_TETRIMINOS_H
#define TETRISDL_TETRIMINOS_H

class Tetriminos {
public:
  static int getBlockType(int tetrimino, int rotation, int x, int y);
  static int getXInitialPosition(int tetrimino, int rotation);
  static int getYInitialPosition(int tetrimino, int rotation);
};

#endif // TETRISDL_TETRIMINOS_H
