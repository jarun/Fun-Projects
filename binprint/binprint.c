/*
 * A fast C program to print the binary representation of a number. 
 *
 * Author: Arun Prakash Jana <engineerarun@gmail.com>
 * Copyright (C) 2015 by Arun Prakash Jana <engineerarun@gmail.com>
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
 * along with Fun-Projects.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <stdlib.h>

void printbin(long long val)
{
	int count = 63;
	char binstr[65] = {0};

	if (!val) {
		printf("0b0");
		return;
	}

	/* If negative, get the 2's complement */
	if (val < 0) {
		val = ~val + 1;
		if (val > 0)
			printf("-0b");
	} else
		printf("0b");

	while (val && count >= 0) {
		binstr[count--] = "01"[val & 1];
		val >>= 1;
	}

	count++;

	printf("%s", binstr + count);
}

int main(int argc, char **argv)
{
	long long val;

	if (argc != 2) {
		printf("usage: printbin val\n");
		return 0;
	}
	
	val = atoll(argv[1]);
	printbin(val);

	return 0;
}
