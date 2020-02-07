#include <stdio.h>
#include <stdlib.h>

/*
*   Age evaluation code with loop.
*   User is asked for an age to evaluate.
*   If stament ladder produces a result based off the age given
*   User is then asked if the would like to evaluate another age
*   If 'y' the loops runs again, If 'n' it breaks the loop and closes the program.
*   
*/

int main () {

    char ans = 'y'; // sets ans to y to begin the loop. Used at end of loop for user input 

    while(ans == 'y'){
        float age; // float age to store age being evaluated

        //Enter an age and store the int.
        printf("Enter an age you would like to evaluate: \n");
        scanf("%f", &age);
        fflush(stdin); // flushes buffer char of 'enter'

        // If statements for possible output based off age input
        if (age < 1){
            printf("Just a baby!\n");
        } else if (age >= 1 && age < 13){
            printf("Just a kid!\n");
        } else if (age >= 13 && age < 20){
            printf("Get off my lawn!\n");
        } else if (age >= 20){
            printf("You're getting old!\n");
        }
        

        char c = 'y';
        while(c == 'y'){
            // Asks user if they want to evaluate another age
            printf("Would you like to to enter another age? (y/n):\n"); 
            // Gets char from user input
            c = getchar();
            fflush(stdin);
           
        
            // Based off input if "n" the program ends
            // Issue arrises with the else if of other character
                // It prints its staement then ends program
                // want to go back and ask "...enter another age" again
            if(c == 'y'){
                ans = c;
                break;
            } else if(ans == 'n'){
                printf("Thank you for using the age evaluator.\n");
                break;
            } else if (ans != 'y' && ans != 'n'){
                printf("You have entered an invalid char.\n");
                c = 'y';
        
            }
        }
    }
    

    return 0;
}