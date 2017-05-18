#ifndef GRAPHICSDISPLAY_H
#define GRAPHICSDISPLAY_H

#include "observer.h"
#include "cell.h"
#include "subject.h"
#include "window.h"
#include "subscriptions.h"

class GraphicsDisplay : public Observer {
	// keeps a pointer to Xwindow
	Xwindow *display;
	// stores a gridSize of LightsOut
	int gridSize;
	public:
	// ctor for GraphicsDisplay that assigns display and gridSize
	GraphicsDisplay(Xwindow &display, int gridSize);
	// GraphicsDisplay will be notified when the state of any
	// cell changes. It will change the cell to color black
	// on the display if state is on, and white if it's off. 
 	void notify(Subject &whoNotified) override;
	// Returns SubscriptionType of GraphicsDisplay, which is
	// SubscriptionType::All
	SubscriptionType subType() const override;	

};

#endif
