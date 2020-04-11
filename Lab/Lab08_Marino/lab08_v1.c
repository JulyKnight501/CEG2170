#include <stdio.h>
#include <stdlib.h>


#define MAX_ADDRESS 25
#define MAX_HOSTNAME 30


/*
* Currently CEG2170 Template
* See Makefile for what is happening in background for "make run"
*/
typedef struct {
    int A, B, C, D;
    char hostname[MAX_HOSTNAME];
} address_t;

typedef struct {
    address_t addresses[MAX_ADDRESS];
} dns_t;



//funtion prototypes
void scan_file (); //scan_file function that only populates a structure of type dns_t
//int scan_file (dns_t *); //scan_file function that populates a structure of type dns_t & returns an int
//Recommendation: return an int of how many valid lines you read so you don't search
//  through array elements that were not populated by valid data

void find_ip (); //Only dns_t structure is input parameter - user is prompted for input in the function
//void find_ip (dns_t, char []); //User is prompted for input in main (or elsewhere) 
//void find_ip (dns_t, int); //dns_t structure is passed as well as valid data value to constrict search space

void find_hostname (); //Only dns_t structure is input parameter - user is prompted for input in the function
//void find_hostname (dns_t, int, int, int, int); //User is prompted for input in main (or elsewhere) 
//void find_hostname (dns_t, int); //dns_t structure is passed as well as valid data value to constrict search space

void find_subnet ();

void program_quit();

void welcome_screen();
void menu();


int main () {



    welcome_screen();
    menu();
    char menu_char = 'c';

    while(menu_char == 'c'){
        printf("Please choose an option:\n");
        //menu_char = getchar();
        //fflush(stdin);
        //printf("menu_char = %c\n", menu_char);

        // While loop to test for the valid input of [a,s,m,d,o]
        while(menu_char != 's' && menu_char != 'h' && menu_char != 'i' && menu_char != 'p' && menu_char != 'q' && menu_char != 'm'){
        menu_char = getchar();
        fflush(stdin);

            // Invalid input checker
            if(menu_char != 's' && menu_char != 'h' && menu_char != 'i' && menu_char != 'p' && menu_char != 'q' && menu_char != 'm'){
                printf("\nInvalid input. Please try again again:\n");
                menu_char = 'n';
            }
        }
    
        switch (menu_char){
            
            // Scan File Case
            case 's':
                scan_file();
                menu_char = 'c';
                break;

            // Find Host name
            case 'h':
                find_hostname();
                menu_char = 'c';
                break;

            // find an ip
            case 'i':
                find_ip();
                menu_char = 'c';
                break;

            // print host name with subnet
            case 'p':
                find_subnet();
                menu_char = 'c';
                break;

            case 'm':
                menu();
                menu_char = 'c';
                break;

            // end program
            case 'q':
                //program_quit();
                printf("Program Ended.\nThank you.\n");
                break;

        }
    }



    return 0;
}


void scan_file (){
    printf("Scan file!\n");
    return;
}


void find_ip (){
    printf("find IP\n");
    return;
}


void find_hostname (){
    printf("find hostname\n");
    return;
}


void find_subnet (){
    printf("Find subnet\n");
    return;
}

void program_quit(){
    printf("Quit program\n");
    return;
}


void welcome_screen(){

    printf(" # # # # # # # # # # # # # # # # # # # # # # # # # # \n");                                           
    printf("#                                                   #\n");
    printf("#                                                   #\n");
    printf("#                    WELCOME                        #\n");
    printf("#                      to                           #\n");
    printf("#                   IPv4 Lookup                     #\n");
    printf("#                                                   #\n");
    printf("#          Plese review menu options below          #\n");
    printf("#                                                   #\n");
    printf("#                                                   #\n");
    printf(" # # # # # # # # # # # # # # # # # # # # # # # # # # \n\n");

    return;
}

void menu(){
    printf("\tMenu Options:\n");
    printf("\ts : scan a data file\n");
    printf("\th : find hostname from associated IP address\n");
    printf("\ti : find IP address from associated hostname\n");
    printf("\tp : print hostnames with associated subnet\n");
    printf("\tm : see menu options\n");
    printf("\tq : end program\n\n");

    return;
}