#include<iostream>
using namespace std;

//������Ҫ��ɲ���ΪCPU���Կ����ڴ�
//��ÿ�������װ��������࣬�����ṩ��ͬ�ĳ���������ͬ�����
//�����������ṩ�õ��Թ����ĺ���������ÿ����������Ľӿ�
//����ʱ��װ��̨��ͬ�ĵ��Խ��й���

//����CPU��
class CPU
{
public:
	virtual void caculate() = 0;
};

//�����Կ���
class GPU
{
public:
	virtual void display() = 0;
};

//�����ڴ���
class MEM
{
public:
	virtual void storage() = 0;
};

//������
class Computer
{
public:
	Computer(CPU * cpu, GPU * gpu, MEM * mem)
	{
		m_cpu = cpu;
		m_gpu = gpu;
		m_mem = mem;
	}
	//��������
	void work()
	{
		m_cpu->caculate();
		m_gpu->display();
		m_mem->storage();
	}
	//�����������ͷŵ������
	~Computer()
	{
		if (m_cpu != NULL)
		{
			delete m_cpu;
			m_cpu = NULL;
		}
		if (m_gpu != NULL)
		{
			delete m_gpu;
			m_gpu = NULL;
		}
		if (m_mem != NULL)
		{
			delete m_mem;
			m_mem = NULL;
		}
	}
private:
	CPU* m_cpu; //CPUָ��
	GPU* m_gpu; //�Կ�ָ��
	MEM* m_mem; //�ڴ�ָ��
};

//����
//Intel����
class IntelCPU :public CPU
{
public:
	virtual void caculate()
	{
		cout << "Intel CPU ��ʼ����" << endl;
	}
};
class IntelGPU :public GPU
{
public:
	virtual void display()
	{
		cout << "Intel GPU ��ʼ��ʾ" << endl;
	}
};
class IntelMEM :public MEM
{
public:
	virtual void storage()
	{
		cout << "Intel MEM ��ʼ�洢" << endl;
	}
};

//Lenovo����
class LenovoCPU :public CPU
{
public:
	virtual void caculate()
	{
		cout << "Lenovo CPU ��ʼ����" << endl;
	}
};
class LenovoGPU :public GPU
{
public:
	virtual void display()
	{
		cout << "Lenovo GPU ��ʼ��ʾ" << endl;
	}
};
class LenovoMEM :public MEM
{
public:
	virtual void storage()
	{
		cout << "Lenovo MEM ��ʼ�洢" << endl;
	}
};

void test1()
{
	//��һ̨�������
	CPU* intelCpu = new IntelCPU;
	GPU* intelGpu = new IntelGPU;
	MEM* intelMem = new IntelMEM;
	//��һ̨������װ
	cout << "��1̨���Կ�ʼ����" << endl;
	Computer* c1 = new Computer(intelCpu, intelGpu, intelMem);
	c1->work();
	delete c1;

	cout << "-----------------------------" << endl;

	//�ڶ�̨������װ
	cout << "��2̨���Կ�ʼ����" << endl;
	Computer* c2 = new Computer(new LenovoCPU, new LenovoGPU, new LenovoMEM);
	c2->work();
	delete c2;

	cout << "-----------------------------" << endl;

	//�ڶ�̨������װ
	cout << "��3̨���Կ�ʼ����" << endl;
	Computer* c3 = new Computer(new LenovoCPU, new IntelGPU, new LenovoMEM);
	c3->work();
	delete c3;
}


int main()
{
	test1();

	system("pause");
	return 0;
}