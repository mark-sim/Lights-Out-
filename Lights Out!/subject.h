#ifndef _SUBJECT_H_
#define _SUBJECT_H_
#include <vector>
#include "subscriptions.h"
class Info;
class Observer;

class Subject {
  // vector of Observer pointers
  std::vector<Observer*> observers;
 public:
  // attach Observer *o to observers
  void attach(Observer *o); 
  // notify all Observers that has SubscriptionType t 
  void notifyObservers(SubscriptionType t);
  // pure virtual method. returns Info of a cell.
  // see info.h for structure of Info
  virtual Info getInfo() const = 0;
  // pure virtual destructor
  virtual ~Subject() = 0;
};

#endif
