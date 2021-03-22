//-----------------------------------------
// NAME		: Zeelkumar Khokhariya
// STUDENT NUMBER	: 7880619
// COURSE		: COMP 2150
// INSTRUCTOR	: Mike Domaratzki
// ASSIGNMENT	: assignment 2
// QUESTION	: question 1
//
// REMARKS: Purpose of this program to make is event-driven Simulation for assembly line to make final product from
// P0, P1 and P3 using two station main and finishing.
//
//
//-----------------------------------------
#include "Simulation.h"
#include "PriorityQueue.h"

#include <iostream>



void printStats(Simulation *simu);

using namespace std;

int main(int argc, char *argv[]){
    if(argc < 2){
        cout << "Usage: " << argv[0] << " SpecificationFile InputFile \n";
        exit(1);
    }
    cout << "Simulation begins...\n";
    Simulation* sim;
    sim = new Simulation();
    // run simulation
    cout << "starting simulation." << endl;
    sim->runSimulation(argv[1]);
    cout << "\n...All Assembly complete.  Final Summary:\n\n";
    printStats(sim);
    cout << "\nEnd of processing.\n";
    return 0;
}


//------------------------------------------------------
// printStats
//
// PURPOSE:    print the summary of Assembly
// PARAMETERS:
//     Simulation *simu
// Returns: nothing
//------------------------------------------------------
void printStats(Simulation *simu)
{
    cout<<"Left with P0:"<<simu->Part0Size()<<endl;
    cout<<"Left with P1:"<<simu->Part1Size()<<endl;
    cout<<"Left with P2:"<<simu->Part2Size()<<endl;
    cout<<"Left with Partially product from main Station:"<<simu->productSize()<<endl;

    cout<<"Number of Final Product: "<<simu->getnoofFinalProduct()<<endl;

    cout<<"Average time to build a product is: "<< simu->getTimeofFinal();
}

