#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
*   Lab 07: Hangman
*   This program asks a playe to play hangman.
*   There is a hard coded word the player is trying to guess.
*/

// Functions
void print_array_int(int [], int);
void print_array_char(char [], int);

// main funtion of hang man
int main (void) {
    // sets up variables used for the program.
    int game_rounds = 14;
    int round_count = 0;
    char game[] = "college";
    int game_size = strlen(game); 
    char guess[game_size];

       // sets up the guess '*' line
        for(int i = 0; i < game_size; i++){
            guess[i] = '*';
        }

        printf("Lets play Hangman!\n");

        // while has two conditions
        // checking to see if game is same as guess
        // also sees how many times the player has guessed a letter
        while(strcmp(game,guess) != 0 && round_count < game_rounds){
            
            // Asks player for a character and saved as a guess character
            printf("Please guess a letter:\n");
            char char_guess = getchar();
            fflush(stdin);

            // counter for iterations of the same element in the array
            // set to 0 for each iteration of the while loop
            int counter = 0;

            // Checks array for guessed character
            // Also writes the chuessed character if present in the guess array
            // Adds the ounter 
            for(int i = 0; i < game_size; i++){
                if(char_guess == game[i]){
                    guess[i] = game[i];
                    counter++;
                } 
            }

            // counts the number of times the guess char is used in the word
            if(counter > 0){   
                printf("\nGood Job!\n");
                printf("'%c' is used %d time(s)\n", char_guess, counter);
                print_array_char(guess, game_size);
            } else {
                printf("\n'%c' is not in the word :-(\nPlease try again.\n", char_guess);
            }

            // counts what while loop itteration player is on   
            round_count++;
        }
        
        // This tests what ended the while loop.
        // if the round_count is less than to given max game_round the player won
        if(round_count < game_rounds){
            printf("You guessed all the correct characters!\nThe word was:");
            print_array_char(game, game_size);
        } else {
            printf("You used the max number of guesses.\nThe word was:");
            print_array_char(game, game_size);
        }
    
    
    return 0;
}

void print_array_char(char array[], int SIZE){
    for(int i = 0; i < SIZE; i++){
           printf("%c", array[i]);
        }
    printf("\n");    
    return;
}

void print_array_int(int array[], int SIZE){
    for(int i = 0; i < SIZE; i++){
           printf("%d", array[i]);
        }
    printf("\n");    
    return;
}