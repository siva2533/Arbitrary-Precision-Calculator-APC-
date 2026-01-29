#include "apc.h"

int power(Node **bh, Node **bt, int exp, Node **rh, Node **rt)
{
    (void)bt;
    if (exp < 0)
    {
        printf("Negative exponent not supported\n");
        return FAILURE;
    }

    *rh = *rt = NULL;
    insert_at_front(rh, rt, 1);

    if (exp == 0)
        return SUCCESS;

    Node *base_h = NULL, *base_t = NULL;
    copy_list(*bh, &base_h, &base_t);

    while (exp > 0)
    {
        if (exp & 1)
        {
            Node *nh = NULL, *nt = NULL;
            mul(rh, rt, &base_h, &base_t, &nh, &nt);
            *rh = nh;
            *rt = nt;
        }

        exp >>= 1;
        if (exp)
        {
            Node *sqh = NULL, *sqt = NULL;
            mul(&base_h, &base_t, &base_h, &base_t, &sqh, &sqt);
            base_h = sqh;
            base_t = sqt;
        }
    }

    return SUCCESS;
}