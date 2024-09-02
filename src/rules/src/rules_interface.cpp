#include "rules/rules_interface.h"

#include <cassert>
#include <cstdlib>
#include <time.h>

RulesInterface::RulesInterface(uint16_t rows, uint16_t cols): _rows(rows), _cols(cols) {}


uint16_t RulesInterface::number_of_rows() const {
  return _rows;
}

uint16_t RulesInterface::number_of_cols() const {
  return _cols;
}

void RulesInterface::randomize() {
  srand(time(nullptr));
  for(uint16_t row = 0; row < _rows; ++row) {
    for(uint16_t col = 0; col < _cols; ++col) {
      set_alive(row, col, rand() % 2 == 0);
    }
  }
}

bool RulesInterface::is_alive(uint16_t row, uint16_t col) const {
  assert(row < _rows && col < _cols);
  return _board[_display][(row * _cols) + col];
}

void RulesInterface::set_alive(uint16_t row, uint16_t col, bool alive /*= true*/) {
  assert(row < _rows && col < _cols);

  size_t board = _initializing ? 0 : _display > 0 ? 0 : 1;
  _board[board][(row * _cols) + col] = alive;
}

