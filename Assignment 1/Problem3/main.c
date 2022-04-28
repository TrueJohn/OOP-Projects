#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
//
// This program takes as command line a single integer value which represents a year and then computes and displays the Easter date for that year
// The algorithm for computing the catholic Easter date is the following :
//	A = year mod 19
//	B = year mod 4
//	C = year mod 7
//	D = (19 * A + 24) mod 30
//	E = (2 * B + 4 * C + 6 * D + 5) mod 7 where mod is the remainder of the division of x to y.
// Easter day is then(22 + E + D) March.Note that this formula can give a date from April if 22 + E + D > 31; also take this case into account!
// The program will display the Easter date in the following way "The Easter day is 02 April " (use trailing zeros for the day if it is less than 10)

int main(int argc, char* argv[]) {

	int year;
	scanf("%d", &year);
	if (year < 1876)
		printf("Invalid input, the year should be greater or equal to 1876");
	else
	{
		int A = year % 19;
		int B = year % 4;
		int C = year % 7;
		int D = (19 * A + 24) % 30;
		int E = (2 * B + 4 * C + 6 * D + 5) % 7;

		if (22 + E + D <= 31)
			if (22 + E + D < 10)
				printf("In %d the Easter date is March 0%d", year, 22 + E + D);
			else
				printf("In %d the Easter date is March %d", year, 22 + E + D);
		else
			if (22 + E + D - 31 < 10)
				printf("In %d the Easter date is April 0%d", year, 22 + E + D - 31);
			else
				printf("In %d the Easter date is April %d", year, 22 + E + D - 31);
	}


	return 0;
}

