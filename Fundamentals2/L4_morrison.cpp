// Author: Megan Morrison
// Assignment Number: Lab 4
// File Name: L4_morrison.cpp
// Course/Section: COSC 1337 Section 010
// Date: 3/31/2019
// Instructor: Dr. B. Hohlt

/*
 This program will get two users to play a
 game of tic tac toe. The program will run
 until one of the players wins (3 of the same
 values in a row) or there is a
 tie (all spots on the board are filled, but
 none of the same values are 3 in a row)
 */


#include <iostream>
#include <iomanip>

using namespace std;

/*********************
 * Class Declaration *
 *********************/
class TicTacToe
{
private:
    char      board[3][3],            // Array that holds the spaces on the board
              player;                 // Variable that holds the current value of
                                      // the player (either x or o)
public:
    TicTacToe();                      // Default constructor which will set the board
                                      // for each game to a 3x3 of astericts
    void setPlayer(char);             // Mutator. Copies player argument into player member
    char getPlayer() const;           // Accessor. Will get the value of the current player
    void changePlayer();              // Function that changes the player's value
                                      // from x to o.
    void drawBoard() const;           // Function to draw the board
    void updateBoard(int, int);       // Function to mark board with x and o
    bool isValidMove(int, int) const; // Function to make sure positions don't get
                                      // overwritten
    bool checkWinner() const;         // Function to check for any wins
    bool isTie() const;               // Function to check if game is tied
    
    
};

/*****************
 * Main Function *
 *****************/

int main() {
    // Initialize an instance of the TicTacToe class
    TicTacToe game;
    
    // Variable declaration
    bool endGame = false;   // When game is over this variable will be true
    int  row,               // Variable to hold next row value
         col;               // Variable to hold next column vale
    
    
    // Greet the user & give them instructions
    cout << "Welcome to the game of Tic Tac Toe!" << endl;
    cout << "Player 1, you will be the 'x' marks on the board." << endl;
    cout << "Player 2, you will be the 'o' marks on the board." << endl;
    cout << "You can enter a number 1-3 for where you want to place ";
    cout << "your marker. For instance, if you want to place your ";
    cout << "marker in row 1, column 1, enter 1 1." << endl;
    
    // Output a 'blank' board
    cout << "Let's set the board for a new game." << endl;
    game.drawBoard();
    
    while(!endGame) /*should be !endGame */
    {
        
        // Get Player 1 to input value
        cout << "Player 1, please enter the row and column you want to place your ";
        cout << "'x' mark in. You may choose 1-3 for each value" << endl;
        cin >> row >> col;
        
        // Check to see if move is valid. If move is out of bounds or if the
        // player picks a move that has already been done, make the player
        // re-enter their choice.
        while(!game.isValidMove(row, col))
        {
            // Make player re-enter their choice if move is invalid
            cout << "Please enter another move. Make sure you ";
            cout << "choose a value between 1-3 for the row and 1-3 for the column." << endl;
            cin >> row >> col;
        }
        
        // Now we can update the board
        game.updateBoard(row, col);
        game.drawBoard();
            
        // Check for any winners. If there is a winner, stop the
        // game. If not continue on.
        if(game.checkWinner() || game.isTie())
        {
            endGame = true;
            break;
        }
        else
        {
            // If no winners, change player and contine game
            game.changePlayer();
        }
        
        // Get Player 2 to input value
        cout << "Player 2, please enter the row and column you want to place your ";
        cout << "'o' mark in. You may choose 1-3 for each value." << endl;
        cin >> row >> col;
        
        // Check to see if move is valid. If move is out of bounds or if the
        // player picks a move that has already been done, make the player
        // re-enter their choice.
        while(!game.isValidMove(row, col))
        {
            // Prompt player to re-enter move
            cout << "Please enter another move. Make sure you ";
            cout << "choose a value between 1-3 for the row and 1-3 for the column." << endl;
            cin >> row >> col;
        }
            
        // Update board
        game.updateBoard(row, col);
        game.drawBoard();
            
        // Check for any winners. If there is a winner, stop the
        // game. If not continue on.
        if(game.checkWinner() || game.isTie())
        {
            endGame = true;
            break;
        }
        else
        {
            // If no winners, change players and contine game
            game.changePlayer();
        }
        
    }
    
    // Let players know the game is over
    cout << "Game ended." << endl;

    // Determine who the winner is. If the game is a tie
    // we will say there are no winners. Otherwise, we will
    // see what the last player's value was and assign the
    // winner to that player.
    if(game.isTie())
    {
        cout << "Game is tied! There are no winners." << endl;
    }
    else
    {
        if(game.getPlayer() == 'x')
        {
            cout << "The winner is Player 1!" << endl;
        }
        else
        {
            cout << "The winner is Player 2!" << endl;
        }
    }
    
    // Thank users for playing the game
    cout << "Thanks for playing!" << endl;
    
    return 0;
}

