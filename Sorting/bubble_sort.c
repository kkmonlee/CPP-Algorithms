#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int a[], int array_size) {
	int tmp;

	for (int i = 0; i < array_size; i++) {
		for (int j = 0; j < (array_size - 1 - i); j++) {
			if (a[j + 1] < a[j]) {
				tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}
}