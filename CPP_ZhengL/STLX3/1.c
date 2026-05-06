#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
 int data;
 struct node* next;
}NODE,*LinkList;

LinkList MyCreate()
{
    LinkList head;
    int n;
    LinkList s,tail;
    head=(LinkList)malloc(sizeof(LinkList));
    head->next=NULL;
    tail=head;
    while(1)
    {
        scanf("%d",&n);
        if(n==0) 
        {
            tail->next=NULL;
            break;
        }
        else
        {
        s=(LinkList)malloc(sizeof(NODE));
        s->data=n;
        tail->next=s;
        tail=s;
        }
    }
    return head;
}


void MyPrint(LinkList p)
{
while(p->next->next!=NULL)
{
    printf("%d->",p->next->data);
    p=p->next;
}

printf("%d\n",p->next->data);

}

void MyFree(LinkList head)
{
 LinkList q,p=head;
 while (p!=NULL)
 {
    q=p->next;
    free(p);
    p=q;
 }
 head=NULL;
}

void deleteDuplicates(LinkList head)
{
 LinkList p = head->next;
 while (p->next!=NULL)
 {
  if (p->next->data==p->data)
  {
   LinkList r=p->next;
   p->next=p->next->next;
   free(r);
  }
  else p=p->next;
 }
}

LinkList NthFromEnd(LinkList head,int k)
{
 LinkList p = head->next;
int n=0,i;
    while(p!=NULL)
    {
        n++;
        p=p->next;
    }
    p = head->next;
    for(i=0;i<n-k;i++)
        p=p->next;
    LinkList h,s,t;
    h=(LinkList)malloc(sizeof(LinkList));
    h->next=NULL;
    t=h;
    for(i=0;i<k;i++)
    {
        s=(LinkList)malloc(sizeof(NODE));
        s->data=p->data;
        p=p->next;
        t->next=s;
        t=s;
    }
    t->next=NULL;
     return h;
}

void removeElements(LinkList head,int v)
{
    LinkList p=head->next;
 while(p->next!=NULL)
 {
  if (p->next->data==v)
  {
   LinkList r=p->next;
   p->next=p->next->next;
   free(r);
  }
  else p=p->next;
 }
}

int main()
{
    LinkList p,new_p;
	int k, v;
	scanf("%d %d", &k, &v);
	p = MyCreate();
    MyPrint(p);
    removeElements(p,v);
    MyPrint(p);
    deleteDuplicates(p);
    MyPrint(p);
    new_p=NthFromEnd(p,k);
    MyPrint(new_p);
    MyFree(p);
}



