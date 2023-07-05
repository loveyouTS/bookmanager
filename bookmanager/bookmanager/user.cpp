#include<iostream>
#include"book.h"
#include<fstream>
#include<string>
#include <Windows.h>
using namespace std;
int i=1;
book* m = new book[100];
struct user
{
	string name;
	int id;
	int passsword;
	void borrowbook(string name1, string auther1);
	void returnbook(string name2, string auther2);
	void personal();
	void book_research(string name3,string auther3);
	void bulletin();
	friend ostream& operator>>(ostream&, user a);
};
ostream& operator>>(ostream&,user a)
{
	cout << "ID:" << a.id<<" "<< "姓名:" << a.name<<" " << "密码:" << a.passsword << endl;
	return cout;
}
string UTF8ToGB(const char* str)
{
	std::string result;
	WCHAR* strSrc;
	LPSTR szRes;

	//获得临时变量的大小
	int i = MultiByteToWideChar(CP_UTF8, 0, str, -1, NULL, 0);
	strSrc = new WCHAR[i + 1];
	MultiByteToWideChar(CP_UTF8, 0, str, -1, strSrc, i);

	//获得临时变量的大小
	i = WideCharToMultiByte(CP_ACP, 0, strSrc, -1, NULL, 0, NULL, NULL);
	szRes = new CHAR[i + 1];
	WideCharToMultiByte(CP_ACP, 0, strSrc, -1, szRes, i, NULL, NULL);

	result = szRes;
	delete[]strSrc;
	delete[]szRes;

	return result;
}
void user::borrowbook(string name1,string auther1)
{

	int number;
	int a = 1;
	string s;
	ifstream inf;
	inf.open("D:\\代码\\bookmanager\\bookmanager\\bk.txt");
	while (getline(inf, s))      //getline(inf,s)是逐行读取inf中的文件信息
	{
		if (a == 1)
		{
			
			m[i].auther = s;
			a = 2;
			continue;
		}
		else
		{
			
			m[i].name = s;
			a = 1;
			i++;
		}
	}
	inf.close();
	number=find_book(m, name1, auther1);
	if (number == 100)
	{
		cout << "抱歉查无此书" << endl;
		return;
	}
	for (int j = number; m[j].name!=""; j++)
	{
		m[j] = m[j + 1];
	}
	ofstream outfile;    //定义输出流对象
	string filePath = "D:\\代码\\bookmanager\\bookmanager\\bk.txt";
	outfile.open(filePath);    //打开文件
	if (!outfile)
	{
		cout << "打开文件失败" << endl;
		exit(1);
	}

	//向文件中写入数据
	for (int j = 1; m[j].name != ""; j++)
	{
		outfile << m[j].auther << endl<<m[j].name<<endl;
	}

	outfile.close();    //关闭文件
	cout << "借阅成功" << endl;
	system("pause");
	system("cls");
}
void user::returnbook(string name2,string auther2)
{
	int j = 0,a=1;
	string s;
	ifstream inf;
	inf.open("D:\\代码\\bookmanager\\bookmanager\\bk.txt");
	while (getline(inf, s))      //getline(inf,s)是逐行读取inf中的文件信息
	{
		if (a == 1)
		{
			 

			m[i].auther = s;
			a = 2;
			continue;
		}
		else
		{
			
			m[i].name = s;
			a = 1;
			i++;
		}
	}
	inf.close();
	for (j = 1; m[j].name != ""; j++);
	m[j].name = name2, m[j].auther = auther2;
		ofstream outfile;    //定义输出流对象
	string filePath = "D:\\代码\\bookmanager\\bookmanager\\bk.txt";
	outfile.open(filePath);    //打开文件
	if (!outfile)
	{
		cout << "打开文件失败" << endl;
		exit(1);
	}

	//向文件中写入数据
	for (int x = 1; m[x].name != ""; x++)
	{
		outfile << m[x].auther << endl << m[x].name << endl;
	}
	cout << "还书成功" << endl;
	system("pause");
	system("cls");
}

void user::personal()
{
	cout >> *this;
	system("pause");
	system("cls");
}
void user::book_research(string name3,string auther3)
{
	int a = 1;
	string s;
	ifstream inf;
	inf.open("D:\\代码\\bookmanager\\bookmanager\\bk.txt");
	while (getline(inf, s))      //getline(inf,s)是逐行读取inf中的文件信息
	{
		if (a == 1)
		{


			m[i].auther = s;
			a = 2;
			continue;
		}
		else
		{

			m[i].name = s;
			a = 1;
			i++;
		}
	}
	inf.close();
	int number = find_book(m, name3, auther3);
	if (number == 100)
	{
		cout << "抱歉查无此书" << endl;
	}
	else
		cout << "本馆有此藏书" << endl;
	system("pause");
	system("cls");
}
void user::bulletin()
{
	string s;
	ifstream inf;
	inf.open("D:\\代码\\bookmanager\\bookmanager\\announcement.txt");
	while (getline(inf, s))      //getline(inf,s)是逐行读取inf中的文件信息
	{
		cout << s;
	}
	system("pause");
	system("cls");
}
