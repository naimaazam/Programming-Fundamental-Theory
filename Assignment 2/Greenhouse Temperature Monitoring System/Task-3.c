#include <stdio.h>
void input(int a[50][50], int s, int h){
    int i, j;
    for(i = 0; i < s; i++){
        printf("\nEnter readings for Sensor %d:\n", i + 1);
        for(j = 0; j < h; j++){
            printf("Enter temperature for hour %d: ", j + 1);
            scanf("%d", &a[i][j]);
        }
    }
}

void analysis(int a[50][50], int s, int h){
    int i, high, low;
    int total = 0;
    int critical = 0, warning = 0;
    int streak = 0, maxstreak = 0;
    float avg;
    high = a[s][0];
    low = a[s][0];
    for(i = 0; i < h; i++){
        total = total + a[s][i];
        if(a[s][i] > high){
            high = a[s][i];
        }
        if(a[s][i] < low){
            low = a[s][i];
        }
        if(a[s][i] >= 40){
            critical++;
        }
        else if(a[s][i] >= 35 && a[s][i] <= 39){
            warning++;
        }
        if(a[s][i] >= 35){
            streak++;
            if(streak > maxstreak){
                maxstreak = streak;
            }
        }
        else{
            streak = 0;
        }
    }
    avg = (float)total / h;
    printf("Total temperature = %d\n", total);
    printf("Average temperature = %.2f\n", avg);
    printf("Highest temperature = %d\n", high);
    printf("Lowest temperature = %d\n", low);
    printf("Critical readings = %d\n", critical);
    printf("Warning readings = %d\n", warning);
    printf("Longest streak = %d hours\n", maxstreak);
}
int highestaverage(int a[50][50], int s, int h){
    int i, j, total;
    float avg;
    float maxavg = -999;
    int sensor = 0;
    for(i = 0; i < s; i++){
        total = 0;
        for(j = 0; j < h; j++){
            total = total + a[i][j];
        }
        avg = (float)total / h;
        if(avg > maxavg){
            maxavg = avg;
            sensor = i;
        }
    }
    return sensor;
}

int main(){
    int a[50][50];
    int s, h, high, low;
    int total = 0;
    float avg;
    printf("Enter number of sensors: ");
    scanf("%d", &s);
    printf("Enter number of hourly readings: ");
    scanf("%d", &h);
    input(a, s, h);
    for(i = 0; i < s; i++){
        analysis(a, i, h);
    }
    sensor = highestaverage(a, s, h);
    total = 0;
    for(i = 0; i < h; i++){
        total = total + a[sensor][i];
    }
    avg = (float)total / h;
    printf("Sensor with highest average temperature = %d\n", sensor + 1);
    printf("Highest average temperature = %.2f C\n", avg);
    return 0;
}
