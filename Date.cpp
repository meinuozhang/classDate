#include <iostream>
using namespace std;
class Date
{
public:
	Date(int x)
		: _day(x)
		, _month(_day)
		, _year(x)
	{
		cout << "Date ()" << endl;
	}


	void Display()
	{
		cout << "year:" << _year << endl;
		cout << "month:" << _month << endl;
		cout << "day:" << _day << endl;
	}


private:
	int _year;     // 年
	int _month;    // 月
	int _day;      // 日
};


void Test()
{
	Date d1(1);
	d1.Display();
}int  main()
{
	Test();
	getchar();
	return 0;
}

//class Time
//{
//public:
//	Time(const Time& t)
//	{
//		cout << "Time (const Time& t)" << endl;
//		_hour = t._hour;
//		_minute = t._minute;
//		_second = t._second;
//	}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//
//
//class Date
//{
//public:
//	Date(int year, int month, int day, const Time& t)
//	{
//		cout << "Date ()" << endl;
//
//
//		_year = year;
//		_month = month;
//		_day = day;
//		_t = t;
//	}
//
//
//private:
//	int _year;     // 年
//	int _month;    // 月
//	int _day;      // 日
//
//
//	const int _testConst;    // 1.测试const 成员变量的初始化
//	int& _testReference;    // 2.测试引用成员变量的初始化
//	Time _t;                // 3.时间测试无缺省构造函数的成员变量的初始化
//};
//int main()
//{
//	Date d1(2015,3, 3, 21);
//	getchar();
//	return 0;
//}
//#include <iostream>
//using namespace std;
//static  int arry[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//class Date
//{
//public:
//	static int GetMonDay(int year, int month)
//	{
//		
//		if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
//		{
//			arry[2] = 29;
//		}
//		else
//		{
//			arry[2] = 28;
//
//		}
//		return arry[month];
//	}
//	void Display()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//	Date(int year = 1900, int month = 1, int day = 1)
//		:_year(year)
//		,_month(month)
//		,_day(day)
//	{
//		if (year<1900 || month>12 || month < 0 || day<0 || day>GetMonDay(year, month))
//		{
//			cout << "您输入的是一个不合法的日期" << endl;
//			_year = 1900;
//			_month = 1;
//			_day = 1;
//		}
//	}
//	Date(const Date& d)
//		:_year(d._year)
//		, _month(d._month)
//		, _day(d._day)	
//	{
//	}
//	Date& operator= (const Date& d)
//	{
//		if (this!=&d)
//		{
//			this->_year = d._year;
//			this->_month = d._month;
//			this->_day = d._day;
//		} 
//		return *this;
//	}
//	friend ostream& operator<<(ostream& os, const Date& d);
//	friend istream& operator>>(istream& is,  Date& d);
//public:
//
//	bool operator == (const Date& d)
//	{
//		return _year == d._year
//				&& _month == d._month 
//	     		&& _day == d._day;
//	}
//	bool operator != (const Date& d)
//	{
//		return !(*this == d);
//	}
//	bool operator > (const Date& d)
//	{
//		if (_year > d._year)
//		{
//			return true;
//		}
//		if (_year == d._year)
//		{
//			if (_month > d._month)
//			{
//				return true;
//			}
//			if (_month == d._month)
//			{
//				if (_day > d._day)
//				{
//					return true;
//				}
//			}
//		}
//		return false;
//	}
//	bool operator >= (const Date& d)
//	{
//		return  (*this >d)||(*this==d);
//	}
//	bool operator < (const Date& d)
//	{
//		return !(*this>=d);
//	}
//	bool operator <= (const Date& d)
//	{
//		return !(*this>d);
//	}
//	Date operator+(int day)
//	{
//		if (day<0)
//		{
//			day = -day;
//			return *this - day;
//		}
//		Date tmp(*this);
//		tmp._day += day;
//		while (tmp._day > GetMonDay(tmp._year, tmp._month))
//		{
//			tmp._day -= GetMonDay(tmp._year, tmp._month);
//			if (tmp._month == 12)
//		{
//			tmp._year++;
//			tmp._month = 1;
//		}
//		else
//			tmp._month++;
//		}
//		return tmp;
//	}
//	Date operator-(int day)
//	{
//		if (day < 0)
//		{
//			day = -day;
//			return *this + day;
//		}
//		Date tmp(*this);
//		tmp._day -= day;
//		while (tmp._day<=0)
//		{
//			if (tmp._month ==1)
//			{
//				tmp._year--;
//				tmp._month=12;
//			}
//			else
//			{
//				tmp._month--;
//			}
//			tmp._day += GetMonDay(tmp._year,tmp._month);
//		}
//		return tmp;
//	}
//	Date& operator-=(int day)
//	{
//		/**this =*this- day;
//		return *this;*/
//		Date tmp= *this- day;
//		*this = tmp;
//		return *this;
//	}
//	Date& operator+=(int day)
//	{
//		/**this =*this+day;
//		return *this;*/
//		Date tmp = *this +day;
//		*this = tmp;
//		return *this;
//	}
//
//	const Date& operator++()//前置++
//	{
//		*this += 1;
//		return *this;
//	}
//	Date operator++(int)//后置++
//	{
//		Date tmp(*this);
//		*this+=1;
//		return tmp;
//	}
//	const Date& operator--()
//	{
//		*this -= 1;
//		return *this;
//	}
//	Date operator--(int)
//	{
//		Date tmp(*this);
//		*this-=1;
//		return  tmp;
//	}
//	//计算两个日期相减以后的差的天数
//	int operator-(const Date& d)
//	{
//		Date a=*this, b=d;
//		int flag = 1;
//		if (a > b)
//		{
//			a = d;
//			b = *this;
//		}
//		else
//		{
//			flag = -1;
//		}
//		int day = 0;//定义一个计数器
//		while (a != b)
//		{
//			++a;
//			++day;
//		}
//		return  day*flag;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//
//	/*const int _testConst;
//	int& _testRef;
//	Time _t;*/
//};
//istream& operator>>(istream& is, Date& d)
//{
//	cout << "请依次输入年-月-日：" << endl;
//	cin >> d._year;
//	cin >> d._month;
//	cin >> d._day;
//	return  is;
//}
//ostream& operator<<(ostream& os, const Date& d)
//{
//	cout << d._year << "-" << d._month << "-" << d._day << endl;
//	return os;
//}
//void Print()
//{
//	cout << "**********欢迎使用万年历******** "<< endl;
//    cout << "1.计算加减天数" << endl;
//	cout << "2.计算两个时间的日期差" << endl;
//	cout << "3.退出" << endl;
//}
//void TestDate1()
//{
//	Date d1(2015, 8, 1), d3(2015, 2, 29);
//	Date d2(2015, 2, 13);
//	d1 + (31);
//	d1.Display();
//	d3.Display();
//	/*Date d2(d1);
//	d2.Display();
//	d3 = d1;
//	d3.Display();*/
//	cout << "d1==d2?:" << (d1 == d2) << endl;
//	cout << "d1>d2?:" << (d1 > d2) << endl; 
//	cout << "d1>=d2?:" << (d1 >= d2) << endl;
//	cout << "d1<d2?:" << (d1 < d2) << endl;
//	cout << "d1<=d2?:" << (d1 <= d2) << endl;
//	
//
//}
//void TestDate2()
//{
//	Date d1(2015, 8, 1);
//	cout << (d1 + 13) << endl;
//	cout << (d1 + 53) << endl;
//	cout << (d1 - 13) << endl;
//	cout << (d1 - 1) << endl;
//	cout << (d1 - 33) << endl;
//
//}
//void TestDate3()
//{
//	Date d1(2015, 8, 1),d3;
//	d3 = d1;
//	//d3.Display(); 
//	Date d2(2015, 2, 13);
//	//cout << (d1 +=13) << endl;
//	//cout << (d1 -= 13)<< endl;
//	cout << (d1 --) << endl;
//	cout << (d1 ++) << endl;
//    cout << (++d1) << endl;
//	cout << (--d1) << endl;
//
//    cout << (d1 -d2) << endl;
//	cout << (d2 - d1) << endl;
//
//}void TestDate4()
//{  
//	Date tmp1, tmp2;
//	int in, days;
//	cin >> in;
//	while (in)
//	{
//		switch (in)
//		{
//		case 0:
//			break;
//		case 1:
//			cout << "请输入日期" << endl;
//			cin >> tmp1;
//			/*{
//				tmp1._year = _year;
//			}
//			if (tmp1._year<1900 || month>12 || month < 0 || day<0 || day>GetMonDay(year, month))
//			{
//				cout << "您输入的是一个不合法的日期" << endl;
//				_year = 1900;
//				_month = 1;
//				_day = 1;
//			}*/
//			cout << "请输入计算推后的天数" << endl;
//			cin >> days;
//			tmp1 += days;
//			cout << tmp1 << endl;
//			break;
//		case 2:
//			cout << "请输入日期" << endl;
//			cin >> tmp1;
//			cout << "请输入日期" << endl;
//			cin >> tmp2;
//			days = tmp1 - tmp2;
//			cout << "相差的天数:" << days << endl;
//			break;
//		default:
//			cout << "请输入正确的选项" << endl;
//			break;
//		}
//	}
//}
//int main()
//{
//   // Print();
//	TestDate1();
//	//TestDate2();
//	//TestDate3();
//   // TestDate4();
//	getchar();
//	return 0;
//}
