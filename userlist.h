/*piotr
22.05.2019
*/ 

#ifndef _USERLIST
#define _USERLIST

/*includes------------------------------------------------------*/
#include "app.h"

/*user list element typedef*/
typedef struct listElem{
    user_t * m_user;
    struct listElem * next;
    struct listElem * prev;
}listElem_t;

/*user list typedef*/
typedef struct userList{
    listElem_t * head;
    pthread_mutex_t list_mutex;
    int counter;
}userList_t;

/*function declarations------------------------------------------*/

/*
initialize userList_t structure.
Return -1 if error.
*/
int userList_init(userList_t * list);

/*
create element with given data and store at the beginning of the list.
If list is empty (head is NULL), data is stored as head.
If failed, return -1.
*/
int store_element(userList_t * list, user_t * usr);

/*
return element from list with name equal to given.
If there is no such user, return NULL.
*/
listElem_t * find_user_by_name(userList_t * list, const char * username);

/*
Combine addresses and names of all users from list 
into one message and send it through filedesc.
Return number of elements in list (0 if empty).
Return -1 if error.
*/
int send_user_list(userList_t * list, user_t * usr);

/*Display address and name of every user from list.
Return number of elements in list.
Return -1 if error.
*/
int display_user_list(userList_t * list);

/*
Remove element from list,
then return number of elements in list.
Return -1 if error.
*/
int delete_user(userList_t * list, listElem_t * elem);

/*
send message to all users in list.
Return -1 if failed.
*/
int send_to_all(userList_t * list, char * message);

#endif
