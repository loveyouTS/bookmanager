#include<iostream>
#include<fstream>
#include"user.h"
#include<string>
#include"manager.h"
using namespace std;
struct supermanager
{
	string name;
	int id;
	int passsword;
	void change_password1();
	void change_user(int,string,int);
	void change_manager(int, string, int);
};
user h[100];
manager g[100];
user* get_user1()
{
	int d = 1, i = 1;
	string s;
	ifstream inf;
	inf.open("D:\\����\\bookmanager\\bookmanager\\user.txt");          //�ر�ע�⣬�����ǣ�//  ��˫б���~~ 
	while (getline(inf, s))      //getline(inf,s)�����ж�ȡinf�е��ļ���Ϣ
	{
		if (d == 1)
		{

			d = 2;
			//s = s.substr(0, s.find_last_not_of('\r'));
			h[i].id = stoi(s, 0, 10);
			continue;
		}

		if (d == 2)
		{
			//s = UTF8ToGB(s.c_str()).c_str();
			h[i].name = s;
			d = 3;
			continue;
		}
		if (d == 3)
		{
			h[i].passsword = stoi(s, 0, 10);
			d = 1;
			i++;
			continue;
		}
	}
	inf.close();
	return h;
}
void get_manager1()
{
	int d = 1, i = 1;
	string s;
	ifstream inf;
	inf.open("D:\\����\\bookmanager\\bookmanager\\manager.txt");          //�ر�ע�⣬�����ǣ�//  ��˫б���~~ 
	while (getline(inf, s))      //getline(inf,s)�����ж�ȡinf�е��ļ���Ϣ
	{
		if (d == 1)
		{

			d = 2;
			//s = s.substr(0, s.find_last_not_of('\r'));
			g[i].id = stoi(s, 0, 10);
			continue;
		}

		if (d == 2)
		{
			//s = UTF8ToGB(s.c_str()).c_str();
			g[i].name = s;
			d = 3;
			continue;
		}
		if (d == 3)
		{
			g[i].passsword = stoi(s, 0, 10);
			d = 1;
			i++;
			continue;
		}
	}
	inf.close();

}
void supermanager::change_password1()
{
	int od = 0;
	int id1=1,password;
	get_manager1();
	get_user1();
	string name;
	cout << "��ѡ���޸�˭�Ĵ���" << endl << "1.����Ա" << endl << "2.�û�" << endl;
	cin >> od;
	if (od == 1)
	{
		cout << "��������Ҫ�޸ĵĹ���Ա����"<<endl;
		cin >> name;
		cout << "��������Ҫ�޸ĵ�����" << endl;
		cin >> passsword;
		for (id1 = 1; g[id1].name != name; id1++);
		g[id1].passsword = passsword;
		ofstream outfile;    //�������������
		string filePath = "D:\\����\\bookmanager\\bookmanager\\manager.txt";
		outfile.open(filePath);    //���ļ�
		if (!outfile)
		{
			cout << "���ļ�ʧ��" << endl;
			exit(1);
		}
		for (int j = 1; g[j].name != ""; j++)
		{
			outfile << g[j].id << endl << g[j].name << endl << g[j].passsword<<endl;
		}

		outfile.close();    //�ر��ļ�
		cout << "�޸�����ɹ�" << endl;
	}
	if (od == 2)
	{
		cout << "��������Ҫ�޸ĵ��û�����" << endl;
		cin >> name;
		cout << "��������Ҫ�޸ĵ�����" << endl;
		cin >> passsword;
		for (id = 1; h[id1].name != name; id++);
		h[id1].passsword = passsword;
		ofstream outfile;    //�������������
		string filePath = "D:\\����\\bookmanager\\bookmanager\\user.txt";
		outfile.open(filePath);    //���ļ�
		if (!outfile)
		{
			cout << "���ļ�ʧ��" << endl;
			exit(1);
		}
		for (int j = 1; h[j].name != ""; j++)
		{
			outfile << h[j].id << endl << h[j].name << endl << h[j].passsword << endl;
		}

		outfile.close();    //�ر��ļ�
		cout << "�޸�����ɹ�" << endl;
	}
	system("pause");
	system("cls");
}
void supermanager::change_user(int id_1,string name_1,int password_1)
{
	cout << "��������Ҫ���еĲ���" << endl << "1.���" << "2.ɾ��"<<endl;
	int od1 = 1,j;
	cin >> od1;
	if (od1 == 1)
	{
		int d = 1, i = 1;
		string s;
		ifstream inf;
		inf.open("D:\\����\\bookmanager\\bookmanager\\user.txt");          //�ر�ע�⣬�����ǣ�//  ��˫б���~~ 
		while (getline(inf, s))      //getline(inf,s)�����ж�ȡinf�е��ļ���Ϣ
		{
			if (d == 1)
			{

				d = 2;
				//s = s.substr(0, s.find_last_not_of('\r'));
				h[i].id = stoi(s, 0, 10);
				continue;
			}

			if (d == 2)
			{
				//s = UTF8ToGB(s.c_str()).c_str();
				h[i].name = s;
				d = 3;
				continue;
			}
			if (d == 3)
			{
				h[i].passsword = stoi(s, 0, 10);
				d = 1;
				i++;
				continue;
			}
		}
		inf.close();
		for ( j = 1; h[j].name != ""; j++);
		h[j].id = id_1, h[j].name = name_1,h[j].passsword=password_1;
		ofstream outfile;    //�������������
		string filePath = "D:\\����\\bookmanager\\bookmanager\\user.txt";
		outfile.open(filePath);    //���ļ�
		if (!outfile)
		{
			cout << "���ļ�ʧ��" << endl;
			exit(1);
		}

		//���ļ���д������
		for (int x = 1; h[x].name != ""; x++)
		{
			outfile << h[x].id << endl << h[x].name << endl<<h[x].passsword<<endl;
		}
		cout << "��ӳɹ�" << endl;
	}
	else
	{
		int d = 1, i = 1;
		string s;
		ifstream inf;
		inf.open("D:\\����\\bookmanager\\bookmanager\\user.txt");          //�ر�ע�⣬�����ǣ�//  ��˫б���~~ 
		while (getline(inf, s))      //getline(inf,s)�����ж�ȡinf�е��ļ���Ϣ
		{
			if (d == 1)
			{

				d = 2;
				//s = s.substr(0, s.find_last_not_of('\r'));
				h[i].id = stoi(s, 0, 10);
				continue;
			}

			if (d == 2)
			{
				//s = UTF8ToGB(s.c_str()).c_str();
				h[i].name = s;
				d = 3;
				continue;
			}
			if (d == 3)
			{
				h[i].passsword = stoi(s, 0, 10);
				d = 1;
				i++;
				continue;
			}
		}
		inf.close();
		i = 0;
		for (i = 1; i <= 99; i++)
		{
			if (h[i].name == name_1 && h[i].passsword == password_1)
				break;
		}
		
		if (i == 100)
		{
			cout << "��Ǹ���޴���" << endl;
			return;
		}
		for (int j = i; h[j].name != ""; j++)
		{
			h[j] = h[j + 1];
		}
		ofstream outfile;    //�������������
		string filePath = "D:\\����\\bookmanager\\bookmanager\\user.txt";
		outfile.open(filePath);    //���ļ�
		if (!outfile)
		{
			cout << "���ļ�ʧ��" << endl;
			exit(1);
		}

		//���ļ���д������
		for (int j = 1; h[j].name != ""; j++)
		{
			outfile <<h[j].id<<endl <<h[j].name << endl <<h[j].passsword << endl;
		}

		outfile.close();    //�ر��ļ�
		cout << "ɾ���ɹ�" << endl;
	}
	system("pause");
	system("cls");
}
void supermanager::change_manager(int id_2, string name_2, int password_2)
{
	cout << "��������Ҫ���еĲ���" << endl << "1.���" << "2.ɾ��" << endl;
	int od1 = 1, j;
	cin >> od1;
	if (od1 == 1)
	{
		int d = 1, i = 1;
		string s;
		ifstream inf;
		inf.open("D:\\����\\bookmanager\\bookmanager\\manager.txt");          //�ر�ע�⣬�����ǣ�//  ��˫б���~~ 
		while (getline(inf, s))      //getline(inf,s)�����ж�ȡinf�е��ļ���Ϣ
		{
			if (d == 1)
			{

				d = 2;
				//s = s.substr(0, s.find_last_not_of('\r'));
				g[i].id = stoi(s, 0, 10);
				continue;
			}

			if (d == 2)
			{
				//s = UTF8ToGB(s.c_str()).c_str();
				g[i].name = s;
				d = 3;
				continue;
			}
			if (d == 3)
			{
				g[i].passsword = stoi(s, 0, 10);
				d = 1;
				i++;
				continue;
			}
		}
		inf.close();
		for (j = 1; g[j].name != ""; j++);
		g[j].id = id_2, g[j].name = name_2, g[j].passsword = password_2;
		ofstream outfile;    //�������������
		string filePath = "D:\\����\\bookmanager\\bookmanager\\manager.txt";
		outfile.open(filePath);    //���ļ�
		if (!outfile)
		{
			cout << "���ļ�ʧ��" << endl;
			exit(1);
		}

		//���ļ���д������
		for (int x = 1; g[x].name != ""; x++)
		{
			outfile << g[x].id << endl << g[x].name << endl << g[x].passsword << endl;
		}
		cout << "��ӳɹ�" << endl;
	}
	else
	{
		int d = 1, i = 1;
		string s;
		ifstream inf;
		inf.open("D:\\����\\bookmanager\\bookmanager\\manager.txt");          //�ر�ע�⣬�����ǣ�//  ��˫б���~~ 
		while (getline(inf, s))      //getline(inf,s)�����ж�ȡinf�е��ļ���Ϣ
		{
			if (d == 1)
			{

				d = 2;
				//s = s.substr(0, s.find_last_not_of('\r'));
				g[i].id = stoi(s, 0, 10);
				continue;
			}

			if (d == 2)
			{
				//s = UTF8ToGB(s.c_str()).c_str();
				g[i].name = s;
				d = 3;
				continue;
			}
			if (d == 3)
			{
				g[i].passsword = stoi(s, 0, 10);
				d = 1;
				i++;
				continue;
			}
		}
		inf.close();
		i = 0;
		for (i = 1; i <= 99; i++)
		{
			if (g[i].name == name_2&& g[i].passsword == password_2)
				break;
		}

		if (i == 100)
		{
			cout << "��Ǹ���޴���" << endl;
			return;
		}
		for (int j = i; g[j].name != ""; j++)
		{
			g[j] = g[j + 1];
		}
		ofstream outfile;    //�������������
		string filePath = "D:\\����\\bookmanager\\bookmanager\\manager.txt";
		outfile.open(filePath);    //���ļ�
		if (!outfile)
		{
			cout << "���ļ�ʧ��" << endl;
			exit(1);
		}

		//���ļ���д������
		for (int j = 1; g[j].name != ""; j++)
		{
			outfile << g[j].id <<endl<< g[j].name << endl << g[j].passsword << endl;
		}

		outfile.close();    //�ر��ļ�
		cout << "ɾ���ɹ�" << endl;
	}
	system("pause");
	system("cls");
}
