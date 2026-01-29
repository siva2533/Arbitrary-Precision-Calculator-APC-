#ifndef APC_H
#define APC_H 

#include<stdio.h>
#include<stdlib.h>

#define SUCCESS 1
#define FAILURE 0
#define DECIMAL_PRECISION 5
#define MAX_EXP 10000
typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
}Node;

int validate(int argc,char *argv[]);
int convert(Node **h1,Node **t1,Node **h2,Node **t2,char *argv[]);

int add(Node **h1,Node **t1,Node **h2,Node **t2,Node **rh,Node **rt);
int sub(Node **h1, Node **t1,Node **h2, Node **t2, Node **rh, Node **rt,int sign1, int sign2, int *rsign);
int mul(Node **h1, Node **t1,Node **h2, Node **t2,Node **rh, Node **rt);
int divi(Node **h1, Node **t1,Node **h2, Node **t2,Node **qh, Node **qt,Node **rh, Node **rt);
int mod(Node **h1, Node **t1,Node **h2, Node **t2,Node **rh, Node **rt);
int power(Node **bh, Node **bt, int exp, Node **rh, Node **rt);

int div_decimal(Node **h1, Node **t1,Node **h2, Node **t2,Node **qh, Node **qt,Node **dh, Node **dt);
int subtract_mag(Node **hbig, Node **tbig,Node **hsmall, Node **tsmall,Node **rh, Node **rt);
int compare( Node *h1, Node *h2);
int insert_at_front(Node **head, Node **tail, int data);
int insert_at_end(Node **head, Node **tail, int data);
int copy_list(Node *src, Node **dh, Node **dt);
void remove_leading_zeros(Node **h);
void free_list(Node *h);
int is_zero(Node *h);


#endif