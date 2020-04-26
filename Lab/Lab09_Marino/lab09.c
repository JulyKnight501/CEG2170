#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/*
* Currently CEG2170 Template
* See Makefile for what is happening in background for "make run"
*/



typedef struct num_s{
    int num;
    struct num_s *next;
} num_t;


// Prototype funtions
void menu();
void num_find(num_t *headp);
void num_insert(num_t *headp);
void num_print(num_t *headp);



int main () {
    
    // Array Initialization
    int num_array[] = {8,10,16,90,42,21,8};
    int num_array_size = sizeof(num_array) / sizeof(num_array[0]);

    //Create headp
    num_t *headp = (num_t *)malloc(sizeof(num_t));
    // Store headp in temp
    num_t *temp = headp;
    for (int i = 0; i < num_array_size; i++){
        //create new structure in heap.  
        num_t *new = (num_t *)malloc(sizeof(num_t));
        //save corresponding element to node temp is looking at
        temp->num = num_array[i];
        //friendly message that I did a thing
        printf("Storing %d\n", temp->num);
        //minor magic
        //we know that the last link in a list will point to NULL
        //  I need to detect when I'm at the end of my array values
        if (i == (num_array_size-1)){
            temp->next = NULL;
        }
        //OTHERWISE, I need to fill in temp->next to point to the address we just created with new
        //  And then set my temp to new so I can rinse and repeat 
        //  (fill in the next value, new address, and move to the new node)
        else{
            temp->next = new;
            temp = new;
        }
    }

     //print all the values in the linked list
    num_t *n = headp;
    while (n != NULL){
        //printf("data is %d\n", n->num);
        n = n->next;
    }
    
    
    
    menu();


     // 'c' is used to continue loop when no correct input is chosen
    char menu_char = 'c';

    // main loop of function runs until user wants to end program.
    while(menu_char == 'c'){
        printf("Please choose an option:\n");
    

        // While loop to test for the valid input of menu options
        while(menu_char != 'f' && menu_char != 'i' && menu_char != 'p' && menu_char != 'q'){
        menu_char = getchar();
        fflush(stdin);

            // Invalid input checker
            if(menu_char != 'f' && menu_char != 'i' && menu_char != 'p' && menu_char != 'q'){
                printf("\nInvalid input. Please try again again:\n");
                menu_char = 'n';
            }
        }
    

        // switch statment to easily move between different functions
        switch (menu_char){
            
            // Fimds spesified number
            case 'f':
                num_find(headp);
                menu_char = 'c';
                break;

            // // inserts number
            case 'i':
                num_insert(headp);
                menu_char = 'c';
                break;

            // print num list
            case 'p':
                num_print(headp);
                menu_char = 'c';
                break;

            // end program
            case 'q':
                // relese nodes
                //freeing a linked list with a loop (note we initialized n above)
                n = headp;
                while (n != NULL)
                {
                    //we need to save the address to get to the next node
                    num_t *next_to_go = n->next;
                    //printf("Free'ing node.  Data was %d\n", n->num);
                    //then free the node we are on
                    free(n);
                    //then move to the next node
                    n = next_to_go;
                }
                //this should print junk, because we free'd the address pointed to by
                //  both n & headp in the loop above
                printf("Free'd node.  Data is %d\n", headp->num);
                printf("Program Ended.\nThank you.\n");
                break;
            }
    }


    return 0;
}


// menu print funtion
void menu (){
    printf("Link List Menu:\n");
    printf("f - find how many of a number exists\ni - insert a number\np - print the numbers\nq - end program\n\n");
}


void num_find(num_t *headp){

    printf("Please enter a number to find:");
    int lookup_num = 0;
    scanf("%d", &lookup_num);
    fflush(stdin);

    int counter = 0;


    num_t *n = headp;
    while (n != NULL){
        if(lookup_num == n ->num){
            //printf("Number found\n");
            counter ++;
            n = n->next;
        } else {
        //printf("Not Found\n");
        n = n->next;
        }
    }

    printf("Your number '%d' was found '%d' times.\n", lookup_num, counter);
    return;
}


void num_insert(num_t *headp){
    printf("Insert Number function!\n");

    int insert_num = 0;
    printf("What number would you like to insert:");
    scanf("%d", &insert_num);
    fflush(stdin);

    num_t *new = (num_t*)malloc(sizeof(num_t));
    new -> num = insert_num;
    new -> next = NULL;

    num_t *temp = headp;
    while(temp != NULL){
        if(temp -> next == NULL){
            break;
        }
        temp = temp -> next;
    }

    temp -> next = new;

    printf("You have added %d to the list\n", new->num);
    
   
    return;
}




void num_print(num_t *headp){
    num_t *temp = headp;
    while (temp != NULL){
        printf("%d\n",temp->num);
        temp = temp->next;
    }
    return;
}