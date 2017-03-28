/*
ID: lxdlam1
LANG: C
TASK: friday
 */
#include <stdio.h>

int isLeap(int year);

int main()
{
	FILE* fin = fopen("friday.in", "r");
	FILE* fout = fopen("friday.out", "w");
	int month[12] = {6, 2, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
	int days[7] = { 0 };
	int i, n, j;
	fscanf(fin, "%d", &n);
	for (i = 1900; i < 1900 + n; i++)
	{
		if (isLeap(i) == 0 && isLeap(i - 1) == 0)
		{
			for (j = 0; j < 12; j++)
			{
				month[j] = (month[j] + 1) % 7;
			}
		}
		else if (isLeap(i))
		{
			month[0] = (month[0] + 1) % 7;
			month[1] = (month[1] + 1) % 7;
			for (j = 2; j < 12; j++)
			{
				month[j] = (month[j] + 2) % 7;
			}
		}
		else if (isLeap(i - 1))
		{
			month[0] = (month[0] + 2) % 7;
			month[1] = (month[1] + 2) % 7;
			for (j = 2; j < 12; j++)
			{
				month[j] = (month[j] + 1) % 7;
			}
		}
		for (j = 0; j < 12; j++)
		{
			days[month[j]]++;
		}
	}
	for (j = 0; j < 7; j++)
	{
		fprintf(fout, "%d", days[j]);
		if (j != 6)
			fprintf(fout, " ");
		else
			fprintf(fout, "\n");
	}
	fclose(fin);
	fclose(fout);
	return 0;
}

int isLeap(int year)
{
	if (((year % 4 == 0) && (year % 100 != 0)) || year % 400 == 0)
		return 1;
	else
		return 0;
}
