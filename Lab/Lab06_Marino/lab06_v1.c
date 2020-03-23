#include <stdio.h>

/*
*   Lab 06: Arrays
*   This lab asks a a user to input an array.
*   It then finds the mean of that array.
*   Last it sorts the array.
*/

// Function
void get_array(int [], int);
void get_mean(const int[], int);
void sort_array(int [], int);
void print_array(int [], int);

int main () {
    //Sets array size for program
    int SIZE = 5;
    //Sets array for program as num_list
    int num_list[SIZE];
            
    get_array(num_list, SIZE);
    get_mean(num_list, SIZE);
    sort_array(num_list, SIZE);
    
    return 0;
}


// This funtion gets an array from the user.
void get_array(int num_list[], int SIZE){

    // Prompts user for array and how to format the input.
    printf("Please input 5 seperate intergers seperated by a space:\n");
        printf("ex: '0 1 2 3 4 5'\n");
        
        // scans and stores user input into the array
        for(int i = 0; i < SIZE; i++){
            scanf("%d", &num_list[i]);
        }

    printf("\nPart 1:\nYour array is: ");
    print_array(num_list, SIZE);
    printf("\n");    

    return;

}


// Funtions uses the users array and finds the mean
void get_mean(const int num_list[], int SIZE){
    
    //Initializes a counter and adds the array using the SIZE int set up in main.
    int total = 0;
    for(int i = 0; i < SIZE; i++){
        total = total + num_list[i];
    }

    // Finds mean by using size of the array and the total we set up earlier in the funtion.
    // Also swithes int to float to allow for a decimal in the mean answer.
    float mean = (float)total / (float)SIZE;

    // Prints the mean as a decimal.
    printf("Part 2:\nArray Mean is: %.2f\n\n", mean);

    return;
}

// This funtion uses a simple sort to sort the array the user provided.
void sort_array(int array[], int SIZE){
    int i, j, temp;
    // Sets how many time the sort will run
    for(i=0; i<SIZE; i++){
        // 
        for(j=i+1; j<SIZE; j++){
            // Test the elements and compairs them to eachother
            if (array[i]>array[j]){
                //The follwoing places the elements either in the temp array in > or continues to sort through the loops.
                temp= array[i];
                array[i]= array[j];
                array[j]=temp;
            }
        }
    }

    printf("Part 3:\nYour sorted array is: ");
    print_array(array, SIZE);
    printf("\n");    

     return;
}


void print_array(int array[], int SIZE){
    for(int i = 0; i < SIZE; i++){
           printf("%d ", array[i]);
        }
    printf("\n");    
    return;
}