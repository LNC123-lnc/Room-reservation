#pragma once
#include<iostream>
#include"identity.h"
#include<vector>
#include"student.h"
#include"teacher.h"
#include"computeroom.h"
using namespace std;

class Manager :public Identity
{
public:
	Manager();//构造

	Manager(string name,string pwd);//有参构造

	virtual void operMenu();//菜单界面

	void addPerson();//添加账号

	void showPerson();//查看账号

	void showComputer();//查看机房信息

	void cleanFile();//清空预约记录

	void initVector();//初始化容器

	bool checkRepeat(int id,int type);//检测重复

	vector<Student>vStu;

	vector<Teacher>vTea;

	vector<Computeroom>vCom;
};
