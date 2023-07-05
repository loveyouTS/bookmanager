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
	inf.open("D:\\代码\\bookmanager\\bookmanager\\user.txt");          //特别注意，这里是：//  是双斜杠喔~~ 
	while (getline(inf, s))      //getline(inf,s)是逐行读取inf中的文件信息
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
	inf.open("D:\\代码\\bookmanager\\bookmanager\\manager.txt");          //特别注意，这里是：//  是双斜杠喔~~ 
	while (getline(inf, s))      //getline(inf,s)是逐行读取inf中的文件信息
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
	inf.open("D:\\代码\\bookmanager\\bookmanager\\supermanager.txt");          //特别注意，这里是：//  是双斜杠喔~~ 
	while (getline(inf, s))      //getline(inf,s)是逐行读取inf中的文件信息
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
		cout << "1.普通用户登陆" << endl << "2.管理员登陆" << endl << "3.超级管理员登陆" << endl<<"请选择你要进行的操作"<<endl;
		cin >> judge;
		if (judge == 1)
		{
			while (true)
			{

				cout << "请输入用户名" << endl;
				cin >> name;
				for (sum = 1; sum <= 99; sum++)
					if (a[sum].name == name)
						break;
				if (sum == 100)
					cout << "抱歉没有此用户" << endl;
				else
					break;
				cout << "请再次输入" << endl;
			}
			while (1)
			{
				cout << "请输入密码" << endl;
				cin >> passworld;
				if (a[sum].passsword == passworld)
				{
					cout << "登陆成功" << endl;
					break;
				}
				else
					cout << "密码错误，请再次输入" << endl;
			}
			while (1)
			{
				cout << "请输入您要进行的操作" << endl << "1.借书" << endl << "2.还书" << endl << "3.查询个人信息" << endl << "4.查询图书信息" << endl << "5.看查公告" <<endl
					<< "6.退出系统" << endl;
				int order = 0;
				cin >> order;
				if (order == 1)
				{
					string find_name, find_auther;
					cout << "请输入你要查找的书名和作者" << endl;
					cin >> find_name >> find_auther;
					a[sum].borrowbook(find_name, find_auther);
				}
				if (order == 2)
				{
					string return_name, return_auther;
					cout << "请输入你要还的书名和作者" << endl;
					cin >> return_name >> return_auther;
					a[sum].returnbook(return_name, return_auther);

				}
				if (order == 3)
					a[sum].personal();
				if (order == 4)
				{
					string re_name, re_auther;
					cout << "请输入你要查询的书名和作者" << endl;
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

					cout << "请输入用户名" << endl;
					cin >> name;
					for (sum2 = 1; sum2 <= 99; sum2++)
						if (c[sum2].name == name)
							break;
					if (sum2 == 100)
						cout << "抱歉没有此用户" << endl;
					else
						break;
					cout << "请再次输入" << endl;
				}
				while (1)
				{
					cout << "请输入密码" << endl;
					cin >> passworld;
					if (c[sum2].passsword == passworld)
					{
						cout << "登陆成功" << endl;
						break;
					}
					else
						cout << "密码错误，请再次输入" << endl;
				}
				while (1)
				{
					cout << "请输入你要进行的操作" << endl << "1.添加图书" << endl << "2.删除图书" << endl << "3.异常归还处罚" << endl << "4.发布公告" << endl << "5.退出系统" << endl;
					int order2 = 0;
					cin >> order2;
					if (order2 == 1)
					{
						string add_name, add_auther;

						cout << "请输入你要添加书的名字和作者" << endl;
						cin >> add_name >> add_auther;
						c[sum2].add_book(add_name, add_auther);

					}
					if (order2 == 2)
					{
						string delete_name, delete_auther;
						cout << "请输入你要删除书的名字和作者" << endl;
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

					cout << "请输入用户名" << endl;
					cin >> name;
					for (sum3 = 1; sum3 <= 99; sum3++)
						if (p[sum3].name == name)
							break;
					if (sum3 == 100)
						cout << "抱歉没有此用户" << endl;
					else
						break;
					cout << "请再次输入" << endl;
				}
				while (1)
				{
					cout << "请输入密码" << endl;
					cin >> passworld;
					if (p[sum3].passsword == passworld)
					{
						cout << "登陆成功" << endl;
						break;
					}
					else
						cout << "密码错误，请再次输入" << endl;
				}
				while (1)
				{
					cout << "请输入你要进行的操作" << endl << "1.修改密码" << endl << "2.管理管理员" << endl << "3.管理用户" << endl<<"4.退出系统" << endl;
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
						cout << "请输入你要添加或删除的id,用户名及密码" << endl;
						cin >> ch_id >> ch_name >> ch_password;
						p[sum3].change_manager(ch_id, ch_name, ch_password);
					}
					if (order3 == 3)
					{
						string ch_name;
						int ch_password, ch_id;
						cout << "请输入你要添加或删除的id,用户名及密码" << endl;
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
