// CLASS: product.h
//
// Author: Zeelkumar Khokhariya, 7880619
//

//-----------------------------------------
#pragma once

#include "ListItem.h"
#include "Parts.h"

class product: public ListItem
{
private:
    Parts* p0;
    Parts* p1;
public:
    product(Parts* one, Parts* two);
    Parts* getPartP0();
    Parts* getPartP1();
    ~product();
};