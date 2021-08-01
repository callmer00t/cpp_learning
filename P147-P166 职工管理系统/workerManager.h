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
	//构造函数
	WorkerManager();
	//展示菜单
	void Show_Menu();

	//退出系统
	void ExitSystem();

	//记录员工人数
	int m_EmpNum;

	//员工数组指针
	Worker** m_EmpArray;

	//添加员工
	void Add_Emp();

	//保存文件
	void save();

	//判断文件是否为空
	bool m_FileIsEmpty;

	//统计人数
	int get_EmpNum();

	//初始化员工
	void init_Emp();

	//显示员工
	void Show_Emp();

	//判断员工是否存在，如果存在，返回员工在数组中的位置，不存在返回-1
	int IsExist(int id);

	//删除员工
	void Del_Emp();

	//修改员工
	void Mod_Emp();

	//查找员工
	void Find_Emp();

	//排序员工
	void Sort_Emp();

	//清空文件
	void Clean_File();

	//析构函数
	~WorkerManager();
};