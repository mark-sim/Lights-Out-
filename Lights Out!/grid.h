#ifndef __GRID_H__
#define __GRID_H__
#include <iostream>
#include <vector>
#include "cell.h"
#include "textdisplay.h"
#include "window.h"
#include "graphicsdisplay.h"

class Grid {
  // the Actual Grid
  std::vector<std::vector<Cell>> theGrid;  
  int gridSize;    // Size of the grid.
  TextDisplay *td; // The text display.
  GraphicsDisplay *display; // pointer to GraphicsDisplay
  // Add private members, if necessary.

  void clearGrid();   // Frees the grid.
  // add neighbours to cells
  void addNeighbors();
 public:
  // ctor for Grid
  Grid();
  // dtor for Grid. Frees any allocated heap memory.
  ~Grid();
  
  bool isWon() const; // Call to determine if grid is in a winning state.
  void init(int n, Xwindow &display); // Sets up an n x n grid.  
				      // Clears old grid, if necessary.
  void turnOn(int r, int c);  // Sets cell at row r, col c to On.
  void toggle(int r, int c);  // Switches cell at (r, c) between On and Off.
  // printing a grid invokes operator<< for the text display, making the grid
  // 	appear on the screen
  friend std::ostream &operator<<(std::ostream &out, const Grid &g);
};

#endif
