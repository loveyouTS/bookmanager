#include<iostream>
#include"user.h"
#include"book.h"
#include<fstream>
#include<string>
#include"manager.h"
#include"supermanager.h"
using namespace std;
user a[100];
manager c[100];
supermanager p[100];
user* get_user()
{
	int d = 1,i=1;
	string s;
	ifstream inf;
	inf.open("D:\\����\\bookmanager\\bookmanager\\user.txt");          //�ر�ע�⣬�����ǣ�//  ��˫б���~~ 
	while (getline(inf, s))      //getline(inf,s)�����ж�ȡinf�е��ļ���Ϣ
	{
		if (d == 1)
		{

			d = 2;
			//s = s.substr(0, s.find_last_not_of('\r'));
			a[i].id = stoi(s, 0, 10);
			continue;
		}

		if (d == 2)
		{
			//s = UTF8ToGB(s.c_str()).c_str();
			a[i].name = s;
			d = 3;
			continue;
		}
		if (d == 3)
		{
			a[i].passsword = stoi(s, 0, 10);
			d = 1;
			i++;
			continue;
		}
	}
	inf.close();
	return a;
}
void get_manager()
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
			c[i].id = stoi(s, 0, 10);
			continue;
		}

		if (d == 2)
		{
			//s = UTF8ToGB(s.c_str()).c_str();
			c[i].name = s;
			d = 3;
			continue;
		}
		if (d == 3)
		{
			c[i].passsword = stoi(s, 0, 10);
			d = 1;
			i++;
			continue;
		}
	}
	inf.close();
	
}
void get_supermanager()
{
	int d = 1, i = 1;
	string s;
	ifstream inf;
	inf.open("D:\\����\\bookmanager\\bookmanager\\supermanager.txt");          //�ر�ע�⣬�����ǣ�//  ��˫б���~~ 
	while (getline(inf, s))      //getline(inf,s)�����ж�ȡinf�е��ļ���Ϣ
	{
		if (d == 1)
		{

			d = 2;
			
			p[i].id = stoi(s, 0, 10);
			continue;
		}

		if (d == 2)
		{
			s = UTF8ToGB(s.c_str()).c_str();
			p[i].name = s;
			d = 3;
			continue;
		}
		if (d == 3)
		{
			p[i].passsword = stoi(s, 0, 10);
			d = 1;
			i++;
			continue;
		}
	}
	inf.close();

}
int main()
{
	
	
	while(1)
	{
		get_user();
		get_manager();
		get_supermanager();
		string name;
		int passworld, sum = 1, sum2 = 1, sum3 = 1;
		int judge = 0;
		cout << "1.��ͨ�û���½" << endl << "2.����Ա��½" << endl << "3.��������Ա��½" << endl<<"��ѡ����Ҫ���еĲ���"<<endl;
		cin >> judge;
		if (judge == 1)
		{
			while (true)
			{

				cout << "�������û���" << endl;
				cin >> name;
				for (sum = 1; sum <= 99; sum++)
					if (a[sum].name == name)
						break;
				if (sum == 100)
					cout << "��Ǹû�д��û�" << endl;
				else
					break;
				cout << "���ٴ�����" << endl;
			}
			while (1)
			{
				cout << "����������" << endl;
				cin >> passworld;
				if (a[sum].passsword == passworld)
				{
					cout << "��½�ɹ�" << endl;
					break;
				}
				else
					cout << "����������ٴ�����" << endl;
			}
			while (1)
			{
				cout << "��������Ҫ���еĲ���" << endl << "1.����" << endl << "2.����" << endl << "3.��ѯ������Ϣ" << endl << "4.��ѯͼ����Ϣ" << endl << "5.���鹫��" <<endl
					<< "6.�˳�ϵͳ" << endl;
				int order = 0;
				cin >> order;
				if (order == 1)
				{
					string find_name, find_auther;
					cout << "��������Ҫ���ҵ�����������" << endl;
					cin >> find_name >> find_auther;
					a[sum].borrowbook(find_name, find_auther);
				}
				if (order == 2)
				{
					string return_name, return_auther;
					cout << "��������Ҫ��������������" << endl;
					cin >> return_name >> return_auther;
					a[sum].returnbook(return_name, return_auther);

				}
				if (order == 3)
					a[sum].personal();
				if (order == 4)
				{
					string re_name, re_auther;
					cout << "��������Ҫ��ѯ������������" << endl;
					cin >> re_name >> re_auther;
					a[sum].book_research(re_name, re_auther);
				}
				if (order == 5)
					a[sum].bulletin();
				if (order == 6)
				system("cls");
					break;
			}
		}
			if (judge == 2)
			{
				while (true)
				{

					cout << "�������û���" << endl;
					cin >> name;
					for (sum2 = 1; sum2 <= 99; sum2++)
						if (c[sum2].name == name)
							break;
					if (sum2 == 100)
						cout << "��Ǹû�д��û�" << endl;
					else
						break;
					cout << "���ٴ�����" << endl;
				}
				while (1)
				{
					cout << "����������" << endl;
					cin >> passworld;
					if (c[sum2].passsword == passworld)
					{
						cout << "��½�ɹ�" << endl;
						break;
					}
					else
						cout << "����������ٴ�����" << endl;
				}
				while (1)
				{
					cout << "��������Ҫ���еĲ���" << endl << "1.���ͼ��" << endl << "2.ɾ��ͼ��" << endl << "3.�쳣�黹����" << endl << "4.��������" << endl << "5.�˳�ϵͳ" << endl;
					int order2 = 0;
					cin >> order2;
					if (order2 == 1)
					{
						string add_name, add_auther;

						cout << "��������Ҫ���������ֺ�����" << endl;
						cin >> add_name >> add_auther;
						c[sum2].add_book(add_name, add_auther);

					}
					if (order2 == 2)
					{
						string delete_name, delete_auther;
						cout << "��������Ҫɾ��������ֺ�����" << endl;
						cin >> delete_auther >> delete_name;
						c[sum2].delete_book(delete_name, delete_auther);

					}
					if (order2 == 4)
					{
						c[sum2].publish();
					}
					if (order2 == 5)
						system("cls");
						break;
				}
			}
			if (judge == 3)
			{
				while (true)
				{

					cout << "�������û���" << endl;
					cin >> name;
					for (sum3 = 1; sum3 <= 99; sum3++)
						if (p[sum3].name == name)
							break;
					if (sum3 == 100)
						cout << "��Ǹû�д��û�" << endl;
					else
						break;
					cout << "���ٴ�����" << endl;
				}
				while (1)
				{
					cout << "����������" << endl;
					cin >> passworld;
					if (p[sum3].passsword == passworld)
					{
						cout << "��½�ɹ�" << endl;
						break;
					}
					else
						cout << "����������ٴ�����" << endl;
				}
				while (1)
				{
					cout << "��������Ҫ���еĲ���" << endl << "1.�޸�����" << endl << "2.�������Ա" << endl << "3.�����û�" << endl<<"4.�˳�ϵͳ" << endl;
					int order3 = 1;
					cin >> order3;
					if (order3 == 1)
					{
						p[sum3].change_password1();
					}
					if (order3 == 2)
					{
						string ch_name;
						int ch_password, ch_id;
						cout << "��������Ҫ��ӻ�ɾ����id,�û���������" << endl;
						cin >> ch_id >> ch_name >> ch_password;
						p[sum3].change_manager(ch_id, ch_name, ch_password);
					}
					if (order3 == 3)
					{
						string ch_name;
						int ch_password, ch_id;
						cout << "��������Ҫ��ӻ�ɾ����id,�û���������" << endl;
						cin >> ch_id >> ch_name >> ch_password;
						p[sum3].change_user(ch_id, ch_name, ch_password);
					}
					if (order3 == 4)
						system("cls");
						break;
				}

			}

		}
	}
