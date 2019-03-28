#ifndef TETRISDL_BOARD_H
#define TETRISDL_BOARD_H

#include "Tetriminos.h"

#define BLOCK_SIZE 16
#define BOARD_WIDTH 10
#define BOARD_HEIGHT 20
#define BOARD_POSITION 320
#define BOARD_LINE_WIDTH 6
#define TETRIMINO_BLOCKS 5
#define MIN_VERTICAL_MARGIN 20
#define MIN_HORIZONTAL_MARGIN 20

class Board {

public:
  Board(Tetriminos *tetriminos, int screenHeight);

  int getXPosInPixels(int pos);
  int getYPosInPixels(int pos);

  void deletePossibleLines();
  void storePiece(int x, int y, int tetrimino, int rotation);

  bool isGameOver();
  bool isFreeBlock(int x, int y);
  bool isPossibleMovement(int x, int y, int tetrimino, int rotation);

private:
  enum { POS_FREE, POS_FILLED };

  int screenHeight;
  Tetriminos *tetriminos;
  int board[BOARD_WIDTH][BOARD_HEIGHT]{};

  void initBoard();
  void deleteLine(int y);
};

#endif // TETRISDL_BOARD_H
