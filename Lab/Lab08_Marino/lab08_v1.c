#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_ADDRESS 25
#define MAX_HOSTNAME 30


/*
* Currently CEG2170 Template
* See Makefile for what is happening in background for "make run"
*/

//  set up structures needed for code
typedef struct {
    int A, B, C, D;
    char hostname[MAX_HOSTNAME];
} address_t;

typedef struct {
    address_t addresses[MAX_ADDRESS];
} dns_t;



//funtion prototypes
int scan_file (dns_t *);
void find_ip (dns_t, int);
void find_hostname (dns_t, int);
void find_subnet ();

void welcome_screen();
void menu();

// main function
int main () {

    //sets up array dns and pointer to pass between functions
    dns_t dns;
    dns_t *dns_p;
    dns_p = &dns;

    
   // counter for how many lines of data are read
    int data_lines = 0; 

    // welcome screen and menu easy print
    welcome_screen();
    menu();

     

    // 'c' is used to continue loop when no correct input is chosen
    char menu_char = 'c';

    // main loop of function runs until user wants to end program.
    while(menu_char == 'c'){
        printf("\n\nPlease choose an option:\n");
    

        // While loop to test for the valid input of menu options
        while(menu_char != 's' && menu_char != 'h' && menu_char != 'i' && menu_char != 'p' && menu_char != 'q' && menu_char != 'm'){
        menu_char = getchar();
        fflush(stdin);

            // Invalid input checker
            if(menu_char != 's' && menu_char != 'h' && menu_char != 'i' && menu_char != 'p' && menu_char != 'q' && menu_char != 'm'){
                printf("\nInvalid input. Please try again again:\n");
                menu_char = 'n';
            }
        }
    

        // switch statment to easily move between different functions
        switch (menu_char){
            
            // Scan File Case
            case 's':
                data_lines = scan_file(&dns);
                menu_char = 'c';
                break;

            // Find Host name
            case 'h':
                find_hostname(dns, data_lines);
                menu_char = 'c';
                break;

            // find an ip
            case 'i':
                find_ip(dns, data_lines);
                menu_char = 'c';
                break;

            // print host name with subnet
            case 'p':
                find_subnet(dns, data_lines);
                menu_char = 'c';
                break;

            case 'm':
                menu();
                menu_char = 'c';
                break;

            // end program
            case 'q':
                printf("Program Ended.\nThank you.\n");
                break;

        }
    }

    return 0;
}


// function scan for file 'data.txt" 
int scan_file(dns_t *a){
    
    printf("scanning file...\n\n");

    // sets up FILE pointer to look for file data.txt
    FILE *inputp;
    inputp = fopen("data.txt","r");
    
    int i = 0;

    // scans file one line at a time and puts info into a dns array called
    // once scan is done it ends --- looks for 'none' for terminating clause
    for(i; i < MAX_ADDRESS; i++){
        fscanf(inputp, "%d.%d.%d.%d %s", &a->addresses[i].A, &a->addresses[i].B,
        &a->addresses[i].C, &a->addresses[i].D, a->addresses[i].hostname);

        if(strcmp(a->addresses[i].hostname, "none") == 0){
            printf("\nEnd of Data Found\n");
            printf("Number of lines read = %d\n\n", i);
            break;
        }
        printf("\n Address %2d: %d.%d.%d.%d %s", i, a->addresses[i].A, a->addresses[i].B,
        a->addresses[i].C, a->addresses[i].D, a->addresses[i].hostname);
    }

    return i;
}


void find_ip (dns_t a, int lines_read){
    

    printf("Please enter a host name to find an IP address:\n");
    char seek_hostname[MAX_HOSTNAME];
    scanf("%s", seek_hostname);
    fflush(stdin);
    
    
    int i = 0;
    while(i < lines_read){
        
        if (strcmp(a.addresses[i].hostname, seek_hostname) == 0){
            printf("\n\nHOSTNAME FOUND\n");
            printf("IP address associated with hostname '%s' is: %d.%d.%d.%d", seek_hostname, 
            a.addresses[i].A, a.addresses[i].B, a.addresses[i].C, a.addresses[i].D);
            return;
        }

        i++;
    }

    return;
}


void find_hostname (dns_t a, int lines_read){
    printf("Please enter an IP Address to find a hostname:\n");
    int A, B, C, D;
    scanf("%d.%d.%d.%d", &A, &B, &C, &D);
    fflush(stdin);


    int i = 0;
    while(i < lines_read){
        //printf("%s\n", a.addresses[i].hostname);
        if (a.addresses[i].A == A && a.addresses[i].B == B && a.addresses[i].C == C && a.addresses[i].D == D){
            printf("\n\nIP ADDRESS FOUND\n");
            printf("Hostname associated with IP address '%d.%d.%d.%d' is: %s", A, B, C, D, a.addresses[i].hostname);
            return;
        }

        i++;
    }

    return;
}


void find_subnet (dns_t a, int lines_read){
    printf("Please enter a Subnet to find all hostnames:\n");
    int A, B, C;
    scanf("%d.%d.%d", &A, &B, &C);
    fflush(stdin);

    int hostname_counter = 0;
    
    
    for(int i = 0; i < lines_read; i++){
        if(a.addresses[i].A == A && a.addresses[i].B == B && a.addresses[i].C == C ){
            hostname_counter++;
        }
    } 

    if(hostname_counter == 0){
        printf("No hostnames found");
    } else {

        int j = 0;
        printf("\n%d Hostnames found with subnet '%d.%d.%d':\n", hostname_counter, A, B, C);
        while(j < lines_read){
            //printf("%s\n", a.addresses[i].hostname);
            if (a.addresses[j].A == A && a.addresses[j].B == B && a.addresses[j].C == C){
                printf("%s\n", a.addresses[j].hostname);
            } 
                
            j++;
        }
    }

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
    printf("\tq : end program\n");

    return;
}