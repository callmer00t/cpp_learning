#include "workerManager.h"
#include <fstream>
#include "worker.h"
#include <string>
#include "employee.h"
#include "manager.h"
#include "boss.h"

WorkerManager::WorkerManager()
{
	//1. 文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
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
	cout << "************** 欢迎使用职工管理系统 *************" << endl;
	cout << "**************** 0. 退出管理程序 ****************" << endl;
	cout << "**************** 1. 增加职工信息 ****************" << endl;
	cout << "**************** 2. 显示职工信息 ****************" << endl;
	cout << "**************** 3. 删除离职职工 ****************" << endl;
	cout << "**************** 4. 修改职工信息 ****************" << endl;
	cout << "**************** 5. 查找职工信息 ****************" << endl;
	cout << "**************** 6. 按照编号排序 ****************" << endl;
	cout << "**************** 7. 清空所有文档 ****************" << endl;
	cout << "*************************************************" << endl;
	cout << endl;
}

//退出功能
void WorkerManager::ExitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

//添加职工
void WorkerManager::Add_Emp()
{
	cout << "请输入添加职工数量：" << endl;
	int addNum = 0; //保存用户输入的数量
	cin >> addNum;
	if (addNum > 0)
	{
		//计算新空间
		int newSize = this->m_EmpNum + addNum; //新空间人数=原来人数+新增人数
		//开辟新空间
		Worker** newSpace = new Worker * [newSize];
		//将原来空间的数据拷贝到新空间
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		//批量添加新数据
		for (int i = 0; i < addNum; i++)
		{
			int id; //职工编号
			string name; //职工姓名
			int dSelect; //部门选择
			cout << "请输入第 " << i + 1 << " 个新员工编号：" << endl;
			cin >> id;
			cout << "请输入第 " << i + 1 << " 个新员工姓名：" << endl;
			cin >> name;
			cout << "请选择员工岗位：" << endl;
			cout << "1-员工" << endl;
			cout << "2-经理" << endl;
			cout << "3-老板" << endl;
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
			//将职工保存到数组中
			newSpace[this->m_EmpNum + i] = worker;
		}
		//释放原有空间
		delete[] this->m_EmpArray;
		//更改新空间的指向
		this->m_EmpArray = newSpace;
		//更新职工人数
		this->m_EmpNum = newSize;
		//提示添加成功
		cout << "成功添加 " << addNum << " 名新员工" << endl;
		//将数据保存到文件
		this->save();
	}
	else
	{
		cout << "输入有误，请重新输入" << endl;
	}
	system("pause");
	system("cls");
}

//保存文件
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out); //用输出的方式打开文件（写文件）
	//将输入写入文件
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}
}

//析构函数
WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		delete[]this->m_EmpArray;
	}
}