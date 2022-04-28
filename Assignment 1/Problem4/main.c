#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
// Substitution cipher or Caesar’s cipher.

// This program which reads a natural number n and a string s. The string s is encoded using Caesar’s cipher with a displacement of n (either positive or negative).
// The program decodes the message and display it on the screen. Punctuation marks and numbers are left as they are.

int main(int argc, char* argv[]) {

	int n;
	char message[400];
	scanf("%d %[^\n]s", &n, message);
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
	printf("%s", message);

	return 0;
}
