/*
 * A simple Tic-Tac-Toe Puzzle state checker
 * Uses bitwise operators heavily
 *
 * Author: Arun Prakash Jana <engineerarun@gmail.com>
 * Copyright (C) 2014, 2015 by Arun Prakash Jana <engineerarun@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with tictactoe.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>

#define TRUE 1
#define FALSE !TRUE

#define EMPTY 0b00
#define TICK 0b01
#define CROSS 0b10
#define INVALID 0b11

/* 
 * Structure to hold the states of 1 row
 * Each square is denoted by 2 bits for 3 states: Empty, Tick, Cross
 * The last two bits of each member (row) is ignored
 */

typedef struct {
	unsigned char row1;
	unsigned char row2;
	unsigned char row3;
} state;

/* 
 * Takes the current state of the board as input
 * Updates won with the sign that won the game if it's solved
 * Can be optimized if the currently filled square is taken as input
 * The square can also be saved as a static variable
 * Can be optimized if the sign of the currently filled square is taken as input
 */

int issolved(state current, unsigned char *won)
{
	unsigned char tmp = 0;

	current.row1 &= 0xfc;
	current.row2 &= 0xfc;
	current.row3 &= 0xfc;

	/* Check if a there is a row match for TICK */
	if (current.row1 == 0b01010100 || current.row2 == 0b01010100 || current.row3 == 0b01010100) {
		*won = TICK;
		return TRUE;
	}

	/* Check if a there is a row match for CROSS */
	if (current.row1 == 0b10101000 || current.row2 == 0b10101000 || current.row3 == 0b10101000) {
		*won = CROSS;
		return TRUE;
	}

	/* Check if there is a match for first column */
	if ((tmp = current.row1 & 0xc0) == (current.row2 & 0xc0)) {
		if (tmp && tmp == (current.row3 & 0xc0)) {
			*won = (tmp >> 6);
			if (*won == INVALID)
				return FALSE;
			return TRUE;
		}
	}

	/* Check if there is a match for second column */
	if ((tmp = current.row1 & 0x30) == (current.row2 & 0x30)) {
		if (tmp && tmp == (current.row3 & 0x30)) {
			*won = ((tmp << 2) >> 6);
			if (*won == INVALID)
				return FALSE;
			return TRUE;
		}
	}

	/* Check if there is a match for third column */
	if ((tmp = current.row1 & 0x0c) == (current.row2 & 0x0c)) {
		if (tmp && tmp == (current.row3 & 0x0c)) {
			*won = ((tmp << 4) >> 6);
			if (*won == INVALID)
				return FALSE;
			return TRUE;
		}
	}

	/* Check if there is a match for first diagonal */
	if ((tmp = current.row1 & 0xc0) == (current.row2 & 0x30) << 2) {
		if (tmp && tmp == (current.row3 & 0x0c) << 4) {
			*won = (tmp >> 6);
			if (*won == INVALID)
				return FALSE;
			return TRUE;
		}
	}

	/* Check if there is a match for second diagonal */
	if ((tmp = current.row3 & 0xc0) == (current.row2 & 0x30) << 2) {
		if (tmp && tmp == (current.row1 & 0x0c) << 4) {
			*won = (tmp >> 6);
			if (*won == INVALID)
				return FALSE;
			return TRUE;
		}
	}

	return FALSE;
}

int main()
{
	unsigned char won = 0;
	/* Test data */
	// state newstate = {0x08, 0x20, 0x80};
	state newstate = {0x0C, 0x30, 0xC0};

	if (issolved(newstate, &won)) {
		if (won == TICK)
			printf("TICK (1) won!\n");
		else
			printf("CROSS (2) won!\n");
	} else if (won == INVALID) {
		printf("Invalid state\n");
	} else {
		printf("Not solved yet\n");
	}
	
	return 0;
}
