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
	int _year;     // ��
	int _month;    // ��
	int _day;      // ��
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
//	int _year;     // ��
//	int _month;    // ��
//	int _day;      // ��
//
//
//	const int _testConst;    // 1.����const ��Ա�����ĳ�ʼ��
//	int& _testReference;    // 2.�������ó�Ա�����ĳ�ʼ��
//	Time _t;                // 3.ʱ�������ȱʡ���캯���ĳ�Ա�����ĳ�ʼ��
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
//			cout << "���������һ�����Ϸ�������" << endl;
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
//	const Date& operator++()//ǰ��++
//	{
//		*this += 1;
//		return *this;
//	}
//	Date operator++(int)//����++
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
//	//����������������Ժ�Ĳ������
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
//		int day = 0;//����һ��������
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
//	cout << "������������-��-�գ�" << endl;
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
//	cout << "**********��ӭʹ��������******** "<< endl;
//    cout << "1.����Ӽ�����" << endl;
//	cout << "2.��������ʱ������ڲ�" << endl;
//	cout << "3.�˳�" << endl;
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
//			cout << "����������" << endl;
//			cin >> tmp1;
//			/*{
//				tmp1._year = _year;
//			}
//			if (tmp1._year<1900 || month>12 || month < 0 || day<0 || day>GetMonDay(year, month))
//			{
//				cout << "���������һ�����Ϸ�������" << endl;
//				_year = 1900;
//				_month = 1;
//				_day = 1;
//			}*/
//			cout << "����������ƺ������" << endl;
//			cin >> days;
//			tmp1 += days;
//			cout << tmp1 << endl;
//			break;
//		case 2:
//			cout << "����������" << endl;
//			cin >> tmp1;
//			cout << "����������" << endl;
//			cin >> tmp2;
//			days = tmp1 - tmp2;
//			cout << "��������:" << days << endl;
//			break;
//		default:
//			cout << "��������ȷ��ѡ��" << endl;
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
