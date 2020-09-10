//define预处理：#define macro-name replacement-text 
#include <iostream>

#define MKSTR(x) #x//# 运算符会把 replacement-text 令牌转换为用引号引起来的字符串
#define CONCAT(x,y) x##y//## 运算符用于连接两个令牌
#define MIN(a,b) (a<b?a:b)//取最小

int main()
{
	std::cout << MKSTR(Hello c++) << std::endl;
	int xy(14);
	std::cout << CONCAT(x,y) << std::endl;//输出xy,相当于cout<<xy<<endl;

	std::cout << __LINE__ << std::endl;//程序编译时包含当前行号
	std::cout << __DATE__ << std::endl;//这会包含一个形式为 month/day/year 的字符串，它表示把源文件转换为目标代码的日期
	std::cout << __TIME__ << std::endl;//这会包含一个形式为 hour:minute:second 的字符串，它表示程序被编译的时间
	std::cout << __FILE__ << std::endl;//这会在程序编译时包含当前文件名

	return 0;
}