#include <stdio.h>
#include <string.h>

int main(){
    char name[100];
    char buf[100];
    int total = 0;
    int lowest = 2147483647;
    int highest = -2147483648;
    int val;

    printf("Enter a filename: ");
    fgets(name, 100, stdin);

    if(name[strlen(name) - 1] == '\n'){
        name[strlen(name) - 1] = '\0';
    }
    FILE *f = fopen(name, "r");

    if(f == NULL){
        fprintf(stderr, "Could not open file %s\n", name);
        return 1;
    }
    while(fgets(buf, 100, f) != NULL){
        if(sscanf(buf, "%d", &val) != 1){
            break;
        }
        total++;
        if (val < lowest) lowest = val;
        if (val > highest) highest = val;
    }
    printf("Count of numbers: %d\n", total);
    printf("Lowest number: %d\n", lowest);
    printf("Highest number: %d\n", highest);
    fclose(f);

    return 0;
}