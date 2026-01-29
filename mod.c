#include "apc.h"

int mod(Node **h1, Node **t1,Node **h2, Node **t2,Node **rh, Node **rt)
{
    Node *qh = NULL, *qt = NULL;

    if (*h2 == NULL)
        return FAILURE;

    divi(h1, t1, h2, t2, &qh, &qt, rh, rt);

    while (*rh && (*rh)->data == 0 && (*rh)->next)
    {
        Node *tmp = *rh;
        *rh = (*rh)->next;
        (*rh)->prev = NULL;
        free(tmp);
    }

    return SUCCESS;
}