/*******************************
 * Class Function Declarations *
 *******************************/

/********************************************
 *        TicTacToe::TicTacToe              *
 *  This is the default constructor. It     *
 *  will reset the board each game and set  *
 *  the variable player to 'x'.             *
 ********************************************/
TicTacToe::TicTacToe()
{
    // Initialize array with astericts
    board[0][0] = '*';
    board[0][1] = '*';
    board[0][2] = '*';
    board[1][0] = '*';
    board[1][1] = '*';
    board[1][2] = '*';
    board[2][0] = '*';
    board[2][1] = '*';
    board[2][2] = '*';
    
    // Set player to 'x'
    player = 'x';
}

/*******************************************
 *         TicTacToe::setPlayer            *
 *  This function sets the member variable *
 *  player.                                *
 *******************************************/
void TicTacToe::setPlayer(char p)
{
    if(player == 'x' || player == 'o')
    {
        p = player;
    }
    else
    {
        cout << "ERROR: The player variable can only ";
        cout << "take on the letters 'x' or 'o'!" << endl;
    }
}

/*************************************
 *       TicTacToe::getPlayer        *
 *  This function returns the member *
 *  variable player.                 *
 *************************************/
char TicTacToe::getPlayer() const
{
    return player;
}

/***********************************************
 *          TicTacToe::changePlayer            *
 *  This function is used to change the player *
 *  during the tic tac toe game. If player 'x' *
 *  just went, then switch to player 'o'.      *
 ***********************************************/
void TicTacToe::changePlayer()
{
    if(player == 'x')
    {
        player = 'o';
    }
    else
    {
        player = 'x';
    }
}

/*********************************************
 *        TicTacToe::drawBoard               *
 *  This function will be called to          *
 *  draw the board after every move. That    *
 *  way the players can see what spaces are  *
 *  left on the board.                       *
 *********************************************/
void TicTacToe::drawBoard() const
{
    // This will display the board in it's current state
    for(int rowCount = 0; rowCount < 3; rowCount++){
        for(int colCount = 0; colCount < 3; colCount++){
            cout << setw(5) << board[rowCount][colCount];
        }
        cout << endl;
    }
}

/************************************************
 *           TicTacToe::updateBoard             *
 *  This function will update the board after   *
 *  each player makes their move. It will set   *
 *  either a 'x' or 'o' in the space the player *
 *  determines.                                 *
 ************************************************/
void TicTacToe::updateBoard(int numRow, int numCol)
{
    if((numRow-1) == 0 && (numCol-1) == 0)
    {
        board[0][0] = player;
    }
    
    else if((numRow-1) == 0 && (numCol-1) == 1)
    {
        board[0][1] = player;
    }
    
    else if((numRow-1) == 0 && (numCol-1) == 2)
    {
        board[0][2] = player;
    }
    
    else if((numRow-1) == 1 && (numCol-1) == 0)
    {
        board[1][0] = player;
    }
    
    else if((numRow-1) == 1 && (numCol-1) == 1)
    {
        board[1][1] = player;
    }
    
    else if((numRow-1) == 1 && (numCol-1) == 2)
    {
        board[1][2] = player;
    }
    
    else if((numRow-1) == 2 && (numCol-1) == 0)
    {
        board[2][0] = player;
    }
    
    else if((numRow-1) == 2 && (numCol-1) == 1)
    {
        board[2][1] = player;
    }
    
    else
    {
        board[2][2] = player;
    }
}

/*********************************************
 *        TicTacToe::checkWinner             *
 * This function will check to see if there  *
 * is a winner after each move the players   *
 * make. If there is a winner then the game  *
 * will stop.                                *
 *********************************************/
