#include "graphicsdisplay.h"
#include "window.h"
#include "subscriptions.h"
#include "cell.h"
#include "info.h"
using namespace std;

// see GraphicsDisplay.h for detail
GraphicsDisplay::GraphicsDisplay(Xwindow &display, int gridSize):
					display{&display}, gridSize{gridSize} {
	int size = 500/this->gridSize;	// 500 is size of display.
	for(int i=0,width=0; i<this->gridSize; i++) {
		for(int j=0,height=0; j<this->gridSize; j++) {
			this->display->fillRectangle(width,height,size,size,
							      Xwindow::White);
			height += size;
		}
		width += size;
	}
}

// see GraphicsDisplay.h for detail
void GraphicsDisplay::notify(Subject &whoNotified) {
	Info info = whoNotified.getInfo();
	int r = info.row;
	int c = info.col;
	bool state = info.state;
	int size = 500 / this->gridSize;	// 500 is size of display
	if(state) {
		//fillRectangle(x,y,width,height,color)
		display->fillRectangle(c * size, r * size,size,size,
							Xwindow::Black);	
	} else {
		//fillRectangle(x,y,width,height,color)
		display->fillRectangle(c * size, r * size,size,size,
							Xwindow::White);
	}
}

// see Graphicsdisplay.h for detail
SubscriptionType GraphicsDisplay::subType() const{
	return SubscriptionType::All;
} 

