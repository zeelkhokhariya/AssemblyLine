// CLASS: Node.h.cpp
//
// Author: Zeelkumar Khokhariya, 7880619
//
// REMARKS: Node.h store the private field and public defination method that have to be implement in Node.cpp
//-----------------------------------------
#pragma once

class ListItem;

/**** Node interface */
class Node {
private:
        ListItem *item;
        Node *next;
public:
        Node();
        Node(ListItem *i, Node *n);
        Node *getNext();
        void setNext(Node *next);
        ListItem *getItem();
        void setItem(ListItem *i);
}; // class Node
