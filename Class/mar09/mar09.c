#include <stdio.h>

/*
* Currently CEG2170 Template
* See Makefile for what is happening in background for "make run"
*/

int main () {
    float num_list[] = {30,50,20,10,57,39};
    float size_array = sizeof(num_list);
    float size_element = size_array / sizeof(num_list[0]);

    printf("Array Size = %f\nElement Size = %f\n", size_array, size_element);

return 0;

}