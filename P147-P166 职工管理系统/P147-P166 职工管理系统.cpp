#include<iostream>
#include"workerManager.h"
//#include"worker.h"
//#include"employee.h"
//#include"manager.h"
//#include"boss.h"
using namespace std;

int main()
{
	//测试
	//Worker* worker = NULL;
	//worker = new Employee(1, "张三", 1);
	//worker->showInfo();
	//delete worker;

	//worker = new Manager(2, "李四", 2);
	//worker->showInfo();
	//delete worker;

	//worker = new Boss(3, "王五", 3);
	//worker->showInfo();
	//delete worker;

	//实例化管理者对象
	WorkerManager wm;
	int choice = 0;
	while (true)
	{
		//展示菜单
		wm.Show_Menu();
		cout << "请输入您的选择：" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0: //退出系统
			wm.ExitSystem();
			break;
		case 1: //添加员工
			wm.Add_Emp();
			break;
		case 2: //显示员工
			wm.Show_Emp();
			break;
		case 3: //删除员工
			wm.Del_Emp();
			break;
		case 4: //修改员工
			wm.Mod_Emp();
			break;
		case 5: //查找员工
			wm.Find_Emp();
			break;
		case 6: //排序员工
			wm.Sort_Emp();
			break;
		case 7: //清空文件
			wm.Clean_File();
			break;
		default:
			system("cls");
			break;
		}
	}



	system("pause");
	return 0;
}