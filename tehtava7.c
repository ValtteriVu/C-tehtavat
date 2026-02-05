#include <stdio.h>
#include <stdbool.h>

bool read_positive(int *value);

int main (){
	int number;
	int incorrect_counter = 0;

	while(incorrect_counter < 3){
		printf("Guess how much money I have!\n");
		printf("Enter a positive number: ");

		if(read_positive(&number)){
			printf("You did not get it right. I have %d euros.\n", number);
		} else {
			printf("Incorrect input\n");
			incorrect_counter++;
		}
	}
	printf("I give up, see you later!\n");
    return 0;
}

bool read_positive(int *value){
    int number;

    if(scanf("%d", &number) != 1){
        while (getchar() != '\n');
        return false;
    }
    if (number <= 0) {
        while (getchar() != '\n');
        return false;
    }
    *value = number * 2 + 20;
    while (getchar() != '\n');
    return true;
}