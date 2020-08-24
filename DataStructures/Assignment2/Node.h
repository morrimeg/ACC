//
//  Node.h
//  COSC2336_Lab2
//
//  This is the header file for our Node class
//

#ifndef Node//
#define Node

class Node
{
private:
    char item;
    Node * next;
    
public:
    
    Node();
    Node(char ch);
    char getItem() const;
    void setItem(char item);
    Node *getNext() const;
    void setNext(Node *next);
};

#include "Node.cpp"
#endif
