/*----------Prog2.cpp--------------------------------------------------------------------------------------
    The main driver file for RiverBank.h and RiverBank.cpp.
    This file will accept all user input to play the game and displays and records the relevent stages of 
    the game for each user decision and well as keeping count of how many turns the user took to win/lose 
    the game.

	Written by:  (Thomas D. Robertson II)			Tennessee Technological University
	Written for: CSC 1310							(07/17/2023)	
--------------------------------------------------------------------------------------------------------*/

#include "RiverBank.h"
#include <iostream>
#include <limits>
#include <fstream>

using namespace std;

ofstream outFile;   /*Declare global ofstream object for writing to file.*/

int main()
{
    /*Variables used throughout program.*/
    RiverBank riverBank;

    string filename;                /*Stores user input filename*/
    string continueState = "y";     /*Sets default continue state.*/

    int gameState = 1;              /*Determines if game continues or enters fail state.*/
    int userInput;
    int turnCount = 1;              /*Initial turn count*/


    /*Introduction message*/
    cout << "Welcome to the Fox, Chicken, and the Grain game!" << endl << endl;
    cout << "Where would you like to save your game data? (Example gameData.txt): ";
    cin >> filename;

    /*Open file for writing all of the users moves throughout the game.*/
    outFile.open(filename);

    /*Check that file is open*/
    if (!outFile)
    {
        cout << "Error opening file. Program will now exit." << endl;
        return 0;
    }

    /*Explain the game and rules to the user.*/
    cout << "\n***********************Description of the game***********************" << endl;
    outFile << "\n***********************Description of the game***********************" << endl;

    cout << "In this game, the objective is for the farmer to get his fox, chicken, and grain safely across a river from the south bank to the north bank. " << endl;
    outFile << "In this game, the objective is for the farmer to get his fox, chicken, and grain safely across a river from the south bank to the north bank. " << endl;

    cout << "The farmer can take at most one thing with him when he makes his trip across the river in his kayak " << endl;
    outFile << "The farmer can take at most one thing with him when he makes his trip across the river in his kayak " << endl;

    cout << "Unfortunately, if the farmer leaves the fox and chicken together, the fox will eat the chicken (because it tastes like chicken). " << endl;
    outFile << "Unfortunately, if the farmer leaves the fox and chicken together, the fox will eat the chicken (because it tastes like chicken). " << endl;

    cout << "However, if the farmer leaves the chicken and the grain together, the chicken will eat the grain..." << endl;
    outFile << "However, if the farmer leaves the chicken and the grain together, the chicken will eat the grain..." << endl;

    cout << "As long as you are present on the same side of the fox, chicken, and the grain. They will not eat each other!" << endl << endl;
    outFile << "As long as you are present on the same side of the fox, chicken, and the grain. They will not eat each other!" << endl << endl;

    /*Call switch case to ask user who they will cross the river with and enact the turn.*/
    cout << "How would you like to cross the river? " << endl << "Enter these values to issue a command: " << endl;
    outFile << "How would you like to cross the river? " << endl << "Enter these values to issue a command: " << endl;

    cout << "\t1. Move ONLY yourself across the river. " << "\n\t2. Move the Fox & yourself across the river. " << "\n\t3. Move the Chicken and yourself across the river. ";
    outFile << "\t1. Move ONLY yourself across the river. " << "\n\t2. Move the Fox & yourself across the river. " << "\n\t3. Move the Chicken and yourself across the river. ";
    
    cout << "\n\t4. Move the Grain and yourself across the river. " << "\n\t5. Display current item positions! (North/South). " << endl;
    outFile << "\n\t4. Move the Grain and yourself across the river. " << "\n\t5. Display current item positions! (North/South). " << endl;

    // Continuously run the game until user presses n or N.
    while (continueState == "y" || continueState == "Y")
    {

        // Continuously get user input while game is not in fail state.        
        do
            {
                cout << "\nTurn " << turnCount << ": ";
                outFile << "\nTurn " << turnCount << ": ";
                cout << "\nWho will you cross to the other side of the river with? ";
                outFile << "\n\tWho will you cross to the other side of the river with? ";
                cout << "\n\t(1) Just yourself, (2) Fox, (3) Chicken, (4) Grain, (5) Display current item positions: ";
                cin >> userInput;

                /*Validate user has entered an integer value, if not keep prompting until they do.*/
                while(cin.fail())   /*Check if previous input operation failed.*/
                {
                    cin.clear();    /*Reset failbit to goodbit, to allow user input again.*/
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); /*Skip bad input reads*/
                    cout << "\n\tInvalid input, please enter an integer: ";
                    cout << "\n\tWho will you cross to the other side of the river with? ";
                    cout << "\n\t(1) Just yourself, (2) Fox, (3) Chicken, (4) Grain, (5) Display current item positions: ";
                    cin >> userInput;
                }

                gameState = riverBank.switchCase(userInput); // Update gameState based on the return value of switchCase()
            } while (gameState == 1); // Repeat the loop while the game state is 1 (continue state)

            if(gameState == 0) /*Failstate was achieved, ask user if they want to continue.*/
            {
                cout << "\nGame Over! You lost." << endl;
                outFile << "\nGame Over! You lost." << endl;
                cout << "\nWould you like to play again? (Enter y or n): ";
                cin >> continueState;

                /*Reset game state and turn count for new game.*/
                if (continueState == "y" || continueState == "Y")
                {
                    riverBank.resetGame();
                    riverBank.displayOptions();
                }
            } 
            else if(gameState == 2) /*Win state was achieved, congratulate user and ask if they want to play again.*/
            {
                cout << "\nCongratulations! You won the game." << endl;
                outFile << "\nCongratulations! You won the game." << endl;
                cout << "\nWould you like to play again? (Enter y or n): ";
                cin >> continueState;

                /*Reset game state and turn count for new game.*/
                if (continueState == "y" || continueState == "Y")
                {
                    riverBank.resetGame();
                    riverBank.displayOptions();
                }
            }        
    }

    /*Close the gameData file*/
    outFile.close();
    cout << "Game data has been saved to " << filename  << endl;

    return 0;
}