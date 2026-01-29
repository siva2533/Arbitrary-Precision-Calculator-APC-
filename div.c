#include"apc.h"

int divi(Node **h1, Node **t1,Node **h2, Node **t2,Node **qh, Node **qt,Node **rh, Node **rt)
{
    
    if (*h2 == NULL)
        return FAILURE;

    *qh = *qt = NULL;
    *rh = *rt = NULL;

    Node *cur = *h1;

    
    while (cur)
    {
        
        insert_at_end(rh, rt, cur->data);

        
        while (*rh && (*rh)->data == 0 && (*rh)->next)
        {
            Node *tmp = *rh;
            *rh = (*rh)->next;
            (*rh)->prev = NULL;
            free(tmp);
        }

        int count = 0;

        
        while (compare(*rh, *h2) >= 0)
        {
            Node *new_h = NULL, *new_t = NULL;
            subtract_mag(rh, rt, h2, t2, &new_h, &new_t);
            *rh = new_h;
            *rt = new_t;
            count++;
        }

        insert_at_end(qh, qt, count);
        cur = cur->next;
    }


    while (*qh && (*qh)->data == 0 && (*qh)->next)
    {
        Node *tmp = *qh;
        *qh = (*qh)->next;
        (*qh)->prev = NULL;
        free(tmp);
    }

    return SUCCESS;
}

int div_decimal(Node **h1, Node **t1,Node **h2, Node **t2,Node **qh, Node **qt,Node **dh, Node **dt)
{
    Node *rem_h = NULL, *rem_t = NULL;

    
    divi(h1, t1, h2, t2, qh, qt, &rem_h, &rem_t);

    *dh = *dt = NULL;

    
    for (int i = 0; i < DECIMAL_PRECISION; i++)
    {
    
        Node *ten_h = NULL, *ten_t = NULL;
        insert_at_front(&ten_h, &ten_t, 1);
        insert_at_end(&ten_h, &ten_t, 0);

        Node *mul_h = NULL, *mul_t = NULL;
        mul(&rem_h, &rem_t, &ten_h, &ten_t, &mul_h, &mul_t);

        rem_h = mul_h;
        rem_t = mul_t;

        int digit = 0;
        while (compare(rem_h, *h2) >= 0)
        {
            Node *nh = NULL, *nt = NULL;
            subtract_mag(&rem_h, &rem_t, h2, t2, &nh, &nt);
            rem_h = nh;
            rem_t = nt;
            digit++;
        }

        insert_at_end(dh, dt, digit);
    }

    return SUCCESS;
}