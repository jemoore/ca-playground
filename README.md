# Cellular Automata Playground

Simple implementation of Conway's Game of Life.
Can be ran from the terminal with:
```
ca-playground t
```
or with a graphical window:
```
ca-playground
```

The graphical version offers a few more features, such as:
- edit starting board
- pausing
- quiting at any time

## Compiling
### Requirements
A C++ compiler.  This has been tested with g++ on Linux and Windows VS2022.

On Linux:
```
cmake -B build -S . --preset linux-debug
cmake --build build
```
