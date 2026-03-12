#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define LINE_MAX 81
#define ROWS 100
#define NAME_SIZE 20
#define OUTFILE "output.txt"

int main(){
    FILE *rd = NULL;
    FILE *wr = NULL;
    char fname[NAME_SIZE];
    char buf[ROWS][LINE_MAX];
    int cnt = 0;

    printf("Enter the file name: ");
    scanf("%s", fname);

    rd = fopen(fname, "r");
    wr = fopen(OUTFILE, "w");

    if(rd == NULL){
        fprintf(stderr, "Unable to open file %s\n", fname);
        exit(1);
    }
    if(wr == NULL){
        fprintf(stderr, "Unable to open file %s\n", OUTFILE);
        exit(1);
    }
    printf("\nReading from %s...\n", fname);

    while(cnt < ROWS && !feof(rd)){
        if(fgets(buf[cnt], LINE_MAX, rd) != NULL){
            for(int j = 0; buf[cnt][j] != '\0'; j++){
                buf[cnt][j] = toupper(buf[cnt][j]);
            }
            fputs(buf[cnt], wr);
            cnt++;
        }
    }
    printf("Read %d lines from %s\n", cnt, fname);

    for(int i = 0; i < cnt; i++){
        printf("Line %d: %s", i + 1, buf[i]);
    }

    fprintf(wr, "\nRead %d lines from %s and wrote them to %s", cnt, fname, OUTFILE);
    fclose(rd);
    fclose(wr);

    return 0;
}