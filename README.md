# Tic-Tac-Toe-Board-Game
Introduction

This project is a simple Tic-Tac-Toe game implemented in C. The game allows a player to compete against the computer in a turn-based manner. The computer moves randomly while ensuring that it follows the basic rules of the game. The game runs in a terminal-based interface and utilizes a 3x3 board.

Features

Single-player mode where the user competes against the computer.

Turn-based gameplay with a 3x3 grid.

Randomized computer moves to simulate AI behavior.

Automatic winner detection for rows, columns, and diagonals.

Draw detection when no spaces are left.

Simple CLI-based interface.

How to Run the Game

Prerequisites

To compile and run the game, you need:

A C compiler (such as GCC or Clang)

A terminal or command prompt

Compilation

Use the following command to compile the program:

gcc board_game.c -o board_game -Wall

Running the Game

Once compiled, execute the program using:

./board_game

Game Rules

The game starts with an empty 3x3 board.

The player moves first and is assigned 'X'.

The computer moves after the player and is assigned 'O'.

Players take turns placing their marks on the board.

The game ends when:

A player gets three marks in a row, column, or diagonal (Winner declared).

The board is full, and there is no winner (Draw).

Code Structure

1. resetBoard()

Initializes the game board by setting all positions to empty spaces.

2. printBoard()

Displays the current state of the board in a structured format.

3. checkFreeSpaces()

Counts and returns the number of remaining spaces on the board.

4. playerMove()

Allows the player to select a position on the board.

Ensures that the position is valid and unoccupied.

5. computerMove()

Generates a random move for the computer.

Ensures the move is placed in an empty space.

6. checkWinner()

Checks rows, columns, and diagonals for a winning condition.

Returns the winner ('X' or 'O') or an empty space (' ') if no winner is found.

7. printWinner(char winner)

Displays the game result based on the winner.

Possible Enhancements

Implement Minimax Algorithm to improve AI decision-making.

Add a score tracking system for multiple rounds.

Create a GUI version using SDL or OpenGL.

Allow a two-player mode.
