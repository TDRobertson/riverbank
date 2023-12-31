/*----------RiverBank.h--------------------------------------------------------------------------------------

	A header file for the data type RiverBank that keeps track of a boolean values for the private objects and the associated functions
	for the RiverBank object.

	Operations are:
        RiverBank – default constructor that initializes the RiverBank object data members.
        resetGame – resets the RiverBank object data members to their default values whenever the user chooses to continue playing the game after a win or loss.
        getPosition – returns bool value of data member
        setPosition – sets position as South (False) or North (True)
        getStatus – optionally returns message telling state of the game world to user after input.
        setStatus – set state of game world based off Boolean combinations of data members.	
        displayOptions – displays the movement options for the user to choose from.
        displayPosition – displays the current location of each item during each turn.
        switchCase – takes user input and calls the appropriate function to move the user and items across the river.


	  
	Data members are:
        Bool farmer – position of the farmer on South (False) or North (True) river bank.
        Bool chicken - position of the chicken on South (False) or North (True) river bank.
        Bool grain - position of the grain on South (False) or North (True) river bank.
        Bool fox - position of the fox on South (False) or North (True) river bank.
        int turnCount - keeps track of the number of turns taken by the user.
        int gameState; - value of game status which determines if game continues or ends.

	Written by:  (Thomas D. Robertson II)			Tennessee Technological University
	Written for: CSC 1310							(07/17/2023)	
--------------------------------------------------------------------------------------------------------*/

#ifndef RIVERBANK_H
#define RIVERBANK_H

#include <iostream>
#include <fstream>

using namespace std;

extern ofstream outFile;   /*Declare global ofstream object for writing to file.*/

class RiverBank
{
    private:
        bool farmer;
        bool chicken;
        bool grain;
        bool fox;
        int turnCount = 1;
        int gameState;

    public:

    	/*-----------------------------------------------------------------------
			The RiverBank class constructor initializes a RiverBank object data members.
		
			Precondition:  None
			Postcondition: The RiverBank object data members are set to default bool
                           values of false.
        -----------------------------------------------------------------------*/
        RiverBank();


        /*-----------------------------------------------------------------------
            The resetGame() function resets the RiverBank object data members to their
            default values whenever the user chooses to continue playing the game after
            a win or loss.

            Precondition:  None
            Postcondition: The RiverBank object data members are set to default bool
                            values of false,gameState of continue, and turnCount of 1.
        -----------------------------------------------------------------------*/
        void resetGame();


        /*-----------------------------------------------------------------------
			The getPosition function returns the boolean value of data object member.
		
			Precondition:  A valid boolean riverbank object member.
            Receives: A valid boolean riverbank object member.
			Postcondition: A bool is returned representing the objects position.
        -----------------------------------------------------------------------*/
        bool getPosition(bool item) const;


        /*-----------------------------------------------------------------------
            The setPosition function sets the opposite boolean value of data object member
            to determine positioning of the object when user picks object to move to
            other side of the river bank during their turn.

			Precondition:  A valid boolean riverbank object member.
            Receives: A valid boolean riverbank object member.
            Postcondition: Current RiverBank Object is set to True(North)/False(South)
        -----------------------------------------------------------------------*/
        void setPosition(bool& );


        /*-----------------------------------------------------------------------
            The getStatus function returns the state of the game based 
            off combinations of boolean values among data object members.

            Precondition:  None
            Postcondition: Determines if game continues or ends
        -----------------------------------------------------------------------*/
        int getStatus();


        /*-----------------------------------------------------------------------
            The setStatus function sets the state of the game based 
            off combinations of boolean values among data object members on a 
            given turn.

            Precondition:  None
            Postcondition: Determines if game continues or ends in loss/victory
        -----------------------------------------------------------------------*/
        int setStatus();


        /*-----------------------------------------------------------------------
            The displayOptions function displays the options the user can choose
            from.

            Precondition:  None
            Postcondition: Displays all options to user.
        -----------------------------------------------------------------------*/
        void displayOptions();


        /*-----------------------------------------------------------------------
            The displayPosition function displays the current location of each item
            at the beginning of each turn.

            Precondition:  None
            Postcondition: Shows all item positions
        -----------------------------------------------------------------------*/
        void displayPositions();


        /*-----------------------------------------------------------------------
            The switchCase function executes actions based on user input, updates
            the turn count, and returns the current game state.

            Precondition:  A valid integer userInput which corresponds to an action.
            Receives: An integer userInput which indicates which action to perform.
            Postcondition: Executes a series of actions based on the userInput and 
                        returns the current game state (win, lose, or continue).
        -----------------------------------------------------------------------*/
        int switchCase(int );
};

#endif