bool TicTacToe::checkWinner() const
{
    bool winner;
    
    if((board[0][0] == board[0][1] && board[0][0] == board[0][2]) && (board[0][0] != '*'))
    {
        winner = true;
    }
    
    else if(board[1][0] == board[1][1] && board[1][0] == board[1][2] && (board[1][0] != '*'))
    {
        winner = true;
    }
    
    else if(board[2][0] == board[2][1] && board[2][0] == board[2][2] && (board[2][0] != '*'))
    {
        winner = true;
    }
    
    else if(board[0][0] == board[1][0] && board[0][0] == board[2][0] && (board[0][0] != '*'))
    {
        winner = true;
    }
    
    else if((board[0][1] == board[1][1] && board[0][1] == board[2][1]) && board[0][1] != '*')
    {
        winner = true;
    }
    
    else if((board[0][2] == board[1][2] && board[0][2] == board[2][2]) && board[0][2] != '*')
    {
       winner = true;
    }
    
    else if((board[0][0] == board[1][1]  && board[0][0] == board[2][2]) && board[1][1] != '*')
    {
        winner = true;
    }
    
    else if((board[2][0] == board[1][1] && board[2][0] == board[0][2]) && board[0][2] != '*')
    {
        winner = true;
    }
    
    else
    {
        winner = false;
    }
    
    return winner;
    
}

/**************************************************
 *               TicTacToe::isTie                 *
 * This function will be called after every move  *
 * the players make to see if the game resulted   *
 * in a tie.                                      *
 **************************************************/
bool TicTacToe::isTie() const
{
    bool tie;
    if(board[0][0] != '*' && board[0][1] != '*' && board[0][2] != '*' &&
       board[1][0] != '*' && board[1][1] != '*' && board[1][2] != '*' &&
       board[2][0] != '*' && board[2][1] != '*' && board[2][2] != '*')
    {
        tie = true;
    }
    else
    {
        tie = false;
    }
    
    return tie;
}

/*************************************************
 *         TicTacToe::isValidMove                *
 * This function will be used to check the       *
 * moves the players make. It will check to      *
 * make sure the players aren't duplicating      *
 * moves as well as make sure the row and        *
 * columns the players select are within bounds. *
 *************************************************/
bool TicTacToe::isValidMove(int numRow, int numCol) const
{
    bool status;
    
    if(board[numRow-1][numCol-1] != '*')
    {
        cout << "You cannot make this move. ";
        cout << "There is already a game piece here." << endl;
        
        status = false;
    }
    else if((numRow < 1 || numRow > 3) || (numCol < 1 || numCol > 3))
    {
        cout << "You cannot choose a number that is less than 1 or ";
        cout << "greater than 3. You must pick a number between 1-3!" << endl;
        
        status = false;
    }
    else
    {
        status = true;
    }
    return status;
}

/*
 Welcome to the game of Tic Tac Toe!
 Player 1, you will be the 'x' marks on the board.
 Player 2, you will be the 'o' marks on the board.
 You can enter a number 1-3 for where you want to place your marker. For instance,
 if you want to place your marker in row 1, column 1, enter 1 1.
 Let's set the board for a new game.
 *    *    *
 *    *    *
 *    *    *
 Player 1, please enter the row and column you want to place your 'x' mark in. You may choose 1-3 for each value
 1 1
 x    *    *
 *    *    *
 *    *    *
 Player 2, please enter the row and column you want to place your 'o' mark in. You may choose 1-3 for each value.
 2 2
 x    *    *
 *    o    *
 *    *    *
 Player 1, please enter the row and column you want to place your 'x' mark in. You may choose 1-3 for each value
 2 1
 x    *    *
 x    o    *
 *    *    *
 Player 2, please enter the row and column you want to place your 'o' mark in. You may choose 1-3 for each value.
 3 1
 x    *    *
 x    o    *
 o    *    *
 Player 1, please enter the row and column you want to place your 'x' mark in. You may choose 1-3 for each value
 1 2
 x    x    *
 x    o    *
 o    *    *
 Player 2, please enter the row and column you want to place your 'o' mark in. You may choose 1-3 for each value.
 1 3
 x    x    o
 x    o    *
 o    *    *
 Game ended.
 The winner is Player 2!
 Thanks for playing!
 */
