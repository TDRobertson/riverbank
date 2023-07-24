# riverbank
CSC 1310 assignment programming exercise

Name: Thomas D. Robertson II
Date: 07-23-2023
Assignment: Program – 2, The Fox, the Chicken, and the Grain


Pseudo-code of Algorithm:
1.	Initialize starting variables in main and class member objects.
2.	Print introductory message to user and ask user for name of text file to save data to.
a.	Open and validate file is open.
3.	Explain the rules of the game and define possible user movements.
4.	Set up a while loop to continue running the game until user decides to end program.
a.	Use a do-while loop to continue taking user input for movements.
i.	Validate user input is an integer value for switch case functions.
ii.	Output all user inputs to the open file.
b.	Call switch case riverbank function to enact turn
i.	Store the returned value in gameState variable to check if game continues, is won, or is lost.
ii.	Continue taking input for switch case until a win/loss state is achieved.
5.	If fail-state is achieved ask user if they want to continue or end the program.
a.	If user enters y or Y continue program.
i.	Reset all riverbank data member values to their default state.
ii.	Display the game menu options for the user.
6.	If win-state is achieved ask user if they want to continue or end the program.
a.	If user enters y or Y continue program.
i.	Reset all riverbank data member values to their default state.
ii.	Display the game menu options for the user.
7.	If user ends the game, then close the output file.
a.	Tell user what file game data has been saved to.
8.	End the program.

Class(es):
For this assignment I will use one class RiverBank. The riverbank class will keep track of data attributes and their Boolean values to show positions as well as implementing the “travel” functions which will be used to set the Boolean values of the data members to be returned to the main driver file.

RiverBank
1.	Data Members
•	Bool farmer – position of the farmer on South (False) or North (True) river bank.
•	Bool chicken - position of the chicken on South (False) or North (True) river bank.
•	Bool grain - position of the grain on South (False) or North (True) river bank.
•	Bool fox - position of the fox on South (False) or North (True) river bank.
•	Int turnCount – keeps track of the number of turns taken by the user.
•	Int gameState – value of game status which determines if game continues or ends.
2.	Operations
a.	RiverBank – default constructor that initializes the RiverBank object data members.
b.	resetGame – resets the RiverBank object data members to their default values whenever the user chooses to continue playing the game after a win or loss.
c.	getPosition – returns bool value of data member
d.	setPosition – sets position as South (False) or North (True)
e.	getStatus – returns state of the game world to user after input.
f.	setStatus – set state of game world based off Boolean combinations of data members.	
g.	displayOptions – displays the current location of each item during each turn.
h.	displayPositions – displays the current location of each item during each turn.
i.	switchCase – takes user input and calls the appropriate function to move the farmer and item across the river.


Summary:

Design Decisions

The purpose of the game is simple enough, move 3 objects from the south part of the river to the north, but you can only move one object at a time. As such I will keep track of the position of the objects by setting them from the start position (south = false) to the end position (north = true). The Boolean values will serve to keep track of the decisions the user has made, and they will receive feedback of the games progression via displayed statement telling the user how the game is progressing. 

The setStatus function keeps track of the Boolean values and checks if any of the values enter a fail-state combination, if so it returns a failing game state and ends the game. If values are not in a fail-state combination then the game continues until the win-state combination is achieved. Fail state combinations involved the chicken + fox, or chicken + grain having matching Boolean values without the farmer also having a matching Boolean value. Win-state is achieved by the farmer and all objects having True (North) Boolean values.

Movement is accomplished via the switchCase function which takes user input from main and calls relevant RiverBank functions to update item locations, the turn counter, and the game state.
All of the game progressing movement inputs by the user are output to a file specified by the user until the program ends.

Issues

Major issues with the code throughout design had to do with having sufficient user input validation to avoid infinite loops or crashes, as well as keeping all game variables such as the turn counter and the game State value updating properly as the game progressed. All issues were eventually solved and the program runs perfectly.

Notes
I feel like the program was overall easy to design and implement at its current basic level. I think a lot of improvements could be made to expand on the game and overall the assignment was fairly enjoyable.
