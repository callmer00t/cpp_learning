#include <iostream>
#include <string>
using namespace std;

//�˵����溯��
void showMenu()
{
	cout << "*************************" << endl;
	cout << "***** 1. �����ϵ�� *****" << endl;
	cout << "***** 2. ��ʾ��ϵ�� *****" << endl;
	cout << "***** 3. ɾ����ϵ�� *****" << endl;
	cout << "***** 4. ������ϵ�� *****" << endl;
	cout << "***** 5. �޸���ϵ�� *****" << endl;
	cout << "***** 6. �����ϵ�� *****" << endl;
	cout << "***** 0. �˳�ͨѶ¼ *****" << endl;
	cout << "*************************" << endl;
}

//��ϵ�˽ṹ��
struct Person
{
	string m_Name; //����
	int m_Gender; //�Ա�1�� 2Ů
	int m_Age; //����
	string m_Phone; //�绰
	string m_Addr; //סַ
};

//ͨѶ¼�ṹ��
#define MAX 1000
struct Addressboooks
{
	struct Person personArray[MAX]; //��ϵ������
	int m_Size; //��ǰ��ϵ����Ŀ
};

//�����ϵ�˺���
void addPerson(Addressboooks* abs)
{
	//�ж�ͨѶ¼�Ƿ���������������������
	if (abs->m_Size == MAX)
	{
		cout << "ͨѶ¼�������޷����" << endl;
		return;
	}
	else
	{
		//�����ϵ��
		//����
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;
		//�Ա�
		int gender = 0;
		cout << "��ѡ���Ա�1-�У�2-Ů����" << endl;
		while (true) //����������1��2���˳�ѭ�����������������ѭ������������
		{
			cin >> gender;
			if ((gender == 1) | (gender == 2)) //�ж��Ա�ֵ�Ƿ�Ϸ�
			{
				abs->personArray[abs->m_Size].m_Gender = gender;
				break;
			}
			cout << "������������������" << endl;
		}
		//����
		int age;
		cout << "���������䣺" << endl;
		while (true)
		{
			cin >> age;
			if ((age >= 0) & (age <= 150))
			{
				abs->personArray[abs->m_Size].m_Age = age;
				break;
			}
			cout << "������������������" << endl;
		}
		//�绰
		string phone;
		cout << "������绰��" << endl;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;
		//סַ
		string addr;
		cout << "������סַ��" << endl;
		cin >> addr;
		abs->personArray[abs->m_Size].m_Addr = addr;
		//����ͨѶ¼����
		abs->m_Size++;
		cout << "��ӳɹ�" << endl;
		system("pause"); //�����������
		system("cls"); //����
	}
}

//��ʾ��ϵ�˺���
void showPerson(Addressboooks* abs)
{
	//�ж�ͨѶ¼�������Ƿ�Ϊ0�����Ϊ0����ʾ��¼Ϊ�գ������Ϊ0����ʾ��¼����ϵ����Ϣ
	if (abs->m_Size == 0)
	{
		cout << "��ǰͨѶ¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "������" << abs->personArray[i].m_Name << "\t|\t";
			cout << "�Ա�" << (abs->personArray[i].m_Gender == 1 ? "��" : "Ů") << "\t|\t";
			cout << "���䣺" << abs->personArray[i].m_Age << "\t|\t";
			cout << "�绰��" << abs->personArray[i].m_Phone << "\t|\t";
			cout << "סַ��" << abs->personArray[i].m_Addr << endl;
		}
	}
	system("pause"); //�����������
	system("cls"); //����
}

//�ж���ϵ���Ƿ���ں���
int isExist(Addressboooks* abs, string name) //����1 ͨѶ¼������2 �Ա�����
{
	//�ж���ϵ���Ƿ���ڣ�������ڣ�������ϵ����ͨѶ¼�е�λ�ã���������ڣ�����-1
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].m_Name == name) //�ҵ�����
		{
			return i;
		}
	}
	return -1;
}

