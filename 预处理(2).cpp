#include <iostream>

#define DEBUG
//#define SOMETHING

//#ifdef SOMETHING
//int func1() {/*...*/ }
//#else
//int func1() {/*...*/ }
//#endif
//#ifdef SOMETHING
//namespace space1 {
//#endif
	//...
//#ifdef SOMETHING
//}//space1
//#endif
//可预定义函数和命名空间

int main()
{
#ifdef DEBUG
	std::cout << "succeed" << std::endl;
	std::cerr << "There's a problem." << std::endl;//cerr用于输出错误，不像cout一样带有重定向和进入缓冲区，直接在显示器上显示。cerr不经过缓冲区是为了在最紧急的时候还能得到输出支持
#endif

#ifndef SOMETHING
#define SOMETHING
	std::cout << "define successfully" << std::endl;
	std::cerr << "failed" << std::endl;
#else
	std::cout << "it's okay" << std::endl;
#endif
}