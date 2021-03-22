// CLASS: Parts.cpp
//
// Author: Zeelkumar Khokhariya, 7880619
//
// REMARKS: Parts stores the arrive time, waittime amd part number
//-----------------------------------------

#include "Parts.h"

Parts::Parts(int arrTime, int waitTime, int no) :arriveTime(arrTime), waitingTIme(waitTime),partNo(no)
{
}

int Parts::getarriveTime() {
    return arriveTime;
}

int Parts::getWaitTime() {
    return waitingTIme;
}

int Parts::getPartNo() {
    return partNo;
}

void Parts::setwaitTime(int time)
{
    waitingTIme = time;
}

Parts::~Parts() {
    delete (this);
}
