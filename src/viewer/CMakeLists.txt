add_library(viewer
    "include/viewer/viewer.h"
    "include/viewer/graphics_viewer.h"
    "include/viewer/terminal_viewer.h"
    "src/viewer.cpp"
    "src/graphics_viewer.cpp"
    "src/terminal_viewer.cpp")

target_include_directories(viewer
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../rules/include
)

include(FetchContent)
FetchContent_Declare(
  raylib
  GIT_REPOSITORY "https://github.com/raysan5/raylib"
  GIT_TAG "5.0"
  GIT_SHALLOW On
)
FetchContent_MakeAvailable(raylib)

target_link_libraries(viewer PRIVATE raylib)
