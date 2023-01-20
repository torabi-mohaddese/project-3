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
int delete(int id_post,S_N_User* check2)
{
    S_N_Message* previousNode_message;
    S_N_Message* currentNode_message;
    previousNode_message=check2->pointer;
    currentNode_message=previousNode_message->next2;
    if((previousNode_message->next2)==NULL)
    {
        if(previousNode_message->post_ID==id_post)
        {
            check2->pointer=NULL;
            free(previousNode_message);
            printf("You deleted your post successfully!*");
            return TRUE;
                    
        }
        else
        {
            printf("You don't have this post!");
            return FALSE;
        }
    }
    else
    {
        if(id_post==previousNode_message->post_ID)
        {
            check2->pointer=currentNode_message;
            free(previousNode_message);
            printf("You deleted your post successfully!");
            return TRUE;
        }
        else
        {
            while(currentNode_message!=NULL)
            {
                if(currentNode_message->post_ID==id_post)
                {
                    previousNode_message->next2=currentNode_message->next2;
                    free(currentNode_message);
                    printf("You deleted your post successfully!");
                    return TRUE;
                }
                else
                {
                    previousNode_message=currentNode_message;
                    currentNode_message=currentNode_message->next2;
                }
            }
        }
    }
}
