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
	cout << "ID:" << a.id<<" "<< "����:" << a.name<<" " << "����:" << a.passsword << endl;
	return cout;
}
string UTF8ToGB(const char* str)
{
	std::string result;
	WCHAR* strSrc;
	LPSTR szRes;

	//�����ʱ�����Ĵ�С
	int i = MultiByteToWideChar(CP_UTF8, 0, str, -1, NULL, 0);
	strSrc = new WCHAR[i + 1];
	MultiByteToWideChar(CP_UTF8, 0, str, -1, strSrc, i);

	//�����ʱ�����Ĵ�С
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
	inf.open("D:\\����\\bookmanager\\bookmanager\\bk.txt");
	while (getline(inf, s))      //getline(inf,s)�����ж�ȡinf�е��ļ���Ϣ
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
		cout << "��Ǹ���޴���" << endl;
		return;
	}
	for (int j = number; m[j].name!=""; j++)
	{
		m[j] = m[j + 1];
	}
	ofstream outfile;    //�������������
	string filePath = "D:\\����\\bookmanager\\bookmanager\\bk.txt";
	outfile.open(filePath);    //���ļ�
	if (!outfile)
	{
		cout << "���ļ�ʧ��" << endl;
		exit(1);
	}

	//���ļ���д������
	for (int j = 1; m[j].name != ""; j++)
	{
		outfile << m[j].auther << endl<<m[j].name<<endl;
	}

	outfile.close();    //�ر��ļ�
	cout << "���ĳɹ�" << endl;
	system("pause");
	system("cls");
}
void user::returnbook(string name2,string auther2)
{
	int j = 0,a=1;
	string s;
	ifstream inf;
	inf.open("D:\\����\\bookmanager\\bookmanager\\bk.txt");
	while (getline(inf, s))      //getline(inf,s)�����ж�ȡinf�е��ļ���Ϣ
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
		ofstream outfile;    //�������������
	string filePath = "D:\\����\\bookmanager\\bookmanager\\bk.txt";
	outfile.open(filePath);    //���ļ�
	if (!outfile)
	{
		cout << "���ļ�ʧ��" << endl;
		exit(1);
	}

	//���ļ���д������
	for (int x = 1; m[x].name != ""; x++)
	{
		outfile << m[x].auther << endl << m[x].name << endl;
	}
	cout << "����ɹ�" << endl;
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
	inf.open("D:\\����\\bookmanager\\bookmanager\\bk.txt");
	while (getline(inf, s))      //getline(inf,s)�����ж�ȡinf�е��ļ���Ϣ
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
		cout << "��Ǹ���޴���" << endl;
	}
	else
		cout << "�����д˲���" << endl;
	system("pause");
	system("cls");
}
void user::bulletin()
{
	string s;
	ifstream inf;
	inf.open("D:\\����\\bookmanager\\bookmanager\\announcement.txt");
	while (getline(inf, s))      //getline(inf,s)�����ж�ȡinf�е��ļ���Ϣ
	{
		cout << s;
	}
	system("pause");
	system("cls");
}
