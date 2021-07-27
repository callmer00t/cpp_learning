#include<iostream>
using namespace std;

//电脑主要组成部件为CPU、显卡、内存
//将每个零件封装出抽象基类，并且提供不同的厂商生产不同的零件
//创建电脑类提供让电脑工作的函数，调用每个零件工作的接口
//测试时组装三台不同的电脑进行工作

//抽象CPU类
class CPU
{
public:
	virtual void caculate() = 0;
};

//抽象显卡类
class GPU
{
public:
	virtual void display() = 0;
};

//抽象内存类
class MEM
{
public:
	virtual void storage() = 0;
};

//电脑类
class Computer
{
public:
	Computer(CPU * cpu, GPU * gpu, MEM * mem)
	{
		m_cpu = cpu;
		m_gpu = gpu;
		m_mem = mem;
	}
	//工作函数
	void work()
	{
		m_cpu->caculate();
		m_gpu->display();
		m_mem->storage();
	}
	//析构函数，释放电脑零件
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
	CPU* m_cpu; //CPU指针
	GPU* m_gpu; //显卡指针
	MEM* m_mem; //内存指针
};

//厂商
//Intel厂商
class IntelCPU :public CPU
{
public:
	virtual void caculate()
	{
		cout << "Intel CPU 开始计算" << endl;
	}
};
class IntelGPU :public GPU
{
public:
	virtual void display()
	{
		cout << "Intel GPU 开始显示" << endl;
	}
};
class IntelMEM :public MEM
{
public:
	virtual void storage()
	{
		cout << "Intel MEM 开始存储" << endl;
	}
};

//Lenovo厂商
class LenovoCPU :public CPU
{
public:
	virtual void caculate()
	{
		cout << "Lenovo CPU 开始计算" << endl;
	}
};
class LenovoGPU :public GPU
{
public:
	virtual void display()
	{
		cout << "Lenovo GPU 开始显示" << endl;
	}
};
class LenovoMEM :public MEM
{
public:
	virtual void storage()
	{
		cout << "Lenovo MEM 开始存储" << endl;
	}
};

void test1()
{
	//第一台电脑零件
	CPU* intelCpu = new IntelCPU;
	GPU* intelGpu = new IntelGPU;
	MEM* intelMem = new IntelMEM;
	//第一台电脑组装
	cout << "第1台电脑开始工作" << endl;
	Computer* c1 = new Computer(intelCpu, intelGpu, intelMem);
	c1->work();
	delete c1;

	cout << "-----------------------------" << endl;

	//第二台电脑组装
	cout << "第2台电脑开始工作" << endl;
	Computer* c2 = new Computer(new LenovoCPU, new LenovoGPU, new LenovoMEM);
	c2->work();
	delete c2;

	cout << "-----------------------------" << endl;

	//第二台电脑组装
	cout << "第3台电脑开始工作" << endl;
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