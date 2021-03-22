// CLASS: ProductArrival.h
//
// Author: Zeelkumar Khokhariya, 7880619

//-----------------------------------------
#pragma once


#include "Event.h"
#include "product.h"

class ProductArrival : public Event {
private:
    product* pp;
public:
    ProductArrival(product *p, int time, Simulation *sim1);
    void print() override ;
    void processEvent() override ;
    ~ProductArrival();
};



