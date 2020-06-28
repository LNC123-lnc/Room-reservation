#pragma once
#include"identity.h"
using namespace std;

class Teacher :public Identity
{
public:
	Teacher();
	//构造
	Teacher(int id,string name,string pwd);
	//有参构造
	virtual void operMenu();//菜单界面

	void showAllOrder();//查看所有预约

	void validOrder();//审核预约

	int m_EmpId;//职工号

};