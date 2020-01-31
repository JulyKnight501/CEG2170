#include <stdio.h>

/*  This is an earthquake damage estimator
*   Ask user for the Richter scale and outputs amount and type of damage
*/

int main () {
    
    float scale = 0; // Variable for Richter scale value
    
    printf("Welcome to the earthquake damage estimator.\n"); // Asks for Richter sclae value
    printf("Please enter a Richter scale value: \n");

    scanf("%f", &scale);

    if(scale < 5){ // If value is lower 5.0
        printf("Little to no damage.\n");
        printf("Just a few shakes. Nothing to worry about.\n");

    } else if (scale <= 5.5){ // If value is 5.5 or less
        printf("Some damage\n");
        printf("You'll be fine, just shaken (not stirred) a liitle bit.\n");

    } else if (scale <= 6.5){ // if value is 6.5 or less
        printf("There will be serious damage. Walls may crack or fall.\n");
        printf("This is a great time to remodeling and move to an open floor plan.\n");

    } else if (scale <= 7.0){ // If value is 7.0 or less
        printf("Disaster: Houses and buildings may collapse.\n");
        printf("Time to move...\n");

    } else if (scale > 7.0){ // If value is more than 7.0
        printf("High Disaster: Most buildings will be destroid.\n");
        printf("Surprised you arent dead.\n");
    }
  
    return 0;

}