#include <stdio.h>
int getValidDays(){
    int days;
    printf("Enter number of festival days (1-7): ");
    scanf("%d", &days);
    while(days < 1 || days > 7){
        printf("Invalid days! Enter again: ");
        scanf("%d", &days);
    }
    return days;
}
float calculateDailySales(int dayNumber){
    int orders, i;
    float amount, total = 0;
    float avg, high;
    printf("\nEnter number of orders for Day %d: ", dayNumber);
    scanf("%d", &orders);
    for(i = 1; i <= orders; i++){
        printf("Enter amount of order %d: ", i);
        scanf("%f", &amount);
        while(amount <= 0){
            printf("Invalid amount! Enter again: ");
            scanf("%f", &amount);
        }
        total = total + amount;
        if(i == 1){
            high = amount;
        }
        if(amount > high){
            high = amount;
        }
    }
    avg = total / orders;
    printf("Total sales = Rs. %.2f\n", total);
    printf("Average order amount = Rs. %.2f\n", avg);
    printf("Highest order amount = Rs. %.2f\n", high);
    return total;
}

int findHighestSalesDay(float dailySales[], int numberOfDays){
    int i;
    int day = 1;
    float high = dailySales[0];
    for(i = 1; i < numberOfDays; i++){
        if(dailySales[i] > high){
            high = dailySales[i];
            day = i + 1;
        }
    }
        return day;
}

void displayBarChart(float dailySales[], int numberOfDays){
    int i, j;
    int stars;
    for(i = 0; i < numberOfDays; i++){
        stars = dailySales[i] / 100;
        printf("Day %d: ", i + 1);
        for(j = 1; j <= stars; j++){
            printf("*");
        }
        printf("\n");
    }
}

int main(){
    int days, i;
    int highDay;
    float dailySales[7];
    float totalFestivalSales = 0;
    days = getValidDays();
    for(i = 0; i < days; i++){
        dailySales[i] = calculateDailySales(i + 1);
        totalFestivalSales = totalFestivalSales + dailySales[i];
    }
    highDay = findHighestSalesDay(dailySales, days);
    printf("Total festival sales = Rs. %.2f\n", totalFestivalSales);
    printf("Day with highest sales = Day %d\n", highDay);
    printf("Highest daily sales = Rs. %.2f\n", dailySales[highDay - 1]);
    displayBarChart(dailySales, days);
    return 0;
}
