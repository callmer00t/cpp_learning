#include<iostream>
using namespace std;
#include<vector>
#include<string>

//vector容器中存放自定义数据类型
class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;
};

void test1()
{
	vector<Person>v;
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	Person p5("eee", 50);
	
	//向容器中添加数据
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	//遍历容器中的数据
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "姓名：" << (*it).m_Name << "\t年龄：" << (*it).m_Age << endl; //it是迭代器，当作指针看待，*it解引用是Person数据类型，所以取姓名和年龄属性，是用.号
		cout << "姓名：" << it->m_Name << "\t年龄：" << it->m_Age << endl; //也可以直接用->的方式取出属性值
	}
}

//存放自定义数据类型 指针
void test2()
{
	vector<Person*>v;
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	Person p5("eee", 50);

	//向容器中添加数据
	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	v.push_back(&p5);

	//遍历容器中的数据
	for (vector<Person*>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "姓名：" << (*it)->m_Name << "\t年龄：" << (*it)->m_Age << endl; //it是迭代器，当作指针看待，*it解引用是Person数据类型，所以取姓名和年龄属性，是用.号
	}

}

int main()
{
	test1();
	test2();

	system("pause");
	return 0;
}