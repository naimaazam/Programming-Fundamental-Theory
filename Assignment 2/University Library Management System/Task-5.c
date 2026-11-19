#include <stdio.h>
#include <string.h>
void displayMenu(){
    printf("2. Display Available Books\n");
    printf("3. Borrow a Book\n");
    printf("4. Return a Book\n");
    printf("5. Display Member Record\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}
void registerMember(char name[], int *studentID, int *memberType){
    printf("\nEnter member name: ");
    scanf(" %49[^\n]", name);
    printf("Enter Student ID: ");
    scanf("%d", studentID);
    printf("1. Student\n");
    printf("2. Faculty\n");
    printf("Enter type: ");
    scanf("%d", memberType);
    while(*memberType != 1 && *memberType != 2){
        printf("Invalid membership type! Enter again: ");
        scanf("%d", memberType);
    }
    printf("\nMember registered successfully!\n");
}

void displayBooks(int bookIDs[], char bookTitles[][50], int availableCopies[], int totalBooks){
    int i;
    for(i = 0; i < totalBooks; i++){
        printf("%d\t\t%-25s %d\n",
               bookIDs[i], bookTitles[i], availableCopies[i]);
    }
}

void borrowBook(int bookIDs[], char bookTitles[][50], int availableCopies[], int totalBooks, int borrowedBookIDs[], int *borrowedCount,
                int memberType){
    int id, i, found = 0;
    if(*borrowedCount >= 3){
        printf("\nYou cannot borrow more than 3 books!\n");
        return;
    }
    printf("\nEnter Book ID to borrow: ");
    scanf("%d", &id);
    for(i = 0; i < totalBooks; i++){
        if(bookIDs[i] == id){
            found = 1;
            break;
        }
    }
    if(found == 0){
        printf("\nInvalid Book ID!\n");
    }
    else if(availableCopies[i] == 0){
        printf("\nThis book is currently not available!\n");
    }
    else{
        borrowedBookIDs[*borrowedCount] = id;
        (*borrowedCount)++;
        availableCopies[i]--;
        printf("Book Name: %s\n", bookTitles[i]);
        if(memberType == 1){
            printf("Allowed borrowing period: 14 days\n");
        }
        else{
            printf("Allowed borrowing period: 30 days\n");
        }
    }
}
float returnBook(int bookIDs[], int availableCopies[],
                 int totalBooks, int borrowedBookIDs[],int *borrowedCount, int memberType, float *totalFine){
    int id, days, allowedDays;
    int i, j, found = 0;
    float fine = 0, payable = 0;
    char code[20];
    printf("\nEnter Book ID to return: ");
    scanf("%d", &id);
    for(i = 0; i < *borrowedCount; i++){
        if(borrowedBookIDs[i] == id){
            found = 1;
            break;
        }
    }
    if(found == 0){
        printf("\nYou have not borrowed this book!\n");
        return 0;
    }
    printf("Enter actual number of days book was kept: ");
    scanf("%d", &days);
    while(days <= 0){
        printf("Invalid days! Enter again: ");
        scanf("%d", &days);
    }
    if(memberType == 1){
        allowedDays = 14;
    }
    else{
        allowedDays = 30;
    }
    if(days > allowedDays){
        if(memberType == 1){
            fine = (days - allowedDays) * 20;
        }
        else{
            fine = (days - allowedDays) * 10;
        }
        printf("\nLate fine = Rs. %.2f\n", fine);
        printf("Enter membership code for 50%% waiver: ");
        scanf("%19s", code);
        if(strcmp(code, "LIB2026") == 0){
            payable = fine * 0.50;
            printf("Correct code! 50%% waiver applied.\n");
        }
        else{
            payable = fine;
            printf("Incorrect code! No waiver applied.\n");
        }
    }
    else{
        payable = 0;
        printf("\nBook returned on time. No fine!\n");
    }
    *totalFine = *totalFine + fine;
    for(i = 0; i < totalBooks; i++){
        if(bookIDs[i] == id){
            availableCopies[i]++;
            break;
        }
    }
    for(j = found - 1; j < *borrowedCount - 1; j++){
        borrowedBookIDs[j] = borrowedBookIDs[j + 1];
    }
    (*borrowedCount)--;
    printf("Fine payable for this return = Rs. %.2f\n", payable);
    return payable;
}

void displayMemberRecord(char name[], int studentID, int memberType, int borrowedBookIDs[],int borrowedCount, float totalFine,
                         float fineAfterWaiver){
    int i;
    printf("Member Name: %s\n", name);
    printf("Student ID: %d\n", studentID);
    if(memberType == 1){
        printf("Membership Type: Student\n");
    }
    else{
        printf("Membership Type: Faculty\n");
    }
    printf("\nCurrently Borrowed Books:\n");
    if(borrowedCount == 0){
        printf("No books currently borrowed.\n");
    }
    else{
        for(i = 0; i < borrowedCount; i++){
            printf("Book ID: %d\n", borrowedBookIDs[i]);
        }
    }
    printf("\nTotal fine before waiver = Rs. %.2f\n", totalFine);
    printf("Final fine payable = Rs. %.2f\n", fineAfterWaiver);
}
int main(){
    int bookIDs[5] = {101, 102, 103, 104, 105};
    char bookTitles[5][50] = {
        "C Programming",
        "Data Structures",
        "Computer Networks",
        "Database Systems",
        "Operating Systems"
    };
    int availableCopies[5] = {5, 4, 3, 6, 2};
    char name[50];
    int studentID = 0;
    int memberType = 0;
    int borrowedBookIDs[3];
    int borrowedCount = 0;
    int choice, registered = 0;
    float totalFine = 0;
    float fineAfterWaiver = 0;
    float currentFine;
    do{
        displayMenu();
        scanf("%d", &choice);
        switch(choice){
            case 1:
                if(registered == 1){
                    printf("\nMember is already registered!\n");
                }
                else{
                    registerMember(name, &studentID, &memberType);
                    registered = 1;
                }
                break;
            case 2:
                displayBooks(bookIDs, bookTitles,availableCopies, 5);
                break;
            case 3:
                if(registered == 0){
                    printf("\nPlease register first!\n");
                }
                else{
                    borrowBook(bookIDs, bookTitles,availableCopies, 5,borrowedBookIDs, &borrowedCount,memberType);
                }
                break;
            case 4:
                if(registered == 0){
                    printf("\nPlease register first!\n");
                }
                else{
                    currentFine = returnBook(bookIDs,
                                             availableCopies,5,borrowedBookIDs,&borrowedCount,memberType, &totalFine);
                                             fineAfterWaiver = fineAfterWaiver + currentFine;
                }
                break;
            case 5:
                if(registered == 0){
                    printf("\nNo member registered yet!\n");
                }
                else{
                    displayMemberRecord(name, studentID,memberType,borrowedBookIDs,borrowedCount,totalFine,fineAfterWaiver);
                }
                break;
            case 6:
                printf("\nThank you for using Library Management System!\n");
                break;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    } while(choice != 6);
    return 0;
}
