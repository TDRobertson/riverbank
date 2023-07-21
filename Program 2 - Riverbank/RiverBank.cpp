/*----------RiverBank.cpp--------------------------------------------------------------------------------------

	The implementation file for RiverBank.h, contains implementations of the function definitions for all functions
    defined in RiverBank.h

	Operations are:
        getPosition – returns bool value of data member
        setPosition – sets position as South (False) or North (True)
        getStatus – optionally returns message telling state of the game world to user after input.
        setStatus – set state of game world based off Boolean combinations of data members.	
        display – displays the current state of the game after every user decision.


	  
	Data members are:
        Bool farmer – position of the farmer on South (False) or North (True) river bank.
        Bool chicken - position of the chicken on South (False) or North (True) river bank.
        Bool grain - position of the grain on South (False) or North (True) river bank.
        Bool fox - position of the fox on South (False) or North (True) river bank.
        bool position - placeholder position for select object member.
        int gameState; - value of game status which determines if game continues or end.

	Written by:  (Thomas D. Robertson II)			Tennessee Technological University
	Written for: CSC 1310							(07/17/2023)	
--------------------------------------------------------------------------------------------------------*/

#include "RiverBank.h"
#include <iostream>

using namespace std;

/*-----------------------------------------------------------------------
    The RiverBank class constructor initializes a RiverBank object data members.

    Precondition:  None
    Postcondition: The RiverBank object data members are set to default bool
                    values of false.
-----------------------------------------------------------------------*/
RiverBank::RiverBank()
{
    farmer = false;
    chicken = false;
    grain = false;
    fox = false;
    gameState = 1;
}


/*-----------------------------------------------------------------------
    The getPosition function returns the boolean value of data object member.

    Precondition:  None
    Postcondition: A bool is returned representing the objects position.
-----------------------------------------------------------------------*/
bool RiverBank::getPosition(bool item) const
{
    return item;
}


/*-----------------------------------------------------------------------
    The setPosition function sets the opposite boolean value of data object member
    to determine positioning of the object when user picks object to move to
    other side of the river bank during their turn.

    Precondition:  A valid RiverBank object member.
    Receives: A valid RiverBank object member.
    Postcondition: Current RiverBank Object is set to True(North)/False(South)
-----------------------------------------------------------------------*/
void RiverBank::setPosition(bool &objectMember)
 
{   
    objectMember = !objectMember; // Toggle the object's current position.
}

    //if (position == false)  /*If object on southern bank, set position to north bank*/
    //{
    //    position = true;
    //}

    //else if (position == true) /*If object on north bank, set position to south bank*/
    //{
    //    position = false; 
    //}



/*-----------------------------------------------------------------------
    The User Optional getStatus function returns the state of the game based 
    off combinations of boolean values among data object members.

    Precondition:  None
    Postcondition: Determines if game continues or ends
-----------------------------------------------------------------------*/
int RiverBank::getStatus()
{
    return gameState;
}


/*-----------------------------------------------------------------------
    The setStatus function sets the state of the game based 
    off combinations of boolean values among data object members on a 
    given turn.

    Precondition:  A valid integer from the user chosen switch case
    Receives:   A valid integer.
    Postcondition: Determines if game continues or ends in loss/victory
-----------------------------------------------------------------------*/
int RiverBank::setStatus()
{
    /*Game States: If Game State = 0, user loses, Game State = 1, game continues, Game State = 2, user wins.
    Fail state occurs if farmer is not present with combinitions of chicken + grain, as chicken eats the grain.
    fox + chicken, as fox eats the chicken. The Fox is not interested in the grain, so he will not eat the grain.
    If farmer is also present (same side of riverbank) with fail state  combinations the game will not end as the 
    farmer will stop that event. */
    
    /*for readability of the below code !farmer means farmer = false, and farmer = true.*/
    
    /* WIN STATE */
    /* If farmer moves all objects and themselves North */
    if (farmer && chicken && grain && fox)
    {
        gameState = 2;  /* All objects have crossed the river safely */
    }
    /* FAIL STATES */
    /* If fox and chicken are together without farmer */
    else if (farmer != fox && fox == chicken)
    {
        gameState = 0;  /* Fox eats chicken */
        cout << "Farmer not present, so fox eats chicken." << endl;
    }
    /* If chicken and grain are together without farmer */
    else if (farmer != chicken && chicken == grain)
    {
        gameState = 0;  /* Chicken eats grain */
        cout << "Farmer not present, so chicken eats grain." << endl;
    }
    /* ALL OTHER POSITION COMBINATIONS ARE SAFE, SO GAME CONTINUES */
    else
    {
        gameState = 1; /* Nothing happens, game continues */
    }

    return this->gameState;
}


