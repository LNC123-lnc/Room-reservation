#pragma once
using namespace std;
#include<string>
class Identity
{
public:
	virtual void operMenu() = 0;//操作菜单，纯虚函数

	string  m_Name;//用户名
	string  m_Pwd;//密码
};