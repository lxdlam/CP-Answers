/*
ID: lxdlam1
LANG: C
TASK: transform
*/
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 10

int main()
{
	FILE* fin = fopen("transform.in", "r");
	FILE* fout = fopen("transform.out", "w");
	char str1[MAX_SIZE][MAX_SIZE] = {0}, str2[MAX_SIZE][MAX_SIZE] = {0};
	char strReflect[MAX_SIZE][MAX_SIZE] = {0}, strRotate_90[MAX_SIZE][MAX_SIZE] = {0}, strRotate_180[MAX_SIZE][MAX_SIZE] = {0}, strRotate_270[MAX_SIZE][MAX_SIZE] = {0};
	char strRotate_Reflect_90[MAX_SIZE][MAX_SIZE] = {0}, strRotate_Reflect_180[MAX_SIZE][MAX_SIZE] = {0}, strRotate_Reflect_270[MAX_SIZE][MAX_SIZE] = {0};
	int numSize, i, j;
	fscanf(fin, "%d", &numSize);
	for (i = 0; i < numSize; i++)
	{
		fscanf(fin, "%s", str1[i]);
	}
	for (i = 0; i < numSize; i++)
	{
		fscanf(fin, "%s", str2[i]);
	}
	//Reflection
	for (i = 0; i < numSize; i++)
	{
		for (j = 0; j < numSize; j++)
		{
			strReflect[i][j] = str1[i][numSize - 1 - j];
		}
	}
	//Rotate 90 degrees
	for (i = 0; i < numSize; i++)
	{
		for (j = 0; j < numSize; j++)
		{
			strRotate_90[i][j] = str1[numSize - 1 - j][i];
		}
	}
	for (i = 0; i < numSize; i++)
	{
		for (j = 0; j < numSize; j++)
		{
			strRotate_Reflect_90[i][j] = strReflect[numSize - 1 - j][i];
		}
	}
	//Rotate 180 degrees
	for (i = 0; i < numSize; i++)
	{
		for (j = 0; j < numSize; j++)
		{
			strRotate_180[i][j] = strRotate_90[numSize - 1 - j][i];
		}
	}
	for (i = 0; i < numSize; i++)
	{
		for (j = 0; j < numSize; j++)
		{
			strRotate_Reflect_180[i][j] = strRotate_Reflect_90[numSize - 1 - j][i];
		}
	}
	//Rotate 270 degrees
	for (i = 0; i < numSize; i++)
	{
		for (j = 0; j < numSize; j++)
		{
			strRotate_270[i][j] = strRotate_180[numSize - 1 - j][i];
		}
	}
	for (i = 0; i < numSize; i++)
	{
		for (j = 0; j < numSize; j++)
		{
			strRotate_Reflect_270[i][j] = strRotate_Reflect_180[numSize - 1 - j][i];
		}
	}
	//Comparation
	if (!memcmp(strRotate_90, str2, MAX_SIZE * MAX_SIZE * sizeof(char)))
		fprintf(fout, "1\n");
	else if (!memcmp(strRotate_180, str2, MAX_SIZE * MAX_SIZE * sizeof(char)))
		fprintf(fout, "2\n");
	else if (!memcmp(strRotate_270, str2, MAX_SIZE * MAX_SIZE * sizeof(char)))
		fprintf(fout, "3\n");
	else if (!memcmp(strReflect, str2, MAX_SIZE * MAX_SIZE * sizeof(char)))
		fprintf(fout, "4\n");
	else if (!memcmp(strRotate_Reflect_90, str2, MAX_SIZE * MAX_SIZE * sizeof(char)))
		fprintf(fout, "5\n");
	else if (!memcmp(strRotate_Reflect_180, str2, MAX_SIZE * MAX_SIZE * sizeof(char)))
		fprintf(fout, "5\n");
	else if (!memcmp(strRotate_Reflect_270, str2, MAX_SIZE * MAX_SIZE * sizeof(char)))
		fprintf(fout, "5\n");
	else if (!memcmp(str1, str2, MAX_SIZE * MAX_SIZE * sizeof(char)))
		fprintf(fout, "6\n");
	else
		fprintf(fout, "7\n");

	fclose(fin);
	fclose(fout);
	return 0;
}
