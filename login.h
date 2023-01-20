#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define ZERO 0
#define ONE 1
typedef struct SocialNetworkUser S_N_User;
typedef struct SocialNetworkMessage S_N_Message;
struct SocialNetworkUser{
    char *username;
    char *password;
    S_N_User *next1;
    S_N_Message *pointer;
};
struct SocialNetworkMessage{
    char *content;
    int likes;
    int post_ID;
    S_N_Message *next2;
};
S_N_User* login(char *in_username,char *in_password,S_N_User *firstNode_user)
{
    S_N_User *checkedNode;
    S_N_User *user_pointer;
    checkedNode=firstNode_user->next1;
    if(checkedNode==NULL)
    {
        return NULL;
    }
    while(checkedNode != NULL)
    {
        if(strcmp(checkedNode->username,in_username)==0)
        {
            user_pointer = checkedNode;
            printf("You have logged in successfully!\n");
            return user_pointer;
        }
        else
        {
            checkedNode = checkedNode->next1;
            if(checkedNode==NULL)
            {
                return NULL;
            }
        }
    }
}