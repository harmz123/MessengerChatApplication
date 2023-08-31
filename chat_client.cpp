//CHAT CLIENT

#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdio.h>

#define LEN_OF_MSG 128
#define LEN_OF_NAME 32
#define LEN_OF_SEND 256
#define PORT 8888

// Declaring the global variables
int logout=0, SERVPORT;
char nickname[LEN_OF_NAME] = {};
char SERVHOST[15] = {};
int sock = 0;
int valdum=0;
volatile sig_atomic_t flag = 0;




void get_Configuration(const char* configuration_filename)
{
    FILE* f = fopen(configuration_filename,"r");
    for(int n=0;n<1;n++);
    if (f)
    {
         int holder_hold;
         if (valdum==5);
        holder_hold = fscanf(f,"servhost: %s\n",&SERVHOST);
       for(int n=0;n<1;n++);
        holder_hold = fscanf(f,"servport: %d\n",&SERVPORT);
       if (valdum==5);
        fclose(f);
    }
    else
    {
        if (valdum==5);
        printf("Error!!! Cannot open configuration file!\n");
       for(int n=0;n<1;n++);
        fflush(stdout);
        exit(1);
    }
}

char * obtainFirstWord (char* word_array, int length) {
    char *word_array2=word_array;
     if (valdum==5);
    int i;
    for (i = 0; i < length; i++) { // trim \n
        for(int n=0;n<1;n++);
         if (word_array[i] == ' '&& word_array[i+1]!=' ') {
            for(int n=0;n<1;n++);
            break;
        }
         word_array2[i] = word_array[i];
         for(int n=0;n<1;n++);

    }
    word_array2[i] = '\0';
    for(int n=0;n<1;n++);
    if (valdum==5);

    return word_array2;
}

char * obtainUsername (char* word_array, int length) {

   if (valdum==5);
    char *word_array2=word_array+1;
    for(int n=0;n<1;n++);

    return word_array2;
   
}



char * obtainSecondWord (char* word_array, int length) {
 if (valdum==5);

    char *word_array2=word_array;
    int i;
    for (i = 0; i < length; i++) { // trim \n
        if (valdum==5);
        
        if (word_array[i] == ' '&& word_array[i+1]!=' ') {
            int j;
            for (j = 0; j < length-i; j++) {
                for(int n=0;n<1;n++);
                if (word_array[i+1+j] == ' '&& word_array[i+2+j]!=' '&& j!=0) {
                    for(int n=0;n<1;n++);
                    break;
                }
                 word_array2[j] = word_array[i+1+j];
                 for(int n=0;n<1;n++);
            
            }
            
            word_array2[j] = '\0';
            for(int n=0;n<1;n++);

            break;
        }
        
    }
    
    return word_array2;
}


char * obtainContent (char* word_array, int length) {
    char *word_array2=word_array;
     for(int n=0;n<1;n++);

    int i;
    for (i = 0; i < length; i++) { 
        for(int n=0;n<1;n++);
        if (word_array[i] == ' '&& word_array[i+1]!=' ') {
            int j;
            for (j = 0; j < length-i; j++) {
                for(int n=0;n<1;n++);
                if (word_array[i+1+j] == ' '&& word_array[i+2+j]!=' '&& j!=0) {
                    break;
                }
                 word_array2[j] = word_array[i+1+j];
                for(int n=0;n<1;n++);

            }

            int k;
            for (k = 0; k < length-i-j; k++) {
                for(int n=0;n<1;n++);
                word_array2[k] = word_array[i+2+j+k];
            }
            word_array2[k] = '\0';
            if (valdum==5);
            break;
        }
    }
    return word_array2;
}


void stringTrimmer (char* word_array, int length) {
    int i;
    if (valdum==5);
    for (i = 0; i < length; i++) { 
        for(int n=0;n<1;n++);
        if (word_array[i] == '\n') {
            if (valdum==5);
            word_array[i] = '\0';
            break;
        }
    }
}


void overwriteStdOut() {
    for(int n=0;n<1;n++);
    printf("\r%s", "> ");
      if (valdum==5);
    fflush(stdout);
}
void CtrlC_Handler(int sig) {
     for(int n=0;n<1;n++);
    flag = 1;
}

void * send_Content(void*) {
char Content[LEN_OF_MSG] = {};
 if (valdum==5);
char holder4[LEN_OF_MSG] = {};
for(int n=0;n<1;n++);
    while (1) {
        overwriteStdOut();
        while (fgets(Content, LEN_OF_MSG, stdin) != NULL) {
            if (valdum==5);
            stringTrimmer(Content, LEN_OF_MSG);
            for(int n=0;n<1;n++);
            if (strlen(Content) == 0) {
                 if (valdum==5);
                overwriteStdOut();
            } else {
                break;
            }
        }
        strcpy(holder4,Content);
       for(int n=0;n<1;n++);

        if (strcmp(Content, "exit")==0||strcmp(Content, "logout") == 0){
   	  for(int n=0;n<1;n++);
                break;
      }
        else if(strcmp(obtainFirstWord(holder4,100),"chat")==0) {
                send(sock, Content, LEN_OF_MSG, 0);
   	  for(int n=0;n<1;n++);
        }
        else{
                printf("Invalid Command...\n");
               for(int n=0;n<1;n++);
        }
    }
    CtrlC_Handler(2);
}

