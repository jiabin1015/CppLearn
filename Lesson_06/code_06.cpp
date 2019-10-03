#include <iostream>

using namespace std;
class Person
{
    const char* name;
    
private: // ①
    int age;
    
protected: // ②
    char sex;
    void showMe();
};

void Person::showMe()
{
    cout << "My name is " << name <<endl;
    cout << "I'm " << age << " now" << endl;
}


class MyDate//日期类
{
    int year;
    int month;
    int day;
public:
    void setYear(int year); // 设置年份
    void setMonth(int month); // 设置月份
    void setDay(int day); // 设置日
    
    void showDate(); // 显示日期
};


void MyDate::setYear(int year)
{
    if (year < 1970) {
        cout << "年份设置不合法" << endl;
        return;
    }
    this->year = year;
}

void MyDate::setMonth(int month)
{
    if (month <= 0 || month >= 13)
    {
        cout << "月份设置不合法" << endl;
        return;
    }
    this->month = month;
    this->day = 1; // 重置日
}

void MyDate::setDay(int day)
{
    if (month <= 0 || month >= 13)
    {
        cout << "请先设置合法月份" << endl;
        return;
    }
    if (day <= 0 || day > 31)
    {
        cout << "请设置合法的日期" << endl;
        return;
    }
    if (month == 4 || month == 6 ||
        month == 9 || month == 11)
    {
        if (day > 30)
        {
            cout << month << "月没有" << day << "日" << endl;
            return;
        }
    }
    if (2 == month)
    {
        if ((year % 4 == 0 && year % 100 == 0) ||
            year % 400 == 0)//闰年
        {
            if (day > 29)
            {
                cout << year << "的2月没有" << day << "日" << endl;
                return;
            }
        }
        else
        {
            if (day > 28)
            {
                cout << year << "的2月没有" << day << "日" << endl;
                return;
            }
        }
    }
    this->day = day;
}

void MyDate::showDate()
{
    cout << year << "-" << month << "-" << day << endl;
}

int main()
{
    //    Person p;//用类实例化一个对象。
    //    p.age = 19;// ③
    //    p.sex = 'f';// ④
    MyDate d;
    d.setYear(2001);
    d.setMonth(2);
    d.setDay(29);
    //    d.showDate();
    return 0;
}



