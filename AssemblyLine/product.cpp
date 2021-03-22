// CLASS: product.cpp
//
// Author: Zeelkumar Khokhariya, 7880619
//
// REMARKS: product stores both part0 and part1
//-----------------------------------------
#include "product.h"

product::product(Parts *one, Parts *two): p0(one),p1(two) {}

Parts *product::getPartP0() {
    return p0;
}
Parts *product::getPartP1() {
    return p1;
}

product::~product() {delete (p0);
delete (p1);}
