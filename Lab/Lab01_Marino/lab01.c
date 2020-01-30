#include <stdio.h>

/*  Program asks for user name and a radius or a circle.
*   Returns user name and area of circle from given radius.
*/

#define pi 3.14 // defining pi to 2 decimal places

int main () {

    char NameFirst[20];
    char NameLast[20];
    float radius;
    

    printf("What is your name: \n"); //Asking for user name
    scanf("%s %s", NameFirst, NameLast);

    printf("Please enter the radius of a circle:\n"); //Asking for circle radius
    scanf("%f", &radius);
    
    float area = pi * (radius * radius); // Formula for area of a circle
    
    printf("Hello, %s %s. %.2f is the area of your circle.\n", NameFirst, NameLast, area); // Prints name and circle area

}


