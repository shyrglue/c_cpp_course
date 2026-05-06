#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int n;
    struct Node*next;
}NODE,*L;

int main()
{
    L o,n,s;
    int i,j,m,k;
    scanf("%d%d",&m,&k);
    if(k==1) printf("%d",m);
    else
    {
        o=(L)malloc(sizeof(NODE));
        o->n=1;
        s=o;
        for(i=2;i<=m;i++)
        {
            n=(L)malloc(sizeof(NODE));
            n->n=i;
            o->next=n;
            o=n;
            n=NULL;
        }
        o->next=s;
        o=NULL;
        n=NULL;
        for(i=m;i>=2;i--)
        {
            for(j=1;j<=k-2;j++) s=s->next;
            o=s->next;
            s->next=o->next;
            s=s->next;
            free(o);
            o=NULL;
        }
        printf("%d",s->n);
        free(s);
    }
}