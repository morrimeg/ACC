//  Name: Megan Morrison
//  Date: 6/12/2019
//  Course: COSC 2436 - 003
//  File: maxArray.cpp
//  Instructor: Professor Miller

//  This program asks the user for
//  a string and inputs the user's
// string into a linked list character
// by character. The user then has options
// to see the length of the list, find a
// character in the list, append a new list
// to the current list, and see if a new
// string is part of the current list.

#include <iostream>
#include <string>
using namespace std;

/*********************
 * Class Definitions *
 *********************/

// Node Class
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

// LinkedChar Class
class LinkedChar
{
private:
    Node *head;
    Node *tail;
    int charCount;
    
public:
    LinkedChar();                               // Default constructor
    LinkedChar(const string s);                 // Convert constructor
    LinkedChar(const LinkedChar& lc);           // copy constructor
    void clear();                               // clears contents in linked list
    int length() const;                         // Function keeps track of how many
                                                // character values have been added to
                                                // the linked list
    int index(char ch) const;                   // Finds index of character value
    void append(const LinkedChar& lc);          // Appends 1 linked list onto another
    bool submatch(const LinkedChar& lc) const;  // Finds a substring in a linked list
    void add(const string s);                   // add string one character at a time
    void display() const;                       // Displays ocntents of linked list
};

// Function Prototype(s)

int main()
{
    
    // Variable declaration
    string userString,   // 1st string the user inputs
           appendString, // variable for appended string
           subString;    // Variable used to find substring
    char   userChar;     // character value used for find index
    int    choice;       // variable to store menu option
    
    LinkedChar userList, userList2, userList3;
    
    // Prompt the user to ente a string
    cout << "Please enter a string so we can begin:" << endl;
    getline(cin, userString);
    userList.add(userString);
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
        if(choice == 1)
        {
            userList.clear();
            cout << "Please enter a string so we can begin:" << endl;
            getline(cin, userString);
            userList.add(userString);
            userList.display();
        }
        
        else if(choice == 2)
        {
            cout << "The number of characters in the string are: " << userList.length() << endl;
        }
        
        else if(choice == 3)
        {
            cout << "Please type the character you wish to find in your string: ";
            cin >> userChar;
            cout << "The index of " << userChar << " is located at: " << userList.index(userChar)
            << " please note that if the index is not found, -1 is returned." << endl;
        }
        
        else if(choice == 4)
        {
            userList2.clear();
            cout << "Please type the new string you want to add to your current string:";
            getline(cin, appendString);
            userList2.add(appendString);
            cout << endl;
            userList.append(userList2);
            cout << "Now, your list looks like: " << endl;
            userList.display();
        }
        
        else
        {
            userList3.clear();
            cout << "Type a string that you want to find in your current list " << endl;
            getline(cin, subString);
            userList3.add(subString);
            cout << endl;
            
            if(userList.submatch(userList3) != 0)
            {
                cout << "The string you entered is a substring of your current list!" << endl;
            }
            else
            {
                cout << "I'm sorry, but the string you entered is not a substring in your current list" << endl;
            }
        }
        
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
    
    return 0;
}


/*****************
 * Class Methods *
 *****************/

// Node Class Methods
/************************************
 *           Node::Node             *
 * This is the default constructor. *
 * It sets next to nullptr.         *
 ************************************/
Node::Node():next(nullptr)
{
}

/*******************
 *    Node::Node   *
 * 2nd constructor *
 *******************/
Node::Node(char ch):item(ch), next(nullptr)
{
     Node::item = ch;
     next = nullptr;
}

/*****************************
 *       Node::getItem       *
 * This method gets the item *
 * that is pointed to by the *
 * current node              *
******************************/
char Node::getItem() const
{
    return Node::item;
}

/*****************************
 *       Node::setItem       *
 * This method sets the item *
 * at the current node to    *
 * a character value         *
 *****************************/
void Node::setItem(char item)
{
    Node::item = item;
}

/********************************
 *        Node::getNext         *
 * This method moves to the     *
 * next item in the linked list *
 ********************************/
Node* Node::getNext() const {
    return next;
}

