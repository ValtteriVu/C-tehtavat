#include <stdio.h>
int read_range(int low, int high);

int main(){
    int roll;
    int result;

    printf("Let's play!\n");

    for(int i = 0; i < 3; i++){
        printf("Roll a die and enter your result.\n");
        roll = read_range(1, 6);

        if(roll == 6){
            printf("I got 6. It is a tie!\n");
        } else{
            result = roll + 1;
            printf("I got %d. I win!\n", result);
        }
    }
    printf("Better luck next time. Bye!\n");
    return 0;
}
int read_range(int low, int high){
    int num;

    do {
        printf("Enter a number between %d and %d: ", low, high);
        if(scanf("%d", &num) != 1){
            while (getchar() != '\n');
            printf("Invalid input\n");
        }
        if(num < low || num > high){
            printf("Number out of range\n");
        }
    }while (num < low || num > high);
    return num;
}