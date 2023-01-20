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

int main()
{
    printf("          *****          Hello!          *****\n          *****   Welcome to Ut_Tuti^^   *****\n");
    
    S_N_User* firstNode_user=(S_N_User*)malloc(sizeof(S_N_User));
    S_N_Message* firstNode_message=(S_N_Message*)malloc(sizeof(S_N_Message));
    S_N_User* previousNode;
    S_N_User* newNode;
    S_N_Message* currentNode_message;
    S_N_Message* previousNode_message;
    S_N_User* currentNode;
    firstNode_message->next2 = NULL;
    firstNode_user->next1=NULL;
    char *input = (char*)malloc(sizeof(char)*100);
    char *in_username = (char*)malloc(sizeof(char)*100);
    char *in_password = (char*)malloc(sizeof(char)*100);
    char *post=(char*)malloc(sizeof(char)*200);
    int check1;
    S_N_User *check2=NULL;
    int check3;
    int id_counter=2;
    int id_post;

    //scanning-------------------------------------------------------------------------------

    
    while(TRUE)
    {
        printf("\n          *****          Enter           *****\n");
        scanf("%s",input);
        if(strcmp(input,"signup")==0)
        {
            scanf("%s ",in_username);
            scanf("%s",in_password);

            //now signing in-------------------------------------------------------------------------

            newNode = (S_N_User*)malloc(sizeof(S_N_User));
            check1 = signup(in_username,in_password,firstNode_user,newNode);
            if(check1==TRUE)
            {
                printf("You joined Ut_Tuti successfully^^!\n");
            }
        }
        if(strcmp(input,"login")==0)
        {
            scanf("%s ",in_username);
            scanf("%s",in_password);
            //check2 is the pointer to the user that logged in!
            check2 = login(in_username,in_password,firstNode_user);
            if(check2==NULL)
            {
                printf("Doesn't exist, please try an other username^^.\n");
            }
            else
            {
                printf("\n          Now you have more choices:)\n          *logout\n          *info\n          *finding other friends,etc.\n");
            }
        }
        if(strcmp(input,"logout")==0)
        {
            if(check2==NULL)
            {
                printf("Please login at first^^.\n");
            }
            else
            {
                //
                previousNode=firstNode_user;
                currentNode=firstNode_user->next1;
                while(currentNode!=NULL)
                {
                    if(strcmp(currentNode->username,check2->username)==0)
                    {
                        previousNode->next1=currentNode->next1;
                        printf("You deleted your account successfully^^.\n");
                        free(currentNode);
                    }
                    else
                    {
                        previousNode=currentNode;
                        currentNode=currentNode->next1;
                    }
                }
            }
        } 
        if(strcmp(input,"info")==0)
        {
            if(check2==NULL)
            {
                printf("Please login at first^^.\n");
            }
            else
            {
                currentNode_message=check2->pointer;
                printf("username: %s\npassword: %s\n\n",check2->username,check2->password);
                if(currentNode_message==NULL)
                {
                    printf("You don't have any post.\n");
                }
                while(currentNode_message!=NULL)
                {
                    printf("post: %s\npost_Id: %d\nlikes: %d\n\n",currentNode_message->content,currentNode_message->post_ID,currentNode_message->likes);
                    currentNode_message=currentNode_message->next2;
                }
            }
        }
        if(strcmp(input,"post")==0)
        {
            //Here we use check2 to know who wants to create new post!
            //We use id_counter to produce ID for our posts!
            if(check2==NULL)
            {
                printf("ERROR!\n");
            }
            else
            {
                if(check2->pointer==NULL)
                {
                    check2->pointer=(S_N_Message*)malloc(sizeof(S_N_Message));
                    currentNode_message=check2->pointer;
                    currentNode_message->next2=NULL;
                    gets(post);
                    currentNode_message->content=(char *)malloc(sizeof(char)*100);
                    strcpy(currentNode_message->content,post);
                    currentNode_message->likes=ZERO;
                    currentNode_message->post_ID=ONE;
                    printf("You upload your post successfully^^.\npost_ID=%d\nlikes=%d\n",currentNode_message->post_ID,currentNode_message->likes);
                }
                else
                {
                   previousNode_message=check2->pointer;
                   currentNode_message=previousNode_message->next2;
                   while(currentNode_message!=NULL)
                   {
                        previousNode_message=previousNode_message->next2;
                        currentNode_message=currentNode_message->next2;
                   }
                   if(currentNode_message==NULL)
                    {
                        currentNode_message=(S_N_Message*)malloc(sizeof(S_N_Message));
                        previousNode_message->next2=currentNode_message;
                        currentNode_message->next2=NULL;
                        gets(post);
                        currentNode_message->content=(char *)malloc(sizeof(char)*100);
                        strcpy(currentNode_message->content,post);
                        currentNode_message->likes=0;
                        currentNode_message->post_ID=id_counter;
                        id_counter++;                
                        printf("You upload your post successfully.\npost_ID=%d\nlikes=%d\n",currentNode_message->post_ID,currentNode_message->likes);
                    } 
                }
            }
        }
        if(strcmp(input,"like")==0)
        {
            scanf("%s ",in_username);
            scanf("%d",&id_post); 
            like(id_post,in_username,firstNode_user);
        }
        if(strcmp(input,"delete")==0)
        {
            previousNode_message=check2->pointer;
            currentNode_message=previousNode_message->next2;
            scanf("%d",&id_post);
            delete(id_post,check2);
        }
        if(strcmp(input,"find_user")==0)
        {
            scanf("%s",in_username);
            find_user(firstNode_user,in_username);
            
        }
        else if((strcmp(input,"find_user")!=0)&&(strcmp(input,"signup")!=0)&&(strcmp(input,"logout")!=0)&&(strcmp(input,"like")!=0)&&(strcmp(input,"info")!=0)&&(strcmp(input,"post")!=0)&&(strcmp(input,"login")!=0)&&(strcmp(input,"delete")!=0))
        {
            printf("Pay attention to your input!\n");
        }
        /*FILE* account;
        FILE* post;
        account=fopen("accounts.txt","w");
        fwrite();
        fclose(account);
        post=fopen("posts.txt","w");
        fwrite();
        fclose(post);*/
    }
}