/*********************************
 *         Node::setNext         *
 * This method sets the value of *
 * the next node                 *
 *********************************/
void Node::setNext(Node *next) {
    Node::next = next;
}


// Linked Char Class Methods

/*******************************************
 *               LinkedChar                *
 * Default constructor. Sets head and tail *
 * pointers to null and charCount to 0.    *
 *******************************************/
LinkedChar::LinkedChar() : head(nullptr), tail(nullptr), charCount(0)
{
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
        newNode->setItem(s[i]);     // set item to character in string
        newNode->setNext(nullptr);  // set next item to null pointer
        charCount++; // keep track of how many chars have been added to list
        
        if(head == nullptr)
        {
            head = newNode;
           // tail = newNode;
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
    Node* origChainPtr = lc.head;  // Points to node in original chain
    
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
    
/*********************************
 *    LinkedChar::clear          *
 * Deletes list and clears       *
 * linked list                   *
 *********************************/
void LinkedChar::clear()
    {
        Node* nodeToDeletePtr = head;
        while (head != nullptr)
        {
            head = head->getNext();
            
            // Return node to the system
            nodeToDeletePtr->setNext(nullptr);
            delete nodeToDeletePtr;
            
            nodeToDeletePtr = head;
        }  // end while
        // headPtr is nullptr; nodeToDeletePtr is nullptr
        
        charCount = 0;
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
 *******************************************/
int LinkedChar::index(char ch) const
{
    int i = 1, // Note that the index starts at 0!
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
    Node *curr = lc.head; // stores current value of lc head in node
    Node *newNode;        //newNode pointer to node
    
    // while the current node is not null, cycle
    // through until the last node is reached
    while(curr != nullptr)
    {
        newNode = new Node;
        curr->getItem();
        newNode->setItem(curr->getItem());
        
        // If head is null, set
        // it to the new node
        if(head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        
        // Else move on and set next
        // items to the end of the list
        else
        {
            tail->setNext(newNode); // set next node
            tail = tail->getNext(); // get next node from the end
            charCount++;
        }
        
        // Get next node
        curr = curr->getNext();
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
    Node *node1 = head; // head node of first list
    Node *node2, *temp; // pointer for 2nd list and temporary pointer
    bool status;
    
    while(node1 != nullptr)
    {
        node2 = lc.head; // start by looking at the first character in the list
        
        // If the characters are the same in both listws
        // keep moving down the list
        if(node1->getItem() == node2->getItem())
        {
            temp = node1; // store node1 in a temp node
            
            // While the characters in both nodes are the same and neither
            // are null, get the next value in each list
            while(node2 != nullptr && temp != nullptr && temp->getItem() == node2->getItem())
            {
                temp = temp->getNext();
                node2 = node2->getNext();
            }
            
            // If everything in node2 matched temp
            if(node2 == nullptr)
            {
                status = true;
                break;
            }
            // Otherwise, if there was not a match
            // set status to false
            else
            {
                status = false;
            }

        }
        // Get next character if initial match doesn't work out
        node1 = node1->getNext();
    }
    
    return status;
}

/***********************************
 *        LinkedChar::add          *
 * This method adds the characters *
 * in the string into nodes of the *
 * linked list                     *
 ***********************************/
void LinkedChar::add(const string s)
{
    for(int i = 0; i < s.size(); i++)
    {
        Node *newNode = new Node();
        newNode->setItem(s[i]);  // set item to character in string
        newNode->setNext(nullptr); // set next item to null pointer
        charCount++; // keep track of how many chars have been added to list
        
        // If head is the null pointer, set it to
        // the new node
        if(head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        
        // Else, continue adding items to the
        // end of the list
        else
        {
            tail->setNext(newNode); // set tail to next node
            tail = tail->getNext(); // get next node from the end
        }
    }
}

/************************************
 *     LinkedChar::display          *
 * Display the characters of        *
 * the linked character list.       *
 * I know this shouldn't be part of *
 * the ADT                          *
 ************************************/
void LinkedChar::display() const
{
    Node * curr = head;
    
    // traverse list
    while(curr != nullptr)
    {
        cout << " " << curr->getItem();
        curr = curr->getNext();
    }
    cout << endl;
}
