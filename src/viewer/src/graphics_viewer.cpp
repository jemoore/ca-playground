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

void GraphicsViewer::display_menu() {
    DrawText("Press E to Edit the starting board", 10, 10, 20, WHITE);
    DrawText("      Press S after editing to Start/Pause/Resume simulation", 10, 30, 20, WHITE);
    DrawText("Press S to start with random board", 10, 70, 20, WHITE);
    DrawText("      Press S while running to Pause/Resume simulation", 10, 90, 20, WHITE);
    DrawText("Press Q or ESC to quit", 10, 150, 30, WHITE);
}

void GraphicsViewer::run() {
    InitWindow(_pixels_per_cell * _rules.number_of_cols(), _pixels_per_cell * _rules.number_of_rows(), "Conway's Game of Life");

    while (!WindowShouldClose())
    {
        BeginDrawing();
          // listen for keyboard events and change state if needed
          if(IsKeyReleased(KEY_E)) {
            if(_state == ViewerState::STARTING) {
             _state = ViewerState::EDITING;
            }
          } else if(IsKeyReleased(KEY_S)) {
            if(_state == ViewerState::STARTING || _state == ViewerState::PAUSED ||  _state == ViewerState::EDITING) {
              _state = ViewerState::RUNNING;
            } else if(_state == ViewerState::RUNNING) {
              _state = ViewerState::PAUSED;
            }
          } else if(IsKeyReleased(KEY_Q) || IsKeyReleased(KEY_ESCAPE)) {
            CloseWindow();
          }

          switch(_state) {
            case ViewerState::STARTING:
              display_menu();
              break;
            case ViewerState::EDITING:
              break;
            case ViewerState::RUNNING:
              update();
              _rules.apply_rules();
              break;
            case ViewerState::PAUSED:
              update();
              break;
          }
        EndDrawing();
    }

    CloseWindow();
}