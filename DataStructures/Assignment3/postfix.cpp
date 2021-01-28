//  Name: Megan Morrison
//  Date: 6/26/2019
//  Course: COSC 2436 - 003
//  File: .cpp
//  Instructor: Professor Miller

// This program asks the user for a postfix
// expression to evaluate. It then evaluates the
// postfix expression and returns the result to
// the user. The expression that can be entered
// may only have digits and the following operators:
// +, -, *, /

#include <iostream>
#include <string>
#include <stack>

using namespace std;

// Function prototype
int postfixCalc(string postfixExpression);

/*****************
 * Main Function *
 *****************/

int main() {
    
    string userExpression; // var to hold the postfix
                           // expression from the user
    
    // Prompt user for postfix expression
    cout << "Welcome to the postfix calculator!" << endl;
    cout << "Please enter a postfix expression you want to evaluate: " << endl;
    getline(cin, userExpression);
    
    // Print out result of postfix function
    cout << "The result of your postfix expression" << endl;
    cout << userExpression << endl;
    cout << " is: " << postfixCalc(userExpression) << endl;

    return 0;
}


/*****************************************
 *       postfixCalc Function            *
 * This function takes in a postfix      *
 * expression and calculates the result. *
 * The result of the postfix expression  *
 * will be returned. This function only  *
 * takes in digits and the following     *
 * operators: +, -, *, /                 *
 *****************************************/

int postfixCalc(string postfixExpression)
{
    int result,            // var used to hold result of postfix calc
        operandOriginal,   // var used to push digits to stack
        operand1,          // var used to hold value at top of stack for math operations
        operand2;          // var used to hold value at top of stack for math operations
   
    stack<int> myStack; // stl stack declared
    
    // We will begin cycling through our postfix expression string
    for(int index = 0; index < postfixExpression.length(); index++)
    {
        // If the index of the string is a digit, then we will
        // detect if there are more than 1 digit (e.g. 3 vs 30), and
        // push this operand to the stack.
        if(postfixExpression[index] >= '0' && postfixExpression[index] <= '9')
        {
            operandOriginal = 0; // set value of operand to 0

            // We need to keep looping until we reach a space. This will help us
            // keep track of single vs multidigit numbers going onto the stack
            while(index < postfixExpression.length() && postfixExpression[index] != ' ')
            {
                // If the operand is more than 1 digit, we will multiply the
                // operand by 10 and add it to the operand at the appropriate index.
                // This allows us to add multidigit numbers to our stack. We also
                // need to subtract a 0 since these numbers are coming in as ASCII
                // characters
                operandOriginal = (operandOriginal * 10) + (postfixExpression[index] - '0');

                // Increment the index until a space is reached
                index++;
            }
            
            // Push value of operand to the stack
            myStack.push(operandOriginal);
        }

        // continue on if the next index in the string is a space
        else if(postfixExpression[index] == ' ')
        {
            continue;
        }
        
        // Once we hit an operator, do the appropriate math
        else if(postfixExpression[index] == '+' || postfixExpression[index] == '-'
                || postfixExpression[index] == '*' || postfixExpression[index] == '/')
        {

            // Last digit that was placed on the
            // stack gets assigned and popped off
            operand2 = myStack.top();
            myStack.pop();
            
            // The next digit that is on top of the
            // stack gets assigned and popped off
            operand1 = myStack.top();
            myStack.pop();
            
            // Addition operator
            if(postfixExpression[index] == '+')
            {
                result = operand1 + operand2;
                myStack.push(result);
            }
            
            // Subtraction operator
            else if(postfixExpression[index] == '-')
            {
                result = operand1 - operand2;
                myStack.push(result);
            }
            
            // Multiplication Operator
            else if(postfixExpression[index] == '*')
            {
                result = operand1 * operand2;
                myStack.push(result);
            }
            
            // Division Operator
            else if(postfixExpression[index] == '/')
            {
                // make sure we aren't dividing by 0
                if(operand2 != 0)
                {
                    result = operand1 / operand2;
                    myStack.push(result);
                }
                
                else
                {
                    cout << "ERROR! You can't divide by 0!" << endl;
                }

            }
            
            // If for some reason the user inputs an incorrect postfix
            // expression (e.g. infix, etc). We will use this
            // as a catch all error.
            else
            {
                cout << "An error occured. Please try again." << endl;
            }
            
        }
        
    }
    // Return the value on the top of the stack, which will be
    // the result of the postfix operation
    return myStack.top();
}