/*-----------------------------------------------------------------------
    The display function displays the current state of the game after every
    user decision.

    Precondition:  None
    Postcondition: Determines if game continues or ends
-----------------------------------------------------------------------*/
void RiverBank::display()
{
    /*Add something here later*/
}

/*-----------------------------------------------------------------------
    The displayPosition function displays the current location of each item
    at the beginning of each turn.

    Precondition:  None
    Postcondition: Shows all item positions
-----------------------------------------------------------------------*/
void RiverBank::displayPositions()
{
    if (!fox && !chicken && !grain) 
    {
        cout << "North Bank: " << endl;        
        cout << "<Empty> " << endl;
        cout << "\nSouth Bank: " << "\nfox\nchicken\ngrain " << endl;
    }
    else
    {
        cout << "North Bank: " << endl;
        if (fox)
        {
            cout << "fox" << endl;
        }
        if (chicken)
        {
            cout << "chicken" << endl;
        }
        if (grain)
        {
            cout << "grain" << endl;
        }

        cout << "South Bank: " << endl;
        if (!fox)
        {
            cout << "fox" << endl;
        }
        if (!chicken)
        {
            cout << "chicken" << endl;
        }
        if (!grain)
        {
            cout << "grain" << endl;
        }
    }
}

int RiverBank::switchCase(int userInput)
{
    int turnCount = 0;
    int gameState = getStatus();  // get the initial game state

    while (gameState != 0 && gameState != 2) /*Check if game is in fail/continue/win state.*/
    {
        if (userInput < 1 || userInput > 5)
        {
            cout << "You must enter one of the valid menu options: ";
            cin >> userInput;
        }
        else
        {
            switch (userInput)
            {
                case 1:
                    turnCount++;
                    cout << "You go to the other side of the river by yourself. " << endl;
                    setPosition(farmer);
                    displayPositions();
                    gameState = setStatus();  // update the game state
                    cout << "Turn: " << turnCount << endl;
                    break;

                case 2:
                    turnCount++;
                    setPosition(farmer);
                    setPosition(fox);
                    cout << "You take the fox to the other side of the river. " << endl;
                    displayPositions();
                    gameState = setStatus();  // update the game state
                    break;

                case 3:
                    turnCount++;
                    setPosition(farmer);
                    setPosition(chicken);
                    cout << "You take the chicken to the other side of the river. " << endl;
                    displayPositions();
                    gameState = setStatus();  // update the game state
                    break;

                case 4:
                    turnCount++;
                    setPosition(farmer);
                    setPosition(grain);
                    cout << "You take the grain to the other side of the river. " << endl;
                    displayPositions();
                    gameState = setStatus();  // update the game state
                    break;

                case 5: 
                    cout << "This is the current position of yourself and all items! " << endl;
                    displayPositions();
                    break;
            }
        }      
        // Get the next userInput only if the game state is not 0 or 2
        if (gameState != 0 && gameState != 2) {
            cout << "How would you like to cross the river? ";
            cin >> userInput;
        }
    }
    return gameState;  // return the final game state
}