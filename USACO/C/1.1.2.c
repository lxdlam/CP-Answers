/*
ID: lxdlam1
LANG: C
TASK: ride
*/
#include <stdio.h>

#define LENGTH 6

int main()
{
	char str1[LENGTH] = {0}, str2[LENGTH] = {0};
	int i, temp1 = 1, temp2 = 1;
	FILE *fin = fopen("ride.in", "r");
	FILE *fout = fopen("ride.out", "w");
	fscanf(fin, "%s", str1);
	fscanf(fin, "%s", str2);
	for (i = 0; i < LENGTH; i++)
	{
		if (str1[i] != '\0')
			temp1 *= (int)(str1[i] - 'A' + 1);
		if (str2[i] != '\0')
			temp2 *= (int)(str2[i] - 'A' + 1);
	}
	if (temp1 % 47 == temp2 % 47)
		fprintf(fout, "GO\n");
	else
		fprintf(fout, "STAY\n");
}