#include <stdio.h>
#include <stdlib.h>

// Copies elemenets from one array to another
// Parameters: 	arr is the array from which elements will be copied
// 				to_arr is the array to which the elements will be copied into.
// 				array_size specifies how many elements need to be copied from 
//				first index
void copy_array(int const arr[], int to_arr[], int array_size) {
	for (int i = 0; i < array_size; i++) {
		to_arr[i] = arr[i];
	}
}