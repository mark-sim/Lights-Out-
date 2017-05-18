#ifndef _OBSERVER_H_
#define _OBSERVER_H_
#include "subscriptions.h"
class Subject;
class Cell;

class Observer {
 public:
  virtual void notify(Subject &whoNotified) = 0;  // pass the Cell that called
                                                  // the notify method
  // pure virtual method. Has to return either SubscriptionType::All or
  // SubscriptionType::SwitchOnly
  virtual SubscriptionType subType() const = 0;
  // virtual default destructor.
  virtual ~Observer() = default;
};
#endif
