#include <stdio.h>

void read_integer(void);

int main(void){
    read_integer();
    return 0;
}
void read_integer(void){
    int user_input;
    int sum = 0;
    int positive_numbers = 0;

    do{
        printf("Enter positive numbers or negative to stop: ");

        if(scanf("%d", &user_input) != 1){
            while (getchar() != '\n')
                printf("Invalid input\n");
        }

        if(user_input < 0){
            break;
        }
        sum += user_input;
        positive_numbers++;

    } while (user_input >= 0);

    if (positive_numbers > 0) {
        float avg = (float)sum / positive_numbers;
        printf("You entered %d positive numbers. The average is: %.3f\n", positive_numbers, avg);
    } else{
        printf("No positive numbers was entered.");
    }
}