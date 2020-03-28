#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
*   Lab 07: Hangman
*   This program asks a playe to play hangman.
*   There is a hard coded word the player is trying to guess.
*/

// Functions
void welcome_screen();
void one_player(int, int, int, char [], char []);
void two_player();
int r_num();
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
    int player_count = 0;
    int game_rounds = 6;
    int round_count = 0;
    char game[0];
    int game_size = strlen(game); 
    char guess[game_size];

    // Welcome screen and first choice
    welcome_screen();
    scanf("%d", &player_count); 
    fflush(stdin);   

    while(player_count != 1 && player_count != 2){
        printf("Invalid input. Please pick '1' or '2':\n");
        scanf("%d", &player_count); 
        fflush(stdin);
    }

    // Switch case for one or two player
    switch (player_count){
        case 1:
            one_player(game_rounds, round_count, game_size, game, guess);
            break;

        case 2:
            two_player();
            break;
    }
    
    return 0;
}


void one_player(int game_rounds, int round_count, int game_size, char game[], char guess[]){
    // random word list
    char word_list[25][15] = {"print", "inflame", "imminent", "previous", "savor",
                          "surprise", "impartial", "address", "inquire", "encourage",
                          "sneeze", "swift", "damaging", "function", "unnatural",
                          "cumbersome", "invention", "excited", "zephyr", "incompetent",
                          "forgetful", "humiliate", "class", "wright", "state"};
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

//Welcome screen
void welcome_screen(){
    printf(" # # # # # # # # # # # # # # # # # # # # # # # # # # \n");                                           
    printf("#                                   ______          #\n");
    printf("#                                   |   \\|          #\n");
    printf("#            Let's Play             O    |          #\n");
    printf("#     |_| _  _  _  _ _  _  _       /|\\   |          #\n");
    printf("#     | |(_|| |(_|| | |(_|| |      / \\   |          #\n");
    printf("#               _|                 ______|__        #\n");
    printf("#                                                   #\n");
    printf("#      One Player                Two Player         #\n");
    printf("#         '1'                        '2'            #\n");
    printf("#                                                   #\n");
    printf("#  Please select one of the options and hit 'Enter' #\n");
    printf("#                                                   #\n");
    printf(" # # # # # # # # # # # # # # # # # # # # # # # # # # \n");
    return;
}


void gallows(){
    printf("\t  ______   \n");
    //delay(10);
    printf("\t  |   \\|   \n");
    //delay(10);
    printf("\t       |   \n");
    //delay(10);
    printf("\t       |   \n");
    //delay(10);
    printf("\t       |   \n");
    //delay(10);
    printf("\t ______|__ \n\n");
    //delay(10);
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
