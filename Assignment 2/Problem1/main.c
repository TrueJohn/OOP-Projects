#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
// Write a function that takes as an input an array of integer numbers(both positive and negative numbers)  and returns the value of the triplet with the maximum product, as well as the elements that form this triplet.
// Use pass by pointer / address to return the elements that form that triplet.
// In the main function, you will first read the size of the array n, and then n integers representing the elements in the array.

long long findTriplets(int *a, int n, int *t1, int *t2, int *t3) {
	int maximum = 0;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			for (int k = j + 1; k < n; k++)
			{
				if (a[i] * a[j] * a[k] > maximum)
				{
					maximum = a[i] * a[j] * a[k];
					*t1 = a[i];
					*t2 = a[j];
					*t3 = a[k];
				}
			}
	return maximum;
}

int main() {
	int n;
	int ok = scanf("%d", &n);

	if (ok == 0) {
		printf("Invalid input! Application will now stop");
	}
	else {


	int* a = (int*)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int* t1, t2, t3;

	long long res = findTriplets(a, n, &t1, &t2, &t3);

	printf("The triplet with the maximum product %lld is (%d, %d, %d)", res, t1, t2, t3);


	}
	return 0;
}