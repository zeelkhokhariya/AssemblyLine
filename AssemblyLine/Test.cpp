// CLASS: Test.cpp
//
// Author: Zeelkumar Khokhariya, 7880619
//
// REMARKS: Test the all method of priorityQueue
//-----------------------------------------

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "PriorityQueue.h"
#include "PartArrival.h"
#include "Parts.h"
#include "Simulation.h"
#include "ListItem.h"
//Making the parts object for testing priority Queue
Parts* partOne = new Parts(5,0,0);
Parts* partTwo = new Parts(10,0,1);
Parts* partThree = new Parts(3,0,2);
Simulation* sim = new Simulation();
//TEST CASE 1
TEST_CASE("CHECK FOR THE LIST IS EMPTY")
{
    PriorityQueue *pqEmpty = new PriorityQueue();
    //checking for whether list is empty or not
    REQUIRE(pqEmpty->getSize() ==0);//if list is empty then size ==0
    REQUIRE(pqEmpty->isEmpty()== true);// if list is empty then isempty() method PriorityQueue returns true
    REQUIRE(pqEmpty->getFront()== nullptr); // if list is empty it should return nullptr
    REQUIRE(pqEmpty->dequeue()== nullptr);// if list is empty then it should return nullptr
}

// TEST CASE 2 will ensure proper working of getSize, isEmpty, enqueue methods
TEST_CASE("CHECK FOR SIZE WHEN INSERTING THE ITEM")
{
    PriorityQueue *pqSize = new PriorityQueue();
    REQUIRE(pqSize->getSize()==0);// checking for inital size
    REQUIRE(pqSize->isEmpty()==true);// checking for inital size=0 so isempty  return true
    pqSize->enqueue(new PartArrival(partOne,sim));
    REQUIRE(pqSize->getSize()==1);// checking for updated size after adding one
    REQUIRE(pqSize->isEmpty()== false);// checking for inital size=1 so isempty  return false

    pqSize->enqueue(new PartArrival(partTwo,sim));
    REQUIRE(pqSize->getSize()==2);// checking for updated size after adding one more
    REQUIRE(pqSize->isEmpty()== false);// checking for inital size=2 so isempty  return false

    pqSize->enqueue(new PartArrival(partThree,sim));
    REQUIRE(pqSize->getSize()==3);// checking for updated size after adding one afteradding one more
    REQUIRE(pqSize->isEmpty()== false);// checking for inital size=3 so isempty  return false
}
//Test case 3
TEST_CASE("checking for enqueue works properly and getfront  ")
{
    PriorityQueue *pqenqueue = new PriorityQueue();
    pqenqueue->enqueue(new PartArrival(partOne,sim)); // arriving time is 5
    pqenqueue->enqueue(new PartArrival(partTwo,sim));// arriving time is 10
    pqenqueue->enqueue(new PartArrival(partThree,sim));// arriving time is 3

     PartArrival *checker = dynamic_cast<PartArrival*>(pqenqueue->getFront());
     // And enqueue method perform the priority by time and swaping
     REQUIRE(checker->getTime()==3);// as per min priority so part 3 will top so it will come out
}

//Test case 4 checking for enqueue getfront and dequeue
TEST_CASE("checking for enqueue and dequeue does their job  ")
{
    PriorityQueue *pqenqueue = new PriorityQueue();
    pqenqueue->enqueue(new PartArrival(partOne,sim)); // arriving time is 5
    pqenqueue->enqueue(new PartArrival(partTwo,sim));// arriving time is 10
    pqenqueue->enqueue(new PartArrival(partThree,sim));// arriving time is 3

    PartArrival *checker = dynamic_cast<PartArrival*>(pqenqueue->dequeue());
    // And enqueue method perform the priority by time and swaping
    REQUIRE(checker->getTime()==3);// as per min priority so part 3 will top so it will come out

    PartArrival *checker1 = dynamic_cast<PartArrival*>(pqenqueue->dequeue());
    REQUIRE(checker1->getTime()==5);// part1

    PartArrival *checker2 = dynamic_cast<PartArrival*>(pqenqueue->dequeue());

    REQUIRE(checker2->getTime()==10);// part2
}

//TEST CASE 5 checking for enqueque getfront dequeue size isEmpty on on everyupdate;

TEST_CASE("checking for every method in priority Queue on every update  ")
{
    PriorityQueue *pqenqueue = new PriorityQueue();
    pqenqueue->enqueue(new PartArrival(partOne,sim)); // arriving time is 5
    REQUIRE(pqenqueue->isEmpty()== false);
    REQUIRE(pqenqueue->getSize()== 1);
    REQUIRE((dynamic_cast<PartArrival*>(pqenqueue->getFront())->getTime())== 5);

    pqenqueue->enqueue(new PartArrival(partTwo,sim));// arriving time is 10
    REQUIRE(pqenqueue->isEmpty()== false);
    REQUIRE(pqenqueue->getSize()== 2);
    REQUIRE((dynamic_cast<PartArrival*>(pqenqueue->getFront())->getTime())== 5);

    pqenqueue->enqueue(new PartArrival(partThree,sim));// arriving time is 3
    REQUIRE(pqenqueue->isEmpty()== false);
    REQUIRE(pqenqueue->getSize()== 3);
    REQUIRE((dynamic_cast<PartArrival*>(pqenqueue->getFront())->getTime())== 3); // updating the priority due to 3 is more prior than 5

    PartArrival *checker = dynamic_cast<PartArrival*>(pqenqueue->dequeue());
    REQUIRE((dynamic_cast<PartArrival*>(pqenqueue->getFront())->getTime())== 5);
    REQUIRE(checker->getTime()==3);// as per min priority so part 3 will top so it will come out
    REQUIRE(pqenqueue->isEmpty()== false);
    REQUIRE(pqenqueue->getSize()== 2); // because of one is dequeue

    PartArrival *checker1 = dynamic_cast<PartArrival*>(pqenqueue->dequeue());
    REQUIRE((dynamic_cast<PartArrival*>(pqenqueue->getFront())->getTime())== 10);
    REQUIRE(checker1->getTime()==5);// part1
    REQUIRE(pqenqueue->isEmpty()== false);
    REQUIRE(pqenqueue->getSize()== 1);// because of one more is dequeue

    PartArrival *checker2 = dynamic_cast<PartArrival*>(pqenqueue->dequeue());
    REQUIRE((pqenqueue->getFront()) == nullptr);
    REQUIRE(pqenqueue->isEmpty()== true);
    REQUIRE(pqenqueue->getSize()== 0);// because of one more is dequeue and list is empty
    REQUIRE(checker2->getTime()==10);// part2
}
