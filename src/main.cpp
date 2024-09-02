#include <cstdlib>
#include <iostream>
#include <cstring>
#include "rules/conway.h"
#include "viewer/terminal_viewer.h"
#include "viewer/graphics_viewer.h"


int main(int argc, char *argv[])
{
  // check if first argument is "t" or "T"
  // if so, run the terminal viewer
  // otherwise, run the graphics viewer
  if( argc > 1 && (strcmp(argv[1], "t") == 0 || strcmp(argv[1], "T") == 0) ) {
    conway::ConwaysGOLRules con(48, 64);
    viewer::TerminalViewer view(con);
    view.run();
  } else {
    // conway::ConwaysGOLRules con(382, 512); // 2 pps
    conway::ConwaysGOLRules con(150, 200); //  4 pps
    viewer::GraphicsViewer view(4, con);
    view.run();
  }

  return EXIT_SUCCESS;
}
