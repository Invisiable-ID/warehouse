#include<iostream>
#include"Header.h"
using namespace std;
const float tensile_strength(1.97);
const int yield_strength(376);
const int steel_EM(205000);
const int concrete_EM(25100);
class A
{
	int length;
	int width;
	int height;
};
int main()
{
	float differ;
	int length;
	float elongation(0);

	A* a;
	a = &A;

	cout << "input difference:" << endl;
	cin >> differ;
	cout << "input length:" << endl;
	cin >> length;
	dif(differ,length,elongation);//Éì³¤ÂÊ
	//cout << elongation<<endl;
	return 0;
}