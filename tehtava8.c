#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 15

void print_numbers(const int *array, int count);

int main() {
	int numbers[SIZE];
	int count = SIZE;
	srand(time(NULL));

	for(int i = 0; i < count; i++){
		numbers[i] = rand();
	}
	print_numbers(numbers, count);
	return 0;
}

void print_numbers(const int *array, int count){
	for(int i = 0; i < count; i++){
		printf("%8d\n", array[i]);
	}
}