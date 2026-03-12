#include <stdio.h>

int main(){
    float income[12];
    float tax[12];
    float tax_rate;
    float income_limit;
    float high_tax_rate;
    float total_income;
    float monthly_tax;
    float low_part;
    float high_part;
    int i;

    printf("Enter tax rate: ");
    scanf("%f", &tax_rate);

    printf("Enter income limit: ");
    scanf("%f", &income_limit);

    printf("Enter tax rate for income over the limit: ");
    scanf("%f", &high_tax_rate);

    tax_rate = tax_rate / 100;
    high_tax_rate = high_tax_rate / 100;

    for(i = 0; i < 12; i++){
        printf("Enter income for month %d: ", i + 1);
        scanf("%f", &income[i]);
    }
    total_income = 0;

    for(i = 0; i < 12; i++){
        monthly_tax = 0;

        if(total_income >= income_limit){
            monthly_tax = income[i] * high_tax_rate;
        }
        else if(total_income + income[i] > income_limit){
            low_part = income_limit - total_income;
            high_part = income[i] - low_part;
            monthly_tax = low_part * tax_rate + high_part * high_tax_rate;
        }
        else{
            monthly_tax = income[i] * tax_rate;
        }
        tax[i] = monthly_tax;
        total_income = total_income + income[i];
    }
    printf("%5s %10s %10s\n", "month", "income", "tax");

    for(i = 0; i < 12; i++){
        printf("%5d %10.2f %10.2f\n", i + 1, income[i], tax[i]);
    }
    return 0;
}