    /*
    1.stringstream
    ss.str(""); 	//清空缓冲区
	ss.clear(); 	//清空状态位（不是清空内容）

    2.正则
    + 一次或多次
    * 零次或多次
    ? 零次或一次

        regex emailaddress("\w[-\w.+]*@([A-Za-z0-9][-A-Za-z0-9]+\.)+[A-Za-z]{2,14}")
    
    3.函数对象
    greater是一个模板类
    greater<int>  用int实例化的类
    greater<int>()  该类的一个对象(匿名对象，像是： Person p = Person(); 这样)
    greater<int>(1,2) 错
    greater<int>()(1,2) 对

        auto func = greater<int>();  -->   greater<int> func = greater<int>();
    函数对象的要求有哪些？
        需要重载operator()运算符
        并且该函数需要是public访问权限



    */
#include <iostream>
#include <stdlib.h>
using namespace std;

template<class T>
class Greater {
public:
	bool operator()(const T &a, const T &b) const	{
		return a > b;
	}
};

void test01(){
    auto func1 = Greater<int>();            //其实就是默认构造
    Greater<int> func2 = Greater<int>();
    // Greater<int> func3();
    Greater<int> func3;                     //默认构造


    cout<<func1(1,2)<<" "<<func1(2,1)<<endl;
    cout<<func2(1,2)<<" "<<func2(2,1)<<endl;
    cout<<func3(1,2)<<" "<<func3(2,1)<<endl;
}

int main(){
    test01();
    system("pause");
    return 0;  
}