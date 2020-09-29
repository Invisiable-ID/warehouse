//数组名就是数组的地址，加上一个数之后就是表达式intarray+i的地址，是常量
#include<iostream>

using namespace std;

int main()
{
	int intarray[5] = { 31,45,65,75,23 };
	int *p;
	p = intarray;//数组名是数组的首地址，指针指向数组的首地址
	for (int i = 0; i < 5; i++)
		cout << *(p++) << endl;
	return 0;
}

#include <iostream>

using namespace std;

const int MAX = 5;

int main()
{
	void centimize(double*);
	double varray[MAX] = { 10.0,2.0,54.0,23.8,54.9 };
	centimize(varray);
	for (int i = 0; i < MAX; i++)
	{
		cout << varray[i] << endl;
	}
	return 0;
}
void centimize(double* p)
{
	for (int i = 0; i < MAX; i++)
	{
		*p *= 3.14;
	}
}

//用指针排序
#include<iostream>

using namespace std;

int main()
{
	void order(int*, int);//函数中定义两个指针变量
	int var1(12), var2(13);
	//order(&var1, &var2);
	int *p,*q;
	p = &var1;
	q = &var2;
	order(p, *q);
	//cout << *p << endl;
	//cout << p << endl;
	cout << &var1 << endl;
	cout << var1<<endl;
	return 0;
}
void order(int* num1, int num2)//定义两个指针
{
	if (*num1<num2)
	{
		int temp = *num1;
		*num1 = num2;
		num2 = temp;
	}
}

#include <iostream>

using namespace std;

int main()
{
	char str[] = "defined as an array";
	char* p;
	p = NULL;//指针初始化
	p = str;
	cout << *p << endl;
}

//内存管理
#include<iostream>
#include<cstring>

using namespace std;

//new操作符，从操作系统中获得内存块并返回该内存块的首地址
//C++中没有renew，只能通过使用new重新申请更大/更小的空间
int main()
{
	char str[] = "C++ is a good language.";
	char* p;
	p = NULL;
	p = str;//指向字符串的首地址
	int len = strlen(p);
	char* ptr;
	ptr = NULL;
	ptr = new char[len + 1];//set aside memory:string +'\0'
	strcpy_s(ptr,len+1, str);//copy str to new memory area ptr
	//errno_t strcpy_s(char *strDestination,size_t numberOfElements,const char *strSource);中间数组长度要+1否则报错
	cout << ptr << endl;
	delete[] ptr;//release ptr's memory，delete用于将内存返还操作系统
//new和delete常常要配套使用
	//加方括号表示删除的是一个数组，简单对象则不必加
	return 0;
}

#include<iostream>
#include<cstring>

using namespace std;

class String
{
private:
	char* str;
public:
	String(char* s)
	{
		int length = strlen(s);
		str = new char[length + 1];
		strcpy_s(str, length + 1, s);
	}
	~String()//自定义析构函数
	{
		cout << "Delete str.\n";
		delete[] str;
	}
	void display()
	{
		cout << str << endl;
	}
};
int main()
{
	char s[] = "who knows";
	String s1=s;
	cout << "s1= ";
	s1.display();
	return 0;
}#include<iostream>
#include<cstring>

using namespace std;

class String
{
private:
	char* str;
public:
	String(char* s)
	{
		int length = strlen(s);
		str = new char[length + 1];
		strcpy_s(str, length + 1, s);
	}
	~String()
	{
		cout << "Delete str.\n";
		delete[] str;
	}
	void display()
	{
		cout << str << endl;
	}
};
int main()
{
	char s[] = "who knows";
	String s1=s;
	cout << "s1= ";
	s1.display();
	return 0;
}

include<iostream>

using namespace std;

class Distance
{
private:
	int feet;
	float inches;
public:
	void getdist()
	{
		cout << "\nEnter feet: ";
		cin >> feet;
		cout << "\nEnter inches: ";
		cin >> inches;
	}
	void showdist()
	{
		cout << feet << "\'-" << inches << '\"-';
	}
};
int main()
{
	Distance* distptr;//pointer to Distance
	distptr = new Distance;//points to new Distance object,new操作符创建Distance另一个对象，并返回一个disptr指针指向它
	distptr->getdist();//access objectmembers
	distptr->showdist();//with->operator
	//运算符->将指针看成对象，就像点运算符操作对象一样
	cout << endl;
	return 0;
}

//链表：提供了一种不使用数组但更为灵活的存储系统，其每一个数据项都是按需要使用new来获得的，且数据项之间通过指针连接起来
#include<iostream>

using namespace std;

struct link
{
	int data;
	link* next;
};
class linklist
{
private:
	link* first;
public:
	linklist()
	{
		first = NULL;
	}//none first link
	void additem(int d);
	void display();
};
void linklist::additem(int d)
{
	link* newlink = new link;
	newlink->data = d;
	newlink->next = first;//it points to next link
	first = newlink;//now first points to this
}
void linklist::display()
{
	link* current = first;
	while (current!=NULL)
	{
		cout << current->data << endl;//print data
		current = current->next;//move to next link
	}
}
int main()
{
	linklist li;//make linked list
	li.additem(25);
	li.additem(36);
	li.additem(49);
	li.additem(64);
	li.display();
	return 0;
}