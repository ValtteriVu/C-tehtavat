#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int num;
    int rnd;
    int shifted;
    int result;

    srand(time(NULL));

    while(1){
        printf("Enter a number between 0 and 15 (negative to stop): ");
        scanf("%d", &num);

        if(num < 0){
            break;
        }
        if(num <= 15){
            rnd = rand();
            printf("Random number: %x\n", rnd);

            shifted = rnd >> num;
            result = shifted & 0x3F;
            printf("Result: %02x\n", result);
        }
    }
    return 0;
}