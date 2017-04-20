#include <stdio.h>
#include <stdlib.h>

void selection_sort(int numbers[], int array_size) {
	int min, temp;

	for (int i = 0; i < array_size - 1; i++) {
		min = i;
		for (int j = i + 1; j < array_size; j++) {
			if (numbers[j] < numbers[min]) 
				min = j;
		}
		temp = numbers[i];
		numbers[i] = numbers[min];
		numbers[min] = temp;
	}
}