#include <stdio.h>

/*  This is a simple guessing game
*   User is asked to guess a number between 1 and 100
*   If correct the game ends. 
*   If wrong the user is told they are incorrect
*/


int main () {

    int a = 57;
    int g;

    printf("PLease pick a number between 1 and 100:\n");
    scanf("%d", &g);

    if (g == a){
        printf("You are correct! :-)\n");
    } else if (g <= 0 || g >= 100){
        printf("You are out of bounds.\n");
    } else if ((g = a + 5) || (g = a - 5)){
        printf("You are getting warmer.\n");
    } else {
        printf("You are getting colder.\n");
    }


    return 0;
}