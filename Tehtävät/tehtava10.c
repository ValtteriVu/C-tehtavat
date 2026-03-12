#include <stdio.h>
#include <string.h>

int main(){
    char words[30];

    while(1){
        printf("Enter a string: ");
        fgets(words, 30, stdin);

        if(words[strlen(words) - 1] == '\n'){
            words[strlen(words) - 1] = '\0';
        }
        printf("Length of the string is: %d\n", strlen(words));

        if(strcmp(words, "stop") == 0){
            printf("Stopped\n");
            break;
        }
    }
    return 0;
}