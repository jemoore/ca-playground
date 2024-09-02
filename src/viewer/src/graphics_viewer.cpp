#include "viewer/graphics_viewer.h"
#include "raylib.h"

using namespace viewer;

GraphicsViewer::GraphicsViewer(uint8_t pixels_per_cell, RulesInterface &rules) : Viewer(rules), _pixels_per_cell(pixels_per_cell) {}

void GraphicsViewer::update() const
{
  ClearBackground(BLACK);

  for (uint16_t row = 0; row < _rules.number_of_rows(); ++row)
  {
    for (uint16_t col = 0; col < _rules.number_of_cols(); ++col)
    {
      if (_rules.is_alive(row, col))
      {
        DrawRectangle(col * _pixels_per_cell, row * _pixels_per_cell, _pixels_per_cell, _pixels_per_cell, LIME);
      }
    }
  }
}

void GraphicsViewer::display_menu()
{
  DrawText("Press E to Edit the starting board", 10, 10, 20, WHITE);
  DrawText("      Press S after editing to Start/Pause/Resume simulation", 10, 30, 20, WHITE);
  DrawText("Press S to start with random board", 10, 70, 20, WHITE);
  DrawText("      Press S while running to Pause/Resume simulation", 10, 90, 20, WHITE);
  DrawText("Press Q or ESC to quit", 10, 150, 30, WHITE);
}

void GraphicsViewer::edit()
{
  if( IsMouseButtonDown(MOUSE_LEFT_BUTTON) || IsMouseButtonDown(MOUSE_RIGHT_BUTTON) )
  {
    bool is_alive = IsMouseButtonDown(MOUSE_LEFT_BUTTON);
    uint16_t col = GetMouseX() / _pixels_per_cell;
    uint16_t row = GetMouseY() / _pixels_per_cell;
    if( col >= 0 && row >= 0 && col < _rules.number_of_cols() && row < _rules.number_of_rows())
    {
      _rules.set_alive(row, col, is_alive);
    }
  }
}

/*
 * Update state of the simulation based on keyboard events.
*/
void GraphicsViewer::update_state()
{
    // listen for keyboard events and change state if needed
    if (IsKeyReleased(KEY_E))
    {
      if (_state == ViewerState::STARTING)
      {
        _state = ViewerState::EDITING;
      }
    }
    else if (IsKeyReleased(KEY_S))
    {
      if (_state == ViewerState::STARTING || _state == ViewerState::PAUSED || _state == ViewerState::EDITING)
      {
        if(_state == ViewerState::STARTING)
        {
          _rules.randomize();
        }
        _state = ViewerState::RUNNING;
      }
      else if (_state == ViewerState::RUNNING)
      {
        _state = ViewerState::PAUSED;
      }
    }
    else if (IsKeyReleased(KEY_Q) || IsKeyReleased(KEY_ESCAPE))
    {
      _state = ViewerState::STOP;
    }
}

void GraphicsViewer::run()
{
  InitWindow(_pixels_per_cell * _rules.number_of_cols(), _pixels_per_cell * _rules.number_of_rows(), "Conway's Game of Life");

  while (!WindowShouldClose() && _state != ViewerState::STOP)
  {
    BeginDrawing();

    update_state();

    switch (_state)
    {
    case ViewerState::STARTING:
      display_menu();
      break;
    case ViewerState::EDITING:
      edit();
      update();
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