#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
int main () {
char guessed[]=("***");
char guess;
bool correct=false;
char word[] = "arm";
    printf("Lets play hang man!\n");
    printf("enter a letter\n");
    scanf("%c", &guess);
    fflush(stdin);
   
    int size = strlen(word);
    while(correct==false){
for (int i = 0; i < size; i++){
    //another while loop to stop at 15 times
    ///anohter loop that says you guessed it and ends it
    //while(){}
       // printf("you ran out of guesses");
        //return 0;
    //}
        while(i>=1){
            printf("enter another letter:\n");
            scanf("%d",&i);
            fflush(stdin);
            break;
        }

    for (int i = 0; i < size; i++){
        if(guess == word[i]){
            printf("%c is in the word\n%s\n", guess, guessed);
            guessed[i]=word[i];
            break;
        }
        else if(guess!=word[i]){
            printf("could not find %c in the word \n",guess);
            break;
        }
    }
    for (int i = 0; i < size; i++){
        if(guessed[i]=='*'){
            break;
        }
        else if(i==size){
            correct=true;
        }
    }   
}
}
return 0;
}
