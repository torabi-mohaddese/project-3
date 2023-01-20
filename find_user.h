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
int find_user(S_N_User *firstNode_user, char *in_username)
{
    S_N_User* currentNode;
    S_N_Message* currentNode_message;
    if(firstNode_user->next1==NULL)
    {
        printf("There is no user!\n");
        return FALSE;
    }
    else
    {
        currentNode=firstNode_user->next1;
        while(currentNode!=NULL)
        {
            if(strcmp(currentNode->username,in_username)==0)
            {
                printf("\nThe user was found successfully!\n");
                currentNode_message=currentNode->pointer;
                if(currentNode_message==NULL)
                {
                    printf("username: %s\n",in_username);
                    printf("This user doesn't have any post!\n");
                    return FALSE;
                }
                while(currentNode_message!=NULL)
                {
                    printf("username: %s\n",in_username);
                    printf("\npost: %s\npost_ID: %d\nlikes: %d\n",currentNode_message->content,currentNode_message->post_ID,currentNode_message->likes);
                    currentNode_message=currentNode_message->next2;
                    if(currentNode_message==NULL)
                    {
                        return TRUE;
                    }
                }
            }
            else
            {
                currentNode=currentNode->next1;
                if(currentNode==NULL)
                {
                    printf("The user wasn't found successfully!\n");
                    return FALSE;
                }
            }
        }
    }
}