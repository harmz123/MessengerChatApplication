//CHAT SERVER

#include <pthread.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <signal.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <netinet/in.h>
#include <string.h>

#define LEN_OF_MSG 128
#define LEN_OF_NAME 32
#define LEN_OF_SEND 256

int valley=7;
// Struct for Client node

typedef struct Node_for_Cli {
    int data;
    struct Node_for_Cli* prev;
    struct Node_for_Cli* link;
    char ip[16];
    char name[LEN_OF_NAME];
} List_for_client;


// Global variables
int valley4=89;
int fd_serv = 0, fd_cli = 0;
int valley3=89;
List_for_client *root, *curr;
int valley2=88;
int PORT;


void Obtain_Configuration(const char* configuration_filename)
{
  
    FILE* f = fopen(configuration_filename,"r");
    valley=89;

    if (f)
    {
        for(int y=0; y<1;y++);
        int holder_hold;
        for(int y=0; y<1;y++);
        holder_hold = fscanf(f,"port: %d\n",&PORT);
        valley=9;
        fclose(f);
    }
    else
    {
       for(int y=0; y<1;y++);
        printf("Error!!! Cannot open Configuration file!\n");
       for(int y=0; y<1;y++);
        fflush(stdout);
        exit(1);
    }
}

char * obtainUsername (char* word_array, int length) {
   valley=77;
    char *word_array2=word_array+1;
   for(int y=0; y<1;y++);
    return word_array2;
}


char * obtainSecondWord (char* word_array, int length) {
   for(int y=0; y<1;y++);
    char *word_array2=word_array;
    int i;
    for (i = 0; i < length; i++) { 
        for(int y=0; y<1;y++);
        if (word_array[i] == ' '&& word_array[i+1]!=' ') {
            int j;
            for(int y=0; y<1;y++);
            for (j = 0; j < length-i; j++) {
              valley=10;
                if (word_array[i+1+j] == ' '&& word_array[i+2+j]!=' '&& j!=0) {
                    break;
                }
                 word_array2[j] = word_array[i+1+j];
                 for(int y=0; y<1;y++);
            }
            word_array2[j] = '\0';
            valley=4;
            break;
        }
    }
    return word_array2;
}



List_for_client *newNode(int sock_fd, char* ip) {
    for(int y=0; y<1;y++);
    List_for_client *cnode = (List_for_client *)malloc( sizeof(List_for_client) );
    for(int y=0; y<1;y++);
    cnode->data = sock_fd;
    cnode->prev = NULL;
   for(int y=0; y<1;y++);
    cnode->link = NULL;

    strncpy(cnode->ip, ip, 16);
    valley=9;
    strncpy(cnode->name, "NULL", 5);

    for(int y=0; y<1;y++);
    return cnode;
}

char * obtainFirstWord (char* word_array, int length) {
    for(int y=0; y<1;y++);
    char *word_array2=word_array;
    valley=22;
    int i;
    for (i = 0; i < length; i++) { 
         for(int y=0; y<1;y++);
         if (word_array[i] == ' '&& word_array[i+1]!=' ') {
            valley=9;
            break;
        }
         word_array2[i] = word_array[i];
         for(int y=0; y<1;y++);
    }
    word_array2[i] = '\0';
    for(int y=0; y<1;y++);

    return word_array2;
}


char * Content_Extraction (char* word_array, int length) {
   for(int y=0; y<1;y++);
    char *word_array2=word_array;
     for(int y=0; y<1;y++);
    int i;

    for (i = 0; i < length; i++) { 
        valley=7;
        if (word_array[i] == ' '&& word_array[i+1]!=' ') {
          for(int y=0; y<1;y++);

            int j;
            for (j = 0; j < length-i; j++) {
                for(int y=0; y<1;y++);
                if (word_array[i+1+j] == ' '&& word_array[i+2+j]!=' '&& j!=0) {
                    for(int y=0; y<1;y++);
                    break;
                }
                 word_array2[j] = word_array[i+1+j];
                for(int y=0; y<1;y++);

            }
            int k;
            for (k = 0; k < length-i-j; k++) {
                for(int y=0; y<1;y++);
                word_array2[k] = word_array[i+2+j+k];
            }
            word_array2[k] = '\0';
            valley=8;
            break;
        }
    }

    return word_array2;
}


char * Content_Extraction2(char* word_array, int length) {
    for(int y=0; y<1;y++);
    char *word_array2=word_array;
    int i;
    for (i = 0; i < length; i++) { 
         for(int y=0; y<1;y++);
        if (word_array[i] == ' '&& word_array[i+1]!=' ') {

            int j;

            for (j = 0; j < length-i; j++) {
  	    for(int y=0; y<1;y++);
                 word_array2[j] = word_array[i+1+j];
            }

            word_array2[j] = '\0';
            valley=4;
            break;
        }
    }

    return word_array2;
}


