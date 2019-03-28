#include "Board.h"

Board::Board(Tetriminos *tetriminos, int screenHeight) {
  this->screenHeight = screenHeight;
  this->tetriminos = tetriminos;
  initBoard();
}

void Board::initBoard() {
  for (auto &i : board)
    for (int &j : i)
      j = POS_FREE;
}

void Board::storePiece(int x, int y, int tetrimino, int rotation) {
  for (int i1 = x, i2 = 0; i1 < x + TETRIMINO_BLOCKS; i1++, i2++)
    for (int j1 = y, j2 = 0; j1 < y + TETRIMINO_BLOCKS; j1++, j2++)
      if (Tetriminos::getBlockType(tetrimino, rotation, j2, i2) != 0)
        board[i1][j1] = POS_FILLED;
}

bool Board::isGameOver() {
  for (auto &i : board)
    if (i[0] == POS_FILLED)
      return true;

  return false;
}

void Board::deleteLine(int y) {
  for (int j = y; j > 0; j--)
    for (auto &i : board)
      i[j] = i[j - 1];
}

void Board::deletePossibleLines() {
  for (int j = 0; j < BOARD_HEIGHT; j++) {
    int i = 0;
    while (i < BOARD_WIDTH) {
      if (board[i][j] != POS_FILLED)
        break;
      i++;
    }

    if (i == BOARD_WIDTH)
      deleteLine(j);
  }
}

bool Board::isFreeBlock(int x, int y) { return board[x][y] == POS_FREE; }

int Board::getXPosInPixels(int pos) {
  return ((BOARD_POSITION - (BLOCK_SIZE * (BOARD_WIDTH / 2))) +
          (pos * BLOCK_SIZE));
}

int Board::getYPosInPixels(int pos) {
  return ((screenHeight - (BLOCK_SIZE * BOARD_HEIGHT)) + (pos * BLOCK_SIZE));
}

bool Board::isPossibleMovement(int x, int y, int tetrimino, int rotation) {
  for (int i1 = x, i2 = 0; i1 < x + TETRIMINO_BLOCKS; i1++, i2++) {
    for (int j1 = y, j2 = 0; j1 < y + TETRIMINO_BLOCKS; j1++, j2++) {
      if (i1 < 0 || i1 > BOARD_WIDTH - 1 || j1 > BOARD_HEIGHT - 1)
        if (Tetriminos::getBlockType(tetrimino, rotation, j2, i2) != 0)
          return false;

      if (j1 >= 0)
        if ((Tetriminos::getBlockType(tetrimino, rotation, j2, i2) != 0) &&
            (!isFreeBlock(i1, j1)))
          return false;
    }
  }

  return true;
}
