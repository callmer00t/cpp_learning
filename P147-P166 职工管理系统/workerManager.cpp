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
		//cout << "文件不存在" << endl; //测试代码
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//2. 文件存在，数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "文件为空" << endl; //测试代码
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//3. 文件存在，数据存在，统计人数
	int num = this->get_EmpNum();
	//cout << "员工人数为：" << num << endl; //测试代码
	this->m_EmpNum = num;

	this->m_EmpArray = new Worker * [this->m_EmpNum]; //开辟空间
	this->init_Emp(); //将文件中的数据存入数组

	////测试代码
	//for (int i = 0; i < this->m_EmpNum; i++)
	//{
	//	cout << "员工编号：" << this->m_EmpArray[i]->m_Id
	//		<< "\t姓名：" << this->m_EmpArray[i]->m_Name
	//		<< "\t部门：" << this->m_EmpArray[i]->m_DeptId
	//		<< endl;
	//}
}

//统计人数函数实现
int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in); //打开文件
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
	cout << "************** 欢迎使用员工管理系统 *************" << endl;
	cout << "**************** 0. 退出管理程序 ****************" << endl;
	cout << "**************** 1. 增加员工信息 ****************" << endl;
	cout << "**************** 2. 显示员工信息 ****************" << endl;
	cout << "**************** 3. 删除离职员工 ****************" << endl;
	cout << "**************** 4. 修改员工信息 ****************" << endl;
	cout << "**************** 5. 查找员工信息 ****************" << endl;
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

//添加员工
void WorkerManager::Add_Emp()
{
	cout << "请输入添加员工数量：" << endl;
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
			int id; //员工编号
			string name; //员工姓名
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
			//将员工保存到数组中
			newSpace[this->m_EmpNum + i] = worker;
		}
		//释放原有空间
		delete[] this->m_EmpArray;
		//更改新空间的指向
		this->m_EmpArray = newSpace;
		//更新员工人数
		this->m_EmpNum = newSize;
		//更新文件是否为空的标志
		this->m_FileIsEmpty = false;
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

//初始化员工
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
		if (dId == 1) //普通员工
		{
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2) //经理
		{
			worker = new Manager(id, name, dId);
		}
		else //老板
		{
			worker = new Boss(id, name, dId);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close(); //关闭文件
}

//显示员工
void WorkerManager::Show_Emp()
{
	//判断文件是否存在，数据是否为空
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			//利用多态调用程序接口
			this->m_EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}

//判断员工是否存在，如果存在，返回员工在数组中的位置，不存在返回-1
int WorkerManager::IsExist(int id)
{
	int index = -1; //默认员工不存在
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

//删除员工
void WorkerManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		//按编号删除员工
		cout << "请输入要删除的员工编号" << endl;
		int id = 0;
		cin >> id;
		int index = this->IsExist(id);
		if (index != -1) //index不等于-1，说明员工存在，需要删掉此位置的员工
		{
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1]; //数据前移
			}
			this->m_EmpNum--; //更新数组中的人员个数
			this->save(); //更新到文件
			cout << "删除成功" << endl; //提示用户
		}
		else
		{
			cout << "未找到员工，删除失败" << endl;
		}
	}
	system("pause");
	system("cls");
}

//修改员工
void WorkerManager::Mod_Emp()
{
	if (this->m_FileIsEmpty) //判断文件是否存在
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		cout << "请输入要修改的员工编号：" << endl;
		int id;
		cin >> id;
		int ret = this->IsExist(id); //判断员工是否存在
		if (ret != -1) //员工ID存在
		{
			delete this->m_EmpArray[ret]; //将原员工信息删除
			int newId = 0;
			string newName = "";
			int newdId = 0;
			cout << "找到：" << id << "号员工，请输入新员工编号：" << endl;
			cin >> newId;
			cout << "请输入新员工姓名：" << endl;
			cin >> newName;
			cout << "请选择新员工岗位：" << endl;
			cout << "1-员工" << endl;
			cout << "2-经理" << endl;
			cout << "3-老板" << endl;
			cin >> newdId;
			Worker* worker = NULL; //重新建立员工对象
			switch (newdId) //根据不同岗位，建立不同的子类对象
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
			this->m_EmpArray[ret] = worker; //将修改后的数据保存到数组中
			cout << "修改成功" << this->m_EmpArray[ret]->m_DeptId << endl; //提示用户
			this->save(); //保存到文件
		}
		else //员工ID不存在
		{
			cout << "修改失败，未找到员工" << endl;
		}
	}
	system("pause");
	system("cls");
}

//查找员工
void WorkerManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		cout << "请选择查找方式：" << endl;
		cout << "1-按员工编号查找" << endl;
		cout << "2-按员工姓名查找" << endl;
		int select = 0;
		cin >> select;
		if (select == 1) //按员工编号查找
		{
			int id;
			cout << "请输入要查找的员工编号：" << endl;
			cin >> id;
			int ret = IsExist(id);
			if (ret != -1)
			{
				cout << "查找成功，员工信息如下：" << endl;
				this->m_EmpArray[ret]->showInfo(); //调用showInfo()函数显示员工信息
			}
			else
			{
				cout << "查找失败，未找到此员工编号" << endl;
			}
		}
		else if (select == 2) //按员工姓名查找
		{
			string name;
			cout << "请输入要查找的员工姓名：" << endl;
			cin >> name;
			bool flag = false; //查找到的标志
			for (int i = 0; i < m_EmpNum; i++)
			{
				if (m_EmpArray[i]->m_Name == name)
				{
					cout << "查找成功，员工编号为： "
						<< m_EmpArray[i]->m_Id
						<< " 号的信息如下" << endl;
					flag = true;
					this->m_EmpArray[i]->showInfo();
				}
			}
			if (flag == false)
			{
				cout << "查找失败，未找到此员工" << endl;
			}
		}
		else
		{
			cout << "输入有误，请重新输入" << endl;
		}
	}
	system("pause");
	system("cls");
}

//排序员工
void WorkerManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择排序方式：" << endl;
		cout << "1-按员工编号升序排序" << endl;
		cout << "2-按员工编号降序排序" << endl;
		int select = 0;
		cin >> select;
		for(int i = 0; i < m_EmpNum; i++)
		{
			int minOrMax = i;
			for (int j = i + 1; i < this->m_EmpNum; j++)
			{
				if (select == 1) //升序
				{
					if (this->m_EmpArray[minOrMax]->m_Id > this->m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
				else //降序
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
		cout << "排序成功，排序后结果为：" << endl;
		this->save();
		this->Show_Emp();
	}
}

//清空文件
void WorkerManager::Clean_File()
{
	cout << "确认清空文件？" << endl;
	cout << "1-确认" << endl;
	cout << "2-取消" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		ofstream ofs(FILENAME, ios::trunc); //ios::trunc 如果文件存在，则删除文件并重新创建
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
		cout << "清空成功" << endl;
	}
	system("pause");
	system("cls");
}

//析构函数
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