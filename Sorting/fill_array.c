#include <stdio.h>
#include <stdlib.h>

// Fills array with random numbers
void fill_array(int arr[], int array_size) {
	srand(time(NULL));
	for (int i = 0; i < array_size; i++) {
		arr[i] = rand();
	}
}