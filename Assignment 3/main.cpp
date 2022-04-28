#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#include "complex_test.h"

int cmpfunc(const void* a, const void* b) {
	return ((Complex*)b)->imag - ((*(Complex*)a).imag);
}

int compare_real_part(const void* a, const void* b) {
	return ((Complex*)a)->real - ((*(Complex*)b).real);
}

int compare_imag_part(const void* a, const void* b) {
	return ((Complex*)a)->imag - ((*(Complex*)b).imag);
}

int compare_magnitude_part(const void* a, const void* b) {
	return complex_mag(*((Complex*)a)) - complex_mag(*((Complex*)b));
}

void print_complex_array(Complex* v, int capacity)
{
	printf("\n");
	for (int i = 0; i < capacity; i++)
	{
		printf("C[%d]=", i);
		complex_display(v[i]);
	}
}

int isSorted(Complex* v, int capacity, int (*condition)(const void* a, const void* b)) {

	Complex* v2 = (Complex*)malloc(capacity * sizeof(Complex));

	for (int i = 0; i < capacity; i++)
		v2[i] = v[i];
	

	qsort(v2, capacity, sizeof(Complex), condition);

	for (int i = 0; i < capacity; i++)
		if (!(complex_equals(v[i], v2[i])))
			return 0;
	return 1;

	free(v2);

}



int main(int argc, char** argv) {

	run_complex_tests(true);

	FILE* fp = fopen("test.txt", "r");



	int capacity;
	int it = 0;
	fscanf(fp, "%d", &capacity);

	printf("n=%d\n\n", capacity);

	Complex* v = (Complex*)malloc(capacity * sizeof(Complex));


	while (!feof(fp)) {


		fscanf(fp, "%f %f", &v[it].real, &v[it].imag);

		printf("%0.2f %0.2f\n", v[it].real, v[it].imag);

		it++;
	}

	print_complex_array(v, capacity);

	printf("\nCompare by real part:\n");
	qsort(v, capacity, sizeof(Complex), compare_real_part);
	print_complex_array(v, capacity);

	printf("\nCompare by imag part:\n");
	qsort(v, capacity, sizeof(Complex), compare_imag_part);
	print_complex_array(v, capacity);

	printf("\nCompare by magnitude part:\n");
	qsort(v, capacity, sizeof(Complex), compare_magnitude_part);
	print_complex_array(v, capacity);

	printf("\nTest isSorted:\n");
	
	qsort(v, capacity, sizeof(Complex), compare_imag_part);
	print_complex_array(v, capacity);

	printf("\nIs sorted by real?:%d\n", isSorted(v, capacity, compare_real_part));

	printf("\nIs sorted by imag?:%d\n", isSorted(v, capacity, compare_imag_part));

	printf("\nIs sorted by magnitude?:%d\n", isSorted(v, capacity, compare_magnitude_part));

	free(v);
	fclose(fp);
	return 0;
}