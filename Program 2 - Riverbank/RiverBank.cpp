/*----------RiverBank.cpp--------------------------------------------------------------------------------------

	The implementation file for RiverBank.h, contains implementations of the function definitions for all functions
    defined in RiverBank.h

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
        int gameState - value of game status which determines if game continues or ends.

	Written by:  (Thomas D. Robertson II)			Tennessee Technological University
	Written for: CSC 1310							(07/17/2023)	
--------------------------------------------------------------------------------------------------------*/

#include "RiverBank.h"
#include <iostream>
#include <fstream>

using namespace std;

/*-----------------------------------------------------------------------
    The RiverBank class constructor initializes a RiverBank object data members
    starting values.

    Precondition:  None
    Postcondition: The RiverBank object data members are initialized to default 
                   bool values of false and gameState of continue.
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
    The resetGame() function resets the RiverBank object data members to their
    default values whenever the user chooses to continue playing the game after
    a win or loss.

    Precondition:  None
    Postcondition: The RiverBank object data members are set to default bool
                    values of false and gameState of continue.
-----------------------------------------------------------------------*/
void RiverBank::resetGame()
{
    farmer = false;
    chicken = false;
    grain = false;
    fox = false;
    gameState = 1;
    turnCount = 1;
}


/*-----------------------------------------------------------------------
    The getPosition function returns the boolean value of data object member.

    Precondition:  A valid boolean riverbank object member.
    Receives: A valid boolean riverbank object member.
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

    Precondition:  A valid boolean riverbank object member.
    Receives: A valid boolean riverbank object member.
    Postcondition: Current RiverBank Object is set to True(North)/False(South)
-----------------------------------------------------------------------*/
void RiverBank::setPosition(bool &objectMember)
{   
    objectMember = !objectMember;   /*Toggle the items current position to the opposite side of the river bank.*/
}


/*-----------------------------------------------------------------------
    The getStatus function returns the state of the game based 
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

    Precondition:  None
    Postcondition: Determines if game continues or ends in loss/victory
-----------------------------------------------------------------------*/
int RiverBank::setStatus()
{
    /*Game States: If Game State = 0, user loses, Game State = 1, game continues, Game State = 2, user wins.
    Fail state occurs if farmer is not present with combinitions of chicken + grain, as chicken eats the grain.
    fox + chicken, as fox eats the chicken. The Fox is not interested in the grain, so he will not eat the grain.
    If farmer is also present (same side of riverbank) with fail state  combinations the game will not end as the 
    farmer will stop that event. */
    
    /*for readability of the below code !farmer means farmer == false, and farmer means farmer == true.*/
    
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
        cout << "The fox ate the chicken because you left them alone! " << endl;
        outFile << "The fox ate the chicken because you left them alone! " << endl;
    }
    /* If chicken and grain are together without farmer */
    else if (farmer != chicken && chicken == grain)
    {
        gameState = 0;  /* Chicken eats grain */
        cout << "You left the chicken alone with the grain! It hungrily jumps into the bag and swiftly devours all of it! " << endl;
        outFile << "You left the chicken alone with the grain! It hungrily jumps into the bag and swiftly devours all of it! " << endl;
    }

    /* ALL OTHER POSITION COMBINATIONS ARE SAFE, SO GAME CONTINUES */
    else
    {
        gameState = 1; /* Nothing happens, game continues */
    }

    /*Update riverbank classes gameState for use in main.*/
    return this->gameState;
}


/*-----------------------------------------------------------------------
    The displayOptions function displays the options the user can choose
    from.

    Precondition:  None
    Postcondition: Displays all options to user.
-----------------------------------------------------------------------*/
void RiverBank::displayOptions()
{
    cout << "\nHow would you like to cross the river? " << endl << "\nEnter these values to issue a command: " << endl;
    cout << "\t1. Move ONLY yourself across the river. " << "\n\t2. Move the Fox & yourself across the river. " << "\n\t3. Move the Chicken and yourself across the river. ";
    cout << "\n\t4. Move the Grain and yourself across the river. " << "\n\t5. Display current item positions! (North/South). " << endl;
}

/*-----------------------------------------------------------------------
    The displayPosition function displays the current location of each item
    at the beginning of each turn.

    Precondition:  None
    Postcondition: Shows all item positions
-----------------------------------------------------------------------*/
void RiverBank::displayPositions()
{
    int tempInput = 0;

    /*If no items are on the north bank.*/
    if (!fox && !chicken && !grain) 
    {
        cout << "\nNorth Bank: " << endl;      
        outFile << "\nNorth Bank: " << endl;  
        cout << "Farmer " << endl;
        outFile << "Farmer " << endl;
        cout << "\nSouth Bank: " << "\nFox\nChicken\nGrain " << endl;
        outFile << "\nSouth Bank: " << "\nFox\nChicken\nGrain " << endl;
    }

    /*If an item has been moved to the north bank, display all current positions based off boolean status.*/
    else
    {
        /*Displaying items on the north river bank.*/
        cout << "\nNorth Bank: " << endl;
        outFile << "\nNorth Bank: " << endl;
        if (farmer)
        {
            cout << "Farmer" << endl;
            outFile << "Farmer" << endl;
        }
        if (fox)
        {
            cout << "Fox" << endl;
            outFile << "Fox" << endl;
        }
        if (chicken)
        {
            cout << "Chicken" << endl;
            outFile << "Chicken" << endl;
        }
        if (grain)
        {
            cout << "Grain" << endl;
            outFile << "Grain" << endl;
        }

        /*Displaying items on the south river bank.*/
        cout << "\nSouth Bank: " << endl;
        outFile << "\nSouth Bank: " << endl;
        if (!farmer)
        {
            cout << "Farmer" << endl;
            outFile << "Farmer" << endl;
        }
        if (!fox)
        {
            cout << "Fox" << endl;
            outFile << "Fox" << endl;
        }
        if (!chicken)
        {
            cout << "Chicken" << endl;
            outFile << "Chicken" << endl;
        }
        if (!grain)
        {
            cout << "Grain" << endl;
            outFile << "Grain" << endl;
        }
        if (!fox && !chicken && !grain)
        {
            cout << "<Empty> " << endl;
            outFile << "<Empty> " << endl;
        }
    }

    /*Force user input to continue display of output messages.*/
    cout <<"\nPress Enter to continue...";
    cin.ignore();
    cin.get();

    cout << "\nTurn: " << turnCount << endl;    /*Display updated turn counter*/
    outFile << "\nTurn: " << turnCount << endl;    /*Display updated turn counter to outFile*/ 

}


