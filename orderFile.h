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
	OrderFile();//构造

	void updateOrder();//更新预约记录

	int m_size;//记录预约条数

	//记录所有预约信息的容器，key记录条数 value记录键值对信息
	map<int, map<string, string>> m_orderdata;
};