//ɾ����ϵ�˺���
void delPerson(Addressboooks* abs)
{
	cout << "������Ҫɾ������ϵ��������" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		for (int i = ret; i < abs->m_Size; i++)
		{
			//����ǰ��
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--; //����ͨѶ¼�е���ϵ����Ŀ
		cout << "ɾ���ɹ�" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause"); //�����������
	system("cls"); //����
}

//������ϵ�˺���
void searchPerson(Addressboooks* abs)
{
	cout << "������Ҫ���ҵ���ϵ��������" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "������" << abs->personArray[ret].m_Name << "\t|\t";
		cout << "�Ա�" << (abs->personArray[ret].m_Gender == 1 ? "��" : "Ů") << "\t|\t";
		cout << "���䣺" << abs->personArray[ret].m_Age << "\t|\t";
		cout << "�绰��" << abs->personArray[ret].m_Phone << "\t|\t";
		cout << "סַ��" << abs->personArray[ret].m_Addr << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause"); //�����������
	system("cls"); //����
}

//�޸���ϵ�˺���
void modPerson(Addressboooks* abs)
{
	cout << "������Ҫ�޸ĵ���ϵ��������" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;
		//�Ա�
		int gender = 0;
		cout << "��ѡ���Ա�1-�У�2-Ů����" << endl;
		while (true) //����������1��2���˳�ѭ�����������������ѭ������������
		{
			cin >> gender;
			if ((gender == 1) | (gender == 2)) //�ж��Ա�ֵ�Ƿ�Ϸ�
			{
				abs->personArray[ret].m_Gender = gender;
				break;
			}
			cout << "������������������" << endl;
		}
		//����
		int age;
		cout << "���������䣺" << endl;
		while (true)
		{
			cin >> age;
			if ((age >= 0) & (age <= 150))
			{
				abs->personArray[ret].m_Age = age;
				break;
			}
			cout << "������������������" << endl;
		}
		//�绰
		string phone;
		cout << "������绰��" << endl;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;
		//סַ
		string addr;
		cout << "������סַ��" << endl;
		cin >> addr;
		abs->personArray[ret].m_Addr = addr;
		cout << "�޸ĳɹ�" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause"); //�����������
	system("cls"); //����
}

//�����ϵ�˺���
void clearPerson(Addressboooks* abs)
{
	cout << "ע�⣡�˲��������ȫ����ϵ����Ϣ��ȷ��Ҫ�����y-ȷ�ϣ�n-ȡ��" << endl;
	string confirm;
	while (true)
	{
		cin >> confirm;
		if (confirm == "y")
		{
			abs->m_Size = 0;
			cout << "ͨѶ¼�����" << endl;
			break;
		}
		else if (confirm == "n")
		{
			cout << "������ȡ��" << endl;
			break;
		}
		cout << "������������������" << endl;
	}
	system("pause"); //�����������
	system("cls"); //����
}

int main()
{
	//����ͨѶ¼�ṹ�����
	Addressboooks abs;
	abs.m_Size = 0;

	//�����û�ѡ������ı���
	int select = 0;

	while (true)
	{
		//�˵�����
		showMenu();
		cout << "���������ѡ���ܣ�";
		cin >> select;

		switch (select)
		{
		case 1: //1. �����ϵ��
			addPerson(&abs); //��ַ���ݣ��޸�ʵ��
			break;
		case 2: //2. ��ʾ��ϵ��
			showPerson(&abs);
			break;
		case 3: //3. ɾ����ϵ��
		{
			delPerson(&abs);
			break;
		}
		case 4: //4. ������ϵ��
			searchPerson(&abs);
			break;
		case 5: //5. �޸���ϵ��
			modPerson(&abs);
			break;
		case 6: //6. �����ϵ��
			clearPerson(&abs);
			break;
		case 0: //0. �˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}