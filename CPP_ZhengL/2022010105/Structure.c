#include <stdio.h>
#include <iso646.h>
#include <stdlib.h>
#include <string.h>

typedef struct stu{
	char name[20];
	char stuno[10];
	char birpl[15];
	char age[4];
	char gender[7];
}STU;

void input(STU *SS);
void output(STU **SS, int i);
void search(STU **SS, char *info, int N);

void main()
{
	STU *SS[128];
	char ser[15][50];
	int N, i, cnt = 0;
	scanf("%d", &N);
	for (i = 0; i <= N - 1; i++)
	{
		SS[i] = (STU*)malloc(sizeof(STU));
		input(SS[i]);
	}
	gets(ser[cnt]);
	while (strcmp(ser[cnt], "quit"))
	{
		cnt++;
		gets(ser[cnt]);
	}
	for (i = 0; i <= N - 1; i++)
		output(SS, i);
	for (i = 0; i <= cnt - 1; i++)
		search(SS, ser[i], N);
	for (i = 0; i <= N - 1; i++)
		free(SS[i]);
}

void input(STU *SS)
{
	char *c, *a, s[57];
	gets(s); if (not(strcmp(s, "\0"))) gets(s);
	c = strchr(s, ','); *c = '\0'; a = c + 2;
	strcpy(SS->name, s);
	c = strchr(a, ','); *c = '\0';
	strcpy(SS->stuno, a); a = c + 2;
	c = strchr(a, ','); *c = '\0';
	strcpy(SS->birpl, a); a = c + 2;
	c = strchr(a, ','); *c = '\0';
	strcpy(SS->age, a); a = c + 2;
	strcpy(SS->gender, a);
}

void output(STU **SS, int i)
{
	printf("%s, ", SS[i]->name);
	printf("%s, ", SS[i]->stuno);
	printf("%s, ", SS[i]->birpl);
	printf("%s, ", SS[i]->age);
	printf("%s\n", SS[i]->gender);
}

void search(STU **SS, char *info, int N)
{
	int cnt = 0, i, j, res = -1, flag;
	char find[5][20];
	for (i = 0, cnt = 0, j = 0; i <= (int)strlen(info) - 1; i++, j++)
	{
		if (info[i] == ',')
		{
			find[cnt][j] = '\0';
			cnt++; j = -1;
			continue;
		}
		find[cnt][j] = info[i];
	}
	find[cnt][j] = '\0';
	for(i = 0; i <= N - 1; i++)
	{
		for(flag = 1, j = 0; j <= cnt; j++)
		{
			if(strcmp(find[j], SS[i]->name) and
			strcmp(find[j], SS[i]->stuno) and
			strcmp(find[j], SS[i]->birpl) and
			strcmp(find[j], SS[i]->age) and
			strcmp(find[j], SS[i]->gender))
			flag = 0;
		}
		if (flag == 1 and res == -1)
			res = i;
		else if (flag == 1 and res != -1)
		{
			res = -1; break;}
	}
	if (res != -1)
		output(SS, res);
	else
		printf("error\n");
}
