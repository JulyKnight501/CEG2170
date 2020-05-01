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
void link_list(int[], int);
void manual_input(int [], int*);
void file_input(int [], int*);
int file_line_counter();




int main () {


    int a[] = {1,2,3,4,5,6,7,8,9,0};
    int a_size = sizeof(a) / sizeof(a[0]);



    // printf("a_size : %d\n", a_size);
    // printf("a : ");
    // for(int i = 0; i < a_size; i++){
    //     printf("%d, ", a[i]);
    // }

    
    printf("\n\nHello!\nWould you like to manual input a number list or scan from a file?\n\ne - enter manualy\ts - scan file\n\n(e/s):\n");
    char method = getchar();
    fflush(stdin);

    while(1){
        if(method == 'e'){
            manual_input(a, &a_size);
            break;
        } else if (method == 's'){
            file_input(a, &a_size);
            break;
        } else {
            printf("Invaid Input\n");
        }
    }
    

    
    // printf("\na_size : %d\n", a_size);
    // printf("a : ");
    // for(int i = 0; i < a_size; i++){
    //     printf("%d, ", a[i]);
    // }


    link_list(a, a_size);


    return 0;
}



void manual_input(int num_list[], int *size){
    int list_length;
    printf("How many numbers will be in your list?\n");
    scanf("%d", &list_length);

    //num_list[list_length];

    printf("Please begin by typing a number and hitting 'ENTER'\n");

    for(int i = 0; i < list_length; i++){
        scanf("%d", &num_list[i]);
        fflush(stdin);

    }


    *size = list_length;

    return;
}



void file_input(int num_list[], int *size){
    printf("File Input\n");
    int line_count = file_line_counter(); 

    *size = line_count;


    printf("Line count is : %d\n", line_count);
    
    FILE *inputp;
    inputp = fopen("data.txt","r");

    
    for(int i = 0; i < line_count; i++){
        fscanf(inputp, "%d", &num_list[i]);
        //printf("Scanned : %d\n", num_list[i]);
       
    }


    fclose(inputp);

    return;
}



int file_line_counter(){
    // count the number of lines in the file called filename                                    
    FILE *fp; 
    int c = 0;
    int lines = 0;
    
    fp = fopen("data.txt","r");
    for (c = getc(fp); c != EOF; c = getc(fp)){
      if (c == '\n')
    lines++;
    }

    fclose(fp);
    return lines;
}





void link_list(int num_array[], int size){
    

    //  for(int i = 0; i < size; i++){
    //     printf("%d\n", num_array[i]);
    //  }
    // Array Initialization
    //int num_array[] = {8,10,16,90,42,21,8};
    //int num_array_size = sizeof(num_array) / sizeof(num_array[0]);

    //Create headp
    num_t *headp = (num_t *)malloc(sizeof(num_t));
    
    num_t *temp = headp;
    for (int i = 0; i < size; i++){
        
        num_t *new = (num_t *)malloc(sizeof(num_t));
        
        temp->num = num_array[i];
        
        printf("Storing %d\n", temp->num);
      
        if (i == (size-1)){
            temp->next = NULL;
        }
       
        else{
            temp->next = new;
            temp = new;
        }
    }

     
    num_t *n = headp;
    while (n != NULL){
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
               // printf("Free'd node.  Data is %d\n", headp->num);
                printf("All numbers deleted from heap.\n");
                printf("Program Ended.\nThank you.\n");
                break;
            }
    }

}

// menu print funtion
void menu (){
    printf("\nLink List Menu:\n");
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