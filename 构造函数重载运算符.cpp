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
	Data data2;
	//调用赋值运算符重载函数
	data2 = 1;
	//调用默认的赋值运算符重载函数
	return 0;
}
//说明：“data2 = 1;”语句调用了我们提供的以int型参数（而非本类或本类的引用）为形参的赋值运算符重载函数，而“data3 = data2;”的成功执行，说明该语句调用了编译器提供的默认的赋值运算符重载函数。