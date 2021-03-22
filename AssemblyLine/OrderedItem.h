// CLASS: OrderedItem.h
//
// Author: Zeelkumar Khokhariya, 7880619
//
// REMARKS: Ordered Item has a compare method to compare the two item
//-----------------------------------------
#pragma once
#include "ListItem.h"

class OrderedItem : public ListItem {
public:
        virtual int compareTo(OrderedItem *other) = 0;
	virtual ~OrderedItem();
}; // class ListItem
