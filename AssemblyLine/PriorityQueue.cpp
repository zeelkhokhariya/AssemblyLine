// CLASS: PriorityQueue.cpp
//
// Author: Zeelkumar Khokhariya, 7880619
//
// REMARKS: PartityQueue is a list that stores the data as per the priority and manipulate it
//-----------------------------------------
#include <iostream>
#include "PriorityQueue.h"
#include "Node.h"
#include "Event.h"
PriorityQueue::PriorityQueue() :front(nullptr), back(nullptr), size(0) {}
int PriorityQueue::getSize(){ return size; }
bool PriorityQueue::isEmpty(){ return size == 0; }


// add item to front of queue.
void PriorityQueue::enqueue(ListItem *item)
{
        // special case: adding to empty queue
        if(front == nullptr)
        {
                front = new Node(item, nullptr);
                back = front;
        } 
        else 
        {
            Node *adder = new Node(item,nullptr);
            Node *curr = front;
            Node *prev = nullptr;
            Event *ee = (Event*)(item);
            bool flag = false;
            while(curr!=nullptr && flag==false)
            {
                ListItem *li = curr->getItem();
                Event *e1 = (Event*)li;
                
                if(ee->compareTo(e1)<1)
                {
			if(prev!=nullptr)
			{
                    		prev->setNext(adder);
				adder->setNext(curr);
					
			}
			else
			{
                    		adder->setNext(curr);
				front=adder;
			}
                    flag=true;
                }
                
                prev = curr;
                curr = curr->getNext();
            }
            
            if(!flag)
            {
            ListItem *li = prev->getItem();
                Event *e1 = (Event*)li;
            
                if(ee->compareTo(e1) == 1)
                {
                    prev->setNext(adder);
                    adder->setNext(nullptr);
                    back=adder;
                }
                
            }
        }
        size++;
}// enqueue

// remove front item from Queue.
ListItem *PriorityQueue::dequeue()
{
        ListItem *theItem = nullptr;
        Node *theNode = front;
        if(front != nullptr){
                theItem = front->getItem();
                // special case: removing last item
                if(front == back){
                        front = back = nullptr;
                } else {
                        front = front->getNext();
                }
                size--;
                delete(theNode);
        }
        return theItem;
}// dequeue


// look at first item in queue without removing. 
ListItem *PriorityQueue::getFront()
{
        ListItem *theItem = nullptr;
        if(front != nullptr){
                theItem = front->getItem();
        }
        return theItem;
}// getFront

void PriorityQueue :: print()
{
	Node* curr= front;
	while(curr!=nullptr)
	{
		ListItem *li = curr->getItem();
                Event *e1 = (Event*)li;
		std::cout<< e1->getTime();
		curr= curr->getNext();
	}
}


// destructor
PriorityQueue::~PriorityQueue() {
    delete(front);
    delete(back);
}


