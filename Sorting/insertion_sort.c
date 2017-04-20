#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int numbers[], int array_size) {
	int index;

	for (int i = 1; i < array_size; i++) {
		index = numbers[i];
		j = i;
		while ((j > 0) && (numbers[j - 1] > index)) {
			numbers[j] = numbers[j - 1];
			j = j - 1;
		}
		numbers[j] = index;
	}
}