# Tic-Tac-Toe 

Tic tac toe is a classic paper and pencil game that is played by two players. The game consists of a 3x3 grid, and each player takes turns marking a square on the grid with their symbol (either an X or an O). The first player to get three of their symbols in a row (horizontally, vertically, or diagonally) is the winner. If all of the spaces on the grid are filled and no player has won, then the game is a draw.

This C program is an implementation of the classic game tic-tac-toe. The game is played on a 3x3 grid and two players take turns marking a square on the grid with their symbol (either an X or an O). The first player to get three of their symbols in a row (horizontally, vertically, or diagonally) is the winner. If all of the spaces on the grid are filled and no player has won, then the game is a draw.

The program includes several functions:

**display_board()**: This function displays the current state of the tic-tac-toe board, with X's, O's, and empty spaces represented by X, O, and _ respectively.

**win_display(int)**: This function displays the winner and exits the program. The input to the function is the player (either 1 for X or 2 for O) who has won the game.

**row_check(int)**, **col_check(int)**, **right_diagonal(int)**, **left_diagonal(int)**: These functions check if the player (represented by the input integer, either 1 for X or 2 for O) has won the game by getting three of their symbols in a row (horizontally, vertically, or diagonally) on the tic-tac-toe board. If the player has won, the **win_display(int)** function is called.

**draw()**: This function checks if the game is a draw, i.e. all of the spaces on the grid are filled and no player has won. If the game is a draw, it displays a message and exits the program.

**player_chance(int, int, int)**: This function is called when a player (either X or O) makes a move on the tic-tac-toe board. The input to the function are the x and y coordinates of the move and the player making the move (either 1 for X or 2 for O). The function updates the board to reflect the move.

**check_user_input(int)**: This function checks if the input integer is between 1 and 3 (inclusive). It returns 1 if the input is between 1 and 3, and 0 otherwise.

**position_check(int, int)**: This function checks if the position on the tic-tac-toe board specified by the input x and y coordinates is free (i.e. not already occupied by an X or an O). It returns 1 if the position is free, and 0 otherwise.

The main function of the program is a loop that continues until the game is won or a draw. On each iteration of the loop, the current state of the tic-tac-toe board is displayed, and the current player (either X or O) makes a move. The input x and y coordinates of the move are read from the user, and the check_user_input(int) and position_check(int, int) functions are called to ensure that the move is valid. If the move is valid, it is made using the player_chance(int, int, int) function, and the row_check(int), col_check(int), right_diagonal(int), and left_diagonal(int) functions are called to check if the player has won. If the game is not won or a draw, the loop continues with the next player's turn. If the game is won
