#ifndef S_N_User
#define S_N_User
#ifndef S_N_Message
#define S_N_Message

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
#endif
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
int signup(char *in_username,char *in_password,S_N_User *firstNode_user,S_N_User *newNode)
{
    S_N_User* currentNode;
    S_N_User* checkedNode;
    checkedNode=firstNode_user->next1;

    //exists or not--------------------------------------------------------------------
    
    while(checkedNode != NULL)
    {
        if(strcmp(checkedNode->username,in_username)==0)
        {
            printf("Choose another username!\n");
            return FALSE;
        }
        else
            checkedNode = checkedNode->next1;
    }
            
    //--------------------------------------------------------------------------------

    currentNode = firstNode_user->next1;
    if(currentNode==NULL)
    {
        firstNode_user->next1 = newNode;
        newNode->next1 = NULL;
        newNode->username=(char*)malloc(100*sizeof(char));
        newNode->password=(char*)malloc(100*sizeof(char));
        strcpy(newNode->username,in_username);
        strcpy(newNode->password ,in_password);
        newNode->pointer=NULL;
        printf("username: %s\npassword: %s\n",newNode->username,newNode->password);
        return TRUE;
    }
    else
    {
        while(currentNode != NULL)
        {
            if(currentNode->next1==NULL)
            {
                currentNode->next1 = newNode;
                newNode->next1 = NULL;
                newNode->username=(char*)malloc(100*sizeof(char));
                newNode->password=(char*)malloc(100*sizeof(char));
                strcpy(newNode->username,in_username);
                strcpy(newNode->password ,in_password);
                newNode->pointer=NULL;
                printf("username: %s\npassword: %s\n",newNode->username,newNode->password);
                return TRUE;
            }
            else
            {
                currentNode = currentNode->next1;
            }
        }
    }
}