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
	inf.open("D:\\����\\bookmanager\\bookmanager\\bk.txt");
	while (getline(inf, s))      //getline(inf,s)�����ж�ȡinf�е��ļ���Ϣ
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
	ofstream outfile;    //�������������
	string filePath = "D:\\����\\bookmanager\\bookmanager\\bk.txt";
	outfile.open(filePath);    //���ļ�
	if (!outfile)
	{
		cout << "���ļ�ʧ��" << endl;
		exit(1);
	}

	//���ļ���д������
	for (int x = 1; n[x].name != ""; x++)
	{
		outfile << n[x].auther << endl << n[x].name << endl;
	}
	cout << "���ͼ��ɹ�" << endl;
	system("pause");
	system("cls");
}
void manager::delete_book(string name1, string auther1)
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
		cout << "��Ǹ���޴���" << endl;
		return;
	}
	for (int j = number; n[j].name != ""; j++)
	{
		n[j] = n[j + 1];
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
	for (int j = 1; n[j].name != ""; j++)
	{
		outfile << n[j].auther << endl << n[j].name << endl;
	}

	outfile.close();    //�ر��ļ�
	cout << "ɾ���ɹ�" << endl;
	system("pause");
	system("cls");
}
void manager::publish()
{
	string announcement;
	cout << "��������Ҫ����������"<<endl;
	cin >> announcement;
	ofstream outfile;    //�������������
	string filePath = "D:\\����\\bookmanager\\bookmanager\\announcement.txt";
	outfile.open(filePath);    //���ļ�
	if (!outfile)
	{
		cout << "���ļ�ʧ��" << endl;
		exit(1);
	}

	//���ļ���д������
	
	
		outfile << announcement;
	
	

	outfile.close();//�ر��ļ�
	cout << "�����ɹ�";
	system("pause");
	system("cls");
}