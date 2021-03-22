// CLASS: Simulation.cpp
//
// Author: Zeelkumar Khokhariya, 7880619
//
// REMARKS: Simulation runs the assembly and process the event as per its priority
//-----------------------------------------
#include "Simulation.h"
#include "PriorityQueue.h"
#include "PartArrival.h"
#include "Queue.h"
#include <iostream>
Simulation :: Simulation(): simulationTime(0), eventList(new PriorityQueue()), productQueue(new Queue()),
            partQueues(new Queue*[3])
                            ,mainAssemblyTime(0), finishingAssemblyTime(0), mainBusy(false), finishingBusy(false),noOfFinalProduct(0),
                            finishing(0)
{

    partQueues[1] = new Queue();
    partQueues[0] = new Queue();
    partQueues[2] = new Queue();

}

int Simulation ::  getSimulationTime()
{
    return simulationTime;
}

void Simulation :: setSimulationTime(int time)
{
    simulationTime = time;
}




void Simulation :: runSimulation(char *fileName)
{
    ifile.open(fileName);

    if(! ifile.fail())
    {


            ifile >> mainAssemblyTime;
            ifile >> finishingAssemblyTime;



            getNextArrival();
            while (!eventList->isEmpty())
            {
                ListItem *li = eventList->dequeue();
                Event *ee;
                ee = dynamic_cast<Event *> (li);
                ee->processEvent();
                ee->print();
            }
    }
}


void Simulation ::  addEvent (Event* ee)
{
    if(dynamic_cast<Event*>(ee)!=nullptr )
    {
        eventList->enqueue(ee);
    }
}

void Simulation :: addPart(Parts* ee)
{
    if(dynamic_cast<Parts*>(ee)!=nullptr )
    {
        if(ee->getPartNo()==0)
        {
            partQueues[0]->enqueue(ee);
        }

        if(ee->getPartNo()==1)
        {
            partQueues[1]->enqueue(ee);
        }

        if(ee->getPartNo()==2)
        {
            partQueues[2]->enqueue(ee);
        }
    }
}

void Simulation::getNextArrival()
{
    if(!ifile.eof()){
        int aTime=-5;
        int pNum=-5;

        ifile>>aTime;
        ifile>>pNum;
        if(aTime!=-5 && pNum!=-5)
        {
            Parts *p;
            p = new Parts(aTime, 0, pNum);

            Event *e = new PartArrival(p, this);
            simulationTime=aTime;
            addEvent(e);
        }
    }
    else
    {
        ifile.close();
    }
}

bool Simulation::isMainBusy()
{
    return mainBusy;
}

bool Simulation::isFinishingBusy()
{
    return finishingBusy;
}

void Simulation::setMainStatus(bool flag)
{
    mainBusy = flag;
}

void Simulation::setFinishingStatus(bool flag)
{
    finishingBusy = flag;
}

Parts *Simulation::dequePart0() {
    return dynamic_cast<Parts*>(partQueues[0]->dequeue());
}

Parts *Simulation::dequePart1() {
    return dynamic_cast<Parts*>(partQueues[1]->dequeue());
}

Parts *Simulation::dequePart2() {
    return dynamic_cast<Parts*>(partQueues[2]->dequeue());
}

product *Simulation::dequeproduct() {
    return  dynamic_cast<product*>(productQueue->dequeue());
}

int Simulation::Part0Size() {
    return partQueues[0]->getSize();
}

int Simulation::Part1Size() {
    return partQueues[1]->getSize();
}

int Simulation::Part2Size() {
    return partQueues[2]->getSize();
}

int Simulation::productSize() {
    return productQueue->getSize();
}

Parts *Simulation::getFrontPart0() {
    return dynamic_cast<Parts*>(partQueues[0]->getFront());
}

Parts *Simulation::getFrontPart1() {
    return dynamic_cast<Parts*>(partQueues[1]->getFront());
}

Parts *Simulation::getFrontPart2() {
    return dynamic_cast<Parts*>(partQueues[2]->getFront());
}

product *Simulation::getFrontProduct() {
    return dynamic_cast<product*>(productQueue->getFront());
}

int Simulation::getmainAssemblyTime() {
    return mainAssemblyTime;
}

int Simulation::getfinishingAssemblyTime() {
    return finishingAssemblyTime;
}

void Simulation::addProduct(product *p)
{
    productQueue->enqueue(p);
}

void Simulation::addtoFinalProduct() {
    noOfFinalProduct++;
}

int Simulation::getnoofFinalProduct() {

    return noOfFinalProduct;
}

void Simulation::TimeoffinalProduct(int timingofone) {
    finishing+=timingofone;
}

int Simulation::getTimeofFinal() {
    return finishing / noOfFinalProduct;
}

Simulation::~Simulation() {
delete(eventList);
delete(productQueue);
delete(*partQueues);
}
