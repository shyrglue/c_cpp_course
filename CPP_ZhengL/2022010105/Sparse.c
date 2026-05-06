#include <stdio.h>
#include <iso646.h>
#include <stdlib.h>

void main()
{
	int mat1[10][10] = {0}, mat2[10][10] = {0};
	int num[10], i, j, res[50], k, flag = 0;
	for (i = 0; i <= 9; i++)
	{
		scanf("%d,%d,%d,%d,%d,%d,%d,%d,%d,%d", &num[0], &num[1], &num[2], &num[3], &num[4], &num[5], &num[6], &num[7], &num[8], &num[9]);
		for (j = 0; j <= 9; j++)
		{
			if (num[j] != 0)
				mat1[i][j] = num[j];
		}
	}
	for (i = 0; i <= 9; i++)
	{
		scanf("%d,%d,%d,%d,%d,%d,%d,%d,%d,%d", &num[0], &num[1], &num[2], &num[3], &num[4], &num[5], &num[6], &num[7], &num[8], &num[9]);
		for (j = 0; j <= 9; j++)
		{
			if (num[j] != 0)
				mat2[i][j] = num[j];
		}
	}
	for (i = 0, k = 0; i <= 9; i++)
	{
		for (j = 0; j <= 9; j++)
		{
			mat2[i][j] += mat1[i][j];
			if(mat2[i][j] != 0)
			{
				res[k] = mat2[i][j];
				k++;
			}
		}
	}
	for (i = 0; i <= k - 2; i++)
	{
		for (j = i; j <= k - 1; j++)
		{
			if (res[j] > res[i])
			{
				mat1[1][1] = res[j];
				res[j] = res[i];
				res[i] = mat1[1][1];
			}
		}
	}
	if (k % 2)
		k = k / 2;
	else
		k = (k / 2) - 1;
	for (i = 9; i >= 0; i--)
	{
		for (j = 9; j >= 0; j--)
		{
			if (mat2[j][i] == res[k])
			{
				flag = 1;
				break;
			}
		}
		if (flag)
			break;
	}
	printf("%d,%d,%d", res[k], j + 1, i + 1);
}