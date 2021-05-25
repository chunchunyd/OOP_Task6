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

    4.自定义类型的排序
        方法一：重载小于运算符
        方法二：定义比较函数
        方法三：定义比较函数对象
    
    5.  模板实现
        #include <iostream>
        #include <fstream>
        #include <functional>
        #include <string>
        using namespace std;
        string readFromScreen()
        {
            string input; getline(cin, input);
            return input;
        }
        class ReadFromFile
        {
        public:
            string operator()(){
                string input;
                getline(ifstream("input.txt"), input);
                return input;
            }
        };
        template<class ReadFunc, class CalFunc, class WriteFunc>
        void process(ReadFunc read,
                            CalFunc calculate,
                            WriteFunc write)
        {
            string data = read();
            string output = calculate(data);
            write(output);
        }
        string calculateAdd(string x)
        {
            return x;
        }
        void writeToScreen(string x)
        {
            cout << x;
        }
        int main()
        {
            process(readFromScreen, calculateAdd, writeToScreen);
            process(ReadFromFile(), calculateAdd, writeToScreen);
            return 0;
        }

    

    6.std::function类       function<返回值类型(参数类型)>
        function<string()> readArr[] = 
			{readFromScreen, ReadFromFile()};
        function<string(string)> calculateArr = 
			{calculateAdd, CalculateMul()};
        function<void(string)> writeArr[] = 
			{writeToScreen, WriteToFile()};


    上面的代码可以改成：
        void process(
            function<string()> read, 
            function<string(string)> calculate,
            function<void(string)>	write)
        {
            string data = read();
            string output = calculate(data);
            write(output);
        }
        int main()
        {
            process(readFromScreen, calculateAdd, writeToScreen);
            process(ReadFromFile(), calculateAdd, writeToScreen);
            return 0;
        }

        使用虚函数实现
            需要构造基类和子类
            运行时确定调用函数的地址
        使用模板实现
            可以支持函数指针和函数对象			（通过模板，自动重载实现）
            编译期确定调用函数的地址（当T不为std::function时）
        使用std::function实现
            也可以支持函数指针和函数对象			（通过function的多态）
            运行时确定调用函数的地址

        function:
        不再需要模板来调用不同的函数
        简化理解，所有的函数都可以看做std::function

        STL有大量函数用到了函数对象(#include <algorithm>)
            for_each	对序列进行指定操作  for_each(Iterator begin, Iterator end, func())
            find_if	找到满足条件的对象  list<CPerson*>::iterator it = find_if(lst.begin(), lst.end(), finder_t(50)); // 查找年龄为50的人
            count_if	对满足条件的对象计数     int num = count_if(lst.begin(), lst.end(), finder_t(50)); 
            binary_search	二分查找满足条件的对象
            ……
        并且也有许多预置的函数对象(#include <functional>)
            less		比较a<b
            equal_to	比较a==b
            greater	比较a>b
            plus		返回a+b
            ……
        熟练使用函数对象有助于实现复杂的功能

    

以下哪些能正常编译？        BCD   (E自己测也可以)                  (为什么？       const int & 可以接受 int, int& 和 const int&)
    int func1(const int &x, int &b) {...};
    function<______> pf1 = func1;

    A.int(int, int)
    B.int(int, int&)
    C.int(int&, int&)
    D.int(const int&, int&)
    E.int(const int, int)
    F.int&(int, int&)               //返回值类型不对

以下哪些能正常编译？            ABE                  (B为什么？ 所以返回值int&可以转成int,int不能转成int&?)
    class Func2{
    public:
        int& operator()(int &&b) const {...}
    };
    function<______> pf2 = func2;

    A.int&(int&&)
    B.int(int&&)
    C.int&(int&)
    D.int(int&)
    E.int&(int)             int&(int)也可以，这似乎有点违反规则，因为int无法直接传给Func2()
                            但实际上，pf2的实现方式是拷贝了一份参数，然后将该参数的右值传给Func2()







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