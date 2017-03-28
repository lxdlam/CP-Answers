/*
ID: lxdlam1
LANG: C
TASK: gift1
*/

#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 10

typedef struct tagPerson
{
	char name[14];
	int account;
} person;

int search(char name[14], person persons[MAX_LENGTH]);

int main()
{
	FILE *fin = fopen("gift1.in", "r");
	FILE *fout = fopen("gift1.out", "w");
	person persons[MAX_LENGTH];
	int numPersons, numMoney, numGivePersons, i,k;
	char nameTemp[14] = {0};
	fscanf(fin, "%d", &numPersons);
	for (i = 0; i < numPersons; i++)
	{
		fscanf(fin, "%s", persons[i].name);
		persons[i].account = 0;
	}
	for (i = 0; i < numPersons; i++)
	{
		fscanf(fin, "%s", nameTemp);
		fscanf(fin, "%d %d", &numMoney, &numGivePersons);
		persons[search(nameTemp, persons)].account -= numMoney;
		if (numGivePersons)
			persons[search(nameTemp, persons)].account += numMoney % numGivePersons;
		for (int j = 0; j < numGivePersons; j++)
		{
			fscanf(fin, "%s", nameTemp);
			if (numGivePersons)
				persons[search(nameTemp, persons)].account += (numMoney - numMoney % numGivePersons) / numGivePersons;
		}
	}
	for (i = 0; i < numPersons; i++)
	{
		fprintf(fout, "%s %d\n", persons[i].name, persons[i].account);
	}
	fclose(fin);
	fclose(fout);
	return 0;
}

int search(char name[14], person persons[MAX_LENGTH])
{
	int i;
	for (i = 0; i < MAX_LENGTH; i++)
	{
		if (!memcmp(name, persons[i].name, strlen(name)))
			break;
	}
	return i;
}
