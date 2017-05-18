#include <iostream>
#include <utility>
#include "textdisplay.h"
#include "cell.h"
#include "info.h"
using namespace std;

// see textdisplay.h for detail
TextDisplay::TextDisplay(int n): gridSize{n}   {
	for(int i=0; i<this->gridSize; i++) {
		vector<char> print;
		for (int j=0; j<this->gridSize; j++) {
			print.emplace_back('_');
		}
		this->theDisplay.emplace_back(print);
	}
}

// see textdisplay.h for detail
void TextDisplay::notify(Subject &whoNotified) {
	Info info = whoNotified.getInfo();
	bool state = info.state;
	int r = info.row;
	int c = info.col;
	if(state) {
		//if state is on change it to 'X'
		this->theDisplay[r][c] = 'X';
	} else {
		//if state is off change it to '_'
		this->theDisplay[r][c] = '_';
	}
}

// see textdisplay.h for detail
TextDisplay::~TextDisplay() {}

// see textdisplay.h for detail
SubscriptionType TextDisplay::subType() const {
  return SubscriptionType::All;
}

// see textdisplay.h for detail
ostream &operator<<(ostream &out, const TextDisplay &td) {
	for (int i=0; i<td.gridSize; i++) {
		for (int j=0; j<td.gridSize; j++) {
			cout << td.theDisplay[i][j];
		}
		cout << endl;
	}
  	return out;
}
