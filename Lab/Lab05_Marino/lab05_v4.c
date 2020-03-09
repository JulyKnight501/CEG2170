#include <stdio.h>
#include <stdlib.h>




// Functions needed for manual calculator
void man_calc(float, float, float, float *);
void add_man(float, float, float *);
void sub_man(float, float, float *);
void mult_man(float, float, float *);
void div_man(float, float, float *);
void mod_man(float, float, float *);

// // Functtions needed for the automatic calculator
// void auto_calc(float, float, float *);
// void add_auto(float, float, float *);
// void sub_auto(float, float, float *);
// void mult_auto(float, float, float *);
// void div_auto(float, float, float *);
// void mod_auto(float, float, float *);
void welcome_screen();



int main(){
    
    welcome_screen();
    char mode = getchar();
    fflush(stdin);

    // Sets variables for input numbers
    float num1 = 0;
    float num2 = 0;
    float result = 0;

    //set pointer for result that the calculator functions can use
    float *resultp;
    resultp = &result;


    switch (mode){
        case 'm':
            man_calc(num1, num2, result, resultp);
            break;

        case 'a':
            //auto_calc(num1, num2, result, resultp);
            break;
    }


    return 0;
}


/*  man_calc funtion. 
*   Displays codes for mathmatical calculation.
*   Run check to see if a valid input. 
*   Then goes through if staesments depending on calculation type.
*/

void man_calc(float num1, float num2, float result, float *resultp){


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
        
        // Asks and stores uses numbers used for calculation
        printf("Enter first number:\n");
        scanf("%f", &num1);
        printf("Enter second number:\n");
        scanf("%f", &num2);
        fflush(stdin);

        // Switch ... to determain which function to use based off mathmatical calculation shown
        switch (math){
            case 'a':
            add_man(num1, num2, resultp);
            printf("%.2f + %.2f = %.2f\n", num1, num2, result);
            break;

            // case 's':
            // sub_man(num1, num2, result, resultp);
            // printf("%.2f - %.2f = %.2f\n", num1, num2, result);
            // break;

            // case 'm':
            // mult_man(num1, num2, result, resultp);
            // printf("%.2f * %.2f = %.2f\n", num1, num2, result);
            // break;
        
            // case 'd':
            // div_man(num1, num2, result, resultp);
            // printf("%.2f / %.2f = %.2f\n", num1, num2, result);
            // break;

            // case 'o':
            // mod_man(num1, num2, result, resultp);
            // printf("%.2f mod %.2f leaves a remainder of %f\n", num1, num2, result);
            // break;
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
void add_man(float num1, float num2, float *resultp){
    *resultp = num1 + num2;
    return;
}

// // Funtion for subtraction of numbers
// void sub_man(float num1, float num2, float *resultp){
//     *resultp = num1 - num2;
//     return;
// }

// // Function for multiplication of numbers
// void mult_man(float num1, float num2, float *resultp){
//     *resultp = num1 * num2;
//     return;
// }

// // Function for divion of numbers.
// void div_man(float num1, float num2, float *resultp){
//     *resultp = num1 / num2;
//     return;
// }


// // Funtion for modulo of numbers
// void mod_man(float num1, float num2, float *resultp){
//     *resultp = (int)num1 % (int)num2;
//     return;
// }





// // Auto Calc

// void auto_calc(){

//     // Set points for file names
//     FILE *inputp;
//     FILE *outputp;
    
//     // opening file input fil in read mode and output file in write mode.
//     inputp = fopen("input.txt", "r");
//     outputp = fopen("output.txt", "w");
    
//     // Sets variables for input numbers
//     char operation = 'n';
    
 
//     //While loop allowing for multiple calculations in a row dependant on user input
//     //scan a line of the file for input
//         // EOF = END OF FILE
//     while(fscanf(inputp, " %c %f %f\n", &operation, &num1, &num2) != EOF){

//         // Shows number variable values
//         //printf("Num1 = %f\nNum2 = %f\n", num1, num2);
        
        

//         // If else ladder to determain which function to use based off operationmatical calculation shown
//         switch (operation){
//             case 'a':
//             add_auto(num1, num2, resultp);
//             break;

//             case 's':
//             sub_auto(num1, num2, resultp);
//             break;
            
//             case 'm':
//             mult_auto(num1, num2, resultp);
//             break;
        
//             case 'd':
//             div_auto(num1, num2, resultp);
//             break;

//             case 'o':
//             mod_auto(num1, num2, resultp);
//             break;
//         }

//         fprintf(outputp, "%.2f\n", result);
        
//         printf("# TEST # operation = %c\tnum1 = %.2f\tnum2 = %.2f\tresult =%.2f\n", operation, num1, num2, result);
    
//     } 

    
//     printf("Thank you for using the calculator!\n");
    
//     fprintf(outputp, "Thank you for using the calculator!\n");

//     fclose(inputp);
//     fclose(outputp);
//     return;
// }




// //Function for addition of numbers
// void add_auto(float num1, float num2, float *resultp){
//     *resultp = num1 + num2;
//     return;
// }

// // Funtion for subtraction of numbers
// void sub_auto(float num1, float num2, float *resultp){
//     *resultp = num1 - num2;
//     return;
// }

// // Function for multiplication of numbers
// void mult_auto(float num1, float num2, float *resultp){
//     *resultp = num1 * num2;
//     return;
// }

// // Function for divion of numbers.
// void div_auto(float num1, float num2, float *resultp){
//     *resultp = num1 / num2;
//     return;
// }


// // Funtion for modulo of numbers
// void mod_auto(float num1, float num2, float *resultp){
//     *resultp = (int)num1 % (int)num2;
//     return;
// }


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