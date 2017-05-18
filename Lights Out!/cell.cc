#include <iostream>
#include <utility>
#include "subject.h"
#include "observer.h"
#include "cell.h"
#include "subscriptions.h"
#include "info.h"

// see Cell.h for detail
Cell::Cell() {
}

// see Cell.h for detail
Cell::~Cell() {}

// see Cell.h for detail
bool Cell::getState() const { return isOn; }

// see cell.h for detail
Info Cell::getInfo() const {
	Info toBeReturned{this->r,this->c,this->isOn};
	return toBeReturned;
}

// see cell.h for detail
void Cell::setOn() {
	this->isOn = true;	
}

// see cell.h for detail
void Cell::toggle() {
	this->isOn = !this->isOn;
}

// see cell.h for detail
void Cell::setCoords(int r, int c) { 
	this->r = r; 
	this->c = c; 
}

// see cell.h for detail
void Cell::notify(Subject &whoNotified) {
	this->toggle();
}

// see cell.h for detail
SubscriptionType Cell::subType() const {
  return SubscriptionType::SwitchOnly;
}
