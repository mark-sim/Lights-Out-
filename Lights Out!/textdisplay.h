#ifndef __TEXTDISPLAY_H__
#define __TEXTDISPLAY_H__
#include <iostream>
#include <vector>
#include "observer.h"
class Cell;

class TextDisplay: public Observer {
  // vector of vector of char that stores display of Lightsout.
  // X represents cell on, _ represents cell off
  std::vector<std::vector<char>> theDisplay;
  // gridSize of the game Lightsout
  const int gridSize;
 public:
  // ctor for TextDisplay that gets n, the gridSize of Lightouts
  TextDisplay(int n);
  // if TextDisplay is notified, this method will be called.
  // checks state of whoNotified and changes the display accordingly
  void notify(Subject &whoNotified) override;
  // return SubscriptionType::All
  SubscriptionType subType() const override;
  // dtor of TextDisplay
  ~TextDisplay(); 
  // operator<< overload for TextDisplay that prints out the entire grid.
  friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};

#endif
