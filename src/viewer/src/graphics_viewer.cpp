#include "viewer/graphics_viewer.h"
#include "raylib.h"

using namespace viewer;

GraphicsViewer::GraphicsViewer(uint8_t pixels_per_cell, RulesInterface& rules) :
Viewer(rules), _pixels_per_cell(pixels_per_cell) {}


void GraphicsViewer::update() const {
    ClearBackground(BLACK);

    for(uint16_t row = 0; row < _rules.number_of_rows(); ++row) {
      for(uint16_t col = 0; col < _rules.number_of_cols(); ++col) {
        if(_rules.is_alive(row, col)) {
          DrawRectangle(col * _pixels_per_cell, row * _pixels_per_cell, _pixels_per_cell, _pixels_per_cell, LIME);
        }
      }
    }
}


void GraphicsViewer::run() {
    InitWindow(_pixels_per_cell * _rules.number_of_cols(), _pixels_per_cell * _rules.number_of_rows(), "Conway's Game of Life");

    while (!WindowShouldClose())
    {
        BeginDrawing();
            update();
            _rules.apply_rules();
        EndDrawing();
    }

    CloseWindow();
}