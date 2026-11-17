/* Programmer: Naima Azam
   Roll no: 26K-2504
   Description: Cinema Hall Seat Booking Management System 
*/
#include <stdio.h>
main(){
	int row,col,i,j,k,middle;
	int available,total=0;
	
	printf("Enter the number of Rows:\n");
	scanf("%d", &row);
	
	printf("Enter the number of seats in each Row:\n");
	scanf("%d", &col);
	
	printf(" Enter the current status 0:available  1:filled ");
    int seats[row][col];
	for(i=0; i<row;i++){
			for(j=0; j<col;j++){
			    scanf("%d \n" , &seats[i][j]);
			}
		}
		
	for(i=0; i<row;i++){
		 printf("Row %d: ", i);
			for(j=0; j<col;j++){
			    if (seats[i][j]==0){
				printf("_");
			    }
			    else
			    printf("X");
	        }	
    }
    
     for (i=0; i<row;i++){
        available = 0;
		for (j = 0; j < col; j++){
            if (seats[i][j] == 0){
                available=available+1;
            }
        }
		printf("There are %d seats available in Row %d\n",available,i);
		total = total + available;
    }
    printf("Input the number of customers who want to sit together:\n");
    scanf("%d",&k);
    middle=row/2;
    
    
}
