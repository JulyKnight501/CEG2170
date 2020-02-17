#include <stdio.h>

/*
*   Asks user for feet measurment and converts to inches
*/

// Function to convert feet to inches
int feet_to_inch(int); 


int main () {
    int feet = 0;

    printf("Please enter feet you would like converted to inches: ");
    scanf("%d", &feet);

    feet_to_inch(feet);

    return 0;
}

// Converts feet to inches
int feet_to_inch(int feet){
    int inch = feet * 12;
    printf("In %d feet, there are %d inches.\n", feet, inch);
    return 0;
}



