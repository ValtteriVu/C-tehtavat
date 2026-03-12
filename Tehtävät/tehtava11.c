#include <stdio.h>
#include <string.h>

int replace_char(char *str, const char *repl);

int main(){
    char text[100];
    char chars[100];
    int total;

    printf("Enter a string: ");
    fgets(text, 100, stdin);

    printf("Enter character to replace and replacement character (example: ae): ");
    fgets(chars, 100, stdin);

    if(chars[strlen(chars) - 1] == '\n'){
        chars[strlen(chars) - 1] = '\0';
    }
    total = replace_char(text, chars);

    if(total == 0){
        printf("String was not modified\n");
    } else{
        printf("Number of replacements: %d\n", total);
        printf("Modified string: %s", text);
    }
    return 0;
}

int replace_char(char *str, const char *repl){
    int i;
    int total = 0;

    if(strlen(repl) != 2){
        return 0;
    }
    for(i = 0; str[i] != '\0'; i++){
        if(str[i] == repl[0]){
            str[i] = repl[1];
            total++;
        }
    }
    return total;
}