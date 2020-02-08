#include <stdio.h>
#include <stdlib.h>
/*
*
*/

// list of funtions and ints used through out the program
int add_nums();
int subtract_nums();
int mult_nums();
int div_nums();
int mod_nums();

float num1;
float num2;

/* 
*   Main Funtion. 
*   Welcomes user and displays codes for mathmatical calculation.
*   Run check to see if a valid input. 
*   Then goes through if staesments depending on calculation type.
*   
*/

int main () {

    // Prints out the intro and key to use the calculator
    printf("Ready for some calculations?\n Please see key below to get started!\n");
    printf("a - addition\ns - subtraction\nm - multiplication\nd - division\no - modelo\n\n");

    // While loop allowing for multiple calculations in a row dependant on user input
    char ans = 'y';
    while(ans == 'y'){

        // While loop to test for the valid input of [a,s,m,d,o]
        char math = 'n';
        while(math != 'a' && math != 's' && math != 'm' && math != 'd' && math != 'o'){
        printf("Enter a mathmatical operation [a, s, m, d, o]:\n");
        math = getchar();
        fflush(stdin);

            // Invalid input checker
            if(math != 'a' && math != 's' && math != 'm' && math != 'd' && math != 'o'){
                printf("\nInvalid input. Please try again again:\n");
                math = 'n';
            }
        }
        
        
        // Asks and stores uses numbers used for calculation
        printf("Enter first number:\n");
        scanf("%f", &num1);
        printf("Enter second number:\n");
        scanf("%f", &num2);

        // Shows number variable values
        printf("Num1 = %f\nNum2 = %f\n", num1, num2);

        // If else ladder to determain which function to use based off mathmatical calculation shown
        if(math == 'a'){
            add_nums();
        } else if ( math == 's'){
            subtract_nums();
        } else if(math == 'm'){
            mult_nums();
        } else if(math == 'd'){
            div_nums();
        } else if(math == 'o'){
            mod_nums();
        }

        // asks is user would like to run another calculationn
        fflush(stdin);
        printf("Would you like to make another calculation?(y/n):\n");
        ans = getchar();
        fflush(stdin);
        
    }

    printf("Thank you for using the calculator!\n");

    return 0;
}




//Function for addition of numbers
int add_nums(){
    float ans_add = num1 + num2;
    printf("%f + %f = %f\n", num1, num2, ans_add);
    return 0;
}

// Funtion for subtraction of numbers
int subtract_nums(){
    float ans_sub = num1 - num2;
    printf("%f - %f = %f\n", num1, num2, ans_sub);
    return 0;
}

// Function for multiplication of numbers
int mult_nums(){
    float ans_mult = num1 * num2;
    printf("%f * %f = %f\n", num1, num2, ans_mult);
    return 0;
}

// Function for divion of numbers.
int div_nums(){
    float ans_div = num1 / num2;
    printf("%f / %f = %f\n", num1, num2, ans_div);
    return 0;
}


// Funtion for modulo of numbers
int mod_nums(){
    //float ans_mod = num1 % num2;
    //printf("%f % %f = %f\n", num1, num2, ans_mod);
   // return 0;
}
