// CLASS: finishedproduct.cpp
//
// Author: Zeelkumar Khokhariya, 7880619
//
// REMARKS: finishedproduct stores the Product and part2 for making finished product
//-----------------------------------------
#include "finishedproduct.h"

finishedproduct::finishedproduct(product *p, Parts *p2): ppp(p), part2(p2) {

}

//destructor
finishedproduct::~finishedproduct(){
    delete (ppp);
    delete (part2);
}
