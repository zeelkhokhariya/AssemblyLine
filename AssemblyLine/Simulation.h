// CLASS: Simulation.h
//
// Author: Zeelkumar Khokhariya, 7880619
//
//-----------------------------------------
#pragma once
#include <fstream>
#include "PartArrival.h"
#include "product.h"

using namespace std;

class PriorityQueue; // Priority Queue
class Queue; // Queue class - provided to you
class Event; // Event - given to you. 

class Simulation {
private:
        ifstream ifile; // input file to read.
        int simulationTime; // what is the current time of the simulation?
        PriorityQueue *eventList; // priority queue of Events.
        Queue* productQueue; // queue of partially assembled products (for finishing station).
        Queue** partQueues; // *array* of queues of parts for the stations.
        int  mainAssemblyTime; //  how long does the main station take?
        int  finishingAssemblyTime; //  how long does the main station take?
        int noOfFinalProduct;
        int finishing;
	bool mainBusy; // is the main station busy?
	bool finishingBusy; // is the finishing station busy?

public:
        Simulation();

	// you need methods to manipulate product and part queues.
	// [add them here.]
	Parts* dequePart0();
    Parts* dequePart1();
    Parts* dequePart2();
    product* dequeproduct();

    int Part0Size();
    int Part1Size();
    int Part2Size();
    int productSize();

    Parts* getFrontPart0();
    Parts* getFrontPart1();
    Parts* getFrontPart2();
    product* getFrontProduct();


        void addPart(Parts*);
        void addProduct(product*);
        int getSimulationTime();
        void setSimulationTime(int time);

        // main method for driving the simulation
        void runSimulation(char *fileName);

	// add an event to event queue.
	void addEvent (Event*); 

	// read next arrival from file and add it to the event queue. 
        void getNextArrival();
	
	// getters and setters for station statuses.
	bool isMainBusy();
	bool isFinishingBusy();
	void setMainStatus(bool);
	void setFinishingStatus(bool);

int getmainAssemblyTime();
int getfinishingAssemblyTime();

void addtoFinalProduct();
int getnoofFinalProduct();

void TimeoffinalProduct(int timingofone);
int getTimeofFinal();
~Simulation();
};// class Simulation
