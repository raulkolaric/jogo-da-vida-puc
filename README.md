# Game of Life

A C++ implementation of Conway's Game of Life built with an MVC architecture, developed as an academic project at PUC.

The program simulates an interactive cellular automaton on a configurable grid, allowing the user to place cells, step through generations manually or automatically, and persist game states to disk.

---

## Background

Conway's Game of Life is a cellular automaton devised in 1970 by the British mathematician John Horton Conway. It is a zero-player game: the entire evolution of the system is determined by its initial state, requiring no further input once set. Despite consisting of only four rules applied to a two-dimensional grid, the automaton is Turing complete and capable of producing a wide range of complex, self-organizing behavior.

The four rules are:

1. A dead cell with exactly three live neighbors becomes alive (reproduction).
2. A live cell with two or three live neighbors survives (survival).
3. A live cell with more than three live neighbors dies (overpopulation).
4. A live cell with fewer than two live neighbors dies (underpopulation).

---

## Features

- Configurable grid size from 10x10 up to 60x60
- Manual cell placement and removal before or during simulation
- Step-by-step generation control or continuous automatic simulation
- Save and load game states via `geracoes.dat`
- In-program display of the game rules

---

## Architecture

The project follows the Model-View-Controller (MVC) pattern:

**Model** (`JVIDA-KLRR-MODEL.h` / `.cpp`) — Defines the data structures for cells and the three tracked cell lists: living, dead, and next generation.

**View** (`JVIDA-KLRR-VIEW.h` / `.cpp`) — Handles all terminal output, including grid rendering, menus, and rule display.

**Controller** (`JVIDA-KLRR-CONTROLLER.h` / `.cpp`) — Contains the core simulation logic: neighbor counting, grid state transitions, save/load operations, and overall game flow.

**Entry Point** (`JVIDA-KLRR-MAIN.cpp`) — Instantiates the components and starts the program.

**Persistence** (`geracoes.dat`) — Binary file written and read by the program to store generation snapshots.

---

## Platform Note

The code uses `<windows.h>` for `Sleep()` and `system("cls")`, making it Windows-native out of the box. To build on Linux or macOS, replace:

- `Sleep(ms)` with `usleep(ms * 1000)` from `<unistd.h>`
- `system("cls")` with `system("clear")`

---

## Building

```bash
g++ JVIDA-KLRR-MAIN.cpp JVIDA-KLRR-MODEL.cpp JVIDA-KLRR-VIEW.cpp JVIDA-KLRR-CONTROLLER.cpp -o jogo_da_vida
```

---

## Authors

Developed by the KLRR group as part of the curriculum at PUC:

- Kaua Bezerra Brito
- Liam Vedovato Lopes
- Raul Kolaric
- Rodrigo Ward Leite

---

## References

- Gardner, M. (1970). *Mathematical Games: The fantastic combinations of John Conway's new solitaire game "life"*. Scientific American, 223(4), 120–123.
