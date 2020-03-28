#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <time.h>



//int main(void){
//search a string (1D)
    // char silly_sentence [] = "A quick brown fox jumps over the lazy dog";
    // char fill_in_blank [] = {"00000000000000000000000000000000000000000"};
    // int size = strlen(silly_sentence);
    // char find_me = 'u';
    // for (int i = 0; i < size; i++){
    //     if(find_me == silly_sentence[i]){
    //         printf("I found char %c at element %d in silly_sentence\n", find_me, i);
    //         fill_in_blank[i] = silly_sentence[i];
    //     }
    // }
    // printf("\n%s\n", fill_in_blank);

    // char str1[] = "abcd", str2[] = "abCd", str3[] = "abcd";
    // int result;

    // // comparing strings str1 and str2
    // result = strcmp(str1, str2);
    // printf("strcmp(str1, str2) = %c\n", result);

    // // comparing strings str1 and str3
    // result = strcmp(str1, str3);
    // printf("strcmp(str1, str3) = %c\n", result);

    // int size = 6;
    // int num_list[] = {3, 5, 2, 1, 5, 3};

    // //how to search an array
    // //we know that size is 6
    // //we want to search for the number 2
    // int seekme = 5;
    // int counter = 0;
    // for (int i = 0; i < size; i++){
    //     //value seeking if
    //     if (seekme == num_list[i]){
    //         counter++;
    //     }
    // }

    // printf("%d is used %d time(s)\n", seekme, counter);

    // C program for generating a 
// random number in a given range. 


// void printRandoms(int lower, int upper,  
//                              int count) 
// { 
//     int i; 
//     for (i = 0; i < count; i++) { 
//         int num = (rand() % 
//            (upper - lower + 1)) + lower; 
//         printf("%d ", num); 
//     } 
// } 
  
// // Driver code 
// int main() 
// { 
//     int lower = 0, upper = 24, count = 1; 
  
//     // Use current time as  
//     // seed for random generator 
//     srand(time(0)); 
  
//     printRandoms(lower, upper, count); 
  
//     return 0; 
// } 

// int main(void){
//    // srand(time(0));
//     //int r_num = rand() % 24;
//    // printf("%d\n",r_num);
//     int player_count = 0;

//     scanf("%d", &player_count); 
//     fflush(stdin);   

//     while(player_count != 1 && player_count != 2){
//         printf("Invalid input. Please pick '1' or '2':\n");
//         scanf("%d", &player_count); 
//         fflush(stdin);
//     }

//     // Switch case for one or two player
//      switch (player_count){
//         case 1:
//             printf("case 1\n");
//             break;

//         case 2:
//             printf("case 2\n");
//             break;
//         }
//     return 0;
// }

// Functions
void print_array_int(int [], int);
void print_array_char(char [], int);
//void print_array_2d_char(char [][], int, int);
int r_num();

// main funtion of hang man
int main (void) {
    // sets up variables used for the program.
    int game_rounds = 15;
    int round_count = 0;
    int game_size = 0;
    char game[game_size];
    int guess_size = 0; 
    char guess[guess_size];
     // random word list
    char word_list[25][15] = {"print", "inflame", "imminent", "previous", "savor",
                                "surprise", "impartial", "address", "inquire", "encourage",
                                "sneeze", "swift", "damaging", "function", "unnatural",
                                "cumbersome", "invention", "excited", "zephyr", "incompetent",
                                "forgetful", "humiliate", "class", "wright", "state"};
    int r_word = r_num();
    printf("%d\n",r_word);

    game_size = strlen(word_list[r_word]);
    guess_size = game_size;
    printf("%d\n", game_size);
    for(int i = 0; i < game_size; i++){
        printf("%c", word_list[r_word][i]);
            game[i] = word_list[r_word][i];    
    }

    printf("\n");

    printf("the game_size is: %d\n", game_size);
    printf("the guess_size is: %d\n", guess_size);
    printf("the string game is: ");
    print_array_char(game, game_size);
    
    //print_array_2d_char(word_list, game_size, r_word);

        // // while has two conditions
        // // checking to see if game is same as guess
        // // also sees how many times the player has guessed a letter
        // while(strcmp(game,guess) != 0 && round_count < game_rounds){
            
        //     // Asks player for a character and saved as a guess character
        //     printf("Please guess a letter:\n");
        //     char char_guess = getchar();
        //     fflush(stdin);

        //     // counter for iterations of the same element in the array
        //     // set to 0 for each iteration of the while loop
        //     int counter = 0;

        //     // Checks array for guessed character
        //     // Also writes the chuessed character if present in the guess array
        //     // Adds the ounter 
        //     for(int i = 0; i < guess_size; i++){
        //         if(char_guess == game[i]){
        //             guess[i] = game[i];
        //             counter++;
        //         } 
        //     }

        //     // counts the number of times the guess char is used in the word
        //     if(counter > 0){   
        //         printf("\nGood Job!\n");
        //         printf("'%c' is used %d time(s)\n", char_guess, counter);
        //     } else {
        //         printf("\n'%c' is not in the word :-(\nPlease try again.\n", char_guess);
        //     }

        //     // counts what while loop itteration player is on   
        //     round_count++;
        // }
        
        // // This tests what ended the while loop.
        // // if the round_count is less than to given max game_round the player won
        // if(round_count < game_rounds){
        //     printf("You guessed all the correct characters!\nThe word was:");
        //     print_array_char(game, guess_size);
        // } else {
        //     printf("You used the max number of guesses.\nThe word was:");
        //     print_array_char(game, guess_size);
        // }
    
    
    return 0;
}

void print_array_char(char array[], int SIZE){
    for(int i = 0; i < SIZE; i++){
           printf("%c", array[i]);
        }
    printf("\n");    
    return;
}

// void print_array_2d_char(char array[], int SIZE, int d1){
//     for(int i = 0; i < SIZE; i++){
//            printf("%c", array[d1][i]);
//         }
//     printf("\n");    
//     return;
// }

void print_array_int(int array[], int SIZE){
    for(int i = 0; i < SIZE; i++){
           printf("%d", array[i]);
        }
    printf("\n");    
    return;
}

int r_num(){
    srand(time(0));
    int r_num = rand() % 24;
    return r_num;
}