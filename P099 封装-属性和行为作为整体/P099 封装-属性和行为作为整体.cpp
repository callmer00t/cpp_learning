#include<iostream>
using namespace std;

//���һ��Բ���࣬��Բ�ε��ܳ�
//��Բ���ܳ��Ĺ�ʽ��C = 2 * pi * r

//ʹ�ó�������Բ����
const double pi = 3.14;

//���һ��Բ����
class CIRCLE
{
	//����Ȩ��
public:

	//����
	int r; //�뾶

	//��Ϊ
	double perimeter()
	{
		return 2 * pi * r;
	}
};

int main()
{
	//ʵ������ͨ��Բ���ഴ�������Բ�Σ�����
	CIRCLE C1;

	//��Բ�ζ���C1�����Խ��и�ֵ
	C1.r = 10;

	cout << "Բ���ܳ�Ϊ��" << C1.perimeter() << endl;

	system("pause");
	return 0;
}
