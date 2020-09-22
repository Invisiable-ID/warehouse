//将数据和函数置入一个单一实体是面向对象程序设计的核心思想
//面向对象程序设计的一个关键特性是隐藏数据，隐藏数据的主要机制是将数据置于类中并将它设为私有，私有数据和函数只能通过类的内部访问，公有的数据和函数能从类的外部访问。隐藏数据不等于保护数据
#include<iostream>

using namespace std;

class part
{
private:
	int modelnumber;
	int partnumber;
	float cost;
public:
	void setpart(int mn, int pn, float c)
	{
		modelnumber = mn;
		partnumber = pn;
		cost = c;
	}
	void showpart()
	{
		cout << "Model " << modelnumber;
		cout << ",part " << partnumber;
		cout << ",costs $" << cost << endl;
	}
};

int main()
{
	part part1;
	part1.setpart(234, 455, 232.66F);
	part1.showpart();
	return 0;
}

#include<iostream>

using namespace std;

class Distance
{
private:
	int feet;
	float inches;
public:
	void setdist(int ft, float in)
	{
		feet = ft; inches = in;
	}
	void getdist()
	{
		cout << "\nEnter feet: "; cin >> feet;
		cout << "Enter inches: "; cin >> inches;
	}
	void showdist()
	{
		cout << feet << "\'-" << inches << '\"';
	}
};

int main()
{
	Distance dist1, dist2;
	dist1.setdist(11, 6.35);
	dist2.getdist();

	cout << "\ndist1= "; dist1.showdist();
	cout << "\ndist2= "; dist2.showdist();
	cout << endl;
	return 0;
}

//构造函数：与所属的类有着一模一样的名称；其次构造函数没有返回类型。因为构造函数是系统自动识别调用的，没有程序能接收它的返回值，返回值无意义。
#include<iostream>

using namespace std;

class Counter
{
private:
	int count;
public:
	Counter() :count(1)//构造函数初始化,初始化的位置位于成员函数声明符和函数体之间，初始值在成员函数后的圆括号内；若初始化多个成员，则必须以逗号分隔
	{	
		cout << "it's finished" << endl;//输出结果证明构造函数在操作
	}
	int inc_count()
	{
		count++;
		return count;
	}
	int get_count()
	{
		return count;
	}
};

int main()
{
	Counter c1, c2;

	cout << "\nc1=" << c1.get_count();
	cout << "\nc2=" << c2.get_count();

	c1.inc_count();
	c2.inc_count();

	cout<<"\nc1= "<<c1.get_count();
	cout<<"\nc2= "<<c2.get_count();
	cout << endl;
	
	return 0;
}

//析构程序，最常用的功能是释放由构造函数分配给对象的内存
//析构函数和构造函数一样，没有返回值，也没有参数
#include <iostream>

using namespace std;

class Distance
{
private:
	int feet;
	float inches;
public:
	Distance():feet(0),inches(0.0)//构造函数初始化
	{ }
	Distance(int ft,float in):feet(ft),inches(in)
	{ }
	void getdist()
	{
		cout << "\nEnter feet: "; cin >> feet;
		cout << "Enter inches; "; cin >> inches;
	}
	void showdist()
	{
		cout << feet << "\'-" << inches << "\'-";
	}
	void add_dist(Distance, Distance);
};
void Distance::add_dist(Distance d2, Distance d3)//重载的构造函数，能够在Distance类型的变量首次创建时就给它们赋值，这是很方便的
{//双冒号，这里表示Distance类的成员函数add_dist()
	inches = d2.inches + d3.inches;
	feet = 0;
	if (inches>=12.0)
	{
		inches -= 12.0;
		feet++;
	}
	feet += d2.feet + d3.feet;
}

int main()
{
	Distance dist1, dist3;
	Distance dist2(11, 6.25);

	dist1.getdist();
	dist3.add_dist(dist1,dist2);

	cout << "\ndist1= "; dist1.showdist();
	cout << "\ndist2= "; dist2.showdist();
	cout << "\ndist3= "; dist3.showdist();
	cout << endl;
	return 0;
}

//类实例：纸牌游戏
#include <iostream>

using namespace std;

enum Suit { clubs, diamonds, hearts, spades };//枚举类型
const int jack = 11;
const int queen = 12;
const int king = 13;
const int ace = 14;

class card
{
private:
	int number;
	Suit suit;
public:
	card()
	{ }
	card(int n, Suit s) :number(n), suit(s)//构造函数
	{ }
	void display();
	bool isEqual(card);
};
void card::display()//派生类
{
	if (number > 2 && number <= 10)
	{
		cout << number << "of";
	}
	else
		switch (number)
		{
		case jack:cout << "jack of "; break;
		case queen:cout << "queen of "; break;
		case king:cout << "king of "; break;
		case ace:cout << "ace of "; break;
		default:
			break;
		}
	switch (suit)
	{
	case clubs:cout << "clubs"; break;
	case diamonds:cout << "diamonds"; break;
	case hearts: cout << "hearts"; break;
	case spades:cout << "spades"; break;
	default:
		break;
	}
}
bool card::isEqual(card c2)
{
	return (number == c2.number&&suit == c2.suit) ? true : false;
}

