//虚函数——实现多态性
#include<iostream>

using namespace std;

class Base
{
public:
	virtual void show()
	{
		cout << "Base\n";
	}
};
class Derv1:public Base
{
public:
	void show()
	{
		cout << "Derv1\n";
	}
};
class Derv2 :public Base
{
public:
	void show()
	{
		cout << "Derv2\n";
	}
};
int main()
{
	Derv1 dv1;
	Derv2 dv2;
	Base* ptr;
	//后联编&动态联编
	ptr = &dv1;//put address of dv1 in pointer,visit class Derv1
	//这是被允许的，因为派生类的对象对于基类对象具有类型兼容性
	ptr->show();
	ptr = &dv2;
	ptr->show();
	return 0;
}

#include<iostream>

using namespace std;

class person
{
protected:
	char name[40];
public:
	void getName()
	{
		cout << "\nEnter name: ";
		cin >> name;
	}
	void putName()
	{
		cout << "Name is: ";
		cout << name;
	}
	virtual void getData() = 0;
	virtual bool isOutstanding() = 0;
};
class student :public person
{
private:
	float GPA;
public:
	void getData()
	{
		person::getName();
		cout << "Enter student's GPA； ";
		cin >> GPA;
	}
	bool isOutstanding()
	{
		return GPA > 3.5 ? true : false;
	}
};
class professor :public person
{
private:
	int numbers;
public:
	void getData()
	{
		person::getName();
		cout << "Enter the number of professor's publication: ";
		cin >> numbers;
	}
	bool isOutstanding()
	{
		return numbers > 100 ? true : false;
	}
};
int main()
{
	person* persptr[100];
	int n = 0;//numbers of person in list
	char choice;
	do
	{
		cout << "student or professor?(s/p): ";
		cin >> choice;
		if (choice == 's')
		{
			persptr[n] = new student;//in array
		}
		else
		{
			persptr[n] = new professor;
		}
		persptr[n++]->getData();
		cout << "Enter another(y/n)";
		cin >> choice;
	} while (choice == 'y');
	for (int i = 0; i < n; i++)
	{
		persptr[i]->putName();
		if (persptr[i]->isOutstanding())
		{
			cout << "This person is outstanding\n";
		}
	}
	return 0;
}

//虚析构函数
//基类析构函数应该总是虚的
#include<iostream>

using namespace std;

class Base
{
public:
	//~Base()//non-virtual destructor(析构函数)
	virtual ~Base()
	{
		cout << "Base destroyed\n";
	}
};
class Derv :public Base
{
public:
	~Derv()
	{
		cout << "Derv destroyed\n";
	}
};
int main()
{
	Base* pBase = new Derv;
	delete pBase;
	return 0;
}

//虚基类(多重继承相关)
#include<iostream>

using namespace std;

class Parent
{
protected:
	int basedata;
};
class Child1:public Parent
//class Child1:virtual public Parent
{ };
class Child2:public Parent
//class Child2:virtual public Parent
{ };
class GrandChild :public Child1, public Child2
{
public:
	int getdata()
	{
		return basedata;//ambiguous
	}
};

//友元函数
//友元如桥梁：函数以两个类的对象为参数，且要对他们的私有数据进行操作
#include<iostream>

using namespace std;

class beta;//needed for frifunc declaration
class alpha
{
private:
	int data;
public:
	alpha():data(3)
	{ }
	friend int frifunc(alpha, beta);//friend function
};
class beta
{
private:
	int data;
public:
	beta():data(7)
	{ }
	friend int frifunc(alpha, beta);
};
int frifunc(alpha a, beta b)
{
	return(a.data + b.data);
}
int main()
{
	alpha aa;
	beta bb;
	cout << frifunc(aa, bb) << endl;
	return 0;
}

//友元类
//当整个类被声明为友元时，该类所有成员函数都同时成为友元
#include<iostream>

using namespace std;

class alpha
{
private:
	int data1;
public:
	alpha():data1(99)
	{ }
	friend class beta;//友元类所有成员函数都可以访问alpha私有数据
};
class beta
{
public:
	void func1(alpha a)
	{
		cout << "\ndata1=" << a.data1;
	}
	void func2(alpha a)
	{
		cout << "\ndata1=" << a.data1;
	}
};
int main()
{
	alpha a;
	beta b;
	b.func1(a);
	b.func2(a);
	cout << endl;
	return 0;
}

#include<iostream>

using namespace std;

class alpha
{
private:
	int data;
public:
	alpha():data(0)
	{ }
	alpha(int d):data(d)
	{ }
	void display()
	{
		cout << data;
	}
	alpha operator=(alpha& a)
	{
		data = a.data;
		cout << "\nAssignment operator invoked";
		return alpha(data);
	}
};
int main()
{
	alpha a1(37);
	alpha a2;
	a2 = a1;
	cout << "\na2=";
	a2.display();
	alpha a3 = a2;
	cout << "\na3=";
	a3.display();
	cout << endl;
	return 0;
}

//this是指向对象本身的指针
#include<iostream>

using namespace std;

class what
{
private:
	int alpha;
public:
	void tester()
	{
		//使用this指针访问成员数据
		this->alpha = 12;
		cout << this->alpha;
	}
	what& operator = (what& a)
	{
		alpha = a.alpha;
		cout << "\nAssignment operator invoked";
		return *this;//使用this指针返回
	}
};
int main()
{
	what w;
	w.tester();
	cout << endl;
	return 0;
}

//动态信息类型
//运行期找出关于对象的类的信息，或改变一个对象的类都是可能的。两个实现机制：dynamic_cast,typeid
//这些功能通常使用在有很多类都由一个基类派生的情况下。为使动态类型转换能工作，基类必须是多态的，即包含虚函数
//用dynamic_cast查询类的类型,改变指针的类型
//typeid可以获得未知对象的类型信息，如类型名
#include<iostream>

using namespace std;

class Base
{
	virtual void vertFunc()
	{ }
};