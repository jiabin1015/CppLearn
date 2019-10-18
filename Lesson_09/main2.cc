#include <iostream>
using namespace std;

//基类People
class People{
public:
    void showDetail();
    void doSomething(string things);
protected:
    string name;
    int age;
};
void People::showDetail(){
    cout<<"我叫"<<name<<"，今年"<<age<<"岁"<<endl;
}
void People::doSomething(string things) {
    cout << "do " << things << endl;
}

//派生类Student
class Student: public People{
public:
    Student(string name, int age, float score);
    void showDetail();  //覆盖基类的showDetail()方法
    void doSomething();
private:
    float m_score;
};

Student::Student(string name, int age, float score){
    name = name;
    age = age;
    m_score = score;
}

void Student::showDetail(){
    cout<<name<<"的年龄是"<<age<<"，成绩是"<<m_score<<endl;
}

void Student::doSomething() {
    cout << "just do it" << endl;
}


int main(){
    Student stu("小明", 18, 88.8);
    //使用的是Student类里面的成员函数
    stu.showDetail();
    //使用的是从Perple类继承来的成员函数
    stu.People::showDetail();
    
    stu.doSomething();
    stu.doSomething("home work"); // Too many arguments to function call, expected 0, have 1;
    
    stu.People::doSomething("home work");
    return 0;
}


