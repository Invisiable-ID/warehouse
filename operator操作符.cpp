//将操作符重载实现为类的成员函数
#include <iostream>

class person
{
private: int age;
public:	  
	person(int nAge)
	{
		this->age = nAge;
	}
	bool operator==(const person& ps)
	{
		if (this->age==ps.age)
		{
			return true;
		}
		return false;
	}
};
int main()
{
	person p1(10);
	person p2(10);
	if (p1==p2)
	{
		std::cout << "p1 is equal with p2" << std::endl;
	}
	else
	{
		std::cout << "p1 is not equal with p2" << std::endl;
	}
	return 0;
}

//将操作符重载实现为非类的成员函数（全局函数）对于全局重载操作符，代表左操作数的参数必须被显式指定。
#include <iostream>

class person
{
	public:int age;
};
bool operator==(person const& p1, person const& p2)
{
	if (p1.age==p2.age)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{
	person p1;
	person p2;
	p1.age = 18;
	p2.age = 19;
	if (p1==p2)
	{
		std::cout << "p1 is equal with p2" << std::endl;
	}
	else
	{
		std::cout << "p1 is not equal with p2" << std::endl;
	}
	return 0;
}

//一个包含赋值运算符重载函数的类
#include <iostream>
#include <string.h>

class ClassA
{
public:	char* pszTestStr;
public:
	ClassA()
	{

	}
	ClassA(const char* pszInputStr)//常指针，char类型，地址*pszInputStr不变为const,地址中包含的内容pszInputStr可变
	{
		pszTestStr = new char[strlen(pszInputStr) + 1];
	}
	virtual ~ClassA()
	{
		delete pszTestStr;
	}
	//赋值运算符重载函数
	ClassA& operator=(const ClassA& cls)
	{
		//避免自赋值
		if (this!=&cls)
		{
			//避免内存泄漏
			if (pszTestStr!=NULL)
			{
				delete pszTestStr;
				pszTestStr = NULL;
			}
			pszTestStr = new char[strlen(cls.pszTestStr) + 1];
		}
		return *this;
	}
};
int main()
{
	ClassA obj1("litter");
	ClassA obj2;
	obj2 = obj1;
	std::cout << "obj2.pszTestStr is:" << obj2.pszTestStr << std::endl;
	std::cout << "addr(obj1.pszTestStr) is:" << &obj1.pszTestStr << std::endl;
	std::cout << "addr(obj2.pszTestStr) is:" << &obj2.pszTestStr << std::endl;
}

//
#include <iostream>
#include <string>

class Data
{
public:
	//构造函数
	Data()
	{

	};
	Data(int _data) :data(_data)
	{
		std::cout << "This is constructor" << std::endl;
	}
	//赋值运算符重载函数
	Data& operator=(const int _data)
	{
		std::cout << "this is operator=(int _data)" << std::endl;
		data = _data;
		return *this;
	}

private:
	int data;
};
int main()
{
	//调用构造函数
	Data data1(1);
	Data data2, data3;
	//调用赋值运算符重载函数
	data2 = 1;
	//调用默认的赋值运算符重载函数
	data3 = data2;
	return 0;
}
//说明：“data2 = 1;”语句调用了我们提供的以int型参数（而非本类或本类的引用）为形参的赋值运算符重载函数，而“data3 = data2;”的成功执行，说明该语句调用了编译器提供的默认的赋值运算符重载函数。
//构造函数和赋值运算符重载函数同时存在时，优先调用赋值运算符重载函数；仅有构造函数时，调用构造函数