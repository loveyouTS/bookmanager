#include<iostream>
using namespace std;
struct manager
{
	string name;
	int id;
	int passsword;
	void add_book(string,string);
	void delete_book(string name1, string auther1);
	void punish();
	void publish();
};
