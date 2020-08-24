//
//  LinkedChar.cpp
//  COSC2336_Lab2
//
//  Created by Megan Morrison on 6/12/19.
//  Copyright © 2019 COSC2436. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <iostream>
#include <cstddef>
#include "Node.h"
#include "LinkedChar.h"

/*******************************************
 *               LinkedChar                *
 * Default constructor. Sets head and tail *
 * pointers to null and charCount to 0.    *
 *******************************************/
LinkedChar::LinkedChar() : head(nullptr), tail(nullptr)
{
    // set all variables to 0 or null
     charCount = 0;
}

/*******************************************
 *              LinkedChar                 *
 * Overloaded constructor. This overloaded *
 * constructor takes in a string value and *
 * places the letters from the string into *
 * a node one at a time.                   *
 *******************************************/
LinkedChar::LinkedChar(const std::string s)
{
    // set string to value
    for(int i = 0; i < s.size(); i++)
    {
        Node *newNode = new Node();
        newNode->setItem(s[i]); // new can take out if not working
        newNode->setNext(nullptr);
        charCount++; // keep track of how many chars have been added to list
        
        if(head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        
        else
        {
            tail->setNext(newNode);
            tail = tail->getNext();
        }
    }
    
}



/*******************************
 *    LinkedChar::LinkedChar   *
 * Copy constructor            *
 *******************************/
LinkedChar::LinkedChar(const LinkedChar& lc)
 {
 charCount = lc.charCount;
 Node* origChainPtr = lc.head;  // Points to nodes in original chain
 
 if (origChainPtr == nullptr)
 head = nullptr;  // Original bag is empty
 else
 {
 // Copy first node
 head = new Node();
 head->setItem(origChainPtr->getItem());
 
 // Copy remaining nodes
 Node* newChainPtr = head;      // Points to last node in new chain
 origChainPtr = origChainPtr->getNext();     // Advance original-chain pointer
 
 while (origChainPtr != nullptr)
 {
 // Get next item from original chain
 char nextItem = origChainPtr->getItem();
 
 // Create a new node containing the next item
 Node* newNodePtr = new Node(nextItem);
 
 // Link new node to end of new chain
 newChainPtr->setNext(newNodePtr);
 
 // Advance pointer to new last node
 newChainPtr = newChainPtr->getNext();
 
 // Advance original-chain pointer
 origChainPtr = origChainPtr->getNext();
 }
 
 newChainPtr->setNext(nullptr);  // Flag end of chain
 }
 }

/***********************************
 *      LinkedChar::length         *
 * This method returns the current *
 * length of the linked list.      *
 ***********************************/
int LinkedChar::length() const
{
    return charCount;
}


/*******************************************
 *         LinkedChar::index               *
 * This method finds the index of a        *
 * character value that the user inputs.   *
 * If the characeter value is found, the   *
 * function returns the index where it was *
 * found. If the character is not in the   *
 * linked list, the function returns -1.   *
 * NOTE the index starts at 0!!            *
 *******************************************/
int LinkedChar::index(char ch) const
{
    int i = 0, // Note that the index starts at 0!
    value = 0; // used to store value of index
    bool found = false;
    Node *curr = head;
    
    while (curr != nullptr && !found)
    {
        
        // Search for character if it exists
        if(ch == curr->getItem())
        {
            value = i;
            found = true;
        }
        
        i++;  // Increment i as you traverse
              // through the list
        curr = curr->getNext();  // move to next node
    }
    
    // If the character value is not found return -1
    if (!found)
    {
        value = -1;
    }
    
    return value;
}

/************************************************
 *           LinkedChar::append                 *
 * The method takes a new linked character list *
 * and appends it to the end of the current     *
 * linked list.                                 *
 ************************************************/
void LinkedChar::append(const LinkedChar& lc)
{
    Node *p = lc.head; // stores current node in lc
    Node *temp; //temp pointer
    
    while(p != nullptr)
    {
        temp = new Node;
        temp->getItem();
        p->getItem();
        temp = p;
        
        if(head == nullptr)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->setNext(temp);
            tail = tail->getNext();
            charCount++;
        }
        
        p = p->getNext();
    }
    
}

/**************************************************
 *            LinkedChar::submatch                *
 * This method takes a string that the user       *
 * wants to search for and returns true (1) if    *
 * the stirng is a substring of the current list, *
 * or returns false (0) if the substring is not   *
 * a string in the current list.                  *
 **************************************************/
bool LinkedChar::submatch(const LinkedChar& lc) const
{
    Node *p1 = head;
    Node *p2, *temp;
    bool status;
    
    while(p1 != nullptr)
    {
        p2 = lc.head; // start from looking at the first character
        
        // If the characters are the same keep moving down the list
        if(p1->getItem() == p2->getItem())
        {
            temp = p1; // store p1 in a temp node
            
            // While the characters in both nodes are the same
            while(p2 != nullptr && temp != nullptr && temp->getItem() == p2->getItem())
            {
                temp = temp->getNext();
                p2 = p2->getNext();
                
            }
            
            // If everything in p2 matched temp
            if(p2 == nullptr)
            {
                status = true;
            }
            else
            {
                status = false;
            }
            
            // If the characters aren't the same go to next node
            // p1 = p1->getNext();
        }
        p1 = p1->getNext();
    }
    
    return status;
    
}

/*
 * display
 */
void LinkedChar::display() const
{
    Node * curr = head;
    
    std::cout << "Linked Chars so far";
    while(curr != nullptr) {
        std::cout << " " << " " << curr->getItem();
        curr = curr->getNext();
    }
    std::cout << std::endl;
}


