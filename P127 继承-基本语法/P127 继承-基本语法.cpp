#include<iostream>
using namespace std;

//公共页面
class BasePage
{
public:
	void header()
	{
		cout << "首页、公开课、登录、注册……（公共头部）" << endl;
	}
	void footer()
	{
		cout << "帮助中心、合作交流、站内地图……（公共底部）" << endl;
	}
	void left()
	{
		cout << "Java、Python、C++……（公共分类列表）" << endl;
	}
};

//Java页面
class Java:public BasePage
{
public:
	void content()
	{
		cout << "Java 学科视频" << endl;
	}
};

//Python页面
class Python :public BasePage
{
public:
	void content()
	{
		cout << "Python 学科视频" << endl;
	}
};

//CPP页面
class CPP :public BasePage
{
public:
	void content()
	{
		cout << "C++ 学科视频" << endl;
	}
};

void test1()
{

	cout << "Java 视频页面如下：" << endl;
	cout << "-------------------------------------------------" << endl;
	Java ja;
	ja.header();
	ja.content();
	ja.footer();
	cout << "-------------------------------------------------" << endl;

	cout << "Python 视频页面如下：" << endl;
	cout << "-------------------------------------------------" << endl;
	Python py;
	py.header();
	py.content();
	py.footer();
	cout << "-------------------------------------------------" << endl;

	cout << "C++ 视频页面如下：" << endl;
	cout << "-------------------------------------------------" << endl;
	CPP cpp;
	cpp.header();
	cpp.content();
	cpp.footer();
	cout << "-------------------------------------------------" << endl;
}

int main()
{
	test1();

	system("pause");
	return 0;
}

//继承语法：class 子类（派生类）:继承方式 父类（基类）