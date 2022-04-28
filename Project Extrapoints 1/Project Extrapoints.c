#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

void decypher(char* message, int n) {
	int i = 0;
	if (n != 0 || n % 26 == 0)
	{
		if (n > 0)
		{
			while (n > 26)
				n = n - 26;

			while (message[i] != '\0')
			{
				if (message[i] != '\n' && !(message[i] >= '0' && message[i] <= '9'))
				{
					if (message[i] >= 'a' && message[i] <= 'z')
					{

						if (message[i] + n < 'a')
							message[i] = 'z' - 'a' + message[i] + n + 1;
						else if (message[i] + n > 'z')
							message[i] = 'a' + message[i] + n - 'z' - 1;
						else
							message[i] = message[i] + n;

					}
					else if (message[i] >= 'A' && message[i] <= 'Z')
					{
						if (message[i] + n < 'A')
							message[i] = 'Z' - 'A' + message[i] + n + 1;
						else if (message[i] + n > 'Z')
							message[i] = 'A' + message[i] + n - 'Z' - 1;
						else
							message[i] = message[i] + n;
					}

				}
				i++;
			}

		}
		else
		{
			while (n < -26)
				n = n + 26;
			while (message[i] != '\0')
			{
				if (message[i] != '\n' && !(message[i] >= '0' && message[i] <= '9'))
				{
					if (message[i] >= 'a' && message[i] <= 'z')
					{

						if (message[i] + n < 'a')
							message[i] = 'z' - 'a' + message[i] + n + 1;
						else if (message[i] + n > 'z')
							message[i] = 'a' + 'z' - message[i] + n - 1;
						else
							message[i] = message[i] + n;

					}
					else if (message[i] >= 'A' && message[i] <= 'Z')
					{
						if (message[i] + n < 'A')
							message[i] = 'Z' - 'A' + message[i] + n + 1;
						else if (message[i] + n > 'Z')
							message[i] = 'A' + 'Z' - message[i] + n - 1;
						else
							message[i] = message[i] + n;
					}

				}
				i++;
			}
		}
	}

}

void letter_distribution(char* message, float* percentage2) {
	int freq[26] = { 0 };
	int i = 0;
	int nr = 0;
	while (message[i] != '\0')
	{
		if (message[i] >= 'a' && message[i] <= 'z')
		{
			freq['z' - message[i]]++;
			nr++;
		}
		else if (message[i] >= 'A' && message[i] <= 'Z')
		{
			freq['Z' - message[i]]++;
			nr++;
		}
		i++;
	}

	for (int i = 25; i >= 0; i--)
		percentage2[25 - i] = 100.0 * freq[i] / nr;


}
float Chi_Squared_distance(float* percentage1, float* percentage2) {

	float rez = 0.0;
	for (int i = 0; i < 26; i++)
		rez = rez + (percentage2[i] - percentage1[i]) * (percentage2[i] - percentage1[i]) / percentage1[i];

	return rez;
}

void menu() {

	printf("Welcome to my application!!!");
	printf("\npress any key to continue");
	char c;
	scanf("%c", &c);
	

}

int main(int argc, char** argv) {

	char message[500];

	menu();
	printf("-------------------------------\nPlease input a string to decipher\n");
	printf("String:");
	scanf("%[^\n]s", message);


	FILE* fp = fopen("distribution.txt", "r");


	float percentage1[26] = { 0 }, percentage2[26] = { 0 };
	int i = 0;

	while (!feof(fp)) {

		fscanf(fp, "%f", &percentage1[i]);

		i++;
	}
	float chi_array[26] = { 0 };
	char messages[26][400];
	for (int i = 0; i < 26; i++) {
		decypher(message, i);
		letter_distribution(message, percentage2);
		//printf("\n[%d]=%s\n", i, message);
		strcpy(messages[i], message);
		chi_array[i] = Chi_Squared_distance(percentage1, percentage2);
		///printf("[%d]=%f\n", i, Chi_Squared_distance(percentage1, percentage2));
	}

	float minimum = chi_array[0];
	int permutation = 0;
	for (int i = 0; i < 26; i++)
		if (chi_array[i] < minimum)
		{
			minimum = chi_array[i];
			permutation = i;
		}

	printf("\n%s\n", messages[permutation]);


	/*


*/

/*
for (int i = 0; i < 26; i++)
	printf("%c%0.1f %0.1f\n", 'a' + i, percentage2[i],percentage1[i]);
*/

	return 0;


}
