//1.C++中引入友元函数，是为了在该类中提供一个对外访问的窗口；
//2.这个友元函数它不属于该类的成员函数，它是定义在外的普通函数，只是类中声明该函数可以直接访问类中的private和protected成员
//3.友元函数形式：friend<返回类型><函数名>(<参数列表>)
//4.使用注意点：类中通过使用friend来修饰，但函数并不是类的成员函数，其声明可以放在私有或公有部分。友元函数定义在类体外实现而无需加类限定；
//友元函数可以访问类中的私有成员和其他数据，但是访问不可直接使用数据成员，需要通过对对象进行引用
//友元函数在调用上同一般函数一样，不必通过对对象进行引用。
#include<iostream>
#include<cstring>

using namespace std;

class persion
{
public:persion(char *pn);
	   //友元函数
	   friend void setweigth(persion &p, int h);//注意，参数列表中一般会有一个引用类型的形参,原因参考上面的使用要点3和4;
	   void disp();//类成员函数
private:
	char name[20];
	int weigth, age;
};
persion::persion(char* pn)//构造函数
{
	strcpy(name, pn);
	weigth = 0;
}
void persion::disp()
{
	cout << name << "--" << weigth << endl;
}////友元函数的具体实现：这里没有类限定例如 (perion::setweigth)这种形式,这里可以与上面的disp()做个对比，一个属于类的成员，有限定，不属于类的成员函数，没有加限定
void setweigth(persion &pn, int w)
{
	strcpy(pn.name,pn);//实现字符串的复制
	pn.weigth = w;//私有成员数据赋值
}
void main()
{
	persion p("zhansan");//调用实现setweigth()与一般函数调用一致
	setweigth(p, 60);
	p.disp();//调用类的成员函数
}

#include <iostream>
#include <cstring>
using namespace std;
 
class wheel;
class car{
public:
    car(char *pn);
    void run(wheel &w);    //成员函数，做成wheel类中友元函数实现
private:
    char name[20];
 
};
car::car(char *pn)
{
strcpy(name,pn);
}
 
class wheel{
public:
    wheel(int s);
    friend void car::run(wheel &w);   //这里把car类的成员函数做了友元函数。
private:
    int speed;
};
wheel::wheel(int s)
{
  speed=s;
}
int  main(int argc, char const *argv[])
{
    wheel w(60);
    car c("New car");
    c.run(w);
    return 0;
}