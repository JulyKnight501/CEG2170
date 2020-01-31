#include <stdio.h>



int main () {
    
    float scale = 0;
    
    printf("Welcome to the earthquake damage estimator.\n");
    printf("Please enter a Richter scale value: \n");

    scanf("%f", &scale);

    if(scale < 5){
        printf("There will be little to no damage.\n");
    } else if (scale <= 5.5){
        printf("There will be some damage\n");
    } else if (scale <= 6.5){
        printf("There will be serious damage. Walls may crack or fall\n");
    } else if (scale <= 7.0){
        printf("Disaster: Houses and buildings may collapse\n");
    } else if (scale > 7.0){
        printf("High Disaster: Most buildings will destroid\n");
    }
  
    return 0;

}