#include <stdio.h>

/*
* Currently CEG2170 Template
* See Makefile for what is happening in background for "make run"
*/

int main () {
    
    //lets make an input checker
   char letter;
   int rating;

   printf("Would you like to run my program?\n");
   letter = getchar();

    while(letter =='y'){
        printf("How are you today on a scale of 1 to 10?\n")
        scanf("%d", &rating);
        if (rating > 1 && rating < 5){
            printf("You need a hug!\n");
        } else if (rating >= 5 && rating < 8){
            printf("Candy!\n");
        } else if(rating >= 8 && rating < 10){
            printf("Yay!\n");
        } else {
            printf("You are out of scope!\n")
        }

    }

    printf("You should talk with your prof!\n")

    return 0;
}