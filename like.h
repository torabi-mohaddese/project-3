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
int like(int id_post,char *in_username,S_N_User *firstNode_user)
{
    S_N_Message* currentNode_message;
    S_N_User* currentNode;
    currentNode=firstNode_user->next1;
    if(currentNode==NULL)
    {
        printf("There is no user here!\n");
    }          
    else
    {
        while(currentNode!=NULL)
        {
            if(strcmp(in_username,currentNode->username)==0)
            {
                currentNode_message=currentNode->pointer;
                if(currentNode_message==NULL)
                {
                    printf("This user doesn't have any posts.\n");
                    return FALSE;
                }
                else
                {
                    while(currentNode_message!=NULL)
                    {
                        if((currentNode_message->post_ID)==id_post)
                        {
                            (currentNode_message->likes)=(currentNode_message->likes)+1;
                            printf("likes:%d",currentNode_message->likes);
                            return TRUE;
                        }
                        else
                        {
                            currentNode_message=currentNode_message->next2;
                            if(currentNode_message==NULL)
                            {
                                printf("There is no post with this ID.\n");
                                return FALSE;
                            }
                        }
                    }
                }
            }
            else
            {
                currentNode=currentNode->next1;
                if(currentNode==NULL)
                {
                    printf("This user doesn't exist\n");
                    return FALSE;
                }
            }
        }
    }
}
