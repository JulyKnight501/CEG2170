#include <stdio.h>
#include <stdlib.h>
/*
*
*/

// list of funtions and ints used through out the program
void add_nums(float, float);
void subtract_nums(float, float);
void mult_nums(float, float);
void div_nums(float, float);
void mod_nums(float, float);


/* 
*   Main Funtion. 
*   Welcomes user and displays codes for mathmatical calculation.
*   Run check to see if a valid input. 
*   Then goes through if staesments depending on calculation type.
*/

int main() {

    // Set points for file names
    // FILE *inputp;
    // FILE *outputp;

    // opening file input fil in read mode and output file in write mode.
    // inputp = fopen("input.txt","n");
    // outputp = fopen("output.txt","w");


    // Prints out the intro and key to use the calculator
    printf("Ready for some calculations?\n Please see key below to get started!\n");
    printf("a - addition\ns - subtraction\nm - multiplication\nd - division\no - modelo\n\n");


    //scan a line of the file for input
    // EOF = END OF FILE
    //while(fscanf(inputp, "%d %f %f\n",  math, &num1, &num2) != EOF){
      //  fprintf(outputp, "%d %f %f\n", math, &num1, &num2);
    //}

 
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
        
        // Sets variables for input numbers
        float num1;
        float num2;

        // Asks and stores uses numbers used for calculation
        printf("Enter first number:\n");
        scanf("%f", &num1);
        printf("Enter second number:\n");
        scanf("%f", &num2);
        fflush(stdin);

        // Shows number variable values
        //printf("Num1 = %f\nNum2 = %f\n", num1, num2);

        // If else ladder to determain which function to use based off mathmatical calculation shown
        switch (math){
            case 'a':
            add_nums(num1, num2);
            break;

            case 's':
            subtract_nums(num1, num2);
            break;

            case 'm':
            mult_nums(num1, num2);
            break;
        
            case 'd':
            div_nums(num1, num2);
            break;

            case 'o':
            mod_nums(num1, num2);
            break;
        }

    
        // asks is user would like to run another calculation
        printf("Would you like to make another calculation?(y/n):\n");
        ans = getchar();
        fflush(stdin);
    } 

    printf("Thank you for using the calculator!\n");

    return 0;
}




//Function for addition of numbers
void add_nums(float num1, float num2){
    float ans_add = num1 + num2;
    printf("%.2f + %.2f = %.2f\n", num1, num2, ans_add);
    return;
}

// Funtion for subtraction of numbers
void subtract_nums(float num1, float num2){
    float ans_sub = num1 - num2;
    printf("%.2f - %.2f = %.2f\n", num1, num2, ans_sub);
    return;
}

// Function for multiplication of numbers
void mult_nums(float num1, float num2){
    float ans_mult = num1 * num2;
    printf("%.2f * %.2f = %.2f\n", num1, num2, ans_mult);
    return;
}

// Function for divion of numbers.
void div_nums(float num1, float num2){
    float ans_div = num1 / num2;
    printf("%.2f / %.2f = %.2f\n", num1, num2, ans_div);
    return;
}


// Funtion for modulo of numbers
void mod_nums(float num1, float num2){
    int ans_mod = (int)num1 % (int)num2;
    printf("%.2f mod %.2f leaves a remainder of %d\n", num1, num2, ans_mod);
    return;
}