
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
// Alice forgot her card’s PIN code.She remembers that her PIN code had 4 digits, all the digits were distinct and in decreasing order, and that the sum of these digits was 24.
// This C program that prints, on different lines, all the PIN codes which fulfill these constraints.

int main(int argc, char* argv[])
{


	for (int i = 9; i >= 1; i--)
		for (int j = 9; j >= 0; j--)
			for (int k = 9; k >= 0; k--)
				for (int l = 9; l >= 0; l--)
					if (i + j + k + l == 24 && i > j && j > k && k > l)
						printf("%d%d%d%d\n", i, j, k, l);




	return 0;
}

