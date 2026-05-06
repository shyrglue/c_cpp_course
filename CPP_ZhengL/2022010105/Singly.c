#include <stdio.h>
#include <iso646.h>
#include <stdlib.h>
#include <string.h>
typedef struct stu{
	long no;
	char name[21];
	struct stu *next;
}*STU;

void lcha(long *a, long *b){
	long temp;
	temp = *a; *a = *b; *b = temp;}

void strcha(char *s1, char *s2){
	char temp[21];
	strcpy(temp, s1); strcpy(s1, s2); strcpy(s2, temp);}

void main()
{
	STU head, pt1, pt2;
	char temp[40], *c;
	int N, flag;
	head = (STU)malloc(sizeof(struct stu)); head->next = NULL;
	gets(temp);
	while ((c = strchr(temp, ',')) != NULL)
	{
		*c = '\0'; c += 2;
		pt2 = (STU)malloc(sizeof(struct stu));
		if (head->next == NULL)
			head->next = pt2;
		else
			pt1->next = pt2;
		pt1 = pt2; pt2->next = NULL;
		pt1->no = atol(temp);
		strcpy(pt1->name, c);
		gets(temp);
	}
	for (pt1 = head->next; pt1->next != NULL; pt1 = pt1->next)
	{
		for (pt2 = pt1; pt2 != NULL; pt2 = pt2->next)
		{
			if (pt2->no > pt1->no)
			{
				lcha(&(pt2->no), &(pt1->no));
				strcha(pt2->name, pt1->name);
			}
		}
	}
	pt1 = head->next; N = 0;
	while (pt1 != NULL)
	{
		N++;
		pt1 = pt1->next;
	}
	printf("%d\n", N);
	for (pt1 = head->next; pt1 != NULL; pt1 = pt1->next)
		printf("%ld, %s\n", pt1->no, pt1->name);
	for (pt1 = head, flag = 0; pt1->next != NULL; pt1 = pt1->next)
	{
		if (atol(temp) == pt1->next->no)
		{
			flag = 1; break;
		}
	}
	if (not(flag))
		printf("ERROR");
	else
	{
		if (pt1->next->next != NULL)
			printf("%ld, %s\n", pt1->next->next->no, pt1->next->next->name);
		if (pt1 != head)
			printf("%ld, %s\n", pt1->no, pt1->name);
	}
	for (pt1 = head->next; pt1 != NULL; pt1 = pt1->next)
	{
		free(head);
		head = pt1;
	}
	free(head);
}