#include <stdio.h>
#include <stdlib.h>

// list of funtions and ints used through out the program
void add_nums(float, float, float *);
void subtract_nums(float, float, float *);
void mult_nums(float, float, float *);
void div_nums(float, float, float *);
void mod_nums(float, float, float *);

/* 
*   Main Funtion. 
*   Welcomes user and displays codes for operationmatical calculation.
*   Run check to see if a valid input. 
*   Then goes through if staesments depending on calculation type.
*/

int main() {

    // Set points for file names
    FILE *inputp;
    FILE *outputp;
    
    // opening file input fil in read mode and output file in write mode.
    inputp = fopen("input.txt", "r");
    outputp = fopen("output.txt", "w");
    
    // Sets variables for input numbers
    char operation = 'n';
    float num1;
    float num2;
    float result;

    //set pointer for result that the functions can use
    float *resultp;
    resultp = &result;
 

    //While loop allowing for multiple calculations in a row dependant on user input
    //scan a line of the file for input
        // EOF = END OF FILE
    while(fscanf(inputp, " %c %f %f\n", &operation, &num1, &num2) != EOF){

        // Shows number variable values
        //printf("Num1 = %f\nNum2 = %f\n", num1, num2);
        
        

        // If else ladder to determain which function to use based off operationmatical calculation shown
        switch (operation){
            case 'a':
            add_nums(num1, num2, resultp);
            break;

            case 's':
            subtract_nums(num1, num2, resultp);
            break;
            
            case 'm':
            mult_nums(num1, num2, resultp);
            break;
        
            case 'd':
            div_nums(num1, num2, resultp);
            break;

            case 'o':
            mod_nums(num1, num2, resultp);
            break;
        }

        fprintf(outputp, "%.2f\n", result);
        
        printf("# TEST # operation = %c\tnum1 = %.2f\tnum2 = %.2f\tresult =%.2f\n", operation, num1, num2, result);
    
    } 

    
    printf("Thank you for using the calculator!\n");
    
    fprintf(outputp, "Thank you for using the calculator!\n");

    fclose(inputp);
    fclose(outputp);
    return 0;
}




//Function for addition of numbers
void add_nums(float num1, float num2, float *resultp){
    *resultp = num1 + num2;
    return;
}

// Funtion for subtraction of numbers
void subtract_nums(float num1, float num2, float *resultp){
    *resultp = num1 - num2;
    return;
}

// Function for multiplication of numbers
void mult_nums(float num1, float num2, float *resultp){
    *resultp = num1 * num2;
    return;
}

// Function for divion of numbers.
void div_nums(float num1, float num2, float *resultp){
    *resultp = num1 / num2;
    return;
}


// Funtion for modulo of numbers
void mod_nums(float num1, float num2, float *resultp){
    *resultp = (int)num1 % (int)num2;
    return;
}