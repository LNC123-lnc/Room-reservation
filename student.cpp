#include"student.h"
#include<iostream>
#include<fstream>
#include"computeroom.h"
#include"globalFile.h"
#include"orderFile.h"
using namespace std;
Student::Student()//默认构造
{

}
Student::Student(int id, string name, string pwd)//有参构造
{
	this->m_id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;

	//初始化机房信息
	ifstream ifs;
	ifs.open(COMPUTER_FILE,ios::in);

	Computeroom com;
	while (ifs >> com.m_Comid &&ifs >> com.m_num)
	{
		vCom.push_back(com);
	}
	ifs.close();


}
void Student:: ApplyOder()//申请预约
{
	cout << "机房开放时间为中一道周五！" << endl;
	cout << "请输入申请预约时间：" << endl;
	cout << "1.周一" << endl;
	cout << "2.周二" << endl;
	cout << "3.周三" << endl;
	cout << "4.周四" << endl;
	cout << "5.周五" << endl;

	int date = 0;
	int interval;
	int room;
	
	while (true)
	{
		cin >> date;
		if (date >= 1 && date <= 5)
		{
			break;
		}
		cout << "输入错误，重新输入：" << endl;
	}
	
	cout << "1.上午" << endl;
	cout << "2.下午" << endl;
	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		cout << "输入错误，重新输入：" << endl;
	}
	cout << "选着机房：" << endl;
	for (int i = 0; i < vCom.size(); i++)
	{
		cout << vCom[i].m_Comid << "号机房容量为：" << vCom[i].m_num << endl;
	}
	while (true)
	{
		cin >> room;
		if (room >= 1 && room<= 3)
		{
			break;
		}
		cout << "输入错误，重新输入：" << endl;
	}
	cout << "预约成功！审核中。" << endl;
	ofstream ofs;
	ofs.open(ORDER_FILE,ios::app);
	
	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "id:" << this->m_id << " ";
	ofs << "name:" << this->m_Name << " ";
	ofs << "roomid:" << room << " ";
	ofs << "status:" << 1 << endl;
	ofs.close();
}
void Student:: ShowMyOder()//查看我的预约
{
	OrderFile of;
	if (of.m_size == 0)
	{
		cout << "无预约记录" << endl;
		return;
	}
	for (int i = 0; i < of.m_size; i++)
	{
		//string 利用 .c_str() 转const char *
		//利用 atoi(const char *)转 Int
		if (this->m_id == atoi(of.m_orderdata[i]["stuid"].c_str()));
		{

			cout << i << " ";
			cout << "预约日期：周" << of.m_orderdata[i]["date"];
			cout << " 时间段：" << (of.m_orderdata[i]["interval"] == "1" ? "上午" : "下午");
			cout << " 机房号：" << of.m_orderdata[i]["roomid"] ;
			string status = "状态:";
			//1 审核中 2已预约 -1预约失败 0取消预约
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
				status += "预约失败";
			}
			else
			{
				status += "预约已取消";
			}
			cout << status << endl;
		}
	}
	
}
void Student::ShowAllOder()//查看所有预约
{
	OrderFile of;
	if (of.m_size == 0)
	{
		cout << "无预约记录" << endl;
		return;
	}
	for (int i = 0; i < of.m_size; i++)
	{
		cout<<"周" << of.m_orderdata[i]["date"];
		cout << "  时间段:  " << (of.m_orderdata[i]["interval"] == "1" ? "上午" : "下午");
		cout << "   学号：" << of.m_orderdata[i]["id"];
		cout << "  姓名： " << of.m_orderdata[i]["name"];
		cout << "  机房号：" << of.m_orderdata[i]["roomid"];
		string status = "状态:";
		//1 审核中 2已预约 -1预约失败 0取消预约
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
			status += "预约失败";
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
void Student::CancelOder()//取消预约
{
	ShowMyOder();
	cout << "请输入你要取消预约的编号：";
	int select;
	cin >> select;
	OrderFile of;
	for (int i = 0; i < of.m_size; i++)
	{
		//string 利用 .c_str() 转const char *
		//利用 atoi(const char *)转 Int
		if (this->m_id == atoi(of.m_orderdata[i]["stuid"].c_str()));
		{
			
			if (select == men)
			{
				of.m_orderdata[i]["status"] = "0";
			}
			men++;
		}
	}
	of.updateOrder();
}
void Student:: operMenu()//菜单界面
{

	cout << "1.申请预约" << endl;
	cout << "2.查看我的预约" << endl;
	cout << "3.查看所有预约" << endl;
	cout << "4.取消预约" << endl;
	cout << "5.注销登录" << endl;

}