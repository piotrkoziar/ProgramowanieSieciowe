/*
piotr
22.05.2019
*/

#ifndef _APP
#define _APP

/*includes------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/errno.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>
#include <pthread.h>
#include <fcntl.h>

/*defines------------------------------------------------------*/
#define BUFFER_SIZE 1024
#define LISTENQ 10
#define USER_NAME_LENGTH 20
#define MAX_CMD_LENGTH 20
#define CHAT_NAME_LENGTH 20


/*user_t typedef*/
typedef struct user_t {
    char user_name[USER_NAME_LENGTH + 1];
    struct sockaddr_in user_address;
    int * fildesc;
    char * chatroom_name;
}user_t;


#endif
