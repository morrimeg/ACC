//  Name: Megan Morrison
//  Date: 7/05/2019
//  Course: COSC 2436 - 003
//  File: giftList.cpp
//  Instructor: Professor Miller


// This program asks the user for names of
// people who are on the nice list, and what
// gifts they would like. The program outputs
// the list of people and their desired gifts.

#include <iostream>
#include <string>
#include <list>

using namespace std;

/*********************
 * Class Declaration *
 *********************/

// NiceList Class
class NiceList
{
private:
    string name;            // naem on the nice list
    list<string> giftList;  // list of gifts for each person
public:
    NiceList();                       // Default constructor
    NiceList(string,  list<string>);  // Overloaded constructor
    void setName(string);             // Mutator for setting the person's name
    void setGift(list<string>);       // Mutator for setting the gift list
    void insertGift(string);          // Method to insert gift into gift list
    string getName() const;           // Accessor to retrieve the person's name
    list<string> getGiftList() const; // Accessor to retrieve the list of gifts
    int giftListLength();             // Method to retrive the length of the gift list
    void display();                   // Display contents of gift list
};

/*****************
 * Main Function *
 *****************/
int main() {
    
    list<NiceList> santasList;  // Instatiate a list of NiceList objects
    list<string> niceListGifts; // list to hold each person's gift
    string name,                // variable to hold each person's name
           gift;                // variable to hold each gift
    


    // Greet user
    cout << "Welcome to Santa's nice list creator!" << endl;
    cout << "You will be asked to enter in names of people "
         << "who are on the nice list and what gifts they want. "
    
    << "If at any time you want to stop, just hit 'enter'." << endl;
    
    // Ask for a name to start the while loop
    cout << "Please enter a name for the nice list: " << endl;
    getline(cin, name);
    
    // While the string of names doesn't
    // equal a space/return value, we keep
    // asking the user to input new names
    // for the nice list
    while(name.length() != 0)
    {
        // Initialize the NiceList objecgt
        NiceList person(name, niceListGifts);
        person.setName(name);
        
        // Prompt user to enter gifts for person
        cout << "Please enter a gift for " << name << ": " << endl;
        getline(cin, gift);
        
        // Insert gift into person object
        person.insertGift(gift);
        
        // Ask  the user for more gifts
        while(gift.length() != 0)
        {
            
            cout << "Enter a gift:" << endl;
            getline(cin, gift);
            person.insertGift(gift);
            
        }
        
        // Now, add the person object (name and gift list) to
        // Santa's list.
        list<NiceList>::const_iterator iter = santasList.end();
        santasList.insert(iter, person);
        
        // Prompt user for next name
        cout << "Please enter a name for the nice list: " << endl;
        getline(cin, name);
        person.setName(name);
    }
    
    cout << endl;
    
    if(!santasList.empty())
    {
        // List out the names and gifts for everyone on the list
        cout << "The names and gifts on Santa's nice list are: " << endl;
        
        // Iterate through the list using the list methods begin and end
        for(list<NiceList>::iterator iter = santasList.begin(); iter != santasList.end(); iter++)
        {
            NiceList person = *iter;
            cout << person.getName() << ": ";
            person.display();
        }
    }

    else
    {
        cout << "There is no one on Santa's nice list. Everyone is "
             << "getting coal this year." << endl;
    }

    return 0;
}


/*******************************
 * Class Function Declarations *
 *******************************/

/**************************************
 *       NiceList::NiceList           *
 * This is the default constructor.   *
 * It sets everything to empty at the *
 * start.                             *
 **************************************/
NiceList::NiceList(): name(0), giftList()
{}

/***************************************
 *        NiceList::NiceList           *
 * This is the overloaded constructor. *
 * It sets the name and gift list.     *
 ***************************************/
NiceList::NiceList(string personsName, list<string> personsGift)
{
    if(name.length() > 0)
    {
        name = personsName;
        giftList = personsGift;
    }
    
    else
    {
        name = " ";
    }
}

/*************************************
 *        NiceList::setName          *
 * Mutator method that sets the name *
 * of the person on the list         *
 *************************************/
void NiceList::setName(string personsName)
{
    name = personsName;
}

/*************************************
 *        NiceList::setGift          *
 * Mutator method that sets the gift *
 * string into the gift list.        *
 *************************************/
void NiceList::setGift(list<string> personsGift)
{
    giftList = personsGift;
}

/*************************************
 *      NiceList::insertGift         *
 * The insertGift method inserts the *
 * gift into the giftList list       *
 *************************************/
void NiceList::insertGift(string personsGift)
{
    if(personsGift.length() > 0)
    {
        list<string>::const_iterator iter = giftList.end();
        giftList.insert(iter, personsGift);
        setGift(giftList);
    }
    
    else
    {
        cout << "Nothing to insert into the gift list." << endl;
    }
    
}

/********************************
 *     NiceList::getName        *
 * This method returns the name *
 * on the nice list             *
 ********************************/
string NiceList::getName() const
{
    return name;
}


/*********************************
 *     NiceList::getGiftList     *
 * This method returns the gift  *
 * list portion of the nice list *
 *********************************/
list<string> NiceList::getGiftList() const
{
    return giftList;
}

/**********************************
 *   NiceList::giftListLength     *
 * This method returns the length *
 * of the gift list.              *
 **********************************/
int NiceList::giftListLength()
{
    return giftList.size();
}

/******************************
 *    NiceList::display       *
 * This method displays the   *
 * items that are on the gift *
 * list.                      *
 ******************************/
void NiceList::display()
{
    // Iterate through the gift list by creating
    // an iterator for the list and then use
    // the list method's begin and end
    std::list<string>::const_iterator iter;
    for(iter = giftList.begin(); iter != giftList.end(); iter++)
    {
        cout << (*iter) << " ";
    }
    cout << endl;
}
