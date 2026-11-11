// Дано літерний рядок, який містить послідовність символів s[0], ..., s[n], ...
// 1.   Вияснити, чи зустрічається в даній послідовності група з трьох знаків оклику '!',які розташовані поспіль.
// 2.   Замінити кожну трійку сусідніх знаків оклику "!!!" парою зірочок "**".
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

bool Contains(const char* s) 
{
	return strstr(s, "!!!") != nullptr;
}


char* Change(char* s)
{
	char* t = new char[strlen(s) + 1];
	char* p;
	int pos1 = 0,
		pos2 = 0;
	*t = 0;

	while (p = strstr(s + pos1, "!!!"))
	{
		pos2 = p - s + 3;
		strncat(t, s + pos1, pos2 - pos1 - 3);
		strcat(t, "**");
		pos1 = pos2;
	}
	strcat(t, s + pos1);

	strcpy(s, t);

	return t;
}

int main()
{
	char str[101];

		cout << "Enter string:" << endl;
	cin.getline(str, 100);

	if (Contains(str))
		cout << "String contains a group of three '!'" << endl;
	else
		cout << "String does not contain a group of three '!'" << endl;

	char* dest = Change(str);

	cout << "Modified string (param) : " << str << endl;
	cout << "Modified string (result): " << dest << endl;

	delete[] dest;

	return 0;
}