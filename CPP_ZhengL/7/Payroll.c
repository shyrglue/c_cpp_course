#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct r
{
	char no[100];
	char name[100];
	int sal;
	struct r *next;
};

void swap(char s1[], char s2[])
{
	char t[100]="\0";
	strcpy(t, s1);
	strcpy(s1, s2);
	strcpy(s2, t);
}

struct r*link(struct r*l1, struct r*l2)
{
	struct r*e,*s1,*s2;
	int t;
	e=l1;
	while(e->next!= NULL)
		e=e->next;
	e->next=l2->next;
	while(e->next!= NULL)
		e=e->next;
	for(s1=l1->next;s1->next!=NULL;s1=s1->next)
	{
		for(s2=s1;s2!=NULL;s2=s2->next)
		{
			if((strcmp(s2->no,s1->no)<0))
			{
				swap(s2->no,s1->no);
				swap(s2->name,s1->name);
				t = s2->sal;s2->sal=s1->sal;s1->sal=t;
			}
		}
	}
	return l1;
}

void sort(struct r*l)
{
	struct r*s1,*s2;
	int t;
	for(s1=l->next;s1->next!=NULL;s1=s1->next)
	{
		for(s2=s1;s2!=NULL;s2=s2->next)
		{
			if(s2->sal<s1->sal)
			{
				swap(s2->no,s1->no);
				swap(s2->name,s1->name);
				t=s2->sal;s2->sal=s1->sal;s1->sal=t;
			}
		}
	}
}

int main()
{
	int n1, n2, i;
	struct r*l1,*l2,*p;
	scanf("%d",&n1);
	l1=(struct r*)malloc((n1+1)*sizeof(struct r));
	l1->next=l1+1;
	for(i=1,p=l1;i<=n1;i++)
	{
		scanf("%s",p->next->no);
		scanf("%s",p->next->name);
		scanf("%d",&(p->next->sal));
		if(i!=n1)
			p->next->next=p->next+1;
		else
			p->next->next=NULL;
		p=p->next;
	}
	scanf("%d",&n2);
	l2=(struct r*)malloc((n2+1)*sizeof(struct r));
	l2->next=l2+1;
	for(i=1,p=l2;i<=n2;i++)
	{
		scanf("%s",p->next->no);
		scanf("%s",p->next->name);
		scanf("%d",&(p->next->sal));
		if(i!=n2)
			p->next->next=p->next+1;
		else
			p->next->next=NULL;
		p=p->next;
	}
	l1=link(l1,l2);
	for(i=1,p=l1->next;i<=n1+n2;i++,p=p->next)
		printf("{%s, %s, %d}\n",p->no,p->name,p->sal);
	sort(l1);
	putchar('\n');
	for(i=1,p=l1->next;i<=n1+n2;i++,p=p->next)
		printf("{%s, %s, %d}\n",p->no,p->name,p->sal);
	free(l1);
	free(l2);
}


