cmake_minimum_required(VERSION 3.28)

project(ca-playground
  VERSION 0.1.0
  DESCRIPTION "An application to explore cellular automata"
  # HOMEPAGE_URL ""
  LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTOR ${CMAKE_BINARY_DIR}/bin)

# Avoid warning about DOWNLOAD_EXTRACT_TIMESTAMP in CMake 3.24
if (CMAKE_VERSION VERSION_GREATER_EQUAL "3.24.0")
	cmake_policy(SET CMP0135 NEW)
endif()
if (CMAKE_VERSION VERSION_GREATER_EQUAL "3.13.0")
	cmake_policy(SET CMP0077 NEW)
endif()

add_subdirectory(src)
