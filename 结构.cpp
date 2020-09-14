#include <iostream>

using namespace std;

struct Distance
{
	int feet;
	float inches;
};

int main()
{
	Distance d1, d3;
	Distance d2 = { 11,6.25 };
	cout << "\nEnter feet:"; cin >> d1.feet;
	cout << "Enter inches:"; cin >> d1.inches;

	d3.inches = d1.inches + d2.inches;
	d3.feet = 0;
	if (d3.inches >= 12.0)
	{
		d3.inches -= 12.0;
		d3.feet++;
	}
	d3.feet += d1.feet + d2.feet;
	cout << d1.feet << "\'-" << d1.inches << "\"+";
	cout<< d2.feet << "\'-" << d2.inches << "\"+";
	cout << d3.feet << "\'-" << d3.inches << "\"+";
	return 0;
}

//结构嵌套

#include<iostream>

using namespace std;

struct Distance
{
	int feet;
	float inches;
};

struct Room
{
	Distance length;
	Distance width;
};

int main()
{
	Room dining;
	dining.length.feet = 13;
	dining.length.inches = 6.5;
	dining.width.feet = 10;
	dining.width.inches = 0.0;

	float l = dining.length.feet + dining.length.inches / 12;
	float w = dining.width.feet + dining.width.inches / 12;

	cout << "dining room area is" << l * w << "square feet\n";
	return 0;
}