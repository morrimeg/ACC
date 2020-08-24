//  Name: Megan Morrison
//  Date: 6/5/2019
//  Course: COSC 2436 - 003
//  File: maxArray.cpp
//  Instructor: Professor Miller

// This program creates and runs a function that
// recursively finds the maximum value in an array.
// The function is a tempalte function, so it can take
// in any type of data.

#include <iostream>
#include <string>

using namespace std;

// Function Prototype
template <class ItemType>
ItemType maxArray(const ItemType array[], int firstIndex, int lastIndex);


/*****************
 * Main Function *
 *****************/
int main() {
    // The arrays below are created for testing purposes
    int arr[] = {10, 3, 5, 7, 13, 8, 2, 4, 15};
    
    int small[] = {13};
    
    double x[] = {4.4, 2.2, 5.5, 1.1, 3.3};
    
    string s[] = {"cc", "bb", "aa"};
    
    // We will test our maxArray function on the above
    // 4 arrays
    
    // First let's test our integer array
    cout << "Let's find the maximum value of our integer array." << endl;
    cout << "The maximum value in our integer array is: " << maxArray(arr, 0 , 8) //9
         << endl;
    
    cout << endl;
    
    // Now we will test our 1 element array
    cout << "Let's find the maximum value of our 1 element array." << endl;
    cout << "The maximum value of our 1 element array is: " << maxArray(small, 0, 0) //1
         << endl;
    
    cout << endl;
    
    // Now let's test our double array
    cout << "Now let's find the maximum value of our floating point array." << endl;
    cout << "The maximum value in our floating point array is: " << maxArray(x, 0, 4) //5
         << endl;
    
    cout << endl;
    
    // Finally, let's test our array of strings
    cout << "Last, we will find the maximum value in our string array." << endl;
    cout << "The maximum value in our string array is: " << maxArray(s, 0, 2) //3
         << endl;
    
    return 0;
}

/****************************************
 *             maxArray                 *
 * This is a recursive function that    *
 * cycles through and finds the highest *
 * value in an array                    *
 ****************************************/
template <class ItemType>
ItemType maxArray(const ItemType array[], int firstIndex, int lastIndex)
{
    int middle;            // variable that holds the middle index of the array
    
    ItemType largestValue, // template variable that holds the largest value
                           // in an array
             leftHalf,     // template variable that holds the left half of values
                           // in an array
             rightHalf;    // template variable that holds the right half of values
                           // in an array
    
    // Bounds checking done here
    if(firstIndex < 0 || lastIndex < firstIndex || lastIndex < 0)
    {
        cout << "ERROR: The bounds you entered are incorrect."
             << " Make sure your array has appropriate bounds."
             << endl;
    }
    
    // The first base case is if there is
    // only one element in the array
    else if(firstIndex == lastIndex)
    {
        largestValue = array[firstIndex];
    }
    
    // Else, we will find the max value of
    // the array that is larger than size 1
    else
    {
        // Calulate the midpoint to split the
        // array in half
        middle = firstIndex + (lastIndex - firstIndex) / 2;
        
        // Now find the max value in the leftzz
        // half of the array
        leftHalf = maxArray(array, firstIndex, middle);
        
        // We will find the max value in the
        // right half of the array now
        rightHalf = maxArray(array, middle + 1, lastIndex);
        
        // Once the largest value is found in both
        // the leftHalf and rightHalf of the array,
        // we save the max of these two values as the
        // largest value
        largestValue = max(leftHalf, rightHalf);

    }
    
    return largestValue;
}

/* Output
 
 Let's find the maximum value of our integer array.
 The maximum value in our integer array is: 15
 
 Let's find the maximum value of our 1 element array.
 The maximum value of our 1 element array is: 13
 
 Now let's find the maximum value of our floating point array.
 The maximum value in our floating point array is: 5.5
 
 Last, we will find the maximum value in our string array.
 The maximum value in our string array is: cc
 Program ended with exit code: 0
 
 */
