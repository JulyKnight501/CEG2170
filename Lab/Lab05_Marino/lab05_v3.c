#include <stdio.h>
#include <stdlib.h>


void welcome_screen();

// list of funtions and ints used through out the program
void man_calc();
void add_man(float, float);
void sub_man(float, float);
void mult_man(float, float);
void div_man(float, float);
void mod_man(float, float);

// list of funtions and ints used through out the program
void auto_calc();
void add_auto(float, float, float *);
void sub_auto(float, float, float *);
void mult_auto(float, float, float *);
void div_auto(float, float, float *);
void mod_auto(float, float, float *);




int main(void){
    
    welcome_screen();
    char mode = getchar();
    fflush(stdin);

    switch (mode){
        case 'm':
            man_calc();
            break;

        case 'a':
            auto_calc();
            break;
    }

    return 0;
}

/* 
*   man_calc funtion. 
*   Displays codes for mathmatical calculation.
*   Run check to see if a valid input. 
*   Then goes through if staesments depending on calculation type.
*/

void man_calc(){

    // Prints out the intro and key to use the calculator
    printf("Ready for some calculations?\nPlease see key below to get started!\n");
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
            add_man(num1, num2);
            break;

            case 's':
            sub_man(num1, num2);
            break;

            case 'm':
            mult_man(num1, num2);
            break;
        
            case 'd':
            div_man(num1, num2);
            break;

            case 'o':
            mod_man(num1, num2);
            break;
        }

        // asks is user would like to run another calculation
        printf("Would you like to make another calculation?(y/n):\n");
        ans = getchar();
        fflush(stdin);
    } 

    printf("Thank you for using the calculator!\n");

    return;
}


//Function for addition of numbers
void add_man(float num1, float num2){
    float ans_add = num1 + num2;
    printf("%.2f + %.2f = %.2f\n", num1, num2, ans_add);
    return;
}

// Funtion for subtraction of numbers
void sub_man(float num1, float num2){
    float ans_sub = num1 - num2;
    printf("%.2f - %.2f = %.2f\n", num1, num2, ans_sub);
    return;
}

// Function for multiplication of numbers
void mult_man(float num1, float num2){
    float ans_mult = num1 * num2;
    printf("%.2f * %.2f = %.2f\n", num1, num2, ans_mult);
    return;
}

// Function for divion of numbers.
void div_man(float num1, float num2){
    float ans_div = num1 / num2;
    printf("%.2f / %.2f = %.2f\n", num1, num2, ans_div);
    return;
}

// Funtion for modulo of numbers
void mod_man(float num1, float num2){
    int ans_mod = (int)num1 % (int)num2;
    printf("%.2f mod %.2f leaves a remainder of %d\n", num1, num2, ans_mod);
    return;
}




// Auto Calc

void auto_calc(){

    //Checking input file:
    printf("To make sure the automatic calculator works correctly please ensure it follows the following guildlines:\n");
    printf("\t1. The input file name is 'input.txt'\n");
    printf("\t2. The input file is in the same directory as the program.\n");
    printf("\t3. The data follows the following format:\n");
    printf("\t  a. Uses 'a', 's', 'm', 'd', or 'o' for a mathmatic operation.\n");
    printf("\t  b. Text is outlined as: 'operation' 'space' 'first number' 'space' 'second number'\n\n");
    printf("Does your input.txt mile meet the above criteria? (y/n):\n");
    char auto_runner;
    auto_runner = getchar();
    fflush(stdin);

    // Set points for file names
    FILE *inputp;
    FILE *outputp;
        
    // opening file input fil in read mode and output file in write mode.
    inputp = fopen("input.txt", "r");
    outputp = fopen("output.txt", "w");
        
    if(auto_runner == 'y'){
            
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

        
            // If else ladder to determain which function to use based off operationmatical calculation shown
            switch (operation){
                case 'a':
                add_auto(num1, num2, resultp);
                break;

                case 's':
                sub_auto(num1, num2, resultp);
                break;
                
                case 'm':
                mult_auto(num1, num2, resultp);
                break;
            
                case 'd':
                div_auto(num1, num2, resultp);
                break;

                case 'o':
                mod_auto(num1, num2, resultp);
                break;
            }

            fprintf(outputp, "%.2f\n", result);
            
            //printf("# TEST # operation = %c\tnum1 = %.2f\tnum2 = %.2f\tresult =%.2f\n", operation, num1, num2, result);
        
        } 
    
        printf("Your calculations are recored in 'output.txt' that can be found in the directory.\n");
        printf("Thank you for using the calculator!\n");
        
    
        fprintf(outputp, "Thank you for using the calculator!\n");
    } else {
        printf("Please reformat the file and run the program again when ready.\n");
        printf("Thanks you!\n");
    }

    fclose(inputp);
    fclose(outputp);
    return;
}


//Function for addition of numbers
void add_auto(float num1, float num2, float *resultp){
    *resultp = num1 + num2;
    return;
}

// Funtion for subtraction of numbers
void sub_auto(float num1, float num2, float *resultp){
    *resultp = num1 - num2;
    return;
}

// Function for multiplication of numbers
void mult_auto(float num1, float num2, float *resultp){
    *resultp = num1 * num2;
    return;
}

// Function for divion of numbers.
void div_auto(float num1, float num2, float *resultp){
    *resultp = num1 / num2;
    return;
}


// Funtion for modulo of numbers
void mod_auto(float num1, float num2, float *resultp){
    *resultp = (int)num1 % (int)num2;
    return;
}

void welcome_screen(){
    printf(" # # # # # # # # # # # # # # # # # # # # # # # # # # \n");                                           
    printf("#     _ _ _ _____ __    _____ _____ _____ _____     #\n");
    printf("#    | | | |   __|  |  |     |     |     |   __|    #\n");
    printf("#    | | | |   __|  |__|   --|  |  | | | |   __|    #\n");
    printf("#    |_____|_____|_____|_____|_____|_|_|_|_____|    #\n");
    printf("#                                                   #\n");
    printf("#          This calculator has two modes:           #\n");
    printf("#                                                   #\n");
    printf("#        Manual                 Automatic           #\n");
    printf("#         'm'                      'a'              #\n");
    printf("#                                                   #\n");
    printf("#  Please select one of the options and hit 'Enter' #\n");
    printf("#                                                   #\n");
    printf(" # # # # # # # # # # # # # # # # # # # # # # # # # # \n");
    return;
}