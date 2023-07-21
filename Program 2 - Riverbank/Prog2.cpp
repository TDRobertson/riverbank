/*----------Prog2.cpp--------------------------------------------------------------------------------------
    The main driver file for RiverBank.h and RiverBank.cpp.
    This file will accept all user input to play the game and display the relevent stages of the game for 
    each user decision and well as keeping count of how many turns the user took to win/lose the game.

	Written by:  (Thomas D. Robertson II)			Tennessee Technological University
	Written for: CSC 1310							(07/17/2023)	
--------------------------------------------------------------------------------------------------------*/

#include "RiverBank.h"
#include <iostream>

using namespace std;

int main()
{
    /*Variables used throughout program.*/
    RiverBank riverBank;

    int gameState = 1; /*Determines if game continues or enters fail state.*/
    int userInput;
    int turnCount = 0;


    cout << "Welcome to the Fox, Chicken, and the Grain game!" << endl << endl; // testing github commit

    /*Explain the game and rules to the user.*/
    cout << "***********************Description of the game***********************" << endl;
    cout << "In this game, the objective is for the farmer to get his fox, chicken, and grain safely across a river from the south bank to the north bank. " << endl;
    cout << "The farmer can take at most one thing with him when he makes his trip across the river in his kayak " << endl;
    cout << "Unfortunately, if the farmer leaves the fox and chicken together, the fox will eat the chicken (because it tastes like chicken). " << endl;
    cout << "However, if the farmer leaves the chicken and the grain together, the chicken will eat the grain..." << endl;
    cout << "As long as you are present on the same side of the fox, chicken, and the grain. They will not eat each other!" << endl << endl;

    /*Call switch case to ask user who they will cross the river with and enact the turn.*/
    cout << "How would you like to cross the river? " << endl << "Enter these values to issue a command: " << endl;
    cout << "\t1. Move ONLY yourself across the river. " << "\n\t2. Move the Fox & yourself across the river. " << "\n\t3. Move the Chicken and yourself across the river. ";
    cout << "\n\t4. Move the Grain and yourself across the river. " << "\n\t5. Display current item positions! (North/South). " << endl;

    // Continuously get user input while game is not in fail state.
   do
    {
        cin >> userInput;
        gameState = riverBank.switchCase(userInput); // Update gameState based on the return value of switchCase()
    } while (gameState == 1); // Repeat the loop while the game state is 1 (continue state)

    if(gameState == 0) 
    {
        cout << "Game Over! You lost." << endl;
    } 
    else if(gameState == 2) 
    {
        cout << "Congratulations! You won the game." << endl;
    }
    
    return 0;
}