/*-----------------------------------------------------------------------
    The switchCase function executes actions based on user input, updates
    the turn count, and returns the current game state.

    Precondition:  A valid integer userInput which corresponds to an action.
    Receives: An integer userInput which indicates which action to perform.
    Postcondition: Executes a series of actions based on the userInput and 
                   returns the current game state (win, lose, or continue).
-----------------------------------------------------------------------*/
int RiverBank::switchCase(int userInput)
{
    this->turnCount = 1;             /*Set the initial turn count.*/
    int gameState = getStatus();  /*get the initial game state*/

    while (gameState != 0 && gameState != 2) /*Check if game is in fail/continue/win state.*/
    {
        if (userInput < 1 || userInput > 5)
        {
            /*If user does not enter a valid option, display options and ask for user input again.*/
            cout << "\nYou must enter one of the valid menu options: ";
            displayOptions();
            cout << "\n\tWho will you cross to the other side of the river with? ";
            cout << "\n\t(1) Just yourself, (2) Fox, (3) Chicken, (4) Grain, (5) Display current item positions: ";
            cin >> userInput;
        }
        else
        {
            /*Move a given item based on user input, update & display turn count, and changes gameStatus per item combinations.*/
            switch (userInput)
            {
                /*If user moves only the farmer.*/
                case 1:
                    this->turnCount++;        /*Update RiverBanks turn counter member*/
                    cout << "\nYou go to the other side of the river by yourself. " << endl;
                    outFile << "\nYou go to the other side of the river by yourself. " << endl;
                    setPosition(farmer);      /*Swap farmers position*/
                    displayPositions();       /*Display all item positions*/
                    gameState = setStatus();  /*update the game state*/

                    break;

                /*If user takes the fox along with the farmer.*/
                case 2:
                    /*Validate farmer and the item to be moved are on the same side of the river.*/
                    if(farmer == fox)
                    {
                        this->turnCount++;        /*Update RiverBanks turn counter member*/                   
                        setPosition(farmer);      /*Swap farmers position*/
                        setPosition(fox);         /*Swap foxes position*/      
                        cout << "\nYou take the fox to the other side of the river. " << endl;    
                        outFile << "\nYou take the fox to the other side of the river. " << endl;              
                    }
                    /*If farmer and fox are not on the same side of the river.*/
                    else if (farmer != fox)
                    {
                        cout << "\nYou cannot move an item that is not on the same side of the river as you! " << endl;
                    }
                    displayPositions();       /*Display all item positions*/
                    gameState = setStatus();  /*update the game state*/
                    break;

                /*If user takes the chicken along with the farmer.*/
                case 3:
                    /*Validate farmer and the item to be moved are on the same side of the river.*/
                    if(farmer == chicken)
                    {
                        this->turnCount++;        /*Update RiverBanks turn counter member*/                      
                        setPosition(farmer);      /*Swap farmers position*/
                        setPosition(chicken);     /*Swap chickens position*/      
                        cout << "\nYou take the chicken to the other side of the river. " << endl;   
                        outFile << "\nYou take the chicken to the other side of the river. " << endl;               
                    }
                    /*If farmer and chicken are not on the same side of the river.*/
                    else if (farmer != chicken)
                    {
                        cout << "\nYou cannot move an item that is not on the same side of the river as you! " << endl;
                    }

                    displayPositions();       /*Display all item positions*/
                    gameState = setStatus();  /*update the game state*/
                    break;

                /*If user takes the grain along with the farmer.*/
                case 4:
                    /*Validate farmer and item to be moved are on the same side of the river.*/
                    if(farmer == grain)
                    {
                        this->turnCount++;        /*Update RiverBanks turn counter member*/                    
                        setPosition(farmer);      /*Swap farmers position*/
                        setPosition(grain);       /*Swap grain position*/      
                        cout << "\nYou take the grain to the other side of the river. " << endl;     
                        outFile << "\nYou take the grain to the other side of the river. " << endl;             
                    }
                    /*If farmer and grain are not on the same side of the river.*/
                    else if (farmer != grain)
                    {
                        cout << "\nYou cannot move an item that is not on the same side of the river as you! " << endl;
                    }
                    displayPositions();       /*Display all item positions*/
                    gameState = setStatus();  /*update the game state*/
                    break;

                /*Display all item positions to user.*/
                case 5: 
                    cout << "\nThis is the current position of the farmer and all items! " << endl;
                    displayPositions();       /*Display all item positions*/
                    break;
            }
        }      

        /*Get the next userInput only if the game state is not 0 or 2 (still in continue state)*/
        if (gameState != 0 && gameState != 2) 
        {
            displayOptions();
            cout << "\n\tWho will you cross to the other side of the river with? ";
            cout << "\n\t(1) Just yourself, (2) Fox, (3) Chicken, (4) Grain, (5) Display current item positions: ";
            cin >> userInput;
        }
    }

    return gameState;  /*return the final game state*/
}