#pragma once
#include"identity.h"
using namespace std;

class Teacher :public Identity
{
public:
	Teacher();
	//����
	Teacher(int id,string name,string pwd);
	//�вι���
	virtual void operMenu();//�˵�����

	void showAllOrder();//�鿴����ԤԼ

	void validOrder();//���ԤԼ

	int m_EmpId;//ְ����

};