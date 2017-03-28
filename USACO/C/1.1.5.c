/*
ID: lxdlam1
LANG: C
TASK: beads
*/
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 351

int main()
{
	FILE* fin = fopen("beads.in", "r");
	FILE* fout = fopen("beads.out", "w");
	int length, numMaxbeads = 0, i, left, right, j, flag = 1, m;
	char necklace[2 * MAX_LENGTH] = {0}, temp[MAX_LENGTH] = {0};
	fscanf(fin, "%d", &length);
	fscanf(fin, "%s", temp);
	strcpy(necklace, temp);
	strcat(necklace, temp);
	for (i = 0; i < 2 * length; i++)
	{
		numMaxbeads++;
		if (necklace[i] != necklace[i + 1] && necklace[i + 1] != 0)
		{
			numMaxbeads = flag = 0;
			break;
		}
	}
	for (i = 0; i < 2 * length; i++)
	{
		if (necklace[i] == necklace[i + 1])
			continue;
		else if (necklace[i + 1] == '\0')
			break;
		else if (flag)
			break;
		left = right = 0;
		m = i;
		while (necklace[m] == 'w' && m > 0)
		{
			m--;
		}
		for (j = i; ; j--)
		{
			if (necklace[j] == necklace[m])
				left++;
			else if (necklace[j] == 'w')
				left++;
			else
				break;
		}
		m = i + 1;
		while (necklace[m] == 'w' && m < length)
		{
			m++;
		}
		for (j = i + 1; ; j++)
		{
			if (necklace[j] == necklace[m])
				right++;
			else if (necklace[j] == 'w')
				right++;
			else
				break;
		}
		numMaxbeads = (left + right) > numMaxbeads ? (left + right) : numMaxbeads;
	}
	if (numMaxbeads >= length)
		fprintf(fout, "%d\n", length);
	else
		fprintf(fout, "%d\n", numMaxbeads);
	fclose(fin);
	fclose(fout);
	return 0;
}
