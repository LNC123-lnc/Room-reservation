#include<iostream>
using namespace std;
#include"identity.h"
#include<string>
#include<fstream>
#include"globalFile.h"
#include"student.h"
#include"teacher.h"
#include"manager.h"

//����ѧ���Ӳ˵�����
void studentMenu(Identity * &student)
{
	
	while (true)
	{
		student->operMenu();

		Student *stu = (Student*)student;

		int select = 0;
		cin >> select;
		if (select == 1)
		{
			stu->ApplyOder();
		}
		else if (select == 2)
		{
			stu->ShowMyOder();
		}
		else if (select == 3)
		{
			stu->ShowAllOder();
		}
		else if (select == 4)
		{
			stu->CancelOder();
		}
		else
		{
			delete student;
			cout << "ע���ɹ�0" << endl;
			return;
		}
	}
}
void teacherMenu(Identity * &teacher)
{
	while (true)
	{
		//�����Ӳ˵�����
		teacher->operMenu();

		Teacher * tea = (Teacher*)teacher;

		int select = 0; //�����û�ѡ��

		cin >> select;

		if (select == 1) //�鿴����ԤԼ
		{
			tea->showAllOrder();
		}
		else if (select == 2) //���ԤԼ
		{
			tea->validOrder();
		}
		else
		{
			delete teacher;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}
//�������Ա�Ӳ˵�����
void managerMenu(Identity *&manager)
{
	while (true)
	{
		//���ù���Ա�Ӳ˵�
		manager->operMenu();
		//������ָ��תΪ����ָ�룬�������������ӿ�
		Manager *man = (Manager*)manager;

		int select = 0;
		cin >> select;
		if (select == 1)
		{
			cout << "����˺�" << endl;
			man->addPerson();

		}
		else if (select == 2)
		{
			cout << "�鿴�˺�" << endl;
			man->showPerson();
		}
		else if (select == 3)
		{
			cout << "�鿴����" << endl;
			man->showComputer();
		}
		else if (select == 4)
		{
			cout << "ȡ��ԤԼ" << endl;
			man->cleanFile();
		}
		else
		{
			delete manager;
			cout << "ע���ɹ�" << endl;
			return;

		}
	}
}
void LoginIn(string filename, int type) //��¼���� �����ļ���   ��������
{
	Identity * person = NULL;//����ָ�룬����ָ���������
	//���ļ�
	ifstream ifs;
	ifs.open(filename,ios::in);
	//�ж��ļ��Ƿ����
	if (!ifs.is_open())
	{
		cout << "wenjianbucunzai." << endl;
		ifs.close();
		return;
	}
	//�����û���Ϣ
	int id = 0;
	string name;
	string pwd;
	
	//�ж����
	if (type == 1)
	{
		cout << "������ѧ�ţ�" << endl;
		cin >>id;
	}
	else if (type == 2)
	{
		cout << "������ְ���ţ�" << endl;
		cin >> id;
	}
	cout << "�������û�����" << endl;
	cin >> name;
	cout << "���������룺" << endl;
	cin >> pwd;

	if (type == 1)
	{
		//ѧ����¼��֤
		int fid;
		string fname;
		string fpwd;
		while(ifs>>fid && ifs>>fname && ifs>>fpwd)
		{
			if (fid = id && fname == name && fpwd == pwd)
			{
				cout << "��¼�ɹ���" << endl;
				system("cls");
				person = new Student(id,name,pwd);
				//����ѧ���Ӳ˵�
				studentMenu(person);
				return;
			}
		}
	}
	else if (type == 2)
	{
		//��ʦ��¼��֤
		int fid;
		string fname;
		string fpwd;
		while (ifs >> fid && ifs >> fname && ifs >> fpwd)
		{
			if (fid = id && fname == name && fpwd == pwd)
			{
				cout << "��¼�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				//������ʦ�Ӳ˵�
				teacherMenu(person);
				return;
			}
		}
	}
	else
	{
		//����Ա��¼��֤
		string fname;
		string fpwd;
		while (ifs >> fname && ifs >> fpwd)
		{
			if (fname == name && fpwd == pwd)
			{
				cout << "��¼�ɹ���" << endl;
				system("cls");
				person = new Manager(name,pwd);
				//�������Ա�Ӳ˵�
				managerMenu(person);
				return;
			}
		}
	}
	cout << "��֤ʧ�ܡ�" << endl;
	system("pause");
	system("cls");

}
int main()
{
	int select = 0;
	while(true)
	{
		cout << "\t\t|-------------------------|\n";
		cout << "\t\t|       1.ѧ������        |\n";
		cout << "\t\t|       2.��    ʦ        |\n";
		cout << "\t\t|       3.�� �� Ա		   |\n";
		cout << "\t\t|       4.��    ��		   |\n";
		cout << "\t\t|-------------------------|\n";
		cout << "�������ѡ��:";
		cin >> select;//�����û�ѡ��
		
			switch (select)
			{
			case 1://ѧ��
				LoginIn(STUDENT_FILE, 1);
				break;
			case 2://��ʦ
				LoginIn(TEACHER_FILE, 2);
				break;
			case 3://����Ա
				LoginIn(ADMIN_FILE, 3);
				break;
			case 4://�˳�
				cout << "��ӭ�´�ʹ��" << endl;
				system("pause");
				return 0;
				break;
			default:
				cout << "��������,���������룺";

				break;
			}
		
	}
	system("pause");
	return 0;
}