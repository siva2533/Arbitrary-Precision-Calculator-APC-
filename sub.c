#include"apc.h"

int sub(Node **h1, Node **t1,Node **h2, Node **t2, Node **rh, Node **rt,int sign1, int sign2, int *rsign)
{
    *rh = *rt = NULL;

    if (sign1 == 1 && sign2 == 1)
    {
        int cmp = compare(*h1, *h2);

        if (cmp == 0)
        {
            Node *z = malloc(sizeof(Node));
            z->data = 0;
            z->prev = z->next = NULL;
            *rh = *rt = z;
            *rsign = 1;
        }
        else if (cmp > 0)
        {
            subtract_mag(h1, t1, h2, t2, rh, rt);
            *rsign = 1;
        }
        else
        {
            subtract_mag(h2, t2, h1, t1, rh, rt);
            *rsign = -1;
        }
    }

    else if (sign1 == 1 && sign2 == -1)
    {
        add(h1, t1, h2, t2, rh, rt);
        *rsign = 1;
    }

    
    else if (sign1 == -1 && sign2 == 1)
    {
        add(h1, t1, h2, t2, rh, rt);
        *rsign = -1;
    }

    else
    {
        int cmp = compare(*h2, *h1);

        if (cmp == 0)
        {
            Node *z = malloc(sizeof(Node));
            z->data = 0;
            z->prev = z->next = NULL;
            *rh = *rt = z;
            *rsign = 1;
        }
        else if (cmp > 0)
        {
            subtract_mag(h2, t2, h1, t1, rh, rt);
            *rsign = 1;
        }
        else
        {
            subtract_mag(h1, t1, h2, t2, rh, rt);
            *rsign = -1;
        }
    }

    return SUCCESS;
}

int subtract_mag(Node **hbig, Node **tbig,Node **hsmall, Node **tsmall,Node **rh, Node **rt)
{
    Node *tp1 = *tbig;
    Node *tp2 = *tsmall;
    int borrow = 0;

    *rh = *rt = NULL;

    while (tp1 || tp2)
    {
        int d1 = tp1 ? tp1->data : 0;
        int d2 = tp2 ? tp2->data : 0;

        int diff = d1 - borrow - d2;

        if (diff < 0)
        {
            diff += 10;
            borrow = 1;
        }
        else
            borrow = 0;

        Node *new = malloc(sizeof(Node));
        new->data = diff;
        new->prev = NULL;
        new->next = *rh;

        if (*rh)
            (*rh)->prev = new;
        else
            *rt = new;

        *rh = new;

        if (tp1) tp1 = tp1->prev;
        if (tp2) tp2 = tp2->prev;
    }

    while (*rh && (*rh)->data == 0 && (*rh)->next)
    {
        Node *tmp = *rh;
        *rh = (*rh)->next;
        (*rh)->prev = NULL;
        free(tmp);
    }

    return SUCCESS;
}  
