#include<iostream>
using namespace std;

//设计一个圆形类，求圆形的周长
//求圆形周长的公式：C = 2 * pi * r

//使用常量定义圆周率
const double pi = 3.14;

//设计一个圆形类
class CIRCLE
{
	//访问权限
public:

	//属性
	int r; //半径

	//行为
	double perimeter()
	{
		return 2 * pi * r;
	}
};

int main()
{
	//实例化：通过圆形类创建具体的圆形（对象）
	CIRCLE C1;

	//给圆形对象C1的属性进行赋值
	C1.r = 10;

	cout << "圆的周长为：" << C1.perimeter() << endl;

	system("pause");
	return 0;
}
