#include<iostream>
using namespace std;

//���һ��ѧ���࣬������������ѧ�ţ����Ը�������ѧ�Ÿ�ֵ��������ʾѧ����������ѧ��

class STUDENT
{
public:
	//����
	string s_Name; //����
	int s_Id; //ѧ��

	//��Ϊ
	void showStudent()
	{
		cout << "������" << s_Name << " ѧ�ţ�" << s_Id << endl;
	}

	//ͨ����Ϊ��������ֵ
	void setName(string name)
	{
		s_Name = name;
	}

	void setId(int id)
	{
		s_Id = id;
	}
};

int main()
{
	//ʵ����
	STUDENT s1;
	//��s1�������Ը�ֵ
	s1.s_Id = 1;
	s1.s_Name = "����";
	//��ʾ��Ϣ
	s1.showStudent();

	STUDENT s2;
	s2.s_Id = 2;
	s2.s_Name = "����";
	s2.showStudent();

	//ͨ����Ϊ��ֵ
	STUDENT s3;
	s3.setName("����");
	s3.setId(3);
	s3.showStudent();

	system("pause");
	return 0;
}