#include <iostream>
#include <string>
using namespace std;

//菜单界面函数
void showMenu()
{
	cout << "*************************" << endl;
	cout << "***** 1. 添加联系人 *****" << endl;
	cout << "***** 2. 显示联系人 *****" << endl;
	cout << "***** 3. 删除联系人 *****" << endl;
	cout << "***** 4. 查找联系人 *****" << endl;
	cout << "***** 5. 修改联系人 *****" << endl;
	cout << "***** 6. 清空联系人 *****" << endl;
	cout << "***** 0. 退出通讯录 *****" << endl;
	cout << "*************************" << endl;
}

//联系人结构体
struct Person
{
	string m_Name; //姓名
	int m_Gender; //性别：1男 2女
	int m_Age; //年龄
	string m_Phone; //电话
	string m_Addr; //住址
};

//通讯录结构体
#define MAX 1000
struct Addressboooks
{
	struct Person personArray[MAX]; //联系人数组
	int m_Size; //当前联系人数目
};

//添加联系人函数
void addPerson(Addressboooks* abs)
{
	//判断通讯录是否已满，如果满，则不再添加
	if (abs->m_Size == MAX)
	{
		cout << "通讯录已满，无法添加" << endl;
		return;
	}
	else
	{
		//添加联系人
		//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;
		//性别
		int gender = 0;
		cout << "请选择性别（1-男，2-女）：" << endl;
		while (true) //如果输入的是1或2，退出循环；如果输入其他，循环，重新输入
		{
			cin >> gender;
			if ((gender == 1) | (gender == 2)) //判断性别值是否合法
			{
				abs->personArray[abs->m_Size].m_Gender = gender;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}
		//年龄
		int age;
		cout << "请输入年龄：" << endl;
		while (true)
		{
			cin >> age;
			if ((age >= 0) & (age <= 150))
			{
				abs->personArray[abs->m_Size].m_Age = age;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}
		//电话
		string phone;
		cout << "请输入电话：" << endl;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;
		//住址
		string addr;
		cout << "请输入住址：" << endl;
		cin >> addr;
		abs->personArray[abs->m_Size].m_Addr = addr;
		//更新通讯录人数
		abs->m_Size++;
		cout << "添加成功" << endl;
		system("pause"); //按任意键继续
		system("cls"); //清屏
	}
}

//显示联系人函数
void showPerson(Addressboooks* abs)
{
	//判断通讯录中人数是否为0，如果为0，提示记录为空；如果不为0，显示记录的联系人信息
	if (abs->m_Size == 0)
	{
		cout << "当前通讯录为空" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "姓名：" << abs->personArray[i].m_Name << "\t|\t";
			cout << "性别：" << (abs->personArray[i].m_Gender == 1 ? "男" : "女") << "\t|\t";
			cout << "年龄：" << abs->personArray[i].m_Age << "\t|\t";
			cout << "电话：" << abs->personArray[i].m_Phone << "\t|\t";
			cout << "住址：" << abs->personArray[i].m_Addr << endl;
		}
	}
	system("pause"); //按任意键继续
	system("cls"); //清屏
}

//判断联系人是否存在函数
int isExist(Addressboooks* abs, string name) //参数1 通讯录，参数2 对比姓名
{
	//判断联系人是否存在，如果存在，返回联系人在通讯录中的位置，如果不存在，返回-1
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].m_Name == name) //找到姓名
		{
			return i;
		}
	}
	return -1;
}

//删除联系人函数
void delPerson(Addressboooks* abs)
{
	cout << "请输入要删除的联系人姓名：" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		for (int i = ret; i < abs->m_Size; i++)
		{
			//数据前移
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--; //更新通讯录中的联系人数目
		cout << "删除成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause"); //按任意键继续
	system("cls"); //清屏
}

//查找联系人函数
void searchPerson(Addressboooks* abs)
{
	cout << "请输入要查找的联系人姓名：" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "姓名：" << abs->personArray[ret].m_Name << "\t|\t";
		cout << "性别：" << (abs->personArray[ret].m_Gender == 1 ? "男" : "女") << "\t|\t";
		cout << "年龄：" << abs->personArray[ret].m_Age << "\t|\t";
		cout << "电话：" << abs->personArray[ret].m_Phone << "\t|\t";
		cout << "住址：" << abs->personArray[ret].m_Addr << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause"); //按任意键继续
	system("cls"); //清屏
}

//修改联系人函数
void modPerson(Addressboooks* abs)
{
	cout << "请输入要修改的联系人姓名：" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;
		//性别
		int gender = 0;
		cout << "请选择性别（1-男，2-女）：" << endl;
		while (true) //如果输入的是1或2，退出循环；如果输入其他，循环，重新输入
		{
			cin >> gender;
			if ((gender == 1) | (gender == 2)) //判断性别值是否合法
			{
				abs->personArray[ret].m_Gender = gender;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}
		//年龄
		int age;
		cout << "请输入年龄：" << endl;
		while (true)
		{
			cin >> age;
			if ((age >= 0) & (age <= 150))
			{
				abs->personArray[ret].m_Age = age;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}
		//电话
		string phone;
		cout << "请输入电话：" << endl;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;
		//住址
		string addr;
		cout << "请输入住址：" << endl;
		cin >> addr;
		abs->personArray[ret].m_Addr = addr;
		cout << "修改成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause"); //按任意键继续
	system("cls"); //清屏
}

//清空联系人函数
void clearPerson(Addressboooks* abs)
{
	cout << "注意！此操作会清空全部联系人信息，确定要清空吗？y-确认，n-取消" << endl;
	string confirm;
	while (true)
	{
		cin >> confirm;
		if (confirm == "y")
		{
			abs->m_Size = 0;
			cout << "通讯录已清空" << endl;
			break;
		}
		else if (confirm == "n")
		{
			cout << "操作已取消" << endl;
			break;
		}
		cout << "输入有误，请重新输入" << endl;
	}
	system("pause"); //按任意键继续
	system("cls"); //清屏
}

int main()
{
	//创建通讯录结构体变量
	Addressboooks abs;
	abs.m_Size = 0;

	//创建用户选择输入的变量
	int select = 0;

	while (true)
	{
		//菜单调用
		showMenu();
		cout << "请输入序号选择功能：";
		cin >> select;

		switch (select)
		{
		case 1: //1. 添加联系人
			addPerson(&abs); //地址传递，修改实参
			break;
		case 2: //2. 显示联系人
			showPerson(&abs);
			break;
		case 3: //3. 删除联系人
		{
			delPerson(&abs);
			break;
		}
		case 4: //4. 查找联系人
			searchPerson(&abs);
			break;
		case 5: //5. 修改联系人
			modPerson(&abs);
			break;
		case 6: //6. 清空联系人
			clearPerson(&abs);
			break;
		case 0: //0. 退出通讯录
			cout << "欢迎下次使用" << endl;
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