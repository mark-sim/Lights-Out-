#include "subject.h"
#include "observer.h"
#include "subscriptions.h"
#include "cell.h"
#include "info.h"
#include <iostream>
using namespace std;

// see subject.h for detail
Subject::~Subject() {}

// see subject.h for detail
void Subject::attach(Observer *o) { 
	observers.emplace_back(o);
}

// see subject.h for detail
void Subject::notifyObservers(SubscriptionType t) {
	int length = this->observers.size();
	if(t == SubscriptionType::All) {
		for(int i=0; i<length; i++) {
			if(this->observers[i]->subType() == 
						SubscriptionType::All) {
				for(int j=0; j<length; j++) {
					if(this->observers[j]->subType() ==
					   SubscriptionType::SwitchOnly) {
					 //cast dynamic_cast since Subscription
					 //Type::SwitchOnly is Cell only
						Cell *a = dynamic_cast<Cell *>
							  (this->observers[j]);
						this->observers[i]->notify(*a); 
					}
				}
			}
		}
	} else if (t == SubscriptionType::SwitchOnly) {
		for(int i=0; i<length; i++) {
			if(this->observers[i]->subType() == 
					SubscriptionType::SwitchOnly) {
				this->observers[i]->notify(*this);
			}
		}
	}
}
