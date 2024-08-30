#include "rules/conway.h"
#include <cstdint>

using namespace conway;
using namespace std;

ConwaysGOLRules::ConwaysGOLRules(uint16_t rows, uint16_t cols): RulesInterface(rows, cols)
{
  for(size_t i =0; i < _rows*_cols; ++i) {
    _board[0].push_back(false);
    _board[1].push_back(false);
  }
}

void ConwaysGOLRules::apply_rules() {
  /*
    Any live cell with fewer than two live neighbours dies, as if by underpopulation.
    Any live cell with two or three live neighbours lives on to the next generation.
    Any live cell with more than three live neighbours dies, as if by overpopulation.
    Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
  */

  _initializing = false;

  // iterate over each bit in the board
  // check each neighbor to see how many are alive
  // apply the rules
  for(uint16_t row = 0; row < _rows; ++row) {
    for(uint16_t col = 0; col < _cols; ++col) {
      uint8_t count = 0;
      for(uint16_t r = row > 0 ? row - 1 : 0; r <= ((row + 1) < _rows ? row + 1 : row); ++r) {
        for(uint16_t c = col > 0 ? col - 1 : 0; c <= ((col + 1) < _cols ? col + 1 : col); ++c) {
          if(r == row && c == col) continue;
          if(is_alive(r, c)) count++;
        }
      }
      if(is_alive(row, col)) {
        if(count < 2 || count > 3) {
          set_alive(row, col, false);
        } else {
          set_alive(row, col, true);
        }
      } else if(count == 3) {
        set_alive(row, col, true);
      } else set_alive(row, col, false);
    }
  }
  _display = (_display > 0) ?  0 : 1;
}