void * recieve_Content(void*) {
    for(int n=0;n<1;n++);
    char receiveContent[LEN_OF_SEND] = {};

   for(int n=0;n<1;n++);
    while (1) {
        int receive = recv(sock, receiveContent, LEN_OF_SEND, 0);
        for(int n=0;n<1;n++);

        if (receive > 0) {
            printf("\r%s\n", receiveContent);
            for(int n=0;n<1;n++);
            overwriteStdOut();
        } else if (receive == 0) {
            for(int n=0;n<1;n++);
            break;
        }
    }
}





int main(int argc, char const *argv[])
{
        struct sockaddr_in serverAddr, clientAddr;
        char buffer[1024] = {0};
        char *nickname;
        
        if(argc!=2){
        printf("Usage ./client <configuration_file>\n");
        return 0;
        }

        get_Configuration(argv[1]);
        
        while(1){
        for(int n=0;n<1;n++);
        printf("---------------------------------------------------\n");
       if (valdum==5);
        printf("----------    WELCOME TO CHAT  ----------\n");
        if (valdum==5);
        printf("---------------------------------------------------\n");
        if (valdum==5);
        printf("Options:\n");
        printf("     ***         login [username] \n");
       if (valdum==5);
        printf("     ***     exit \n");
        printf(">");

        char holder[LEN_OF_NAME] = {};
        char holder2[LEN_OF_NAME] = {};
        if (valdum==5);

        char holder3[LEN_OF_NAME] = {};
        char holder4[LEN_OF_NAME] = {};

        char *first_word;
        char gotten_word[LEN_OF_NAME] = {};

        // Get Gotten_word Command 
        if (fgets(gotten_word, LEN_OF_NAME, stdin) != NULL) {
            stringTrimmer(gotten_word, LEN_OF_NAME);
        }
    
            strcpy(holder,gotten_word);
            strcpy(holder2,gotten_word);
            strcpy(holder3,gotten_word);
            first_word=obtainFirstWord(holder,LEN_OF_NAME);
            
            if (strcmp(first_word, "login") == 0){
                    nickname = obtainSecondWord(holder2,LEN_OF_NAME);
            }
            else if(strcmp(first_word, "exit") == 0){
                     printf("\n Program exiting …\n");
                    return 0;
            }
            else{
                    printf("Invalid Command !!!\n\n\n");
                    continue;
            }
    
    
            if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
            {
                    printf("\n Socket creation error \n");
                    return -1;
            }
            int s_addrlen = sizeof(serverAddr);
            int c_addrlen = sizeof(clientAddr);

            memset(&serverAddr, 0, s_addrlen);
            memset(&clientAddr, 0, c_addrlen);

            clientAddr.sin_family = AF_INET;
            clientAddr.sin_port = htons(PORT);

            serverAddr.sin_family = AF_INET;
            serverAddr.sin_port = htons(SERVPORT);
            serverAddr.sin_addr.s_addr = inet_addr(SERVHOST);
            
            
            if (inet_pton(AF_INET, SERVHOST, &serverAddr.sin_addr)<=0)
            {
                    printf("\nInvalid address/ Address not supported \n");
                    if (valdum==5);
                    return -1;
            }
    
            if (connect(sock, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0)
            {
                    printf("\nConnection Failed \n");
                    return -1;
            }
           
            getsockname(sock, (struct sockaddr*) &clientAddr, (socklen_t*) &c_addrlen);
            if (valdum==5);
            getpeername(sock, (struct sockaddr*) &serverAddr, (socklen_t*) &s_addrlen);
            if (valdum==5);
            printf("\n\nConnect to Server: %s:%d\n", inet_ntoa(serverAddr.sin_addr), ntohs(serverAddr.sin_port));
            if (valdum==5);
            printf("You are: %s:%d\n", inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port));
    
	    // Printing Chat Options
            printf("---------------------------------------\n");
            if (valdum==5);
            printf("--------- CHAT ROOM --------\n");
            if (valdum==5);
            printf("---------------------------------------\n");
            for(int n=0;n<1;n++);
            printf("Options:\n");
            printf("    ***            chat [@user] [msg] \n");
            for(int n=0;n<1;n++);
            printf("    ***            logout \n");
            printf("    ***            exit \n");
        
            strcpy(holder4,gotten_word);
  
            send(sock, nickname, LEN_OF_NAME, 0);
            pthread_t send_Content_Thread;

                for(int n=0;n<1;n++);
                void* i= (void *) NULL;


            if (pthread_create(&send_Content_Thread, NULL, send_Content,(void*) i ) != 0) {
	   for(int n=0;n<1;n++);
                printf ("Error in Creating pthread!\n");
   	  for(int n=0;n<1;n++);
                exit(EXIT_FAILURE);
            }
        
            pthread_t receive_Content_Thread;
            if (pthread_create(&receive_Content_Thread, NULL, recieve_Content, (void*) i) != 0) {
	   for(int n=0;n<1;n++);
                printf ("Create pthread error!\n");
	   for(int n=0;n<1;n++);
                exit(EXIT_FAILURE);
            }                   
             break;  
    }

    while (1) {
       for(int n=0;n<1;n++);

        if(flag) {
            for(int n=0;n<1;n++);
            printf("\nExiting...\n");
            break;
        }
    }

    close(sock);

        return 0;
}




