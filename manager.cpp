#include"manager.h"
using namespace std;
#include<fstream>
#include"globalFile.h"
#include<algorithm>
Manager::Manager()//����
{

}
Manager::Manager(string name, string pwd)//�вι���
{
	this->m_Name = name;
	this->m_Pwd = pwd;
	
	//��ʼ��������Ϣ

	ifstream ifs;
	ifs.open(COMPUTER_FILE,ios::in);

	Computeroom com;
	while (ifs >> com.m_Comid && ifs >> com.m_num)
	{
		vCom.push_back(com);
	}
	ifs.close();
	cout << "����������" << vCom.size() << endl;
}
void Manager:: operMenu()//�˵�����
{
	cout << "��ӭ" << this->m_Name << "��¼" << endl;
	cout << "1.����˺�"<<endl;
	cout << "2.�鿴�˺�"<<endl;
	cout << "3.�鿴����"<<endl;
	cout << "4.���ԤԼ"<<endl;
	cout << "0.ע����¼"<<endl;
}
void Manager::addPerson()//����˺�
{
	this->initVector();
	cout << "1.���ѧ��" << endl;
	cout << "2.��ӽ�ʦ" << endl;

	string fileName;
	string tip;
	string errortip;


	ofstream ofs;

	int select;
	cin >> select;
	if (select == 1)
	{
		fileName = STUDENT_FILE;
		tip = "������ѧ�ţ�";
		errortip = "ѧ���Ѵ���,���������룺";
	}
	else
	{
		fileName = TEACHER_FILE;
		tip = "������ְ�����:";
		errortip = "ְ�����Ѵ��ڣ����������룺";
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

	cout << "����������:" << endl;
	cin >> name;
	cout << "����������:" << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "��ӳɹ�" << endl;
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
void Manager::showPerson()//�鿴�˺�
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
void Manager::showComputer()//�鿴������Ϣ
{
	cout << "������Ϣ���£�" << endl;

	for (vector<Computeroom>::iterator it = vCom.begin(); it != vCom.end(); it++)
	{
		cout << "�������: " << it->m_Comid <<
			"������С��  " << it->m_num << endl;
	}
	system("pause");
	system("cls");
}
void Manager::cleanFile()//���ԤԼ��¼
{
	ofstream ofs(ORDER_FILE,ios::trunc);
	ofs.close();
	cout << "��ճɹ���" << endl;
	system("pause");
	system("cls");
}
void Manager::initVector()//��ʼ������
{
	ifstream ifs;
	vStu.clear();//���ѧ������
	vTea.clear();//��ս�ʦ����
	ifs.open(STUDENT_FILE,ios::in);///��ȡѧ���ļ�
	if (!ifs.is_open())
	{
		cout << "read file fail;" << endl;
		return;
	}
	Student s;
	while (ifs >> s.m_id &&ifs >> s.m_Name &&ifs >> s.m_Pwd)
	{
		vStu.push_back(s);//ѧ����Ϣ��ȡ��������
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
bool Manager::checkRepeat(int id, int type)//����ظ�
{
	if (type == 1)
	{
		//���ѧ��
		for (vector<Student>::iterator it = vStu.begin();it!=vStu.end();it++)
		{
			if (id == it->m_id)
			{
				return true;
			}
		}
	}
	if (type == 2)
	{//�����ʦ
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