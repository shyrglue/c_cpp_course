#include<stdio.h>
#include<string.h>
int main()
{
	char alpha[27]="ABCDEFGHIJKLMNOPQRSTUVWXYZ",key[1000],temp[128]="\0",key1[27]="\0",word[1000]="\0";
	int i,j,k=0,n,m=0;
	scanf("%s",key); 
	for(i=0;key[i]!=0;i++)
		{
			if(temp[key[i]]==0)
			{
				temp[key[i]]++;
				key[k]=key[i];
				k++;
			}
	}
	for(i=0;i<k;i++)
		key1[i]=key[i];
	n=strlen(key1);
	for(i=0;i<26;i++)
	{
		for(j=0;j<k;j++)
		{
			if(alpha[i]==key[j])
				break;
			else
				m++;
		}
		if(m==k)
		{
			key1[n]=alpha[i];
			n++;
		}
			m=0;
	}
	scanf("%s",word);
	for(i=0;i<strlen(word);i++)
	printf("%c",key1[word[i]-65]);
	return 0;
}