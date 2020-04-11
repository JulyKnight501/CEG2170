#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (void){
int SIZE = 4;
char test1[] = "test";
char test2[] = "jrlk";

for(int i = 0; i <= SIZE; i++){
   
    for(int i = 0; i < SIZE; i++){
           printf("%c", test1[i]);
    }
    printf("\n");

    for(int i = 0; i < SIZE; i++){
           printf("%c", test2[i]);
    }
    printf("\n");  
    
    int test_cmp = strcmp(test1, test2);
    printf("cmp number: %d\n", test_cmp);
    test2[i] = test1[i];

}


    return 0;
}