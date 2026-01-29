#include"apc.h"


int insert_at_front(Node **head, Node **tail, int data)
{
    Node *new = malloc(sizeof(Node));
    if (!new)
        return FAILURE;

    new->data = data;
    new->prev = NULL;
    new->next = *head;

    if (*head)
        (*head)->prev = new;
    else
        *tail = new;
        
    *head = new;
    return SUCCESS;
}

int insert_at_end(Node **head, Node **tail, int data)
{
    Node *new = malloc(sizeof(Node));
    if (!new)
        return FAILURE;

    new->data = data;
    new->next = NULL;
    new->prev = *tail;

    if (*tail)
        (*tail)->next = new;
    else
        *head = new;

    *tail = new;
    return SUCCESS;
}




int copy_list(Node *src, Node **dh, Node **dt)
{
    *dh = *dt = NULL;

    while (src)
    {
        Node *n = malloc(sizeof(Node));
        if (!n) return FAILURE;

        n->data = src->data;
        n->prev = *dt;
        n->next = NULL;

        if (*dt)
            (*dt)->next = n;
        else
            *dh = n;

        *dt = n;
        src = src->next;
    }
    return SUCCESS;
}




int compare( Node *h1,  Node *h2)
{
    int len1=0,len2=0;
    Node *t1=h1,*t2=h2;

if (!h1 && !h2) return 0;
if (!h1) return -1;
if (!h2) return 1;
    while (t1) 
    {
         len1++; t1 = t1->next; 
    }
    while (t2) 
    {
         len2++; t2 = t2->next;
    }

    if (len1 > len2) return 1;
    if (len1 < len2) return -1;

    t1=h1;
    t2=h2;

    while (t1 && t2)
    {
        if (t1->data > t2->data)
        return 1;
        if (t1->data < t2->data)
        return -1;
        t1 = t1->next;
        t2 = t2->next;
    }
    return 0;
}

void remove_leading_zeros(Node **h)
{
    while (*h && (*h)->data == 0 && (*h)->next)
    {
        Node *temp = *h;
        *h = (*h)->next;
        (*h)->prev = NULL;
        free(temp);
    }
}
void free_list(Node *h)
{
    Node *temp;
    while (h)
    {
        temp = h;
        h = h->next;
        free(temp);
    }
}
int is_zero(Node *h)
{
    return (h && h->next == NULL && h->data == 0);
}