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

	if (val < 0) {
		printf("-0b");
		val = ~val + 1; // Get the 2's complement of the number
	} else
		printf("0b");

	while (val && count >= 0) {
		binstr[count--] = "01"[val & 1];
		val >>= 1;
	}

	count++;

	if (val) {
		printf("OVERFLOW %s", binstr + count);
	} else
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
