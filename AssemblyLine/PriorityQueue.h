// CLASS: PriorityQueue.h
//
// Author: Zeelkumar Khokhariya, 7880619
//

//-----------------------------------------
# pragma once
#include "ListItem.h"

class Node;

class PriorityQueue 
{
private:
        Node *front; // front of queue.
        Node *back; // back of queue
        int size; // size of queue.
public:
        PriorityQueue(); 
        int getSize(); // how many elements are in queue?
        bool isEmpty(); // is queue empty?
        void enqueue(ListItem *item); // add item to queue.
        ListItem *getFront(); // look at first item in queue.
        ListItem *dequeue(); // remove first item from queue. 
	void print();
	~PriorityQueue();
};