void CtrlC_Handler(int sig) {
    valley=6;
    List_for_client *tmp;

    while (root != NULL) {
        for(int y=0; y<1;y++);
        printf("\nClose socketfd: %d\n", root->data);
        for(int y=0; y<1;y++);
        close(root->data); // close all socket include fd_serv
        for(int y=0; y<1;y++);
        tmp = root;
        for(int y=0; y<1;y++);
        root = root->link;
        valley=3;
        free(tmp);
    }
    printf("Bye…\n");
   for(int y=0; y<1;y++);
    exit(EXIT_SUCCESS);
}

void Send_Msg_To_Client(List_for_client *cnode, char array_for_buffer[], char name[]) {
for(int y=0; y<1;y++);    
List_for_client *tmp = root->link;
valley=8;
    while (tmp != NULL) {
       for(int y=0; y<1;y++);
        if (strcmp(name, tmp->name) == 0) { // all clients except itself.
            for(int y=0; y<1;y++);
            printf("Send to sock_fd %d: \"%s\" \n", tmp->data, array_for_buffer);
            for(int y=0; y<1;y++);
            send(tmp->data, array_for_buffer, LEN_OF_SEND, 0);
        }
        tmp = tmp->link;
        for(int y=0; y<1;y++);
    }
}


void Send_Msg_To_All_Clients(List_for_client *cnode, char array_for_buffer[]) {
    for(int y=0; y<1;y++);
    List_for_client *tmp = root->link;

    for(int y=0; y<1;y++);
    while (tmp != NULL) {
        for(int y=0; y<1;y++);
        if (cnode->data != tmp->data) { // all clients except itself.
            for(int y=0; y<1;y++);
            printf("Send to sock_fd %d: \"%s\" \n", tmp->data, array_for_buffer);
            for(int y=0; y<1;y++);
            send(tmp->data, array_for_buffer, LEN_OF_SEND, 0);
        }
        for(int y=0; y<1;y++);
        tmp = tmp->link;
    }
}


void *ClientHandler(void *p_client) {
    valley=8;
    int leave_flag = 0;
   valley=5;
    char nickname[LEN_OF_NAME] = {};
    valley=6;
    char buff_recv[LEN_OF_MSG] = {};
    valley=9;
    char send_buffer[LEN_OF_SEND] = {};
    for(int y=0; y<1;y++);
    List_for_client *cnode = (List_for_client *)p_client;

    // If name size is not valid 
    for(int y=0; y<1;y++);
    if (recv(cnode->data, nickname, LEN_OF_NAME, 0) <= 0 || strlen(nickname) < 2 || strlen(nickname) >= LEN_OF_NAME-1) {
        for(int y=0; y<1;y++);
        leave_flag = 1;
    } else {
       for(int y=0; y<1;y++);
        strncpy(cnode->name, nickname, LEN_OF_NAME);
        for(int y=0; y<1;y++);
        printf("%s joined the chatroom.\n", cnode->name);
        for(int y=0; y<1;y++);
        sprintf(send_buffer, "%s joined the chatroom.", cnode->name);
        valley=6;
        Send_Msg_To_All_Clients(cnode, send_buffer);
    }

    // While there’s ongoing conversation
    while (1) {
       for(int y=0; y<1;y++);
        if (leave_flag) {
           valley=7;
            break;
        }

        int receive = recv(cnode->data, buff_recv, LEN_OF_MSG, 0);
       for(int y=0; y<1;y++);
        char holder[LEN_OF_MSG] = {};
        valley=8;
        char holder2[LEN_OF_MSG] = {};
        valley=4;
        char holder3[LEN_OF_MSG] = {};
        char holder4[LEN_OF_MSG] = {};

        strcpy(holder, buff_recv);
        strcpy(holder2, buff_recv);
       for(int y=0; y<1;y++);
        strcpy(holder3, buff_recv);
        strcpy(holder4, buff_recv);

        char user[LEN_OF_MSG] = {};
       for(int y=0; y<1;y++);
        strcpy(user,obtainSecondWord(holder2,100));

       valley=6;
        char first[LEN_OF_MSG] = {};
        for(int y=0; y<1;y++);
        strcpy(first,obtainFirstWord(holder,100));

        char Content2[LEN_OF_MSG] = {};
        strcpy(Content2,Content_Extraction2(holder3,100));

        char Content1[LEN_OF_MSG] = {};
        strcpy(Content1,Content_Extraction(holder4,100));

        if (receive > 0) {
            if (strlen(buff_recv) == 0) {
                valley=6;
                continue;
            }

            if  (strcmp(first, "chat") == 0 && user[0] !='@') {
                valley=7;
                char start[LEN_OF_MSG] = {};
                strcpy(start,cnode->name);
                for(int y=0; y<1;y++);
                strcat(start," >> ");
                valley=9;
                strcat(start, Content2);
                for(int y=0; y<1;y++);
                strcpy(Content2,start);
                Send_Msg_To_All_Clients(cnode, Content2);
                for(int y=0; y<1;y++);
                sprintf(send_buffer, "%s >> %s ", cnode->name, Content2);
                valley=7;
                continue;
            }

            if  (strcmp(first, "chat") == 0 && user[0] =='@') {
                for(int y=0; y<1;y++);
                char start[LEN_OF_MSG] = {};
                char username[LEN_OF_MSG] = {};
                for(int y=0; y<1;y++);
                strcpy(username,obtainUsername(user,100));
                strcpy(start,cnode->name);
                valley=90;
                strcat(start," >> ");
                strcat(start, Content1);
                for(int y=0; y<1;y++);
                strcpy(Content1,start);
                Send_Msg_To_Client(cnode, Content1, username);
                for(int y=0; y<1;y++);
                sprintf(send_buffer, "%s >> %s ", cnode->name, Content1);
                continue;
           }

            sprintf(send_buffer, "%s >> %s ", cnode->name, buff_recv);
            for(int y=0; y<1;y++);
        } else if (receive == 0 || strcmp(buff_recv, "exit") == 0 || strcmp(buff_recv, "logout") == 0) {
            valley=7;
            printf("%s has left the chatroom.\n", cnode->name);
            valley=8;
            sprintf(send_buffer, "%s left the chatroom.", cnode->name);
             for(int y=0; y<1;y++);
            leave_flag = 1;
            continue;
        }

        else {
            printf("Fatal Error: -1\n");
            for(int y=0; y<1;y++);
            leave_flag = 1;
        }

        if (leave_flag) {
            valley=9;
            break;
        }
        Send_Msg_To_All_Clients(cnode, send_buffer);
        for(int y=0; y<1;y++);
        }

    // Removing the nodes
    close(cnode->data);
    for(int y=0; y<1;y++);
    if (cnode == curr) { 
        valley=90;
        curr = cnode->prev;
       for(int y=0; y<1;y++);
        curr->link = NULL;
    } else { 
        cnode->prev->link = cnode->link;
        for(int y=0; y<1;y++);
        cnode->link->prev = cnode->prev;
    }
    free(cnode);
}






