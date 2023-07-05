#include<iostream>
#include"book.h"
using namespace std;
int find_book(book*m,string name1, string auther1)
{
	int i = 0;
	for ( i = 1; i <= 99; i++)
	{
		if (m[i].name == name1 && m[i].auther == auther1)
			break;
	}
	return i;
}

