#include <stdio.h>

int main()//
{
    //Input
    float busprice, taxiprice, money;
    int choice;

    printf("Enter price of bus:");
    scanf("%f",&busprice);
    printf("Enter price of taxi:");
    scanf("%f",&taxiprice);
    printf("How much money you have:");
    scanf("%f",&money);

    //Loop
    while (money >= busprice || money >= taxiprice) {

        printf("\nYou have %.2f euros left.\n", money);
        printf("Do you want to take\n");
        printf("1) bus (%.2f euros)\n", busprice);
        printf("2) taxi (%.2f euros)\n", taxiprice);
        printf("Enter your selection: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("You chose bus.\n");
            if (money >= busprice) {
                money -= busprice;
                printf("You have %.2f euros left.\n", money);
            } else {
                printf("You don’t have enough money for bus.\n");
            }
        }
        else if (choice == 2) {
            printf("You chose taxi.\n");
            if (money >= taxiprice) {
                money -= taxiprice;
                printf("You have %.2f euros left.\n", money);
            } else {
                printf("You dont have enough money for taxi.\n");
            }
        }
    }
    printf("You need to walk bye\n");
    return 0;
}