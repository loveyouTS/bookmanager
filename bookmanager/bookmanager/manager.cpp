#include<iostream>
#include"book.h"
#include<fstream>
#include<string>
#include"user.h"
using namespace std;
struct manager
{
	string name;
	int id;
	int passsword;
	void add_book(string name,string auther);
	void delete_book(string name1,string auther1);
	void punish();
	void publish();
};
int x=1;
book* n = new book[100];
void manager::add_book(string name,string auther)
{
	int j = 0, a = 1;
	string s;
	ifstream inf;
	inf.open("D:\\代码\\bookmanager\\bookmanager\\bk.txt");
	while (getline(inf, s))      //getline(inf,s)是逐行读取inf中的文件信息
	{
		if (a == 1)
		{


			n[x].auther = s;
			a = 2;
			continue;
		}
		else
		{

			n[x].name = s;
			a = 1;
			x++;
		}
	}
	inf.close();
	for (j = 1; n[j].name != ""; j++);
	n[j].name = name, n[j].auther = auther;
	ofstream outfile;    //定义输出流对象
	string filePath = "D:\\代码\\bookmanager\\bookmanager\\bk.txt";
	outfile.open(filePath);    //打开文件
	if (!outfile)
	{
		cout << "打开文件失败" << endl;
		exit(1);
	}

	//向文件中写入数据
	for (int x = 1; n[x].name != ""; x++)
	{
		outfile << n[x].auther << endl << n[x].name << endl;
	}
	cout << "添加图书成功" << endl;
	system("pause");
	system("cls");
}
void manager::delete_book(string name1, string auther1)
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

			n[x].auther = s;
			a = 2;
			continue;
		}
		else
		{

			n[x].name = s;
			a = 1;
			x++;
		}
	}
	inf.close();
	number = find_book(n, name1, auther1);
	if (number == 100)
	{
		cout << "抱歉查无此书" << endl;
		return;
	}
	for (int j = number; n[j].name != ""; j++)
	{
		n[j] = n[j + 1];
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
	for (int j = 1; n[j].name != ""; j++)
	{
		outfile << n[j].auther << endl << n[j].name << endl;
	}

	outfile.close();    //关闭文件
	cout << "删除成功" << endl;
	system("pause");
	system("cls");
}
void manager::publish()
{
	string announcement;
	cout << "请输入你要发布的内容"<<endl;
	cin >> announcement;
	ofstream outfile;    //定义输出流对象
	string filePath = "D:\\代码\\bookmanager\\bookmanager\\announcement.txt";
	outfile.open(filePath);    //打开文件
	if (!outfile)
	{
		cout << "打开文件失败" << endl;
		exit(1);
	}

	//向文件中写入数据
	
	
		outfile << announcement;
	
	

	outfile.close();//关闭文件
	cout << "发布成功";
	system("pause");
	system("cls");
}