//
//  main.c
//  prac1
//
//  Created by Fouad Aoude on 1/15/20.
//  Copyright © 2020 Fouad Aoude. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int addition(choice)
{
    int addition_num1, addition_num2, addition_total;
    int addition_user_answer;
    int i, flag = 0;
    int addition_correct_counter=0, addition_incorrect_counter=0;
    
    srand(time(0));
    
addition_loop:
    for(i=0;i<5;i++)
    {
        if(flag==1)
        {
            break;
        }
        addition_num1 = rand() % 50;
        printf(" \n\t%d\n", addition_num1);
        for(i=0;i<5;i++)
        {
            addition_num2 = rand() % 50;
            addition_total = addition_num1 + addition_num2;
            printf("\t%d", addition_num2);
            printf(" +\n\t----\n\t");
            scanf("%d", &addition_user_answer);
            if(addition_user_answer == addition_total)
            {
                printf("\nCorrect! Remember to type 5000 to exit.");
                printf("\n");
                printf("Try another problem!\n");
                addition_correct_counter++;
                goto addition_loop;
            }
            if(addition_user_answer == 5000)
            {
                printf("\nYou have answered %d correct.",addition_correct_counter);
                printf("\nYou have answered %d incorrect.\n\n", addition_incorrect_counter);
                flag = 1;
                break;
            }
            else if(addition_user_answer != addition_total)
            {
                printf("\nIncorrect! the correct answer is : %d\n", addition_total);
                addition_incorrect_counter++;
                goto addition_loop;
            }
        }
    }
    
    return 0;
}
int subtraction(choice)
{
    int subtraction_num1, subtraction_num2, subtraction_total;
    int subtraction_user_answer;
    int subtraction_correct_counter=0, subtraction_incorrect_counter=0;
    int i, flag=0;
    
subtraction_loop:
    for(i=0;i<5;i++)
    {
        if(flag==1)
        {
            break;
        }
        subtraction_num1 = rand() % 50;
        printf(" \n %d\n", subtraction_num1);
        for(i=0;i<5;i++)
        {
            subtraction_num2 = rand() % 50;
            subtraction_total = subtraction_num1 - subtraction_num2;
            printf(" %d", subtraction_num2);
            printf(" -\n----\n ");
            scanf("%d", &subtraction_user_answer);
            if(subtraction_user_answer == subtraction_total)
            {
                printf("\nCorrect! Remember to type 5000 to exit.");
                printf("\n");
                printf("Try another problem!\n");
                subtraction_correct_counter++;
                goto subtraction_loop;
            }
            if(subtraction_user_answer == 5000)
            {
                printf("\nYou have answered %d correct.",subtraction_correct_counter);
                printf("\nYou have answered %d incorrect.\n\n", subtraction_incorrect_counter);
                flag=1;
                break;
            }
            else if(subtraction_user_answer != subtraction_total)
            {
                printf("\nIncorrect! the correct answer is : %d\n", subtraction_total);
                printf("Try another problem!\n");
                subtraction_incorrect_counter++;
                goto subtraction_loop;
            }
        }
    }
    return 0;
}
int multiplication(choice)
{
    int multi_num1, multi_num2, multi_total;
    int multi_user_answer;
    int multi_correct_counter=0,multi_incorrect_counter=0;
    int i, flag=0;
    
multi_loop:
    for(i=0;i<5;i++)
    {
        if(flag == 1)
        {
            break;
        }
        multi_num1 = rand() % 10;
        printf(" \n %d\n", multi_num1);
        for(i=0;i<5;i++)
        {
            multi_num2 = rand() % 10;
            multi_total = multi_num1 * multi_num2;
            printf(" %d", multi_num2);
            printf(" *\n----\n ");
            scanf("%d", &multi_user_answer);
            if(multi_user_answer == multi_total)
            {
                printf("\nCorrect! Remember to type 5000 to exit.");
                printf("\n");
                printf("Try another problem!\n");
                multi_correct_counter++;
                goto multi_loop;
            }
            if(multi_user_answer == 5000)
            {
                printf("\nYou have entered %d correct.\n",multi_correct_counter);
                printf("You have entered %d incorrect.\n\n",multi_incorrect_counter);
                flag=1;
                break;
            }
            else if(multi_user_answer != multi_total)
            {
                printf("\nIncorrect! the correct answer is : %d\n", multi_total);
                printf("Try another problem!\n");
                multi_incorrect_counter++;
                goto multi_loop;
            }
        }
    }
    return 0;
}
int mod(choice)
{
    // division needs work
    int mod_num1, mod_num2, mod_total;
    int mod_user_answer;
    int i, flag=0;
    int mod_correct_counter = 0;
    int mod_incorrect_counter = 0;
    
mod_loop:
    for(i=0;i<5;i++)
    {
        if(flag == 1)
        {
            break;
        }
        mod_num1 = rand() % 10;
        printf(" \n %d\n", mod_num1);
        for(i=0;i<5;i++)
        {
            mod_num2 = rand() % 10;
            mod_total = mod_num1 % mod_num2;
            printf(" %d", mod_num2);
            printf(" \n----\n ");
            scanf("%d", &mod_user_answer);
            if(mod_user_answer == mod_total)
            {
                printf("\nCorrect! Remember to type 5000 to exit.");
                printf("\n");
                printf("Try another problem!\n");
                mod_correct_counter++;
                goto mod_loop;
            }
            if(mod_user_answer == 5000)
            {
                printf("\nYou have answered %d correct.\n", mod_correct_counter);
                printf("You have answered %d incorrect.\n\n\n", mod_incorrect_counter);
                flag=1;
                break;
            }
            else if(mod_user_answer != mod_total)
            {
                printf("\nIncorrect! the correct answer is : %d\n", mod_total);
                printf("Try another problem!\n");
                mod_incorrect_counter++;
                goto mod_loop;
            }
        }
    }
    return 0;
}
int main(int args, char ** argv)
{
    unsigned short int choice;
    unsigned short int reset;
    printf("Welcome to the math calculator\n\n");
reset_main:
    printf("\n1. Addition");
    printf("\n2. Subtraction");
    printf("\n3. Multiplication");
    printf("\n4. Modulous");
    printf("\n\nPlease select a type : ");
    scanf("%hu", &choice);
    if(choice == 1)
    {
        addition(choice);
    }
    else if(choice == 2)
    {
        subtraction(choice);
    }
    else if(choice == 3)
    {
        multiplication(choice);
    }
    else if(choice == 4)
    {
        mod(choice);
    }
    printf("Press 1 to restart, 0 to exit. ");
    scanf("%d", &reset);
    if(reset == 1)
    {
        goto reset_main;
    }
    if(reset == 0)
    {
        printf("\n\n");
        exit(0);
    }
    printf("\n\n\n");
    return 0;
}
