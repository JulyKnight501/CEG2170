#include <stdio.h>
#include <stdlib.h>

/*
*   Notes:
*   Loops:
*   C uses both for and while loops
*   For loops:
*   Iterator - variable that keeps track of a number
*
*   count up => i++
*   count up => i--
*
*   
*   
*   
*/

/* int main () {

int item_count = 5;
    for(int i = 0; i <= item_count; i++){
        printf("You have %d items in your cart.\n", i);
    }
    printf("Do you want to go to check out?\n");

    char letter = scanf("%c", letter);
    if(letter == 'y'){
        for(int i = item_count; i >= 0; i--){
        printf("Checking out item %d\n", i);
        }
    }


    return 0;
}


 */


/*  While loops:
*   doing something from user input yes or no or based of an varable
*
*
*/



int main () {

int cart_items = 0;
int item_max = 5;

for(cart_items <= item_max){
    if(cart_items <= item_max - 1){
        printf("Keep Shopping! You have %d items.\n", cart_items);
        cart_items++;
    } else {
        printf("Your cart is full! You have %d items.\n", cart_items);
    }
}

    return 0;
}




/*
int main(void){

    char letter = 'y';

    while (letter == 'y'){
        printf("Run program stuff.\n");
        printf("Keep going?: ");
        scanf("%c", &letter);
        fflush(stdin); // flushes buffer char of 'enter'
    }




    return 0;

}

*/