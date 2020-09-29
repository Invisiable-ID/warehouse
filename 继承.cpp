//派生类可以调用基类的protected和public对象，而基类无法调用派生类
#include<iostream>

using namespace std;

class Counter//basic class
{
protected:
	int count;
public:
	Counter():count(0)
	{ }
	Counter(int c):count(c)
	{ }
	int get_cout()const
	{
		return count;
	}
	Counter operator ++()
	{
		return Counter(++count);
	}
};
class CountDn :public Counter//derived class
{
public:
	Counter operator --()
	{
		return Counter(--count);//返回--count的值，且其为Counter类
	}
};
int main()
{
	CountDn c1;
	cout << "\nc1= " << c1.get_cout();
	++c1; ++c1; ++c1;
	cout << "\nc1= " << c1.get_cout();
	--c1; --c1;
	cout << "\nc1= " << c1.get_cout();
	cout << endl;
	return 0;
}

#include<iostream>

using namespace std;

enum poseng{pos,eng};

class Distance
{
protected:
	int feet;
	float inches;
public:
	Distance():feet(0),inches(0.0)
	{ }
	Distance(int ft,float in):feet(ft),inches(in)
	{ }
	void getdist()
	{
		cout << "\nEnter feet； "; cin >> feet;
		cout << "Enter inches: "; cin >> inches;
	}
	void showdist()const
	{
		cout << feet << "\'-" << inches << '\"-';
	}
};
class DistSign :public Distance
{
private:
	poseng sign;//sign is pos or eng
public:
	DistSign():Distance()
	{
		sign = pos;//set the sign to +
	}
	DistSign(int ft, float in, poseng sg = pos) :Distance(ft, in)
	{
		sign = sg;//set the sign
	}
	void getdist()
	{
		Distance::getdist();
		char ch;
		cout << "Enter sign(+ or -): "; cin >> ch;
		sign = (ch == '+') ? pos : eng;
	}
	void showdist()const
	{
		cout << ((sign == pos) ? "(+)" : "(-)");//show sign
		Distance::showdist();//ft and in
	}
};
int main()
{
	DistSign alpha;
	alpha.getdist();
	DistSign beta(11, 6.25);
	DistSign gamma(100, 5.5, eng);
	cout << "\nalpha= "; alpha.showdist();
	cout << "\nbeta= "; beta.showdist();
	cout << "\ngamma= "; gamma.showdist();
	cout << endl;
	return 0;
}

//重载成员函数
//派生出来一个新类Stack2，其中加入了警告机制
#include<iostream>
#include<process.h>

using namespace std;

class Stack
{
protected:
	enum{MAX=3};//size of stack array
	int st[MAX];
	int top;
public:
	Stack()
	{
		top = -1;
	}
	void push(int var)//put number on stack
	{
		st[++top] = var;
	}
	int pop()//take number off stack
	{
		return st[top--];
	}
};
class Stack2 :public Stack
{
public:
	void push(int var)//put number on stack
	{
		if (top>=MAX-1)
		{
			cout << "\nError:stack is full";
			exit(1);
		}
		Stack::push(var);
	}
	int pop()
	{
		if (top<0)
		{
			cout << "\nError :stack is empty\n";
			exit(1);
		}
		return Stack::pop();
	}
};
int main()
{
	Stack2 s1;
	s1.push(11);
	s1.push(22);
	s1.push(33);
	cout << endl << s1.pop();
	cout << endl << s1.pop();
	cout << endl << s1.pop();
	cout << endl << s1.pop();
	cout << endl;
	return 0;
}

//类的层次
#include <iostream>

using namespace std;

static const int LEN = 80;

