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
		//cout << "�ļ�������" << endl; //���Դ���
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//2. �ļ����ڣ�����Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "�ļ�Ϊ��" << endl; //���Դ���
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//3. �ļ����ڣ����ݴ��ڣ�ͳ������
	int num = this->get_EmpNum();
	//cout << "Ա������Ϊ��" << num << endl; //���Դ���
	this->m_EmpNum = num;

	this->m_EmpArray = new Worker * [this->m_EmpNum]; //���ٿռ�
	this->init_Emp(); //���ļ��е����ݴ�������

	////���Դ���
	//for (int i = 0; i < this->m_EmpNum; i++)
	//{
	//	cout << "Ա����ţ�" << this->m_EmpArray[i]->m_Id
	//		<< "\t������" << this->m_EmpArray[i]->m_Name
	//		<< "\t���ţ�" << this->m_EmpArray[i]->m_DeptId
	//		<< endl;
	//}
}

//ͳ����������ʵ��
int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in); //���ļ�
	int num = 0;
	int id;
	string name;
	int dId;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		num++;
	}
	return num;
}

void WorkerManager::Show_Menu()
{
	cout << "*************************************************" << endl;
	cout << "************** ��ӭʹ��Ա������ϵͳ *************" << endl;
	cout << "**************** 0. �˳�������� ****************" << endl;
	cout << "**************** 1. ����Ա����Ϣ ****************" << endl;
	cout << "**************** 2. ��ʾԱ����Ϣ ****************" << endl;
	cout << "**************** 3. ɾ����ְԱ�� ****************" << endl;
	cout << "**************** 4. �޸�Ա����Ϣ ****************" << endl;
	cout << "**************** 5. ����Ա����Ϣ ****************" << endl;
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

//���Ա��
void WorkerManager::Add_Emp()
{
	cout << "���������Ա��������" << endl;
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
			int id; //Ա�����
			string name; //Ա������
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
			//��Ա�����浽������
			newSpace[this->m_EmpNum + i] = worker;
		}
		//�ͷ�ԭ�пռ�
		delete[] this->m_EmpArray;
		//�����¿ռ��ָ��
		this->m_EmpArray = newSpace;
		//����Ա������
		this->m_EmpNum = newSize;
		//�����ļ��Ƿ�Ϊ�յı�־
		this->m_FileIsEmpty = false;
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

//��ʼ��Ա��
void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int dId;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;
		if (dId == 1) //��ͨԱ��
		{
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2) //����
		{
			worker = new Manager(id, name, dId);
		}
		else //�ϰ�
		{
			worker = new Boss(id, name, dId);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close(); //�ر��ļ�
}

//��ʾԱ��
void WorkerManager::Show_Emp()
{
	//�ж��ļ��Ƿ���ڣ������Ƿ�Ϊ��
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			//���ö�̬���ó���ӿ�
			this->m_EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}

//�ж�Ա���Ƿ���ڣ�������ڣ�����Ա���������е�λ�ã������ڷ���-1
int WorkerManager::IsExist(int id)
{
	int index = -1; //Ĭ��Ա��������
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		{
			index = i;
			break;
		}
	}
	return index;
}

//ɾ��Ա��
void WorkerManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		//�����ɾ��Ա��
		cout << "������Ҫɾ����Ա�����" << endl;
		int id = 0;
		cin >> id;
		int index = this->IsExist(id);
		if (index != -1) //index������-1��˵��Ա�����ڣ���Ҫɾ����λ�õ�Ա��
		{
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1]; //����ǰ��
			}
			this->m_EmpNum--; //���������е���Ա����
			this->save(); //���µ��ļ�
			cout << "ɾ���ɹ�" << endl; //��ʾ�û�
		}
		else
		{
			cout << "δ�ҵ�Ա����ɾ��ʧ��" << endl;
		}
	}
	system("pause");
	system("cls");
}

