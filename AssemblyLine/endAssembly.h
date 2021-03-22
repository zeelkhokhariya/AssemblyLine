// CLASS: endAssembly.h
//
// Author: Zeelkumar Khokhariya, 7880619
//
// REMARKS: endAssembly.h provides the method name and field for implementing endAssembly.cpp
//-----------------------------------------
#ifndef ASSIGNMENTC2_ENDASSEMBLY_H
#define ASSIGNMENTC2_ENDASSEMBLY_H


#include "Event.h"
#include "product.h"
#include "finishedproduct.h"

class endAssembly : public Event {
private:
    product* pp= nullptr;
    finishedproduct* fp= nullptr;

public:
    endAssembly(product* p,int time, Simulation* sim1);
    endAssembly(finishedproduct* p,int time, Simulation* sim1);
    void print() override ;
    void processEvent() override;
    void calculateAssemblyTime(product* temp);

    ~endAssembly();
};


#endif //ASSIGNMENTC2_ENDASSEMBLY_H
