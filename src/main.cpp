#include <cstdlib>
#include <iostream>
#include <chrono>
#include <thread>
#include "rules/conway.h"
#include "viewer/terminal_viewer.h"
#include "viewer/graphics_viewer.h"

int main(int /*argc*/, char** /*argv*/) {

  // conway::ConwaysGOLRules con(48, 64);
  conway::ConwaysGOLRules con(150, 200); //  4 pps
  // conway::ConwaysGOLRules con(382, 512); // 2 pps
  con.randomize();

  // viewer::TerminalViewer view(con);
  viewer::GraphicsViewer view(4, con);

  view.run();


  return EXIT_SUCCESS;
}
