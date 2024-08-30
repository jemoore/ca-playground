add_library(rules
  "include/rules/conway.h"
  "src/rules_interface.cpp"
  "src/conway.cpp"
)

target_include_directories(rules
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)
