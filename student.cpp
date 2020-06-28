#include"student.h"
#include<iostream>
#include<fstream>
#include"computeroom.h"
#include"globalFile.h"
#include"orderFile.h"
using namespace std;
Student::Student()//Ĭ�Ϲ���
{

}
Student::Student(int id, string name, string pwd)//�вι���
{
	this->m_id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;

	//��ʼ��������Ϣ
	ifstream ifs;
	ifs.open(COMPUTER_FILE,ios::in);

	Computeroom com;
	while (ifs >> com.m_Comid &&ifs >> com.m_num)
	{
		vCom.push_back(com);
	}
	ifs.close();


}
void Student:: ApplyOder()//����ԤԼ
{
	cout << "��������ʱ��Ϊ��һ�����壡" << endl;
	cout << "����������ԤԼʱ�䣺" << endl;
	cout << "1.��һ" << endl;
	cout << "2.�ܶ�" << endl;
	cout << "3.����" << endl;
	cout << "4.����" << endl;
	cout << "5.����" << endl;

	int date = 0;
	int interval;
	int room;
	
	while (true)
	{
		cin >> date;
		if (date >= 1 && date <= 5)
		{
			break;
		}
		cout << "��������������룺" << endl;
	}
	
	cout << "1.����" << endl;
	cout << "2.����" << endl;
	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		cout << "��������������룺" << endl;
	}
	cout << "ѡ�Ż�����" << endl;
	for (int i = 0; i < vCom.size(); i++)
	{
		cout << vCom[i].m_Comid << "�Ż�������Ϊ��" << vCom[i].m_num << endl;
	}
	while (true)
	{
		cin >> room;
		if (room >= 1 && room<= 3)
		{
			break;
		}
		cout << "��������������룺" << endl;
	}
	cout << "ԤԼ�ɹ�������С�" << endl;
	ofstream ofs;
	ofs.open(ORDER_FILE,ios::app);
	
	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "id:" << this->m_id << " ";
	ofs << "name:" << this->m_Name << " ";
	ofs << "roomid:" << room << " ";
	ofs << "status:" << 1 << endl;
	ofs.close();
}
void Student:: ShowMyOder()//�鿴�ҵ�ԤԼ
{
	OrderFile of;
	if (of.m_size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		return;
	}
	for (int i = 0; i < of.m_size; i++)
	{
		//string ���� .c_str() תconst char *
		//���� atoi(const char *)ת Int
		if (this->m_id == atoi(of.m_orderdata[i]["stuid"].c_str()));
		{

			cout << i << " ";
			cout << "ԤԼ���ڣ���" << of.m_orderdata[i]["date"];
			cout << " ʱ��Σ�" << (of.m_orderdata[i]["interval"] == "1" ? "����" : "����");
			cout << " �����ţ�" << of.m_orderdata[i]["roomid"] ;
			string status = "״̬:";
			//1 ����� 2��ԤԼ -1ԤԼʧ�� 0ȡ��ԤԼ
			if (of.m_orderdata[i]["status"] == "1")
			{
				status += "�����";
			}
			else if (of.m_orderdata[i]["status"] == "2")
			{
				status += "ԤԼ�ɹ�";
			}
			else if (of.m_orderdata[i]["status"] == "-1")
			{
				status += "ԤԼʧ��";
			}
			else
			{
				status += "ԤԼ��ȡ��";
			}
			cout << status << endl;
		}
	}
	
}
void Student::ShowAllOder()//�鿴����ԤԼ
{
	OrderFile of;
	if (of.m_size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		return;
	}
	for (int i = 0; i < of.m_size; i++)
	{
		cout<<"��" << of.m_orderdata[i]["date"];
		cout << "  ʱ���:  " << (of.m_orderdata[i]["interval"] == "1" ? "����" : "����");
		cout << "   ѧ�ţ�" << of.m_orderdata[i]["id"];
		cout << "  ������ " << of.m_orderdata[i]["name"];
		cout << "  �����ţ�" << of.m_orderdata[i]["roomid"];
		string status = "״̬:";
		//1 ����� 2��ԤԼ -1ԤԼʧ�� 0ȡ��ԤԼ
		if (of.m_orderdata[i]["status"] == "1")
		{
			status += "�����";
		}
		else if (of.m_orderdata[i]["status"] == "2")
		{
			status += "ԤԼ�ɹ�";
		}
		else if (of.m_orderdata[i]["status"] == "-1")
		{
			status += "ԤԼʧ��";
		}
		else
		{
			status += "ԤԼ��ȡ��";
		}
		cout << status << endl;
	}
	system("pause");
	system("cls");
}
void Student::CancelOder()//ȡ��ԤԼ
{
	ShowMyOder();
	cout << "��������Ҫȡ��ԤԼ�ı�ţ�";
	int select;
	cin >> select;
	OrderFile of;
	for (int i = 0; i < of.m_size; i++)
	{
		//string ���� .c_str() תconst char *
		//���� atoi(const char *)ת Int
		if (this->m_id == atoi(of.m_orderdata[i]["stuid"].c_str()));
		{
			
			if (select == men)
			{
				of.m_orderdata[i]["status"] = "0";
			}
			men++;
		}
	}
	of.updateOrder();
}
void Student:: operMenu()//�˵�����
{

	cout << "1.����ԤԼ" << endl;
	cout << "2.�鿴�ҵ�ԤԼ" << endl;
	cout << "3.�鿴����ԤԼ" << endl;
	cout << "4.ȡ��ԤԼ" << endl;
	cout << "5.ע����¼" << endl;

}