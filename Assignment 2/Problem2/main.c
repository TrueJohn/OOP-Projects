#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
// Write a program that takes a single command line argument: 
// the path to a file.This file is actually a dictionary that contains, on each line, a word from the given language.
// You can consider that the maximum size of a word is 50 characters.
// Display the frequency table of the letters from this file, and then the word with the maximum number of letters, the word with the maximum number of vowels and the word with the maximum number of consonants

int main(int argc, char* argv[]) {
	if (argc < 2)
	{
		printf("error on parsing the cmd line");
		return 0;
	}

	char* filename = "English.txt";

	FILE* fp = fopen(filename, "r");
	if (!fp) {
		printf("error on oppening the file");
		return 0;
	}
	int n = 35000;
	char** letters = (char**)malloc(n * sizeof(char*));
	int i = 0;
	char current[100];
	while (!feof(fp)) {
		fscanf(fp, "%s", current);

		letters[i] = malloc((strlen(current) + 1) * sizeof(char));
		strcpy(letters[i], current);

		i++;
	}

	for (int i = 0; i < 100; i++) {
		printf("I read %s \n", letters[i]);

	}

	return 0;
}