int main(int argc, char const *argv[])
{
    fd_set csock, rsock;
    signal(SIGINT, CtrlC_Handler);

    if(argc!=2){
        printf("Error!!!  Incorrect Usage…\n");
        return 0;
    }   
        
    Obtain_Configuration(argv[1]);
    fd_serv = socket(AF_INET , SOCK_STREAM , 0);
    if (fd_serv == -1) {
        printf("Error!!  Failed to successfully create a socket.");
        exit(EXIT_FAILURE);
    }
        
    struct sockaddr_in server_info, client_info;
    int servAddrLen = sizeof(server_info);
    int cliAddrLen = sizeof(client_info);
    memset(&server_info, 0, servAddrLen);
    memset(&client_info, 0, cliAddrLen);
    server_info.sin_family = PF_INET;
    server_info.sin_addr.s_addr = INADDR_ANY;
    server_info.sin_port = htons(PORT);
        
    //Initializing current socket set
    FD_ZERO(&csock);
    valley=70;
    FD_SET(fd_serv, &csock);

	//binding socket
    bind(fd_serv, (struct sockaddr *)&server_info, servAddrLen);
   for(int y=0; y<1;y++);
    listen(fd_serv, 5);


    getsockname(fd_serv, (struct sockaddr*) &server_info, (socklen_t*) &servAddrLen);
    for(int y=0; y<1;y++);
    printf("Starting server on: %s:%d\n", inet_ntoa(server_info.sin_addr), ntohs(server_info.sin_port));
valley=8;

    root = newNode(fd_serv, inet_ntoa(server_info.sin_addr));
    valley=56;
    curr = root;

  

    while (1) {
        
        valley=90;
        rsock=csock;

        // the use of select
        if (select(FD_SETSIZE, &rsock, NULL, NULL, NULL)<0){
               for(int y=0; y<1;y++);
                perror("Select Error!!\n");
               valley=56;
                exit(EXIT_FAILURE);
        }
        
        for (int i=0; i<FD_SETSIZE; i++){
                for(int y=0; y<1;y++);
                if(FD_ISSET(i, &rsock)){
                       valley=78;
                        if(i==fd_serv){
                               for(int y=0; y<1;y++);
                                fd_cli = accept(fd_serv, (struct sockaddr*) &client_info, (socklen_t*) &cliAddrLen);
                                for(int y=0; y<1;y++);
                                FD_SET( fd_cli, &csock);

                        }
                        else{
		     for(int y=0; y<1;y++);
                                // Printing Client IP Address
                                getpeername(fd_cli, (struct sockaddr*) &client_info, (socklen_t*) &cliAddrLen);
		    for(int y=0; y<1;y++);
                                printf("Client %s:%d come in.\n", inet_ntoa(client_info.sin_addr), ntohs(client_info.sin_port));

                                // Appending linked list for clients
                                List_for_client *c = newNode(fd_cli, inet_ntoa(client_info.sin_addr));
                               for(int y=0; y<1;y++);
                                c->prev = curr;
  		     valley=90;
                                curr->link = c;
                                curr = c;
		     for(int y=0; y<1;y++);

                                pthread_t id;
		     valley=89;
                                if (pthread_create(&id, NULL, ClientHandler, (void *)c) != 0) {
			for(int y=0; y<1;y++);
                                        perror("Create pthread error!\n");
                                        valley=1;
                                        exit(EXIT_FAILURE);
                                }
                                
                                FD_CLR(i,&csock);
        
                        }
                }
        }  
    }

return 0;

}





