/*
*/
#include <iostream>
#include <cstring>
#include <stdlib.h>
using namespace std;

void func1() {
//   char a[20];
  char a[20]={0};                       //不初始化的话，最后输出的strlen(a)是21（离谱）
  int i = 0;
  while (strlen(a) < 10) {
      a[i] = char(i + int('a'));        //abcdefghij
      i++;
  }
  std::cout << a << std::endl;
  std::cout << strlen(a) << std::endl;
}

// void func2() {
//   std::string a = "abcdefg";
//   char* b = a.c_str();
//   for (int i = 0; i < a.size(); ++i) {
//       b[i] = char(i + 'A');
//   }
//   std::cout << a << std::endl;
// }

void func3() {
  char a[20];
  const char* b = "abcdefg";
  int len = strlen(b);
  for (int i = 0; i < len; ++i) {
      a[i] = b[i];
  }
  std::cout << a << std::endl;
  std::cout << strlen(a) << std::endl;
}

void func4() {
  std::string a = "abcdefg";
  for (int i = 0; i < a.size(); ++i) {
      a.at(i) = char(i + 'A');
  }
  std::cout << a << std::endl;
  std::cout << a.length() << std::endl;
}

int main(){
    func4();
    system("pause");
    return 0;
}