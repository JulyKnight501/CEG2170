#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
*   Lab 07: Hangman
*   This program asks a playe to play hangman.
*   There is a hard coded word the player is trying to guess.
*/

// Functions

void one_player(int, int, int, int);
int r_num();
void hm_icon(int);
void print_array_int(int [], int);
void print_array_char(char [], int);
void gallows();
void head();
void body();
void left_arm();
void right_arm();
void left_leg();
void right_leg();

// main funtion of hang man
int main (void) {
    // sets up variables used for the program.
    //int player_count = 0;
    int game_rounds = 6;
    int round_count = 0;
    int wrong_guess = 6;
    int wrong_counter = 0;

    one_player(game_rounds, round_count, wrong_guess, wrong_counter);
    
    return 0;
}




void one_player(int game_rounds, int round_count, int wrong_guess, int wrong_counter){
    
    //random word list for random word genorator
    char word_list[25][15] = {"print", "inflame", "imminent", "previous", "savor",
                                "surprise", "impartial", "address", "inquire", "encourage",
                                "sneeze", "swift", "damaging", "function", "unnatural",
                                "cumbersome", "invention", "excited", "zephyr", "incompetent",
                                "forgetful", "humiliate", "class", "wright", "state"};
    int r_word = r_num();
    printf("%d\n",r_word);

    int game_size = strlen(word_list[r_word]);
    char game[game_size];
    for(int i = 0; i < game_size; i++){
        game[i] = word_list[r_word][i];    
    }
    
    printf("\n");
    printf("the game_size is: %d\n", game_size);
    printf("the string game is:  ");
    print_array_char(game, game_size);    
    printf("\n");


    int guess_size = strlen(word_list[r_word]);
    char guess[guess_size];
    // sets up the guess '*' line
    for(int j = 0; j < guess_size; j++){
        guess[j] = '*';
    }

    printf("the guess_size is: %d\n", guess_size);
    printf("the string guess is: ");
    print_array_char(guess, guess_size);
    
    printf("the game_size is: %d\n", game_size);
    printf("the string game is:  ");
    print_array_char(game, game_size);
    

    
    // while has two conditions
    // checking to see if game is same as guess
    // also sees how many times the player has guessed a letter
    while(strcmp(game,guess) != 0 && wrong_counter < wrong_guess){
            
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
            printf("wrong guess counter: %d\n", wrong_counter);
            wrong_counter ++;
            hm_icon(wrong_counter);
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
    
    printf("rounds played: %d\n", round_count);
    return;
}

void hm_icon(int wrong_counter){
    switch(wrong_counter){
        case 0:
            gallows();
            break;
        
        case 1:
            head();
            break;

        case 2:
            body();
            break;

        case 3:
            left_arm();
            break;

        case 4:
            right_arm();
            break;

        case 5:
            left_leg();
            break;

        case 6:
            right_leg();
            break;
    }
    return;
}

int r_num(){
    srand(time(0));
    int r_num = rand() % 24;
    return r_num;
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



void gallows(){
    printf("\t  ______   \n");
    printf("\t  |   \\|   \n");
    printf("\t       |   \n");
    printf("\t       |   \n");
    printf("\t       |   \n");
    printf("\t ______|__ \n\n");
}

void head(){
    printf("  ______   \n");
    printf("  |   \\|   \n");
    printf("  O    |   \n");
    printf("       |   \n");
    printf("       |   \n");
    printf(" ______|__ \n\n");
}

void body(){
    printf("  ______   \n");
    printf("  |   \\|   \n");
    printf("  O    |   \n");
    printf("  |    |   \n");
    printf("       |   \n");
    printf(" ______|__ \n\n");
}

void left_arm(){
    printf("  ______   \n");
    printf("  |   \\|   \n");
    printf("  O    |   \n");
    printf(" /|    |   \n");
    printf("       |   \n");
    printf(" ______|__ \n\n");
}

void right_arm(){
    printf("  ______   \n");
    printf("  |   \\|   \n");
    printf("  O    |   \n");
    printf(" /|\\   |   \n");
    printf("       |   \n");
    printf(" ______|__ \n\n");
}

void left_leg(){
    printf("  ______   \n");
    printf("  |   \\|   \n");
    printf("  O    |   \n");
    printf(" /|\\   |   \n");
    printf(" /     |   \n");
    printf(" ______|__ \n\n");

}

void right_leg(){
    printf("  ______   \n");
    printf("  |   \\|   \n");
    printf("  O    |   \n");
    printf(" /|\\   |   \n");
    printf(" / \\   |   \n");
    printf(" ______|__ \n\n");
}
