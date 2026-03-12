#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GRADE 100
#define MAX_PEOPLE 20
#define FILENAME "grade_file.txt"

//Structure for data
typedef struct{
    char subject[MAX_GRADE];
    int score;
    int grade;
}SubjectRecord;

//Prototypes
int calculate_grade(int score);
void remove_newline(char *str);
void get_student_data(char *name);
int get_subject_count();
void read_subjects(SubjectRecord subjects[], int count);
void print_report(char *name, SubjectRecord subjects[], int count);
void write_report_file(char *name, SubjectRecord subjects[], int count);

//Main program
int main(){
    char studentName[MAX_GRADE];
    SubjectRecord subjects[MAX_PEOPLE];
    int subjectCount;

    printf("Welcome to the Student Grade Calculator!\n");

    get_student_data(studentName);
    subjectCount = get_subject_count();
    read_subjects(subjects, subjectCount);

    print_report(studentName, subjects, subjectCount);
    write_report_file(studentName, subjects, subjectCount);

    return 0;
}
//Calculation function
int calculate_grade(int score){
    if (score >= 90) return 5;
    if (score >= 80) return 4;
    if (score >= 70) return 3;
    if (score >= 60) return 2;
    if (score >= 50) return 1;

    return 0;
}
//New line removal
void remove_newline(char *str){
    str[strcspn(str, "\n")] = '\0';  //Asked helped from a friend and looked online for this.
}
//Asks for name
void get_student_data(char *name){
    printf("Please enter your name: ");

    fgets(name, MAX_GRADE, stdin);
    remove_newline(name);

    while(strlen(name) == 0){
        printf("Error: Name cannot be empty. Enter again: ");
        fgets(name, MAX_GRADE, stdin);
        remove_newline(name);
    }
}
//Ask for number of people
int get_subject_count(){
    int count;

    printf("How many subjects do you want to calculate grades for? ");
    scanf("%d", &count);

    while(count <= 0 || count > MAX_PEOPLE){
        printf("Invalid number. Enter between 1 and %d: ", MAX_PEOPLE);
        scanf("%d", &count);
    }

    getchar(); // clear newline //got help with AI 
    return count;
}
//Get people and score
void read_subjects(SubjectRecord subjects[], int count){
    for(int i = 0; i < count; i++){

        printf("Enter subject %d name: ", i + 1);
        fgets(subjects[i].subject, MAX_GRADE, stdin);
        remove_newline(subjects[i].subject);

        printf("Enter your score for %s (0-100): ", subjects[i].subject);
        scanf("%d", &subjects[i].score);

        while(subjects[i].score < 0 || subjects[i].score > MAX_GRADE){
            printf("Invalid score. Enter again (0-100): ");
            scanf("%d", &subjects[i].score);
        }
        getchar();
        subjects[i].grade = calculate_grade(subjects[i].score);
    }
}
//Report
void print_report(char *name, SubjectRecord subjects[], int count){
    int total = 0;

    printf("-------------------------------------\n");
    printf("Student: %s\n", name);
    printf("-------------------------------------\n");
    printf("%-25s %-7s %-5s\n", "Subject", "Score", "Grade");
    printf("-------------------------------------\n");

    for(int i = 0; i < count; i++){
        printf("%-25s %3d%% %5d\n",
               subjects[i].subject,
               subjects[i].score,
               subjects[i].grade);
        total += subjects[i].grade;
    }

    double average = (double)total / count;

    printf("-------------------------------------\n");
    printf("Average Grade: %.2f\n", average);
    printf("-------------------------------------\n");
}
//Report to file
void write_report_file(char *name, SubjectRecord subjects[], int count){
    FILE *file = fopen(FILENAME, "w");

    if(file == NULL){
        printf("Error: Could not write report file.\n");
        return;
    }
    int total = 0;
    fprintf(file, "Student: %s\n", name);
    fprintf(file, "%-25s %-7s %-5s\n", "Subject", "Score", "Grade");

    for(int i = 0; i < count; i++){
        fprintf(file, "%-25s %3d%% %5d\n",
                subjects[i].subject,
                subjects[i].score,
                subjects[i].grade);
        total += subjects[i].grade;
    }
    double average = (double)total / count;
    fprintf(file, "Average Grade: %.2f\n", average);
    fclose(file);
}