#pragma once
#include"identity.h"
#include<vector>
#include"computeroom.h"
class Student :public Identity
{
public:
	Student();//Ĭ�Ϲ���

	Student(int id,string name,string pwd);//�вι���

	void ApplyOder();//����ԤԼ

	void ShowMyOder();//�鿴�ҵ�ԤԼ

	void ShowAllOder();//�鿴����ԤԼ

	void CancelOder();//ȡ��ԤԼ

	virtual void operMenu();

	int m_id;

	int men=0;

	vector<Computeroom>vCom;
};