class employee//抽象类，只用于派生其他类
{
private:char name[LEN];
		long number;
public:
	void getdata()
	{
		cout << "\nEnter last name: "; cin >> name;
		cout << "Enter number: "; cin >> number;
	}
	void putdata()const
	{
		cout << "\nName； "<<name;
		cout << "\nNumber: " << number;
	}
};
class manager :public employee
{
private:
	char title[LEN];
	double dues;
public:
	void getdata()
	{
		employee::getdata();
		cout << "Enter title: "; cin >> title;
		cout << "Enter golf club dues: "; cin >> dues;
	}
	void putdata()const
	{
		employee::putdata();
		cout << "\nTitle: " << title;
		cout << "\nGolf club dues: " << dues;
	}
};
class scientist :public employee
{
private:int pubs;
public:
	void getdata()
	{
		employee::getdata();
		cout << "Enter number of pubs: "; cin >> pubs;
	}
	void putdata()const
	{
		employee::putdata();
		cout << "\n Number of publications: " << pubs;
	}
};
class laborer :public employee
{ };
int main()
{
	manager m1, m2;
	scientist s1;
	laborer l1;
	cout << endl;
	cout << "\nEnter data for manager 1";
	m1.getdata();
	cout << "\nEnter data for manager 2";
	m2.getdata();
	cout << "\nEnter data for scientist 1";
	s1.getdata();
	cout << "\nEnter data for laborer 1";
	l1.getdata();
	cout << "\nData on manager 1";
	m1.putdata();
	cout << "\nData on manager 2";
	m2.putdata();
	cout << "\nData on scientist 1";
	s1.putdata();
	cout << "\nData on laborer 1";
	l1.putdata();
	cout << endl;
	return 0;
}

//公共和私有的继承
//私有继承private派生类对象无法访问基类公共成员函数，没有一个基类成员可以访问
//合并访问
#include<iostream>

using namespace std;

class A
{
private:
	int privdataA;
protected:
	int protdataA;
public:
	int pubdataA;
};
class B :public A//public-derived class
{
public:
	void funct()
	{
		int a;
		a = privdataA;//error
		a = protdataA;
		a = pubdataA;
	}
};
class C :private A//private-derived class
{
public:
	void funct()
	{
		int a;
		a = privdataA;//error
		a = protdataA;
		a = pubdataA;
	}
};
int main()
{
	int a;
	
	B objB;
	a = objB.privdataA;//error
	a = objB.protdataA;//error
	a = objB.pubdataA;

	C objC;
	a = objC.privdataA;//error
	a = objC.protdataA;//error
	a = objC.pubdataA;//error,a private-dervied class
	return 0;
}

//继承的级别：派生类本身可以继续派生
#include <iostream>

using namespace std;

const int LEN = 80;

class employee
{
private:
	char name[LEN];
	long number;
public:
	void getdata()
	{
		cout << "\nEnter last name: "; cin >> name;
		cout << "Enter number: "; cin >> number;
	}
	void putdata()const
	{
		cout << "\nName: " << name;
		cout << "\nNumber: " << number;
	}
};
class manager :public employee
{
private:
	char title[LEN];
	double dues;
public:
	void getdata()
	{
		employee::getdata();
		cout << "Enter title: "; cin >> title;
		cout << "Enter golf club dues: "; cin >> dues;
	}
	void putdata()const
	{
		employee::putdata();
		cout << "\nTitle: " << title;
		cout << "\nGolf club dues: " << dues;
	}
};
class scientist :public employee
{
private:int pubs;
public:
	void getdata()
	{
		employee::getdata();
		cout << "Enter number of pubs: "; cin >> pubs;
	}
	void putdata()const
	{
		employee::putdata();
		cout << "Enter number of pubs: "; cin >> pubs;
	}
	void putdata()const
	{
		employee::putdata();
		cout << "\nNumber of publications: " << pubs;
	}
};
class laborer :public employee
{ };
class foreman :public laborer
{
private:float quotas;
public:
	void getdata()
	{
		laborer::getdata();
		cout << "Enter quotas: "; cin >> quotas;
	}
	void putdata()const
	{
		laborer::putdata();
		cout << "\n Quotas: " << quotas;
	}
};
int main()
{
	laborer l1;
	foreman f1;
	cout << endl;
	cout << "\nEnter data for laborer 1";
	l1.getdata();
	cout << "\nEnter data for forman 1";
	f1.getdata();
	cout << endl;
	cout << "\nData on laborer 1";
	l1.putdata();
	cout << "\nData on forman 1";
	f1.putdata();
	cout << endl;
	return 0;
}

//多重继承