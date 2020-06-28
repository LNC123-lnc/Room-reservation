#include<iostream>
using namespace std;
#include"identity.h"
#include<string>
#include<fstream>
#include"globalFile.h"
#include"student.h"
#include"teacher.h"
#include"manager.h"

//进入学生子菜单界面
void studentMenu(Identity * &student)
{
	
	while (true)
	{
		student->operMenu();

		Student *stu = (Student*)student;

		int select = 0;
		cin >> select;
		if (select == 1)
		{
			stu->ApplyOder();
		}
		else if (select == 2)
		{
			stu->ShowMyOder();
		}
		else if (select == 3)
		{
			stu->ShowAllOder();
		}
		else if (select == 4)
		{
			stu->CancelOder();
		}
		else
		{
			delete student;
			cout << "注销成功0" << endl;
			return;
		}
	}
}
void teacherMenu(Identity * &teacher)
{
	while (true)
	{
		//调用子菜单界面
		teacher->operMenu();

		Teacher * tea = (Teacher*)teacher;

		int select = 0; //接受用户选择

		cin >> select;

		if (select == 1) //查看所有预约
		{
			tea->showAllOrder();
		}
		else if (select == 2) //审核预约
		{
			tea->validOrder();
		}
		else
		{
			delete teacher;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}
//进入管理员子菜单界面
void managerMenu(Identity *&manager)
{
	while (true)
	{
		//调用管理员子菜单
		manager->operMenu();
		//将父类指针转为子类指针，调用子类其他接口
		Manager *man = (Manager*)manager;

		int select = 0;
		cin >> select;
		if (select == 1)
		{
			cout << "添加账号" << endl;
			man->addPerson();

		}
		else if (select == 2)
		{
			cout << "查看账号" << endl;
			man->showPerson();
		}
		else if (select == 3)
		{
			cout << "查看机房" << endl;
			man->showComputer();
		}
		else if (select == 4)
		{
			cout << "取消预约" << endl;
			man->cleanFile();
		}
		else
		{
			delete manager;
			cout << "注销成功" << endl;
			return;

		}
	}
}
void LoginIn(string filename, int type) //登录功能 操作文件名   操作类型
{
	Identity * person = NULL;//父类指针，用于指向子类对象
	//读文件
	ifstream ifs;
	ifs.open(filename,ios::in);
	//判断文件是否存在
	if (!ifs.is_open())
	{
		cout << "wenjianbucunzai." << endl;
		ifs.close();
		return;
	}
	//接收用户信息
	int id = 0;
	string name;
	string pwd;
	
	//判断身份
	if (type == 1)
	{
		cout << "请输入学号：" << endl;
		cin >>id;
	}
	else if (type == 2)
	{
		cout << "请输入职工号：" << endl;
		cin >> id;
	}
	cout << "请输入用户名：" << endl;
	cin >> name;
	cout << "请输入密码：" << endl;
	cin >> pwd;

	if (type == 1)
	{
		//学生登录认证
		int fid;
		string fname;
		string fpwd;
		while(ifs>>fid && ifs>>fname && ifs>>fpwd)
		{
			if (fid = id && fname == name && fpwd == pwd)
			{
				cout << "登录成功！" << endl;
				system("cls");
				person = new Student(id,name,pwd);
				//进入学生子菜单
				studentMenu(person);
				return;
			}
		}
	}
	else if (type == 2)
	{
		//老师登录认证
		int fid;
		string fname;
		string fpwd;
		while (ifs >> fid && ifs >> fname && ifs >> fpwd)
		{
			if (fid = id && fname == name && fpwd == pwd)
			{
				cout << "登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				//进入老师子菜单
				teacherMenu(person);
				return;
			}
		}
	}
	else
	{
		//管理员登录认证
		string fname;
		string fpwd;
		while (ifs >> fname && ifs >> fpwd)
		{
			if (fname == name && fpwd == pwd)
			{
				cout << "登录成功！" << endl;
				system("cls");
				person = new Manager(name,pwd);
				//进入管理员子菜单
				managerMenu(person);
				return;
			}
		}
	}
	cout << "验证失败。" << endl;
	system("pause");
	system("cls");

}
int main()
{
	int select = 0;
	while(true)
	{
		cout << "\t\t|-------------------------|\n";
		cout << "\t\t|       1.学生代表        |\n";
		cout << "\t\t|       2.老    师        |\n";
		cout << "\t\t|       3.管 理 员		   |\n";
		cout << "\t\t|       4.退    出		   |\n";
		cout << "\t\t|-------------------------|\n";
		cout << "输入你的选择:";
		cin >> select;//接收用户选择
		
			switch (select)
			{
			case 1://学生
				LoginIn(STUDENT_FILE, 1);
				break;
			case 2://老师
				LoginIn(TEACHER_FILE, 2);
				break;
			case 3://管理员
				LoginIn(ADMIN_FILE, 3);
				break;
			case 4://退出
				cout << "欢迎下次使用" << endl;
				system("pause");
				return 0;
				break;
			default:
				cout << "输入有误,请重新输入：";

				break;
			}
		
	}
	system("pause");
	return 0;
}