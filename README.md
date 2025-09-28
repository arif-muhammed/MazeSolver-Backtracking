🌀 Maze Solver – Backtracking with Stack

📌 Overview

This project is a C++ console application that solves an MxN maze by finding the shortest path from the start point to the exit point.
It uses backtracking and a stack data structure to explore possible paths, backtrack when needed, and record valid steps.

🚀 Features

Backtracking Algorithm

Explores all possible paths in the maze.

Backtracks when reaching a dead end.

Stack Data Structure

Stores current valid steps during exploration.

Supports efficient backtracking.

Flexible Design

Works for any MxN maze.

Modular code split into multiple files.

🗂️ File Structure

Konum.hpp / Konum.cpp → Defines Konum struct (position & direction) and Yon enum.

Labirent.hpp / Labirent.cpp → Defines the maze structure and solving logic.

Stack.hpp → Implements a custom stack class.

Test.cpp → Contains the main() function and runs the maze solver.

Makefile → Compilation and execution instructions.

🔮 Future Improvements

Support for multiple start & exit points.

Graphical visualization of maze solving.

Export solved path to a file (e.g., JSON or TXT).

📜 License

This project is licensed under the MIT License – free to use, modify, and distribute.
