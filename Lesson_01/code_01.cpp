#include <iostream> //  iostream,为标准输入输出流头文件，i == in；o == out

using namespace std;  //  使用 std 命名空间


void funCout() {
  //  std::cout,将其后面的内容，输出至标准输出设备（终端）
  //  std::endl 为换行在Linux下等价于"\r\n"
  std::cout << "hello, world" << std::endl; 

  // 输出变量
  int count  = 10;
  std::cout << count << std::endl;

  // 输出字符串+变量组合
  int a = 10;
  int b = 20;
  std::cout << "a+b="<< a+b << std::endl;
}

void funCin() {
  int age = 0;
  float height = 0.0f;
  char name[100] = {0};
  std::cout << "请输入你的年龄:" << std::endl;
  std::cin >> age;
  std::cout << "请输入你的身高:" << std::endl;
  std::cin >> height;
  std::cout << "请输入你的姓名:" << std::endl;
  std::cin >> name;
  std::cout << "你的年龄为:" << age << std::endl;
  std::cout << "你的身高为:" << height << std::endl;
  std::cout << "你的姓名是:" << name << std::endl;
}
 
// 第一个命名空间
namespace funSpace1{
   void func(){
      std::cout << "funSpace1" << std::endl;
   }
}
// 第二个命名空间
namespace funSpace2{
   void func(){
      std::cout << "funSpace2" << std::endl;
   }
}

// 嵌套命名空间
// 第一个命名空间
namespace space1{
   void funSpace(){
      cout << "Inside first_space" << endl;
   }
   // 第二个命名空间
   namespace space2{
      void funSpace(){
         cout << "Inside second_space" << endl;
      }
   }
}

using namespace funSpace1; // 使用funSpace1命名空间
using namespace space1::space2; // 使用嵌套命名空间
int main() {
  /*
  funCout();
  funCin();
  */

  // 调用第一个命名空间中的函数
  funSpace1::func();
  // 调用第二个命名空间中的函数
  funSpace2::func(); 

  // 调用funSpace1命名空间中的func函数
  func();

  cout << "whit out std::" << endl;
  std::cout << "whit std::" << std::endl;

  space1::space2::funSpace();

}