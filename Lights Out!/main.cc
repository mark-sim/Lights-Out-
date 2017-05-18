#include <iostream>
#include <string>
#include "grid.h"
#include "window.h"
using namespace std;

int main() {
  cin.exceptions(ios::eofbit|ios::failbit);
  string cmd, aux;
  Grid g;
  int moves = 0;
  // You will need to make changes to this code.
  Xwindow display;

  try {
    while (true) {
      cin >> cmd;
      if (cmd == "new") {
        int n;
        cin >> n;
	//initialize the grid.
	g.init(n,display);
      }
      else if (cmd == "init") {
	int c;
	int r;
	while (true) {
		cin >> r;
		cin >> c;
		//stop if it inputs -1 -1 and r and c
		if(r == -1 && c == -1) {
			cout << g;
			break;
		} else {
		//turn on r and c given that r and c are valid
		g.turnOn(r,c);
		}
	}	
      }
      else if (cmd == "game") {
	// get number of moves a player can move
        cin >> moves;
	if (moves == 1) {
		cout << moves << " move left" << endl;
	} else {
		cout << moves << " moves left" << endl;
		
	}
      }
      else if (cmd == "switch") {
        int r = 0, c = 0;
        cin >> r >> c;
	// toggle the cell that's at r and c
	g.toggle(r,c);
	// print the updated grid
	cout << g;
	// subtract allowed move by 1
	moves--;
	if(moves == 1) {
		cout << moves << " move left" << endl;
	} else {
		cout << moves << " moves left" << endl;
	}
	if(moves >= 0) {
		// if a player won within specified moves, print out Won
		if(g.isWon()) {
			cout << "Won" << endl;
			display.fillRectangle(0,0,500,500,Xwindow::White);	
			display.drawBigString(200,250,"Won",Xwindow::Black);
			display.drawBigString(100,300,"Game Over (q to quit)",
							      Xwindow::Black);
			string c;
			cin >> c;
			// quit if a player inputs q
			if (c == "q") {
				break;
			}		
		} else if(!g.isWon() && moves ==0) {
		// if a player has no moves, and there's still a cell on, print
		// out lost
			cout << "Lost" << endl;
			display.fillRectangle(0,0,500,500,Xwindow::White);
			display.drawBigString(200,250,"Lost",Xwindow::Black);
			display.drawBigString(100,300,"Game Over (q to quit)",
							      Xwindow::Black);
			string c;
			cin >> c;
			// quit if a player inputs q
			if(c == "q"){
				break;
			}
		}
	}
      }
    }
  }
  catch (ios::failure &) {
  }
}
