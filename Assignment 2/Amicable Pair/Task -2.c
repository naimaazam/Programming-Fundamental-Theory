#include <stdio.h>
int sum(int num){
    int i, total = 0;
     for(i = 1; i <= num / 2; i++){
        if(num % i == 0){
            total = total + i;
        }
    }
return total;
}

int main(){
    int n, i, j;
    int sum1, sum2;
    int count = 0;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("\nAmicable pairs are:\n");
    for(i = 1; i <= n; i++){
        sum1 = sum(i);
        j = sum1;
        if(j > i && j <= n){
            sum2 = sum(j);
            if(sum2 == i && sum1 != i){
                printf("(%d, %d)\n", i, j);
                count++;
            }
        }
    }
    if(count == 0){
        printf("No amicable pairs found.\n");
    }
    else{
        printf("\nTotal number of pairs = %d", count);
    }
return 0;
}
