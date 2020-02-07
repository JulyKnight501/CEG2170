#include <stdio.h>

#define MONTHS 6 // Global variable for number of months


/*
*   Info need to know:
*   Cutting callories by 500 a day, one person can loose 4lbs a month
*
*   Print out a graph of weight loss per month 
*/

int main () {

    int i; // storage for weight

    // Asks user for weight and stores in 'int i'
    printf("Please enter your current weight: \n");
    scanf("%d", &i);

    //Prints our the heading for weight per month chart
    printf("\nAt your current weight of %d, let's look at your numbers over the next %d months:\n", i, MONTHS);
    printf("Month   Weight(lbs)\n");
    printf("-------------------\n");
     
    //Prints  Table for linesL
    // 1 line per month and decreament weight by 4 lbs
    // int c is used as a counter
    for(int c = 1; c <= MONTHS; c++){
        printf("%d\t%d\n", c,i);
        i = i - 4;
    }
    
    //weight loss int too show total possible lbs lost per MONTHS
    int wloss = MONTHS * 4;
    printf("Wow you could loose %dlbs in %d months!\n", wloss, MONTHS);

    return 0;
}