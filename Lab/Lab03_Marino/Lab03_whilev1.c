#include <stdio.h>

/*
*   Age evaluation code with loop.
*   The following are the conditions:
*   If the person is 1 year old or less, they are an infant
*   Output “Just a baby!”
*   If the person is older than 1 year, but younger than 13 years, they are a child
*   Output “Just a kid!”
*   If the person is at least 13 years old, but less than 20 years old, they are a teenager
*   Output “Get off my lawn!”
*   If the person is at least 20 years old, they are an adult
*   Output “You’re getting old!”
*/

int main () {

    float age;

    //Enter an age and store the int.
    printf("Enter an age you would like to evaluate: \n");
    scanf("%f", &age);

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

    char ans; // Stores users answer to evaluating another age

    printf("Would you like to to enter another age? (y/n):\n"); // Asks user if they want to evaluate another age

    scanf("%c", &ans);

    printf("Your answer was: %c", ans);

    return 0;
}