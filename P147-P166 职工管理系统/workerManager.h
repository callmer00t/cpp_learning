#pragma once
#include<iostream>
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
#include<fstream>
#define FILENAME "empFile.txt"

class WorkerManager
{
public:
	//���캯��
	WorkerManager();
	//չʾ�˵�
	void Show_Menu();

	//�˳�ϵͳ
	void ExitSystem();

	//��¼Ա������
	int m_EmpNum;

	//Ա������ָ��
	Worker** m_EmpArray;

	//���Ա��
	void Add_Emp();

	//�����ļ�
	void save();

	//�ж��ļ��Ƿ�Ϊ��
	bool m_FileIsEmpty;

	//ͳ������
	int get_EmpNum();

	//��ʼ��Ա��
	void init_Emp();

	//��ʾԱ��
	void Show_Emp();

	//�ж�Ա���Ƿ���ڣ�������ڣ�����Ա���������е�λ�ã������ڷ���-1
	int IsExist(int id);

	//ɾ��Ա��
	void Del_Emp();

	//�޸�Ա��
	void Mod_Emp();

	//����Ա��
	void Find_Emp();

	//����Ա��
	void Sort_Emp();

	//����ļ�
	void Clean_File();

	//��������
	~WorkerManager();
};