//�޸�Ա��
void WorkerManager::Mod_Emp()
{
	if (this->m_FileIsEmpty) //�ж��ļ��Ƿ����
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		cout << "������Ҫ�޸ĵ�Ա����ţ�" << endl;
		int id;
		cin >> id;
		int ret = this->IsExist(id); //�ж�Ա���Ƿ����
		if (ret != -1) //Ա��ID����
		{
			delete this->m_EmpArray[ret]; //��ԭԱ����Ϣɾ��
			int newId = 0;
			string newName = "";
			int newdId = 0;
			cout << "�ҵ���" << id << "��Ա������������Ա����ţ�" << endl;
			cin >> newId;
			cout << "��������Ա��������" << endl;
			cin >> newName;
			cout << "��ѡ����Ա����λ��" << endl;
			cout << "1-Ա��" << endl;
			cout << "2-����" << endl;
			cout << "3-�ϰ�" << endl;
			cin >> newdId;
			Worker* worker = NULL; //���½���Ա������
			switch (newdId) //���ݲ�ͬ��λ��������ͬ���������
			{
			case 1:
				worker = new Employee(newId, newName, newdId);
				break;
			case 2:
				worker = new Manager(newId, newName, newdId);
				break;
			case 3:
				worker = new Boss(newId, newName, newdId);
				break;
			default:
				break;
			}
			this->m_EmpArray[ret] = worker; //���޸ĺ�����ݱ��浽������
			cout << "�޸ĳɹ�" << this->m_EmpArray[ret]->m_DeptId << endl; //��ʾ�û�
			this->save(); //���浽�ļ�
		}
		else //Ա��ID������
		{
			cout << "�޸�ʧ�ܣ�δ�ҵ�Ա��" << endl;
		}
	}
	system("pause");
	system("cls");
}

//����Ա��
void WorkerManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		cout << "��ѡ����ҷ�ʽ��" << endl;
		cout << "1-��Ա����Ų���" << endl;
		cout << "2-��Ա����������" << endl;
		int select = 0;
		cin >> select;
		if (select == 1) //��Ա����Ų���
		{
			int id;
			cout << "������Ҫ���ҵ�Ա����ţ�" << endl;
			cin >> id;
			int ret = IsExist(id);
			if (ret != -1)
			{
				cout << "���ҳɹ���Ա����Ϣ���£�" << endl;
				this->m_EmpArray[ret]->showInfo(); //����showInfo()������ʾԱ����Ϣ
			}
			else
			{
				cout << "����ʧ�ܣ�δ�ҵ���Ա�����" << endl;
			}
		}
		else if (select == 2) //��Ա����������
		{
			string name;
			cout << "������Ҫ���ҵ�Ա��������" << endl;
			cin >> name;
			bool flag = false; //���ҵ��ı�־
			for (int i = 0; i < m_EmpNum; i++)
			{
				if (m_EmpArray[i]->m_Name == name)
				{
					cout << "���ҳɹ���Ա�����Ϊ�� "
						<< m_EmpArray[i]->m_Id
						<< " �ŵ���Ϣ����" << endl;
					flag = true;
					this->m_EmpArray[i]->showInfo();
				}
			}
			if (flag == false)
			{
				cout << "����ʧ�ܣ�δ�ҵ���Ա��" << endl;
			}
		}
		else
		{
			cout << "������������������" << endl;
		}
	}
	system("pause");
	system("cls");
}

//����Ա��
void WorkerManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ������ʽ��" << endl;
		cout << "1-��Ա�������������" << endl;
		cout << "2-��Ա����Ž�������" << endl;
		int select = 0;
		cin >> select;
		for(int i = 0; i < m_EmpNum; i++)
		{
			int minOrMax = i;
			for (int j = i + 1; i < this->m_EmpNum; j++)
			{
				if (select == 1) //����
				{
					if (this->m_EmpArray[minOrMax]->m_Id > this->m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
				else //����
				{
					if (this->m_EmpArray[minOrMax]->m_Id < this->m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
			}
			if (i != minOrMax)
			{
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
				this->m_EmpArray[minOrMax] = temp;
			}
		}
		cout << "����ɹ����������Ϊ��" << endl;
		this->save();
		this->Show_Emp();
	}
}

//����ļ�
void WorkerManager::Clean_File()
{
	cout << "ȷ������ļ���" << endl;
	cout << "1-ȷ��" << endl;
	cout << "2-ȡ��" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		ofstream ofs(FILENAME, ios::trunc); //ios::trunc ����ļ����ڣ���ɾ���ļ������´���
		ofs.close();
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i] != NULL)
				{
					delete this->m_EmpArray[i];
				}
			}
			this->m_EmpNum = 0;
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_FileIsEmpty = true;
		}
		cout << "��ճɹ�" << endl;
	}
	system("pause");
	system("cls");
}

//��������
WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArray != NULL)
			{
				delete this->m_EmpArray[i];
			}
		}
		delete[]this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}