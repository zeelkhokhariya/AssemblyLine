// CLASS: Parts.h
//
// Author: Zeelkumar Khokhariya, 7880619
//

//-----------------------------------------
#pragma once

#include "ListItem.h"

class Parts : public ListItem {
private:
    int arriveTime;
    int waitingTIme;
    int partNo;

public:
    Parts(int arrTime, int waitTime, int no);
    int getarriveTime();
    int getWaitTime();
    int getPartNo();
    void setwaitTime(int time);
    ~Parts();



};



