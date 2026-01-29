#include "apc.h"

int main(int argc,char *argv[])
{
    Node *h1=NULL, *t1=NULL;
    Node *h2=NULL, *t2=NULL;
    Node *rh=NULL, *rt=NULL;

    int sign1=1,sign2=1,sign=1;
    
    


    if((validate(argc,argv))!=SUCCESS)
    {
        printf("Validation failed\n");
        return 0;
    }
    
    

    if(argv[1][0]=='-')
    sign1=-1;

    if(argv[3][0]=='-')
    sign2=-1;


    
     if(convert(&h1,&t1,&h2,&t2,argv)!=SUCCESS)
     {
        printf("Operands conversion failed!\n");
        free_list(h1);
        free_list(h2);
        free_list(rh);
        return 0;
    }
    remove_leading_zeros(&h1);
    remove_leading_zeros(&h2);
    
if ((argv[2][0] == '/' || argv[2][0] == '%') && is_zero(h2))
{
    printf("Error: Division by zero\n");
    free_list(h1);
    free_list(h2);
    free_list(rh);
    return 1;
}
    


    if (argv[2][0] == '+')
{
    if (sign1 == sign2)
    {
        add(&h1, &t1, &h2, &t2, &rh, &rt);
        sign = sign1;
    }
    else
    {
        int cmp = compare(h1, h2);

        if (cmp == 0)
        {
            insert_at_end(&rh, &rt, 0);
            sign = 1;
        }
        else if (cmp > 0)
        {
            sub(&h1, &t1, &h2, &t2, &rh, &rt, 1, 1, &sign);
            sign = sign1;
        }
        else
        {
            sub(&h2, &t2, &h1, &t1, &rh, &rt, 1, 1, &sign);
            sign = sign2;
        }
    }
}
    else if (argv[2][0] == '-')
    {
        sub(&h1, &t1, &h2, &t2, &rh, &rt, sign1, sign2, &sign);
    }
    else if(argv[2][0]=='x' )
    {
        mul(&h1, &t1, &h2, &t2, &rh, &rt);
        sign = sign1 * sign2;
    }

    else if (argv[2][0] == '/')
    {
    Node *qh = NULL, *qt = NULL;
    Node *dh = NULL, *dt = NULL;

    div_decimal(&h1, &t1, &h2, &t2, &qh, &qt, &dh, &dt);

    sign = sign1 * sign2;

    rh = qh;
    rt = qt;

    printf("%s %s %s is ",argv[1],argv[2],argv[3]);
    if (sign == -1)
        printf("-");

    Node *tmp = rh;
    while (tmp)
    {
        printf("%d", tmp->data);
        tmp = tmp->next;
    }

    printf(".");

    
    tmp = dh;
    while (tmp)
    {
        printf("%d", tmp->data);
        tmp = tmp->next;
    }

    printf("\n");
    free_list(h1);
    free_list(h2);
    free_list(rh);
    return 0;
    }
    else if (argv[2][0] == '%')
    {
    mod(&h1, &t1, &h2, &t2, &rh, &rt);
    sign = sign1;
    }

    else if (argv[2][0] == '^')
    {
    int exp = 0;
    for (int i = 0; argv[3][i]; i++)
    {
    if (argv[3][i] < '0' || argv[3][i] > '9')
    {
        printf("Invalid exponent\n");
        free_list(h1);
        free_list(h2);
        free_list(rh);
        return 0;
    }
    exp = exp * 10 + (argv[3][i] - '0');
    if (exp > MAX_EXP)
    {
        printf("Exponent too large\n");
        free_list(h1);
        free_list(h2);
        free_list(rh);
        return 0;
    }
    }
    if (power(&h1, &t1, exp, &rh, &rt) == FAILURE)
    return 0;
    sign = (sign1 == -1 && (exp % 2)) ? -1 : 1;
    }
   
    printf("%s %s %s is ",argv[1],argv[2],argv[3]);
    
        if(sign==-1)
        printf("-");
        if (!rh) printf("0");

        Node *temp=(rh);
        while(temp!=NULL)
        {
            printf("%d",temp->data);
            temp=temp->next;
        }
        printf("\n"); 
        free_list(h1);
        free_list(h2);
        free_list(rh);
        return 0;

}

