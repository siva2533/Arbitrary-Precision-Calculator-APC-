#include"apc.h"


int mul(Node **h1, Node **t1,Node **h2, Node **t2,Node **rh, Node **rt)
{
    Node *tp2 = *t2;
    int pos = 0;

    *rh = *rt = NULL;

    while (tp2)
    {
        Node *tp1 = *t1;
        Node *temp_h = NULL, *temp_t = NULL;
        int carry = 0;

        while (tp1)
        {
            int prod = tp1->data * tp2->data + carry;
            carry = prod / 10;
            insert_at_front(&temp_h, &temp_t, prod % 10);
            tp1 = tp1->prev;
        }

        if (carry)
            insert_at_front(&temp_h, &temp_t, carry);

        
        for (int i = 0; i < pos; i++)
        {
            Node *z = malloc(sizeof(Node));
            z->data = 0;
            z->next = NULL;
            z->prev = temp_t;

            if (temp_t)
                temp_t->next = z;
            else
                temp_h = z;

            temp_t = z;
        }

        Node *new_h = NULL, *new_t = NULL;
        add(rh, rt, &temp_h, &temp_t, &new_h, &new_t);

        *rh = new_h;
        *rt = new_t;

        tp2 = tp2->prev;
        pos++;
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