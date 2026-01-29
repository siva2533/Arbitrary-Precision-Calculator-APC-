#include "apc.h"
int add(Node **h1,Node **t1,Node **h2,Node **t2,Node **rh,Node **rt)
{
    (void)h1;
    (void)h2;
 Node *tp1=*t1;
 Node *tp2=*t2;
 
 int sum=0,carry=0;


 while(tp1!=NULL || tp2!=NULL)
 {
    sum=carry;

    if(tp1!=NULL)
    {
        sum+=tp1->data;
        tp1=tp1->prev;
    }

    if(tp2!=NULL)
    {
        sum+=tp2->data;
        tp2=tp2->prev;
    }
    carry=sum/10;
    sum=sum%10;

    Node *new=malloc(sizeof(Node));
    new->data=sum;
    new->next=NULL;
    new->prev=NULL;

    if(*rh==NULL)
    {
        *rh=new;
        *rt=new;
    }
    else
    {
        new->next=(*rh);
        (*rh)->prev=new;
        *rh=new;
    }

 }
 if (carry)
{
    Node *new = malloc(sizeof(Node));
    new->data = carry;
    new->prev = NULL;
    new->next = *rh;

    if (*rh)
        (*rh)->prev = new;
    else
        *rt = new;

    *rh = new;
}

 return SUCCESS;
}