//
//  Node.cpp
//  COSC2336_Lab2
//
//  Created by Megan Morrison on 6/12/19.
//  Copyright © 2019 COSC2436. All rights reserved.
//

//#include <stdio.h>
#include "Node.h"
//#include <iostream>


Node::Node():next(nullptr)
{
}

Node(char ch):item(ch), next(nullptr)
{
   // Node::item = ch;
   // next = nullptr;
}


char getItem() const
{
    return Node::item;
}

void Node::setItem(char item)
{
    Node::item = item;
}

Node* Node::getNext() const {
    return next;
}

void Node::setNext(Node *next) {
    Node::next = next;
}



