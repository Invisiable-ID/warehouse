//函数的另一种写法

#include <iostream>

using namespace std;

void starline();//先宣布函数

int main()
{
	starline();//调用starline()
	cout << "Data type range" << endl;
	starline();
	cout << "char -128 to 127" << endl
		<< "short --32,768 to 32,767" << endl
		<< "int system dependent" << endl
		<< "long -2147483648 to 2147483647" << endl;
	starline();
	return 0;
}
void starline()
{
	for (int j=0;j<45;j++)
		cout << '*';
	cout << endl;
}

//可以自己编写以.h为后缀的头文件，将自定义的类和函数都放进去，这样有助于简化代码
#include<iostream>

using namespace std;

//自主地定义一个类，相当于int char这些
struct Distance
{
	int feet;
	float inches;
};

void engldisp(Distance);

int main()
{
	Distance d1, d2;
	cout << "Enter feet:"; cin >> d1.feet;
	cout << "Enter inches:"; cin >> d1.inches;
	cout << "\nEnter feet:"; cin >> d2.feet;
	cout << "Enter inches:"; cin >> d2.inches;

	cout << "\nd1=";
	engldisp(d2);
	cout << endl;
	return 0;
}

//定义一个函数，将上面定义的结构作为整个参数传入函数中
void engldisp(Distance dd)
{
	cout << dd.feet << "\'-" << dd.inches << "\"";
}

//内联函数-在函数声明中加上关键字inline，inline关键字只是对编译器的一个请求
//内联函数可以取代#define宏
//内联函数是为了提高函数的执行效率，消除了写成函数的额外开销
//注意：当函数只有10行及以下才写成内联，较复杂的内联可以放在.h文件中
#include<iostream>

using namespace std;

inline float lbstokg(float pounds)
{
	return 0.45*pounds;
}
int main()
{
	float lbs;

	cout << "\nEnter your weight in pounds:";
	cin >> lbs;
	cout << "your weight in kilograms is" << lbstokg(lbs)
		<< endl;
	return 0;
}
//域解析运算符：局部&文件
//具有局部域解析运算符的变量仅在块内可见，具有文件域解析运算符的变量在整个文件内可见
//块：基本上就是在一个表示开始的括号和一个表示结束的括号之间的代码
//两种存储类：automatic和static类。具有automatic存储类的变量，在定义它的函数的生命周期内存在；具有static存储类的变量，在整个程序的生命周期内存在