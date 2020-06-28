#include"teacher.h"
#include"orderFile.h"
#include<vector>
#include<iostream>
using namespace std;

Teacher::Teacher()//构造
{

}
Teacher::Teacher(int empId, string name, string pwd)//有参构造
{
	//初始化属性
	//初始化属性
	this->m_EmpId = empId;
	this->m_Name = name;
	this->m_Pwd = pwd;
}
void Teacher::operMenu()//菜单界面
{
	cout << "欢迎教师：" << this->m_Name << "登录！" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          1.查看所有预约          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          2.审核预约              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          0.注销登录              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "请选择您的操作： " << endl;
}
void Teacher::showAllOrder()//查看所有预约
{
	OrderFile of;
	if (of.m_size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_size; i++)
	{
		cout << i + 1 << "、 ";
		cout << "预约日期： 周" << of.m_orderdata[i]["date"];
		cout << " 时间段： " << (of.m_orderdata[i]["interval"] == "1" ? "上午" : "下午");
		cout << " 学号： " << of.m_orderdata[i]["id"];
		cout << " 姓名： " << of.m_orderdata[i]["name"];
		cout << " 机房编号： " << of.m_orderdata[i]["roomid"];
		string status = " 状态： ";
		//1 审核中 2 已预约 -1 预约失败  0 取消预约
		if (of.m_orderdata[i]["status"] == "1")
		{
			status += "审核中";
		}
		else if (of.m_orderdata[i]["status"] == "2")
		{
			status += "预约成功";
		}
		else if (of.m_orderdata[i]["status"] == "-1")
		{
			status += "预约失败，审核未通过";
		}
		else
		{
			status += "预约已取消";
		}
		cout << status << endl;

	}

	system("pause");
	system("cls");
}
void Teacher::validOrder()//审核预约
{
	OrderFile of;
	if (of.m_size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}

	vector<int>v;
	int index = 0;
	cout << "待审核的预约记录如下：" << endl;

	for (int i = 0; i < of.m_size; i++)
	{
		if (of.m_orderdata[i]["status"] == "1")
		{
			v.push_back(i);
			cout << ++index << "、 ";
			cout << "预约日期： 周" << of.m_orderdata[i]["date"];
			cout << " 时间段： " << (of.m_orderdata[i]["interval"] == "1" ? "上午" : "下午");
			cout << " 学生编号： " << of.m_orderdata[i]["id"];
			cout << " 学生姓名： " << of.m_orderdata[i]["name"];
			cout << " 机房编号： " << of.m_orderdata[i]["roomid"];
			string status = " 状态：审核中 ";
			cout << status << endl;
		}
	}

	cout << "请输入审核的预约记录，0代表返回" << endl;
	int select = 0; //接受用户选择的预约记录
	int ret = 0;  //接受预约结果记录

	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				cout << "请输入审核结果" << endl;
				cout << "1、通过" << endl;
				cout << "2、不通过" << endl;
				cin >> ret;
				if (ret == 1)
				{
					//通过情况
					of.m_orderdata[v[select - 1]]["status"] = "2";
				}
				else
				{
					//不通过情况
					of.m_orderdata[v[select - 1]]["status"] = "-1";
				}
				of.updateOrder(); // 更新预约记录
				cout << "审核完毕" << endl;
				break;
			}
		}
		cout << "输入有误，请重新输入！" << endl;
	}
	system("pause");
	system("cls");
}