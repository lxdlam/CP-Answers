/*
ID: lxdlam1
PROG: namenum
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

inline char char2num(char a)
{
	switch (a)
	{
	case 'A':
	case 'B':
	case 'C':
		return '2';
	case 'D':
	case 'E':
	case 'F':
		return '3';
	case 'G':
	case 'H':
	case 'I':
		return '4';
	case 'J':
	case 'K':
	case 'L':
		return '5';
	case 'M':
	case 'N':
	case 'O':
		return '6';
	case 'P':
	case 'R':
	case 'S':
		return '7';
	case 'T':
	case 'U':
	case 'V':
		return '8';
	case 'W':
	case 'X':
	case 'Y':
		return '9';
	default:
		return '0';
	}
}

int main()
{
	ifstream in("namenum.in"), dict("dict.txt");
	ofstream out("namenum.out");
	string buf, temp;
	int count = 0;
	while (in >> buf)
	{
		if
	}
	if (!count)
		out << "NONE\n";
	in.close();
	dict.close();
	out.close();
	return 0;
}