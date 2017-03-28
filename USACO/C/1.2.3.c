/*
ID: lxdlam1
LANG: C
TASK: namenum
*/
#include <stdio.h>
#include <string.h>

char char2num(char a);

const char a[15] = {0};

int main()
{
	FILE* fin = fopen("namenum.in", "r");
	FILE* fout = fopen("namenum.out", "w");
	FILE* fdict = fopen("dict.txt", "r");
	char name[15] = {0}, number[15] = {0}, numberTemp[15] = {0};
	int count = 0, i;
	fscanf(fin, "%s", number);
	while (fscanf(fdict, "%s", name) != EOF)
	{
		memcpy(numberTemp, a, 15 * sizeof(char));
		if (strlen(name) == strlen(number))
		{
			for (i = 0; i < strlen(number); i++)
				numberTemp[i] = char2num(name[i]);
		}
		if (!memcmp(numberTemp, number, 15 * sizeof(char)))
		{
			fprintf(fout, "%s\n", name);
			count++;
		}
	}
	if (!count)
		fprintf(fout, "NONE\n");
	fclose(fin);
	fclose(fout);
	return 0;
}

char char2num(char a)
{
	switch (a)
	{
	case 'A':
	case 'B':
	case 'C': return '2';
	case 'D':
	case 'E':
	case 'F': return '3';
	case 'G':
	case 'H':
	case 'I': return '4';
	case 'J':
	case 'K':
	case 'L': return '5';
	case 'M':
	case 'N':
	case 'O': return '6';
	case 'P':
	case 'R':
	case 'S': return '7';
	case 'T':
	case 'U':
	case 'V': return '8';
	case 'W':
	case 'X':
	case 'Y': return '9';
	default: return '0';
	}
}
