#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct r
{
    char no[3];
    char name[7];
    int sal;
    struct r*next;
};
void swap(char s1[],char s2[])
{
    char t[7];
    strcpy(t,s1);
    strcpy(s1,s2);
    strcpy(s2,t);
}
struct r *link(struct r* list1, struct r* list2)
{
	struct r* ed, *p, *q;
	int tint;
	ed = list1;
	while (ed->next != NULL)
		ed = ed->next;
	ed->next = list2->next;
	while (ed->next != NULL)
		ed = ed->next;
	for (p = list1->next; p->next != NULL; p = p->next)
	{
		for(q = p; q != NULL; q = q->next)
		{
			if((strcmp(q->no, p->no) < 0))
			{
				swap(q->no, p->no);
				swap(q->name, p->name);
				tint = q->sal; q->sal = p->sal; p->sal = tint;
			}
		}
	}
	return list1;
}
/*struct r*link(struct r*l1,struct r*l2)
{
    struct r*ed,*p,*q;
    int t;
    ed=l1;
    while(ed->next!=NULL) ed=ed->next;
    ed->next=l2->next;
    while(ed->next!=NULL) ed=ed->next;
    for(p=l1->next;p->next!=NULL;p=p->next)
    {
        for(q=p;q!=NULL;q=q->next)
        {
            if(strcmp(q->no,p->no)<0)
            {
                swap(q->no,p->no);
                swap(q->name,p->name);
                t=q->sal;
                q->sal=p->sal;
                p->sal=t;
            }
        }
    }
    return l1;
}*/
void sort(struct r*l)
{
    struct r *n1,*n2;
    int t;
    for(n1=l->next;n1->next!=NULL;n1=n1->next)
    {
        for(n2=n1;n2!=NULL;n2=n2->next)
        {
            if(n2->sal<n1->sal)
            {
                swap(n1->no,n2->no);
                swap(n1->name,n2->name);
                t=n2->sal;
                n2->sal=n2->sal;
                n1->sal=t;
            }
        }
    }
}

void input(struct r*l)
{
    
}
int main()
{
    struct r*l1,*l2;
    int i,n1,n2;
    struct r*p;

    scanf("%d",&n1);
    l1=(struct r*)malloc((n1+1)*sizeof(struct r));
    l1->next=l1+1;
    for(i=1,p=l1;i<=n1;i++)
    {
        scanf("%s", p->next->no);
		scanf("%s", p->next->name);
		scanf("%d", &(p->next->sal));  
        if(i!=n1)
            p->next->next=p->next+1;
        else
            p->next->next=NULL;
        p=p->next;
    }

    scanf("%d",&n2);
    l2=(struct r*)malloc((n2+1)*sizeof(struct r));
    l2->next=l2+1;
    for(i=1,p=l1;i<=n2;i++)
    {
        scanf("%s", p->next->no);
		scanf("%s", p->next->name);
		scanf("%d", &(p->next->sal));  
        if(i!=n2)
            p->next->next=p->next+1;
        else
            p->next->next=NULL;
        p=p->next;
    }
    l1=link(l1,l2);
    for(i=1,p=l1->next;i<=n1+n2;i++,p=p->next)
        printf("{%s %s ,%d}\n",p->no,p->name,p->sal);
    free(l1);
    free(l2);
    
}