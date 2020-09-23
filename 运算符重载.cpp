//运算符重载体现了C++的自由度，即可以自定义运算符
//一般来讲，默认的运算符只对int float等类型变量有效；而需要对自定义类的变量使用时，则需重载运算符
//程序编译时，编译器会自动识别变量；若为默认类型则调用操作符默认意义；而为自定义类型时要知道所写的operator++
//重载一元运算符
#include <iostream>

using namespace std;

class Counter
{
private:
	int count;
public:
	Counter():count(0)
	{ }
	int get_count()
	{
		return count;
	}
	void operator ++()
	{
		++count;
	}
};
int main()
{
	Counter c1, c2;
	cout << "\nc1=" << c1.get_count();
	cout << "\nc2=" << c2.get_count();

	++c1;
	++c2;
	++c2;
	cout << "\nc1=" << c1.get_count();
	cout << "\nc2=" << c2.get_count() << endl;
	return 0;
}

#include <iostream>

using namespace std;

class Counter
{
private:int count;
public:
	Counter() :count(0) { };
	int get_count()
	{
		return count;
	}
	Counter operator ++ ()
	{
		++count;
		Counter temp;
		temp.count = count;
		return temp;//++运算符此次返回的是一个Counter类型的变量而非void
	}
};
int main()
{
	Counter c1, c2;
	cout << "\nc1=" << c1.get_count();
	cout << "\nc2=" << c2.get_count();
	++c1;
	c2 = ++c1;//不会报错了
	cout << c1.get_count();
	cout << c2.get_count() << endl;
	return 0;
}

//重载二元运算符
#include<iostream>

using namespace std;

class Distance
{
private:
	int feet;
	float inches;
public:
	Distance() :feet(0), inches(0.0)
	{ }
	Distance(int ft, float in) :feet(ft), inches(in)
	{ }
	void getdist()
	{
		cout << "\nEnter feet: "; cin >> feet;
		cout << "Enter inches: "; cin >> inches;
	}
	void showdist() const
	{
		cout << feet << "\'-" << inches << '\"';
	}
	Distance operator +(Distance) const;//add 2 distances
};
Distance Distance::operator+(Distance d2)const//return sum
{
	int f = feet + d2.feet;
	float i = inches + d2.inches;
	if (i>=12.0)
	{
		i -= 12.0;
		f++;
	}
	return Distance(f, i);
}
int main()
{
	Distance dist1, dist3, dist4;
	dist1.getdist();
	Distance dist2(11, 6.25);
	dist3 = dist1 + dist2;
	dist4 = dist1 + dist2 + dist3;
	cout << "dist1="; dist1.showdist(); cout << endl;
	cout << "dist2="; dist2.showdist(); cout << endl;
	cout << "dist3="; dist3.showdist(); cout << endl;
	cout << "dist4="; dist4.showdist(); cout << endl;
	return 0;
}

#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;

class String
{
private:
	static const int SZ = 80;//更符合标准C++规定
	//enum { SZ = 80 };
	char str[SZ];
public:
	String()
	{
		strcpy(str, "");
	}
	String(char s[])
	{
		strcpy(str, s);
	}
	void display() const
	{
		cout << str;
	}
	String operator + (String ss) const
	{
		String temp;
		if (strlen(str) + strlen(ss.str) < SZ)
		{
			strcpy(temp.str, str);
			stract(temp.str, ss.str);
		}
		else
		{
			cout << "\nString overflow";
			exit(1);
		}
		return temp;
	}
};
int main()
{
	String s1 = "\nMerry Christmas!";
	String s2 = "Happy new year!";
	String s3;

	s1.display();
	s2.display();
	s3.display();
	s3 = s1 + s2;
	s3.display();
	cout << endl;
	return 0;
}

//多重重载
//比较运算符
#include<iostream>

using namespace std;

class Distance
{
private:
	int feet;
	float inches;
public:
	Distance():feet(0),inches(0.0)
	{ }
	Distance(int ft,float in):feet(ft),inches(in)
	{ }
	void getdisk()
	{
		cout << "\nEnter feet: "; cin >> feet;
		cout << "Enter inches: "; cin >> inches;
	}
	void showdisk()const
	{
		cout << feet << "\'-" << inches << '\"-';
	}
	bool operator < (Distance) const;
};
bool Distance::operator < (Distance d2)const
{
	float bf1 = feet + inches / 12;
	float bf2 = d2.feet + d2.inches / 12;
	return (bf1 < bf2) ? true : false;
}
int main()
{
	Distance dist1;
	dist1.getdisk();
	Distance dist2(6, 2.5);
	cout << "\ndist1= "; dist1.showdisk();
	cout << "\ndist2= "; dist2.showdisk();
	if (dist1<dist2)
	{
		cout << "\ndist1 is less than dist2";
	}
	else
	{
		cout << "\ndist1 is greater than dist2";
	}
	cout << endl;
	return 0;
}//对象和基本类型间的转换
#include<iostream>

using namespace std;

