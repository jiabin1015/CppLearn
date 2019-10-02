#include <iostream>

using namespace std;

class Person
{
public:
    Person();//默认构造函数
    Person(const char* name, int age, float height, float weight);//带参构造函数
    Person(const Person &p);
    ~Person();//析构函数，只存在这个唯一版本
    void showPerson();
    
private:
    char * name;//姓名定义为指针类型  ①
    int age;
    float height;
    float weight;
};

Person::Person()
{
    cout << "Person默认构造函数" << endl;
    // ②.1
    name = new char[32];
    strcpy(name, "Lily");
    age = 1;
    height = 1.50;
    weight = 5.0;
}

Person::Person(const char* n, int a, float h, float w) :
age(a),//基础类型变量直接赋值
height(h),
weight(w)
{
    // ②.2
    name = new char[strlen(n)+1];
    strcpy(name, n);
    cout << "Person带参构造函数" << endl;
}

Person::Person(const Person &p)
{
    //    name = p.name; // ⑤
    
    // 深拷贝 ⑥
    name = new char[strlen(p.name)+1];
    strcpy(name, p.name);
    age = p.age;
    height = p.age;
    weight = p.weight;
}


Person::~Person()//析构函数实现
{
    cout << "Person析构函数" << endl;
    delete[]name; // ③
}
void Person::showPerson()
{
    cout << "name" << name << " age:" << age << " height:" << height << " weight:" << weight << endl;
}
int main()
{
    Person p("张三疯", 88, 175, 70);
    Person per(p); // ④
    
    p.showPerson();
    per.showPerson();
    return 0;
}



