//
//  main.cpp
//  COSC2336_Lab2
//
//  Created by Megan Morrison on 6/8/19.
//  Copyright © 2019 COSC2436. All rights reserved.
//

#include <iostream>
#include <string>
#include "Node.cpp"
#include "LinkedChar.cpp"

using namespace std;

// Node Class
/*class Node {
private:
    char item;
    Node * next;
    
public:
    
    Node() : next(nullptr)
    {
    }
    
    Node(char ch):item(ch), next(nullptr){}
    
    char getItem() const {
        return item;
    }
    
    void setItem(char item) {
        Node::item = item;
    }
    
    Node *getNext() const {
        return next;
    }
    
    void setNext(Node *next) {
        Node::next = next;
    }
};*/

int main() {
    
    // Variable declaration
    string userString,   // 1st string the user inputs
           appendString, // variable for appended string
           subString;    // Variable used to find substring
    char   userChar;    // character value used for find index
    int    choice;      // variable to store menu option
    //LinkedChar userList, userList2, userList3;
    
    
    
    // Prompt the user to ente a string
    cout << "Please enter a string so we can begin:" << endl;
    getline(cin, userString);
    LinkedChar userList(userString);
    cout << "You entered the string: ";
    userList.display();
    cout << endl;
    
    // Now give the user a menu of options
    cout << "Please select one of the following: " << endl;
    cout << "1. Enter a new string." << endl;
    cout << "2. See the current length of your string." << endl;
    cout << "3. Find a character in your string." << endl;
    cout << "4. Add another string to your string." << endl;
    cout << "5. See if a different string exists in your string." << endl;
    cout << "6. Quit" << endl;
    cin >> choice;
    cin.ignore(); // this is needed to clear the buffer
    
    // Now that the user has selected an option, we will perform the necessary operations
    // As long as the user doesn't hit quit, perform their selecte choice
    while(choice != 6)
    {
        switch(choice)
        {
           /* case 1:
            {
                cout << "Please enter a string so we can begin:" << endl;
                getline(cin, userString);
               // userList(userString);
                break;
            }*/
           
            case 2:
            {
                cout << "The number of characters in the string are: " << userList.length() << endl;
                break;
            }

           /* case 3:
            {
                cout << "Plaese type the character you wish to find in your string: ";
                cin >> userChar;
                cout << "The index of " << userChar << " is located at: " << userList.index(userChar)
                << " please note that if the index is not found, -1 is returned." << endl;
                break;
            }
            case 4:
            {
                cout << "Please type the new string you want to add to your current string:";
                getline(cin, appendString);
                cout << endl;
                LinkedChar userList2(appendString);
                userList.append(userList2);
                cout << "Now, your list looks like: " << endl;
                userList.display();
                break;
            }
    
            case 5:
            {
                cout << "Type a string that you want to find in your current list " << endl;
                getline(cin, subString);
                cout << endl;
                LinkedChar userList3(subString);
                if(userList.submatch(userList3) != 0)
                {
                    cout << "The string you entered is a substring of your current list!" << endl;
                }
                else
                {
                    cout << "I'm sorry, but the string you entered is not a substring in your current list" << endl;
                }
                break;
            }
            
        }*/
        // Give user the menu options again
        cout << "Please select one of the following: " << endl;
        cout << "1. Enter a new string." << endl;
        cout << "2. See the current length of your string." << endl;
        cout << "3. Find a character in your string." << endl;
        cout << "4. Add another string to your string." << endl;
        cout << "5. See if a different string exists in your string." << endl;
        cout << "6. Quit" << endl;
        cin >> choice;
        cin.ignore();
    }
    
    // Say good bye to the user
    if(choice == 6)
    {
        cout << "Good bye!" << endl;
    }
    
    
    /*
    // Testing things
    string aStr = "Dog";
    string aStr2 = "Cat";
    string aStr3 = "og";
    string aStr4 = "bat";
    
    LinkedChar myChar(aStr), myChar2(aStr2), myChar3(aStr3), myChar4(aStr4); // Initialize class
    
    // add string to linked list
   // myChar.add(myStr[0]);
    //myChar.add(aStr);
    //myChar2.add(aStr2);
    myChar.display();
    
    cout << "The letter D is in index: " << myChar.index('D') << endl;
    cout << "The letter Z is in index: " << myChar.index('z') << endl;
    cout << "O is found: " << myChar.index('o') << endl;
    cout << "The number of characters in the list are: " << myChar.length() << endl;

    myChar.append(myChar2);
    myChar.display();
    cout << "Now we have " << myChar.length() << " letters in the list" << endl;
  //  cout << "The new length is: " << myChar.length() << endl;
    
    cout << "Does it match? " << myChar.submatch(myChar3) << endl;
    cout << "Does it match? " << myChar.submatch(myChar4) << endl;*/

    return 0;
}


// LinkedChar function Definitions

/*
 *   LinkedChar
 * Default constructor
 */
/*    LinkedChar() ; head(nullptr), tail(nullptr)
{
    // set all variables to 0
   // head = nullptr;
   // tail = nullptr;
   // charCount = 0;
}*/

/*
 * LinkedChar
 * Overloaded constructor
 */
/*LinkedChar::LinkedChar(const string s)
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



/*
 * LinkedChar::LinkedCar
 * Copy constructor
 */
/*LinkedChar::LinkedChar(const LinkedChar& lc)
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
}*/

/*
 * LinkedChar::length
 */
/*int LinkedChar::length() const
{
    return charCount;
}*/


/*
 * LinkedChar::index
 */
/*int LinkedChar::index(char ch) const
{
    int i = 0,
        value = 0; // index
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
    
    if (!found)
    {
        value = -1;
    }
    
    return value;
}

/*
 * LinkedChar::append
 */
/*void LinkedChar::append(const LinkedChar& lc)
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

/*
 * LinkedChar::submatch
 */
/*bool LinkedChar::submatch(const LinkedChar& lc) const
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
/*void LinkedChar::display() const
{
    Node * curr = head;
    
    cout << "Linked Chars so far";
    while(curr != nullptr) {
        cout << " " << " " << curr->getItem();
        curr = curr->getNext();
    }
    cout << endl;
}
}
