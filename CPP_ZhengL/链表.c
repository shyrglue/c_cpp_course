#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    int arr[]={1,2,3,4,5,6,7,8,9};
    int n=sizeof(arr)/sizeof(int);

    struct node *head,*p;

    for(int i=0;i<n;i++)
    {
        p=(struct node *)malloc(sizeof(struct node));
        p->data=arr[i];
        p->next=head;
    }

    return 0;
}