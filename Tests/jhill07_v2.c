#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
int main () {
char guessed[]=("******");
char guess;
//bool correct=false;
char word[] = "letter";
    printf("Lets play hang man!\n");
    // printf("enter a letter\n");
    // scanf("%c", &guess);
    // fflush(stdin);
   
    int size = strlen(word);
    

    // for 15 rounds add a round counter and max round
    //add a counter att end of loop e.i: round coutner++

    int round_max = 15;
    int round_counter = 0;



    // compairing word to guessed to see if the same.
    while(strcmp(word,guessed) != 0 && round_counter < round_max){


        // i moved this while loop out for the for loop
        //while(i>=1){
                    printf("enter another letter:\n");
                    scanf("%c",&guess);
                    fflush(stdin);
                    //break;
                //}

        //for (int i = 0; i < size; i++){
            
              
            // josh added
            int counter = 0;
            // good to go
            for (int i = 0; i < size; i++){
                if(guess == word[i]){
                    //printf("%c is in the word\n%s\n", guess, guessed);
                    guessed[i]=word[i];
                    counter++;
                    //break;
                } //else if (guess!=word[i]){
                    //printf("could not find %c in the word \n",guess);
                    //break;
                //}
            }

            if(counter > 0){
                printf("%c is in the word\n%s\n", guess, guessed);
            } else {
                printf("could not find %c in the word \n",guess);
            }


            for (int i = 0; i < size; i++){
                if(guessed[i]=='*'){
                    break;
                }
                else if(i==size){
                    //correct=true;
                }
            }   
        //}
        round_counter++;
    }
return 0;
}
