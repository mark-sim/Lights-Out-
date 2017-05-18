#include <iostream>
#include "grid.h"
#include "info.h"
#include "graphicsdisplay.h"
using namespace std;

// see grid.h for detail
Grid::Grid(): gridSize{0},td{nullptr},display{nullptr} {}

// see grid.h for detail
Grid::~Grid() {
	this->clearGrid();
}

// see grid.h for detail
void Grid::clearGrid() {
	delete this->td;
	delete this->display;
	this->gridSize = 0;
	this->td = nullptr;
	this->display = nullptr;
	
}

// see grid.h for detail
bool Grid::isWon() const {
  for(int i=0; i<this->gridSize; i++) {
	for(int j=0; j<this->gridSize; j++) {
		if (this->theGrid[i][j].getState() == true) {
			return false;
		}
	}
  }
  return true;
}

// see grid.h for detail
void Grid::addNeighbors() {
	for(int i=0; i<this->gridSize; i++) {
		for(int j=0; j<this->gridSize; j++) {
			// attach the cell itself
			this->theGrid[i][j].attach(&this->theGrid[i][j]);
			// if column is greater than 0, add the left cell
			if(j > 0) {
				this->theGrid[i][j].attach(&this->theGrid[i][j-1]);
			}
			// if column is less or equal to gridSize, 
			// add the right cell
			if(j+1 < this->gridSize) {
				this->theGrid[i][j].attach(&this->theGrid[i][j+1]);
			}
			// if row is greater than 0, add the top cell
			if(i > 0) {
				this->theGrid[i][j].attach(&this->theGrid[i-1][j]);
			}
			// if row is less or equal to gridSize,
			// add the bottom cell
			if(i+1 < this->gridSize) {
				this->theGrid[i][j].attach(&this->theGrid[i+1][j]);
			}
			// attach textdisplay to cell 
			this->theGrid[i][j].attach(this->td);
			// attach graphicsdisplay to cell
			this->theGrid[i][j].attach(this->display);	
		}
	}
}		

// see grid.h for detail
void Grid::init(int n, Xwindow &display) {
	clearGrid();
	this->gridSize = n;
	this->td = new TextDisplay{n};
	this->display = new GraphicsDisplay{display,this->gridSize};
	for(int i=0; i<n; i++) {
		vector<Cell> row;
		for(int j=0; j<n; j++) {
			Cell add{};
			//set coords of each cell
			add.setCoords(i,j);
			row.emplace_back(add);
		}
		this->theGrid.emplace_back(row);
	}
	addNeighbors();
		
}

// see grid.h for detail
void Grid::turnOn(int r, int c) {
	theGrid[r][c].setOn();
	this->td->notify(theGrid[r][c]);
	this->display->notify(theGrid[r][c]);
}

// see grid.h for detail
void Grid::toggle(int r, int c) {
  //notify SubscriptionType::SwitchOnly
  theGrid[r][c].notifyObservers(theGrid[r][c].subType());
  //notify SubscriptionType::All
  theGrid[r][c].notifyObservers(this->td->subType());
}

// see grid.h for detail
ostream &operator<<(ostream &out, const Grid &g) {
	cout << *(g.td);
	return out;
}
