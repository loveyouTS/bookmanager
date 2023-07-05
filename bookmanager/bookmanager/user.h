
#include<iostream>
using namespace std;
struct user
{
	string name;
	int id;
	int passsword;
	void borrowbook(string name1, string auther1);
	void returnbook(string,string);
	void personal();
	void book_research(string name3, string auther3);
	void bulletin();
};
string UTF8ToGB(const char* str);