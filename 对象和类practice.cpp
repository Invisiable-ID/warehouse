//第一题
#include<iostream>

using namespace std;

class Compare
{
public:
	Compare() :i(23), j(2)
	{
		cout << "waiting" << endl;
	};
	int zeroSmaller()
	{
		return i < j ? i : j;
	}
private:
	int i, j;
};

int main()
{
	Compare fir;
	cout<<fir.zeroSmaller();
	return 0;
}
//第二题
#include <iostream>

using namespace std;

struct Distance
{
	int first;
	int second;
};

Distance bigengl(Distance, Distance);
void engldisp(Distance);

int main()
{
	Distance d1, d2,d3;

	cout << "\nEnter the first number: "; cin >> d1.first;
	cout << "\nEnter the second number"; cin >> d2.first;
	d3 = bigengl(d1, d2);
	cout << "\nd1= "; engldisp(d1);
	cout << "\nd2= "; engldisp(d2);
	cout << "\nlargest is "; engldisp(d3); cout << endl;
	return 0;
}

Distance bigengl(Distance dd1, Distance dd2)
{
	if (dd1.first > dd2.first)
		return dd1;
	else if(dd1.first<dd2.first)
		return dd2;
	else cout << "warning,a mistake" << endl;
}

void engldisp(Distance dd)
{
	cout << dd.first << "\'-";
}

//第三题
#include<iostream>

using namespace std;

class Int
{
private:
	int i;
public:
	Int():i(0)
	{
		cout << "do once" << endl;
	}
	Int(int ii)
	{
		i = ii;
	}
	void add(Int i2, Int i3)
	{
		i = i2.i + i3.i;
	}
	void display()
	{
		cout << i;
	}
};

int main()
{
	Int Int1(7);
	Int Int2(11);
	Int Int3;
	Int3.add(Int1, Int2);
	Int3.display();
	cout << endl;
	return 0;
}

//第四题
#include <iostream>
#include <conio.h>

using namespace std;
const char ESC = 27;
const double TOLL = 0.5;

class tollbooth
{
private:
	int total_number;
	double total_cost;//双精度
public:
	tollbooth() :total_number(0), total_cost(0.0)
	{ }
	void payingCar()
	{
		total_number++;
		total_cost += TOLL;	
	}
	void nopayCar()
	{
		total_number++;
	}
	void display() const
	{
		cout << "\nCars=" << total_number << ",cost=" << total_cost << endl;
	}
};

int main()
{
	tollbooth booth1;
	char ch;
	cout << "\npress 0 for each non-paying car," << "\n 1 for each paying car," << "\n Esc to exit the program.\n";
	do
	{
		ch = getche();
		if (ch=='0')
		{
			booth1.nopayCar();
		}
		if (ch=='1')
		{
			booth1.payingCar();
		}
	} while (ch!=ESC);
	booth1.display();
	return 0;
}

//第五题 计算输出时间
#include <iostream>

using namespace std;

class time
{
private:
	int hour, minute, second;
public:
	time():hour(0),minute(0),second(0)
	{ }
	time(int h,int m,int s):hour(h),minute(m),second(s)
	{ }
	void display() const
	{
		cout << hour << ":" << minute << ":" << second << endl;
	}
	void add_time(time t1, time t2)
	{
		second = t1.second + t2.second;
		if (second>59)
		{
			second -= 60; minute++;
		}
		minute = t1.minute + t2.minute;
		if (minute>59)
		{
			minute -= 60; hour++;
		}
		hour = t1.hour + t2.hour;
	}
};
int main()
{
	const time time1(5, 59, 59);
	const time time2(4, 30, 30);
	time time3;
	time3.add_time(time1, time2);
	cout << "time3= ";
	time3.display();
	cout << endl;
	return 0;
}