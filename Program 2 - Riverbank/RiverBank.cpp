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
    position = false; /* might breakstuff, delete later*/
}


/*-----------------------------------------------------------------------
    The getPosition function returns the boolean value of data object member.

    Precondition:  None
    Postcondition: A bool is returned representing the objects position.
-----------------------------------------------------------------------*/
bool RiverBank::getPosition() const
{
    return position;
}


/*-----------------------------------------------------------------------
    The setPosition function sets the opposite boolean value of data object member
    to determine positioning of the object when user picks object to move to
    other side of the river bank during their turn.

    Precondition:  A valid RiverBank object member.
    Receives: A valid RiverBank object member.
    Postcondition: Current RiverBank Object is set to True(North)/False(South)
-----------------------------------------------------------------------*/
void RiverBank::setPosition(bool objectMember)
{   
    position = objectMember; /*Set user-selected option as input for position*/

    if (position == false)  /*If object on southern bank, set position to north bank*/
    {
        position = true;
    }

    else if (position == true) /*If object on north bank, set position to south bank*/
    {
        position = false; 
    }
}


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
    
    /*if farmer and all objects are south (default starting position)*/
    if (!farmer && !chicken && !grain && !fox)
    {
        gameState = 1; /*Nothing happens, game continues*/
        return gameState;
    }

    /*WIN STATE*/
    /*If farmer moves all objects and themselves North*/
    else if (farmer && chicken && grain && fox)
    {
        gameState = 2;  /*All objects have crossed the river safely*/
        return gameState;   /*User wins*/
    }

    /*FAIL STATES*/
    /*If farmer is north and objects are south*/
    else if(farmer && !chicken && !grain && !fox)
    {
        gameState = 0; /*Farmer not present, so fox eats chicken while chicken tries to eat grain.*/
        return gameState; /*User loses*/
    }

    /*If farmer is North and chicken + fox are South or chicken + grain are South*/
    else if(farmer && !chicken && grain && !fox || farmer && !chicken && !grain && fox)
    {
        gameState = 0; /*Either fox eats chicken or chicken eats grain*/
        return gameState; /*User loses*/
    }

    /*If farmer is South and chicken + fox are North, or chicken + grain are North.*/
    else if (!farmer && chicken && !grain && fox || !farmer && chicken && grain && !fox)
    {
        gameState = 0;  /*Either fox eats chicken or chicken eats grain*/
        return gameState;   /*User loses*/
    }

    /*ALL OTHER POSITION COMBINATIONS ARE SAFE, SO GAME CONTINUES*/
    else
    {
        gameState = 1;
        return gameState;
    }

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
    if (!fox, !chicken, !grain) 
    {
        cout << "North Bank: " << endl;        
        cout << "<Empty> " << endl;
        cout << "\nSouth Bank: " << "fox\nchicken\ngrain " << endl;
    }
    cout << "North Bank: " << endl;
    if (fox || chicken || grain)
    {
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
    }

    cout << "South Bank: " << endl;
    if (!fox || !chicken || !grain)
    {
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

int RiverBank::switchCase(int)
{
    return 0;
}