#pragma once
#include"identity.h"
#include<vector>
#include"computeroom.h"
class Student :public Identity
{
public:
	Student();//默认构造

	Student(int id,string name,string pwd);//有参构造

	void ApplyOder();//申请预约

	void ShowMyOder();//查看我的预约

	void ShowAllOder();//查看所有预约

	void CancelOder();//取消预约

	virtual void operMenu();

	int m_id;

	int men=0;

	vector<Computeroom>vCom;
};