int main()
{
	card temp, chosen, prize;
	int position;

	card card1(7, clubs);
	cout << "\nCard 1 is the ";
	card1.display();
	card card2(jack, hearts);
	cout << "\nCard 2 is the ";
	card2.display();
	card card3(ace, spades);
	cout << "\nCard 3 is the ";
	card3.display();

	prize = card3;

	cout << "\nI'm swapping card 1 and card 3";
	temp = card3; card3 = card1; card1 = temp;

	cout << "\nI'm swapping card 2 and card 3";
	temp = card3; card3 = card2; card2 = temp;

	cout << "\nI'm swapping card 1 and card 2";
	temp = card2; card2 = card1; card1 = temp;

	cout << "\nNow,where (1,2,3) is the ";
	prize.display();
	cout << "? ";
	cin >> position;

	switch (position)
	{
	case1:chosen = card1; break;
	case2:chosen = card2; break;
	case3:chosen = card3; break;
	default:
		break;
	}
	if (chosen.isEqual(prize))
	{
		cout << "That's right! You win!";
	}
	else cout << "Sorry.You lose.";
	cout << "You chose the ";
	chosen.display();
	cout << endl;
	return 0;
}

//静态成员数据
//当同一类的所有对象需要共享一个信息项时，静态数据项很有用。定义为static的成员变量具有和普通静态变量相似的特性，只在类的内部可见，生命周期和整个程序相同。即使没有类的对象，它也继续存在。
//普通静态变量被用来在各个函数调用之间保持信息，而静态的类成员数据是供类的各个对象共享信息的。
#include <iostream>

using namespace std;

class foo
{
private:
	static int count;//only one data for all objects
public:
	foo()
	{
		count++;
	}
	int getcount()
	{
		return count;
	}
};
int foo::count = 0;//definition of count
int main()
{
	foo f1, f2, f3;
	cout << "count is " << f1.getcount() << endl;//each object
	cout << "count is " << f2.getcount() << endl;
	cout << "count is " << f3.getcount() << endl;
	return 0;
}
//类foo是有静态int类型的count数据项的示例。类的构造函数每次使count自加1.在main()中定义了三个foo类的对象。因为构造函数被调用了三次，因此count自增三次
//因为count前面加了static，为类的对象所共有，因此count增到3；如果使用常规的自动变量，即与静态变量相反去掉static，则输出1；每个构造函数只会将自己私有的count副本加1。
//以下输出结果是1
#include <iostream>

using namespace std;

class foo
{
private:
	int count;//only one data for all objects
public:
	foo() :count(0)
	{
		count++;
	}
	int getcount()
	{
		return count;
	}
};
int main()
{
	foo f1, f2, f3;
	cout << "count is " << f1.getcount() << endl;//each object
	cout << "count is " << f2.getcount() << endl;
	cout << "count is " << f3.getcount() << endl;
	return 0;
}
//类的定义只是一个在内存中不开辟任何空间的蓝图。将定义置于类之外也强调了在程序开始执行前这种数据的内存空间只被分配一次；且整个类都可以访问静态成员变量。每个对象都没有它自己的变量版本，就像没有它自己的普通成员数据的版本一样。
//const和类
//const成员函数保证了它不会修改任何本类对象的数据成员
//把const置于声明符和函数体之间，就可以将一般的函数变为const函数 void function() const{  };若有单独的函数声明，则声明和定义中都要加上const
#include <iostream>

using namespace std;

class Distance
{
private:int feet;
		float inches;
public:
	Distance():feet(0),inches(0.0)
	{ }
	Distance(int ft, float in) :feet(ft), inches(in)
	{ }

	void getdist()
	{
		cout << "\nEnter feet: "; cin >> feet;
		cout << "Enter inches: "; cin >> inches;
	}
	void showdist() const//不容许更改对象数据成员
	{
		cout << feet << "\'-" << inches << '\"';
	}
	Distance add_dist(const Distance&) const;
};

Distance Distance::add_dist(const Distance& d2) const
{
	Distance temp;
	temp.inches = inches + d2.inches;
	if (temp.inches>=12.0)
	{
		temp.inches -= 12.0;
		temp.feet = 1;
	}
	temp.feet += feet + d2.feet;
	return temp;
}

int main()
{
	Distance dist1, dist3;
	Distance dist2(11, 6.25);

	dist1.getdist();
	dist3 = dist1.add_dist(dist2);
	cout << "\ndist1= "; dist1.showdist();
	cout << "\ndist2= "; dist2.showdist();
	cout << "\ndist3= "; dist3.showdist();
	cout << endl;
	return 0;
}