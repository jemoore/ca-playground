#include "viewer/terminal_viewer.h"

#include <cstdint>
#include <iostream>
#include <thread>

using namespace viewer;
using namespace std;

TerminalViewer::TerminalViewer(RulesInterface &rules) : Viewer(rules) {}

void TerminalViewer::update() const
{
  // std::cout << "\033[2J";
  std::cout << "\033c";
  for (uint16_t row = 0; row < _rules.number_of_rows(); ++row)
  {
    for (uint16_t col = 0; col < _rules.number_of_cols(); ++col)
    {
      std::cout << (_rules.is_alive(row, col) ? "X" : " ");
    }
    std::cout << std::endl;
  }
}

void TerminalViewer::run()
{
  for (int i = 0; i < 100; ++i)
  {
    update();
    _rules.apply_rules();
    // Sleep for 50ms to reduce flickering (at least make it more bearable)
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
  }
}