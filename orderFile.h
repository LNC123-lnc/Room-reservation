#pragma once
#include<iostream>
using namespace std;
#include"globalFile.h"
#include<fstream>
#include<map>
#include<string>
class OrderFile
{
public:
	OrderFile();//����

	void updateOrder();//����ԤԼ��¼

	int m_size;//��¼ԤԼ����

	//��¼����ԤԼ��Ϣ��������key��¼���� value��¼��ֵ����Ϣ
	map<int, map<string, string>> m_orderdata;
};