class Distance
{
private:
	const float MTF;//meters to feet
	int feet;
	float inches;
public:
	Distance():feet(0),inches(0.0),MTF(3.286554F)
	{ }
	Distance(float meters) :MTF(3.286554F)
	{
		float fltfeet = MTF * meters;
		feet = int(fltfeet);
		inches = 12 * (fltfeet - feet);
	}
	Distance(int ft,float in):feet(ft),inches(in),MTF(3.286554F)
	{ }
	void getdist()
	{
		cout << "\nEnter feet: "; cin >> feet;
		cout << "Enter inches: "; cin >> inches;
	}
	void showdist() const
	{
		cout << feet << "\'-" << inches << '\"';
	}
	operator float() const
	{
		float fracfeet = inches / 12;
		fracfeet += static_cast<float>(feet);//cast是显式转换
		return fracfeet / MTF;
	}
};
int main()
{
	float mtrs;
	Distance dist1 = 2.35F;
	cout << "\ndist1= "; dist1.showdist();
	mtrs = static_cast<float>(dist1);
	cout << "\ndist1= " << mtrs << "meters\n";
	Distance dist2(5, 10.25);
	mtrs = dist2;
	cout << "\ndist2= " << mtrs << "mtrs\n";
	return 0;
}

//不同类对象之间转换
//民用时制-军用时制
#include <iostream>
#include<string>

using namespace std;

class time12
{
private:
	bool pm;
	int hrs;
	int mins;
public:
	time12():pm(true),hrs(0),mins(0)
	{ }
	time12(bool ap,int h,int m):pm(ap),hrs(h),mins(m)
	{ }
	void display() const
	{
		cout << hrs << ':';
		if (mins<10)
		{
			cout << '0';
		}
		cout << mins << ' ';
		string am_pm = pm ? "p.m." : "a.m.";
		cout << am_pm;
	}
};
class time24
{
private:
	int hours;
	int minutes;
	int seconds;
public:
	time24():hours(0),minutes(0),seconds(0)
	{ }
	time24(int h,int m,int s):hours(h),minutes(m),seconds(s)
	{ }
	void display() const
	{
		if (hours<10)
		{
			cout<<'0';
		}
		cout << hours << ':';
		if (minutes<10)
		{
			cout << '0';
		}
		cout << minutes << ':';
		if (seconds<10)
		{
			cout << '0';
		}
		cout << seconds;
	}
	operator time12() const;//conversion operator
};
time24::operator time12() const
{
	int hrs24 = hours;
	bool pm = hours < 12 ? false : true;
	int roundMins = seconds < 30 ? minutes : minutes + 1;
	if (roundMins==60)
	{
		roundMins = 0;
		++hrs24;
		if (hrs24 == 12||hrs24==24)
		{
			pm = (pm == true) ? false : true;
		}
	}
	int hrs12 = (hrs24 < 13) ? hrs24 : hrs24 - 12;
	if (hrs12==0)
	{
		hrs12 = 12;
		pm = false;
	}
	return time12(pm, hrs12, roundMins);
}
int main()
{
	int h, m, s;
	while (true)
	{
		cout << "Enter 24-hour time: \n";
		cout << "Hours(0 to 23): "; cin >> h;
		if (h>23)
		{
			return (1);
		}
		cout << "Minutes: "; cin >> m;
		cout << "Seconds: "; cin >> s;
		time24 t24(h, m, s);
		cout << "You entered: ";
		t24.display();
		time12 t12 = t24;
		cout << "\n12-hour time: ";
		t12.display();
		cout << "\n\n";
	}
	return 0;
}
//运算符重载和类型转换，提供了一个机会——一个创造一门崭新语言的机会
//运算符重载要有节制
//不能被重载的运算符：成员访问运算符（点运算符）(.);域解析运算符分解运算符(::);条件运算符(?:);指向成员运算符(->)
//只能重载已有的运算符而不能创建新的运算符再重载它们

//关键字explicit和mutable
#include<iostream>

using namespace std;

class Distance
{
private:
	const float MTF;//meters to feet
	int feet;
	float inches;
public:
	Distance():feet(0),inches(0.0),MTF(3.280833F)
	{ }
	explicit Distance(float meters) :MTF(3.280833F)//用explicit防止转换，explicit出现在单参数构造函数前面
	{
		float fltfeet = MTF * meters;
		feet = int(fltfeet);
		inches = 12 * (fltfeet - feet);
	}
	void showdist()
	{
		cout << feet << "\'-" << inches << '\"';
	}
};
int main()
{
	void fancyDist(Distance);
	Distance dist1(2.35F);
	cout << "\ndist1= "; dist1.showdist();
	float mtrs = 3.0F;
	cout << "\ndist1 ";
	//fancyDist(mtrs);将发生错误，因为mtrs被用explicit修饰，不能转换类型
	//若不加explicit修饰，此处将由float转换为Distance发生隐式转换
	return(0);
}
void fancyDist(Distance d)
{
	cout << "(in feet and inches)= ";
	d.showdist();
	cout << endl;
}

//使用mutable改变const对象数据
//本质类似是希望能创建const类型的滚动条，它的属性保持不变，可能改变的只有其所有者，这便是需要引入mutable的地方
#include<iostream>
#include<string>

using namespace std;

class scrollbar
{
private:int size;
		mutable string owner;
public:
	scrollbar(int sz,string own):size(sz),owner(own)
	{ }
	void setSize(int sz)
	{
		size = sz;
	}
	void setOwner(string own) const
	{
		owner = own;
	}
	int getSize()const
	{
		return size;
	}
	string getOwner()const
	{
		return owner;
	}
};
int main()
{
	const scrollbar sbar(60, "Window1");//它的尺寸不能改变，但使用setOwner()可以改变其所有者，这种被称为逻辑常量属性
	//sbar.setSize(100);//this is OK
	sbar.setOwner("Window2");//these are OK too
	cout << sbar.getSize() << "," << sbar.getOwner() << endl;
	return 0;
}