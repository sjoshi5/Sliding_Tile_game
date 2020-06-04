# Sliding_Tile_game
A sliding tile puzzle game

1. class game: The default class created for the gameplay is class game. 
  All aspects of the game are controlled from this class. All functions mentioned are present in the game class
2. void play: This function is present in the public domain and is called by the user when game is started. 
  Using functions in the private domain it executes ordered flow of the game 
  i.e. Calls function to check win condition and takes the action accordingly. 
  It also displays the winning message and takes input from user for replay.
3. void createBoard: This function initializes the board and its elements as the starting of the game. 
  The tiles are initialized in the form of the solution and 1000 random moves are made in order to jumble the board.
4. void possibleMvts: 
  This function calculates the possible movements for the blank tile, or the possible tiles which can be slid into the blank space. 
  It is calculated by considering the location of the file in the two variables ‘x’ and ‘y’.
5. void getMove: This function takes the input from the user amongst the neighbouring tiles. 
  It then attributes it with the integers associated with movements.
  Up=1. Right =2. Down= 4. Left =8.
  This integer is passed to the move function which moves the tile.
  In case of an invalid move, it prompts the user with another try
6. void move: 
  The move function takes an input in the form of an integer 1,2,4 or 8 for movements up, right, down and left respectively.
  It then swaps the blank tile with the corresponding tile.
7. void drawBoard: The drawBoard function draws the altered version of the board after every turn played by the user.
8. bool WinC: This function checks the winning condition.
  It checks of the contents of the array are in order and this is essentially the win condition
  
Apart from this, the brd[] array is the array which stores the numbers present on each tile and it is represented accordingly by the draw board function. 
However, order of elements in the array do not change.
The Vector ‘vector’ stores the possible movements for the tiles and stores it such that any of the 4 movements can be easily removed/added.

The game is scalable by changing a few values in the code. A 4X4 game is also coded using the same algorithm. 
