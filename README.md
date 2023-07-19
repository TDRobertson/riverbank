# riverbank
CSC 1310 assignment programming exercise

Assignment: Program – 2, The Fox, the Chicken, and the Grain


Pseudo-code of Algorithm:

1.	Set up a do-while loop to initially run the game and prompt the user to continue or not afterwards.
a.	Run program again if user enters y or Y, end if n, or N. 
b.	Validate user input so user doesn’t accidentally fat finger quit program.
2.	Initialize all game state variables to their default values upon game start.
a.	Use a while loop to end game if game state variables enter fail state.
3.	Print instructions for user
4.	Prompt user for input
a.	Ask user for input every turn, and give option to display current game state.
b.	Keep track of number of turns.
5.	Display results from user input
a.	Update game state results per user input.
b.	Optionally display game state to user if they asked for it last step.
6.	Print outcome message
a.	Tell user if they move to the next turn.
b.	Tell user if they lost the game (entered fail state for while loop).
c.	Tell user if they won the game and print congratulations message.
7.	Prompt to run game again or quit.

Class(es):

For this assignment I will use one class RiverBank. The riverbank class will keep track of data attributes and their Boolean values to show positions as well as implementing the “travel” functions which will be used to set the Boolean values of the data members

RiverBank
1.	Data Members
•	Bool farmer – position of the farmer on South (False) or North (True) river bank.
•	Bool chicken - position of the chicken on South (False) or North (True) river bank.
•	Bool grain - position of the grain on South (False) or North (True) river bank.
•	Bool fox - position of the fox on South (False) or North (True) river bank.
2.	Operations
a.	getPosition – returns bool value of data member
b.	setPosition – sets position as South (False) or North (True)
c.	getStatus – optionally returns message telling state of the game world to user after input.
d.	setStatus – set state of game world based off Boolean combinations of data members.	
e.	display – displays the current state of the game after every user decision.


Summary:

Design Decisions

The purpose of the game is simple enough, move 3 objects from the south part of the river to the north, but you can only move one object at a time. As such I will keep track of the position of the objects by setting them from the start position (south = false) to the end position (north = true). The Boolean values will serve to keep track of the decisions the user has made, and they will receive feedback of the games progression via displayed statement telling the user how the game is progressing. 

They cannot have The chicken and grain, or chicken or fox, on the same side of the river without the farmer being present, or the game will enter a fail state. The user will win by successfully moving all objects to the north side of the river at the same time (all object values = true). Switch statements will be used to enter users decisions and display the results each turn. The amount of turns the user needed to win the game will be kept track of. At the start of every game, initial Boolean values will be set to a default in order to reset the game state for the next round.
