#include "workerManager.h"
#include <fstream>
#include "worker.h"
#include <string>
#include "employee.h"
#include "manager.h"
#include "boss.h"

WorkerManager::WorkerManager()
{
	//1. �ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}



	//2. 


	//3. 

}

void WorkerManager::Show_Menu()
{
	cout << "*************************************************" << endl;
	cout << "************** ��ӭʹ��ְ������ϵͳ *************" << endl;
	cout << "**************** 0. �˳�������� ****************" << endl;
	cout << "**************** 1. ����ְ����Ϣ ****************" << endl;
	cout << "**************** 2. ��ʾְ����Ϣ ****************" << endl;
	cout << "**************** 3. ɾ����ְְ�� ****************" << endl;
	cout << "**************** 4. �޸�ְ����Ϣ ****************" << endl;
	cout << "**************** 5. ����ְ����Ϣ ****************" << endl;
	cout << "**************** 6. ���ձ������ ****************" << endl;
	cout << "**************** 7. ��������ĵ� ****************" << endl;
	cout << "*************************************************" << endl;
	cout << endl;
}

//�˳�����
void WorkerManager::ExitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

//���ְ��
void WorkerManager::Add_Emp()
{
	cout << "���������ְ��������" << endl;
	int addNum = 0; //�����û����������
	cin >> addNum;
	if (addNum > 0)
	{
		//�����¿ռ�
		int newSize = this->m_EmpNum + addNum; //�¿ռ�����=ԭ������+��������
		//�����¿ռ�
		Worker** newSpace = new Worker * [newSize];
		//��ԭ���ռ�����ݿ������¿ռ�
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		//�������������
		for (int i = 0; i < addNum; i++)
		{
			int id; //ְ�����
			string name; //ְ������
			int dSelect; //����ѡ��
			cout << "������� " << i + 1 << " ����Ա����ţ�" << endl;
			cin >> id;
			cout << "������� " << i + 1 << " ����Ա��������" << endl;
			cin >> name;
			cout << "��ѡ��Ա����λ��" << endl;
			cout << "1-Ա��" << endl;
			cout << "2-����" << endl;
			cout << "3-�ϰ�" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}
			//��ְ�����浽������
			newSpace[this->m_EmpNum + i] = worker;
		}
		//�ͷ�ԭ�пռ�
		delete[] this->m_EmpArray;
		//�����¿ռ��ָ��
		this->m_EmpArray = newSpace;
		//����ְ������
		this->m_EmpNum = newSize;
		//��ʾ��ӳɹ�
		cout << "�ɹ���� " << addNum << " ����Ա��" << endl;
		//�����ݱ��浽�ļ�
		this->save();
	}
	else
	{
		cout << "������������������" << endl;
	}
	system("pause");
	system("cls");
}

//�����ļ�
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out); //������ķ�ʽ���ļ���д�ļ���
	//������д���ļ�
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}
}

//��������
WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		delete[]this->m_EmpArray;
	}
}