#include"manager.h"
using namespace std;
#include<fstream>
#include"globalFile.h"
#include<algorithm>
Manager::Manager()//构造
{

}
Manager::Manager(string name, string pwd)//有参构造
{
	this->m_Name = name;
	this->m_Pwd = pwd;
	
	//初始化机房信息

	ifstream ifs;
	ifs.open(COMPUTER_FILE,ios::in);

	Computeroom com;
	while (ifs >> com.m_Comid && ifs >> com.m_num)
	{
		vCom.push_back(com);
	}
	ifs.close();
	cout << "机房数量：" << vCom.size() << endl;
}
void Manager:: operMenu()//菜单界面
{
	cout << "欢迎" << this->m_Name << "登录" << endl;
	cout << "1.添加账号"<<endl;
	cout << "2.查看账号"<<endl;
	cout << "3.查看机房"<<endl;
	cout << "4.清空预约"<<endl;
	cout << "0.注销登录"<<endl;
}
void Manager::addPerson()//添加账号
{
	this->initVector();
	cout << "1.添加学生" << endl;
	cout << "2.添加教师" << endl;

	string fileName;
	string tip;
	string errortip;


	ofstream ofs;

	int select;
	cin >> select;
	if (select == 1)
	{
		fileName = STUDENT_FILE;
		tip = "请输入学号：";
		errortip = "学号已存在,请重新输入：";
	}
	else
	{
		fileName = TEACHER_FILE;
		tip = "请输入职工编号:";
		errortip = "职工号已存在，请重新输入：";
	}

	ofs.open(fileName,ios::out | ios::app);

	int id;
	string name;
	string pwd;

	cout << tip << endl;
	
	while(true)
	{
		cin >> id;
		bool ret = checkRepeat(id,select);
		if(ret)
		{
			cout << errortip << endl;
		}
		else
		{
			break;
		}

	}

	cout << "请输入姓名:" << endl;
	cin >> name;
	cout << "请输入密码:" << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "添加成功" << endl;
	ofs.close();
	this->initVector();
	system("cls");
	return;

}
void printstu(Student &s)
{
	cout << "id:" << s.m_id << "name:" << s.m_Name << "password:" << s.m_Pwd << endl;
}
void printtea(Teacher &s)
{
	cout << "id:" << s.m_EmpId << "name:" << s.m_Name << "password:" << s.m_Pwd << endl;
}
void Manager::showPerson()//查看账号
{
	cout << "1.show student information:" << endl;
	cout << "2.show teacher information:" << endl;
	int select;
	cin >> select;
	if (select == 1)
	{
		for_each(vStu.begin(),vStu.end(),printstu);
	}
	else if (select == 2)
	{
		for_each(vTea.begin(),vTea.end(),printtea);
	}
	system("pause");
	system("cls");
}
void Manager::showComputer()//查看机房信息
{
	cout << "机房信息如下：" << endl;

	for (vector<Computeroom>::iterator it = vCom.begin(); it != vCom.end(); it++)
	{
		cout << "机房编号: " << it->m_Comid <<
			"机房大小：  " << it->m_num << endl;
	}
	system("pause");
	system("cls");
}
void Manager::cleanFile()//清空预约记录
{
	ofstream ofs(ORDER_FILE,ios::trunc);
	ofs.close();
	cout << "清空成功！" << endl;
	system("pause");
	system("cls");
}
void Manager::initVector()//初始化容器
{
	ifstream ifs;
	vStu.clear();//清空学生容器
	vTea.clear();//清空教师容器
	ifs.open(STUDENT_FILE,ios::in);///读取学生文件
	if (!ifs.is_open())
	{
		cout << "read file fail;" << endl;
		return;
	}
	Student s;
	while (ifs >> s.m_id &&ifs >> s.m_Name &&ifs >> s.m_Pwd)
	{
		vStu.push_back(s);//学生信息读取到容器中
	}
	cout << "student number:" << vStu.size() << endl;
	ifs.close();

	ifs.open(TEACHER_FILE, ios::in);
	Teacher t;
	while (ifs>>t.m_EmpId && ifs>>t.m_Name && ifs>>t.m_Pwd)
	{
		vTea.push_back(t);
	}
	cout << "teacher number:" << vTea.size() << endl;
	ifs.close();



}
bool Manager::checkRepeat(int id, int type)//检测重复
{
	if (type == 1)
	{
		//检测学生
		for (vector<Student>::iterator it = vStu.begin();it!=vStu.end();it++)
		{
			if (id == it->m_id)
			{
				return true;
			}
		}
	}
	if (type == 2)
	{//检测老师
		for (vector<Teacher>::iterator it = vTea.begin(); it !=vTea.end(); it++)
		{
			if (id == it->m_EmpId)
			{
				return true;
			}
		}
	}
	return false;
}