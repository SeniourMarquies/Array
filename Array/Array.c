#define _CRT_SECURE_NO_WARNINGS


/*


	int bigArray[] = { [0] = 0,[999] = 0 };

	for (int i = 0; i < 1000; i++)
	{
		printf(" %d Number is: %d ",i, bigArray[i]);
		printf("\n");
	}



*/



// array struct tanýmlayalým

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int* elements;
	int size;
}Array;


 Array* mergeArrays( Array* arr1,  Array* arr2) {
	// yeni bir array oluþtur
	 Array* result = malloc(sizeof(Array));
	result->size = arr1->size + arr2->size;
	result->elements = calloc(result->size, sizeof(int));

	// arr1 elemanlarýný result'a kopyala
	for (int i = 0; i < arr1->size; i++) {
		result->elements[i] = arr1->elements[i];
	}

	// arr2 elemanlarýný result'a kopyala
	for (int i = 0; i < arr2->size; i++) {
		result->elements[arr1->size + i] = arr2->elements[i];
	}

	return result;
}
Array* createArray(int size) {
	Array* arr = malloc(sizeof(Array));
	arr->elements = calloc(size, sizeof(int));
	arr->size = size;
	return arr;
}

void freeArray(Array* arr) {
	free(arr->elements);
	free(arr);
}

void setArrayElement(Array* arr, int index, int value) {
	if (index >= arr->size) {
		printf("Error: index out of bounds\n");
		return;
	}
	arr->elements[index] = value;
}

int getArrayElement(Array* arr, int index) {
	if (index >= arr->size) {
		printf("Error: index out of bounds\n");
		return 0;
	}
	return arr->elements[index];
}

void printArray(Array* arr) {
	printf("[ ");
	for (int i = 0; i < arr->size; i++) {
		if (i == arr->size - 1) printf("]");
		else
		{
			printf("%d, ", arr->elements[i]);

		}
	}
	printf("\n");
}

void sortArray(Array* arr) {
	for (int i = 0; i < arr->size; i++) {
		for (int j = i + 1; j < arr->size; j++) {
			if (arr->elements[i] > arr->elements[j]) {
				int temp = arr->elements[i];
				arr->elements[i] = arr->elements[j];
				arr->elements[j] = temp;
			}
		}
	}
}

int searchArray(Array* arr, int value) {
	for (int i = 0; i < arr->size; i++) {
		if (arr->elements[i] == value) {
			return i;
		}
	}
	return -1;
}


int main() {
	int arr_size1 = 0;
	printf("How many items do you want to put into the first array? :");
	scanf("%d", &arr_size1);

	int arr_size2 = 0;
	printf("How many items do you want to put into the second array? :");
	scanf("%d", &arr_size2);

	Array* arr = createArray(arr_size1);
	Array* arr2 = createArray(arr_size2);

	for (int i = 0; i < arr_size1; i++)
	{
		printf("Enter [%d] item : ", i + 1);
		scanf("%d", &arr->elements[i]);
	}
	for (int i = 0; i < arr_size2; i++)
	{
		printf("Enter [%d] item : ", i + 1);
		scanf("%d", &arr2->elements[i]);
	}

	/* setArrayElement(arr, 0, 3);
	 setArrayElement(arr, 1, 7);
	 setArrayElement(arr, 2, 2);
	 setArrayElement(arr, 3, 9);
	 setArrayElement(arr, 4, 1);*/

	printf("Original array of arr1: ");
	printArray(arr);

	sortArray(arr);
	printf("Sorted array: ");
	printArray(arr);
	printf("Original array of arr2: ");
	printArray(arr2);

	sortArray(arr2);
	printf("Sorted array: ");
	printArray(arr2);

	int index = searchArray(arr, 9);
	if (index != -1) {
		printf("Value 9 found at index %d\n", index);
	}
	else {
		printf("Value 9 not found in the arr\n");
	}
	int idx = searchArray(arr2, 13);
	if (index != -1) {
		printf("Value 9 found at index %d\n", idx);
	}
	else {
		printf("Value 9 not found in the arr2\n");
	}

	 Array* result = mergeArrays(arr, arr2);
	printf("Merged array: ");
	for (int i = 0; i < result->size; i++) {
		printf("%d ", result->elements[i]);
	}
	printf("\n");


	freeArray(arr);
	freeArray(arr2);
	return 0;
}