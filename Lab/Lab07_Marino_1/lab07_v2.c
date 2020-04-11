#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
*   Lab 07: Hangman
*   LETS PLAY HANGMAN
*   Gives option of 1 or 2 players
*/

// Functions used for the loops

void welcome_screen();
void one_player(int, int, int);
void two_player(int, int, int);
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
    // determin if one of more players
    int player_count = 0;
    //sets max game rounds
    int game_rounds = 6;
    int round_count = 0;
    // used to count wrong answers and print stick figures
    int wrong_guess = 6;
    int wrong_counter = 0;

    // Welcome screen and first choice
    welcome_screen();
    scanf("%d", &player_count); 
    fflush(stdin);   

    // valid intery check
    while(player_count != 1 && player_count != 2){
        printf("Invalid input. Please pick '1' or '2':\n");
        scanf("%d", &player_count); 
        fflush(stdin);
    }

    // Switch case for one or two player
    switch (player_count){
        case 1:
            one_player(round_count, wrong_guess, wrong_counter);
            break;

        case 2:
            two_player(round_count, wrong_guess, wrong_counter);
            break;
    }
    
    return 0;
}

//
//  One PLayer function.  
//  Allows used to play by them self. Random number gererator is used to pick a wordk from a list.
//  User then guesses letters and ouput is derived form user input
// 
void one_player(int round_count, int wrong_guess, int wrong_counter){
   char play_again = 'y';

    // While loop to play more than one time in a row
    while(play_again == 'y'){
       int wrong_guess = 6;
       int wrong_counter = 0;

        //random word list for random word genorator
        char word_list[25][15] = {"print", "inflame", "imminent", "previous", "savor",
                                    "surprise", "impartial", "address", "inquire", "encourage",
                                    "sneeze", "swift", "damaging", "function", "unnatural",
                                    "cumbersome", "invention", "excited", "zephyr", "incompetent",
                                    "forgetful", "humiliate", "class", "wright", "state"};
        
        // random word number from random number generator funtion.
        int r_word = r_num();

        //find the lenth of the word and sets the size in the game funtion
        int game_size = strlen(word_list[r_word]);
        char game[game_size];

        // populates game str with radom word
        for(int i = 0; i < game_size; i++){
            game[i] = word_list[r_word][i];    
        }
        
        // this sets the size of the guess str
        int guess_size = strlen(word_list[r_word]);
        char guess[guess_size];

        // sets up the guess '*' line
        for(int j = 0; j < guess_size; j++){
            guess[j] = '*';
        }


        printf("Lets play Hangman!\n");

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
                printf("\n\nGood Job!\n");
                printf("'%c' is used %d time(s)\n", char_guess, counter);
                print_array_char(guess, game_size);
                printf("\n\n");
            } else {
                wrong_counter ++;
                printf("\n");
                //prints hangman icon depending on how many inccorect rounds there have been.
                hm_icon(wrong_counter);
                printf("'%c' is not in the word :-(\nPlease try again.\n", char_guess);
                print_array_char(guess, game_size);
                printf("\n\n");
                
            }

            // counts what while loop itteration player is on   
            round_count++;
        }
            
        // This tests what ended the while loop.
        // if the round_count is less than to given max game_round the player won
        if(wrong_counter < wrong_guess){
            printf("You guessed all the correct characters!\nThe word was:");
            print_array_char(game, game_size);
        } else {
            printf("You used the max number of guesses.\nThe word was:");
            print_array_char(game, game_size);
        }
        
        // asks user if like to play again
        printf("Would you like to play again? (y/n):\n");
        play_again = getchar();
        fflush(stdin);

        // play again input checker
        while(play_again != 'y' && play_again != 'n'){
            printf("Invalid input. Please pick 'y' or 'n':\n");
            play_again = getchar(); 
            fflush(stdin);
        }

   }


    printf("Thank you for playing 1 Player Hangman!\n\n");
    return;
}


//
// Two player game 
// ask one player to type a word 
// then clears screen and allows other player to play as the 1 player game would work
//

void two_player(int round_count, int wrong_guess, int wrong_counter){
   char play_again = 'y';

    // While loop to play more than one time in a row
    while(play_again == 'y'){
       int wrong_guess = 6;
       int wrong_counter = 0;

        int word_size_MAX = 25;
        char game[word_size_MAX]; 
        char guess[0];

        // asks player 1 for a word
        printf("\nPlayer 1:\n\nPlease type one word only using lower-case letters then hit enter:\n");
        scanf("%s", game);
        fflush(stdin);

        //stores the word in an array
        int game_size = strlen(game);
        print_array_char(game, game_size);
        printf("\n");
        
        // sets up guess print out
        int guess_size = strlen(game);
        // sets up the guess '*' line
        for(int i = 0; i < guess_size; i++){
            guess[i] = '*';
        }

        // print_array_char(guess, guess_size);
        // printf("\n");

        // print_array_char(game, game_size);
        // printf("\n");


        

        printf("\n\n\nLets play Hangman!\n");
        
        // clears screen so player two cannot see the word that was written
        system("@cls||clear");

        printf("Player 2:\nIt's your turn!\n");


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
                    printf("\n\nGood Job!\n");
                    printf("'%c' is used %d time(s)\n", char_guess, counter);
                    print_array_char(guess, game_size);
                    printf("\n\n");
                } else {
                    wrong_counter ++;
                    printf("\n");
                    hm_icon(wrong_counter);
                    printf("'%c' is not in the word :-(\nPlease try again.\n", char_guess);
                    print_array_char(guess, game_size);
                    printf("\n\n");
                    
                }

                // counts what while loop itteration player is on   
                round_count++;
            }
                
            // This tests what ended the while loop.
            // if the round_count is less than to given max game_round the player won
            if(wrong_counter < wrong_guess){
                printf("You guessed all the correct characters!\nThe word was:");
                print_array_char(game, game_size);
            } else {
                printf("You used the max number of guesses.\nThe word was:");
                print_array_char(game, game_size);
            }

            printf("Would you like to play again? (y/n):\n");
            play_again = getchar();
            fflush(stdin);

            while(play_again != 'y' && play_again != 'n'){
                printf("Invalid input. Please pick 'y' or 'n':\n");
                play_again = getchar(); 
                fflush(stdin);
            }

   }


    printf("Thank you for playing 2 Player Hangman!\n\n");
    return;
}




// functions using the inccorct guess counter to print out the icons
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

// random rumber gererator
// sets a clock which is used to get the a remainder
// remainder is used for select random word
int r_num(){
    srand(time(0));
    int r_num = rand() % 24;
    return r_num;
}

//prints array with characters
void print_array_char(char array[], int SIZE){
    for(int i = 0; i < SIZE; i++){
           printf("%c", array[i]);
        }
    printf("\n");    
    return;
}

// prints array with int
void print_array_int(int array[], int SIZE){
    for(int i = 0; i < SIZE; i++){
           printf("%d", array[i]);
        }
    printf("\n");    
    return;
}


// Rest are all icons used for ASCII graphics in the game
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
