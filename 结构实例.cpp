//纸牌游戏
#include <iostream>

using namespace std;

const int clubs = 0;
const int diamonds = 1;
const int hearts = 2;
const int spades = 3;
//或者采用：
//enum Suit
//{
	//clubs,diamonds,hearts,spades//enum类型声明定义花色集合，枚举数据可以这样使用
//};

const int jack = 11;
const int queen = 12;
const int king = 13;
const int ace = 14;

struct card
{
	int number;
	int suit;
};

int main()
{
	card temp, chosen, prize;
	int position;
	card card1 = { 7,clubs };
	cout << "card 1 is the 7 of clubs\n";
	
	card card2 = { jack,hearts };
	cout << "card 2 is the jack of hearts\n";

	card card3 = { ace,spades };
	cout << "card 3 is the ace of spades\n";

	prize = card3;

	cout << "i am swapping card 1 and card 3\n";
	temp = card3; card3 = card1; card1 = temp;
	cout << "i am swapping card 2 and card 3\n";
	temp = card3; card3 = card2; card2 = temp;
	cout << "i am swapping card 1 and card 2\n";
	temp = card2; card2 = card1; card1 = temp;
	cout << "now where(1,2,or 3)is the ace of spades?";
	
	cin >> position;
	switch (position)
	{
	case 1:chosen = card1; break;
	case 2:chosen = card2; break;
	case 3:chosen = card3; break;
	default:
		break;
	}
	if (chosen.number==prize.number&&chosen.suit==prize.suit)
	{
		cout << "that is right!you win\n";
	}
	else cout << "sorry you lose.\n";
	
	return 0;
}

//枚举：允许自定义数据类型，澄清和简化编程工作
//如果预先知道某种数据类型可取值的长度有限（通常较短），便可以使用enum类型。这里使用enum类型表示一周中的各天

#include<iostream>

using namespace std;

enum days_of_week//枚举enumeration，enum类型的声明定义了这种类型所有允许值名称的集合。enum实际上是int类型
{
	Sun, Mon, Tue, Wed, Thu, Fri, Sat
};

int main()
{
	days_of_week day1, day2;

	day1 = Mon; day2 = Thu;

	int diff = day2 - day1;
	cout << "days between =" << diff << endl;

	if (day1<day2)
	{
		cout << "day1 comes before day2\n";
	}
	return 0;
}

//统计单词数目

#include<iostream>
#include<conio.h>

using namespace std;

enum itsaWord
{
	NO,YES
};
int main()
{
	itsaWord isWord = NO;

	char ch = 'a';
	int wordcount = 0;

	cout << "Enter a phrase:\n";
	do
	{
		ch = _getche();
		if (ch=='  '||ch=='\r')
		{
			if (isWord == YES)
			{
				wordcount++;
				isWord = NO;
			}
		}
		else
			if (isWord==NO)
			{
				isWord = YES;
			}
	} while (ch!='\r');
	cout << "\n---Word count is " << wordcount << "---\n";
	return 0;
}

