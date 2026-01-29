#include"apc.h"

int validate(int argc,char *argv[])
{
    if(argc!=4)
    {
        printf("Invalid Argument\n Format : (operand_1) (operator) (operator_2)\n");
        return FAILURE;
    }    
    
    
    for(int i=0;argv[1][i]!='\0';i++)
    {
        if(i==0 && argv[1][0]=='-')
        continue;

        if(!(argv[1][i]>='0' && argv[1][i]<='9'))
        {
            printf("Invalid operand 1 !\n");
            return FAILURE;
        } 
    }
    
    if(!(argv[2][0]=='+' || argv[2][0]=='-' || argv[2][0]=='*' || argv[2][0]=='x' || argv[2][0]=='/' || argv[2][0]=='%' || argv[2][0]=='^'))
    {
        printf("Invalid operator %s\n",argv[2]);
        return FAILURE;
    }

    if (argv[2][1] != '\0')
{
    printf("Invalid operator\n");
    return FAILURE;
}

    for(int i=0;argv[3][i]!='\0';i++)
    {
        if(i==0 && argv[3][0]=='-')
        continue;

        if(!(argv[3][i]>='0' && argv[3][i]<='9'))
        {
            printf("Invalid operand 2 !\n");
            return FAILURE;
        } 
    }
    if (argv[1][0] == '-' && argv[1][1] == '\0')
    return FAILURE;

    if (argv[3][0] == '-' && argv[3][1] == '\0')
    return FAILURE;
    
    return SUCCESS;
   

}


int convert(Node **h1,Node **t1,Node **h2,Node **t2,char *argv[])
{
    
    for (int i=0;argv[1][i]!='\0';i++)
    {
        if(i==0 && argv[1][0]=='-')
        continue;

        Node *new =malloc(sizeof(Node));
        new->data=argv[1][i]-'0';
        new->prev=NULL;
        new->next=NULL;

        if(*h1==NULL)
        {
            *h1=new;
            *t1=new;
        }
        else
        {
            new->prev=*t1;
            (*t1)->next=new;
            *t1=new;
        }
    }
    
    for (int i=0;argv[3][i]!='\0';i++)
    {
        if(i==0 && argv[3][0]=='-')
        continue;

        Node *new =malloc(sizeof(Node));
        new->data=argv[3][i]-'0';
        new->prev=NULL;
        new->next=NULL;

        if(*h2==NULL)
        {
            *h2=new;
            *t2=new;
        }
        else
        {
            new->prev=*t2;
            (*t2)->next=new;
            *t2=new;
        }
    }



    return SUCCESS;
}

