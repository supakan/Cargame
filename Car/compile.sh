#!/bin/bash
cc -o tictactoe main.c tictactoefunctions.c score.c enemy.c treasure.c -lncurses drunken.c trap.c jump.c -lm 
./tictactoe
