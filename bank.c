// Created by Fouad Aoude 
// Copyright Fouad Aoude 2020

#include <stdio.h>
#include <conio.h>
//#include <curses.h>
#include <string.h>
#include <stdlib.h>

int displayMenu(int);
void login(char *, char *, int*, FILE *);
int userInterface(int *, char *, char *, FILE *);
void createAccount(char *, char *, int *, FILE *);
void deposit(char *, double *, FILE *);
void withdrawl(char *, double *, FILE *);
void checkAccountDetails(char *, char *, double *, FILE*);
void cls();

int main(){
    int menuOption, i, *loginPtr=0;
    FILE *accountDetails;
    char username[30], password[30];
    char *usernamePtr, *passwordPtr;    

    usernamePtr = username;
    passwordPtr = password;

    do{
        if(loginPtr){
            userInterface(loginPtr, &username, &password, accountDetails);
        }
        menuOption = displayMenu(menuOption);

        switch(menuOption){
            case 1:
                createAccount(&username, &password, loginPtr, accountDetails);
                break;
            case 2:
                login(&username, &password, loginPtr, accountDetails);
                break;
            case 3:
                break;
            default:
                printf("\nPlease select a valid option\n");
        }
    }while(menuOption != 3);
}// End main
void cls(){
    system("cls");
}
int displayMenu(int menuOption){
    printf("\n\tAoude Bank\n");
    printf("\n(1) Create an Account\n");
    printf("\n(2) Login\n");
    printf("\n(3) Exit\n");
    printf("\nPlease Select an Option : \n\n");
    scanf("%d", &menuOption);

    return menuOption;
}// End displayMenu
void createAccount(char *usernamePtr, char *passwordPtr, int *loginPtr, FILE *accountDetails){
    int i, *userid=0;
    char username[30], password[30];


    system("cls");

    do{
        do{
            accountDetails = fopen("accounts.txt", "a+"); // Open file for writing

            printf("\nPlease Enter a username : \n");
            scanf("%s", &username);
            //printf("\nusernamePtr %s", *usernamePtr);
            printf("\nPlease Enter a Password : \n");
            scanf("%s", &password);

            if(strlen(username) < 5 && strlen(password) < 10){
                printf("\nBoth username and password are too short please try again\n");
            }
            else if(strlen(username) > 30 && strlen(password) > 30){
                printf("\nBoth username and password are too long please try again\n");
            }
            else if(strlen(username) < 5){
                do{
                    printf("\nUsername is too short try again\n");
                    printf("\nPlease Enter a username : \n");
                    scanf("%s", &username);
                    if(strlen(username) > 30){
                        printf("Username is too long");
                    }
                }while(strlen(username) < 5 && strlen(username) < 30);
            }
            else if(strlen(password) < 10){
                do{
                    printf("\nPassword is too short try again\n");
                    printf("\nPlease Enter a password : \n");
                    scanf("%s", &password);
                    if(strlen(password) > 30){
                        printf("Password is too long");
                    }
                }while(strlen(password) < 10 && strlen(password) < 30);
            }
        }while(strlen(username) < 5 || strlen(password) < 10);
    }while(strlen(password) < 10 || strlen(username) < 5);

    if(strlen(username) >= 5 && strlen(password) >= 10 && strlen(username) < 30 && strlen(password) < 30){
            userid++;     
            strcpy(usernamePtr, username);
            strcpy(passwordPtr, password);
            //loginPtr = 1;
            fprintf(accountDetails,"Userid\t\tUsername\tPassword\n\n" "%d\t" "\t%s\t" "\t" "%s", userid, usernamePtr, passwordPtr);
            fclose(accountDetails);
            system("cls");            
            printf("\nRegistered Successfully.\n");            
    }
    else{
        printf("\nThere was an error registering your account please try again later.\n");
    }
    
    fclose(accountDetails);


} // End createAccount
void login(char *usernamePtr, char *passwordPtr, int *loginPtr, FILE *accountDetails){
    int counter=0, i;
    char userA[30], passA[30];
    
    system("cls");

    accountDetails = fopen("accounts.txt", "r");

    do{
        if(counter >= 4){   
            printf("\nToo many incorrect attempts try again later\n");
            break;
        }

        printf("\n\tLogin\n");
        printf("\nPlease enter your username : ");
        scanf("%s", &userA);
        printf("\nPlease enter your password : ");
        scanf("%s", &passA);

        counter = 0;
        for(i=0;i<20;i++){
            if(strcmp(usernamePtr, userA) == 0 && strcmp(passwordPtr, passA) == 0){     // Notes for 3/9/2020 this is where you left off finish validating the login form.
                loginPtr = 1;
            }
        }
                if(loginPtr){
                    system("cls");
                    printf("\n\nLogged in successfully\n\n");
                    userInterface(loginPtr, usernamePtr, passwordPtr, accountDetails);
                    break;                    
                }
                else{
                    printf("\n\nIncorrect username or password please try again\n\n");
                    loginPtr = 0;
                    counter++;
                }
    }while(loginPtr == 0 && counter >= 4 );
}// End login
int userInterface(int *loginPtr, char *usernamePtr, char *passwordPtr, FILE *accountDetails){
    int menuOption, userid=0;
    double accountBalance, *accountBalancePtr;

    accountBalancePtr = &accountBalance;

    do{
        printf("\n\tAoude Bank\n");
        printf("\n(1) Deposit\n");
        printf("\n(2) Withdrawl\n");
        printf("\n(3) Check Account Details\n");    // Notes for 3/10/2020 allow the file to indicate the username and password so you dont have to keep creating an account and continue working on the userinterface
        printf("\n(4) Log Out\n");
        printf("\nPlease Select an Option : \n\n");
        scanf("%d", &menuOption);

        switch(menuOption){
            case 1:
                cls();
                deposit(usernamePtr, accountBalancePtr, accountDetails);    // Work on the deposit function 3/11/2020
                break;
            case 2:
                cls();
                withdrawl(usernamePtr, accountBalancePtr, accountDetails);
                break;
            case 3:
                cls();
                checkAccountDetails(usernamePtr, passwordPtr, accountBalancePtr, accountDetails);
                break;
        }
    }while(menuOption != 4);
    if(menuOption == 4){
        cls();
        printf("\nLogged out Successfully\n");
        userid = 0;
        loginPtr = 0;
    }
    return 0;
}// End userInterface
void deposit(char *usernamePtr, double *accountBalancePtr, FILE *accountDetails){
    char choice;
    double deposit;
    double accountBalance;
    double deposits[50];

    do{
        printf("\nHow Much Would You Like to Deposit Today?\n$");
        scanf("%lf", &deposit);
        if(deposit > 10000){
            printf("\nPlease Come to The Bank to Deposit Anything Over 10,000\n");
        }
        else if(deposit < 0){
            printf("\nInvalid Amount Please Try Again.\n");
            cls();
        }
        else{
            *accountBalancePtr += deposit;
            printf("\nNew Balance : $%.2lf\n", *accountBalancePtr);
        }
        printf("\nWould You Like to Make Another Deposit? (Y/N) ");
        scanf("\n%c", &choice);
        cls();
    }while(choice != 'n' && choice != 'N');
}// End deposit
void withdrawl(char *usernamePtr, double *accountBalancePtr, FILE *accountDetails){
    int i;
    char choice;
    double withdrawl, *withdrawlPtr;

    do{
        printf("\nBalance = $%.2lf\n", *accountBalancePtr);
        if(accountBalancePtr <= 0){
            printf("\nInsufficient Funds\n");
            break;
        }
        printf("\nHow Much Would You Like to Withdrawl Today?\n$");
        scanf("%lf", &withdrawl);
        if(withdrawl > *accountBalancePtr){
            printf("\nInvalid Amount Please Try Again.\n");
        }
        else if(withdrawl < 0){
            printf("\nInvalid Amount Please Try Again.\n");
        }
        else if(withdrawl > 10000){
            printf("\nPlease Come to The Bank to Withdrawl Anything Over 10,000\n");
        }
        else{
            *accountBalancePtr -= withdrawl;
            printf("\nNew Balance : $%.2lf\n", *accountBalancePtr);
        }
        printf("\nWould You Like to Make Another Withdrawl? (Y/N) ");
        scanf("\n%c", &choice);
        cls();
    }while(choice != 'n' && choice != 'N');
}
void allWithdrawls(){
    
}
void checkAccountDetails(char *usernamePtr, char *passwordPtr, double *accountBalancePtr, FILE *accountDetails){
    int choice, i, accountNumber[10];
    char hiddenPassword;
    char passA[30];

    cls();
    for(i=0;i<10;i++){
        accountNumber[i] = rand();
    }

    do{
        printf("Hello %s What Would You Like to Check Today?\n\n", usernamePtr);
        printf("(1) Check Account Balance\n");
        printf("\n(2) Check Account Settings\n");
        printf("\n(3) Change Password\n");
        printf("\n(4) Return to Previous Menu\n");
        scanf("%d", &choice);

        if(choice == 1){
            cls();
            printf("\nYour Current Balance is $%.2lf\n", *accountBalancePtr);
            printf("\nPress Enter to Return to Previous Menu\n\n");
            getch();
            cls();
        }
        if(choice == 2){
            cls();
            printf("\nUsername\t%s", usernamePtr);
            printf("\n\nAccount Number\t%d", accountNumber);
            printf("\n\nPress Enter to Return to Previous Menu\n\n");
            getch();
            cls();
        }
        if(choice == 3){
            cls();
            printf("\nEnter Current Password ");
            scanf("%s", &passA);
            if(strcmp(passA, passwordPtr)==0){
                printf("\nEnter New Password ");
                scanf("%s", &passA);
                do{
                    if(strlen(passA) < 10){
                        printf("\nPassword is Too Short Try Again\n");                        
                        scanf("%s", &passA);
                    }
                    if(strlen(passA) > 30){
                        printf("\nPassword is Too Long Try Again\n");
                        scanf("%s", &passA);
                    }
                    if(strlen(passA) >= 10 && strlen(passA) < 30){
                        strcpy(passwordPtr, passA);
                        cls();
                        printf("\nPassword Has Been Updated\n\n");
                    }
                }while(strlen(passA) < 10 && strlen(passA) < 30);
            }
            else{
                printf("\nIncorrect Password\n");
            }
        }
    }while(choice != 4);
}