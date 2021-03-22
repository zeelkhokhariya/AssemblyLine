// CLASS: finishedproduct.cpp
//
// Author: Zeelkumar Khokhariya, 7880619
//
// REMARKS: finishedproduct.h has method header for the finishedproduct.cpp
//-----------------------------------------
#pragma once
#include "ListItem.h"
#include "Parts.h"
#include "product.h"

class finishedproduct : public ListItem
        {

private:
            product* ppp;
            Parts* part2;

public:
            finishedproduct(product* p, Parts* p2);
            ~finishedproduct();
};



