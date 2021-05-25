/*
智能指针(<memory>库)
共享指针shared_ptr
    构造：   shared_ptr<int> p1(new int(1));
            shared_ptr<MyClass> p2 = make_shared<MyClass>(2);
            shared_ptr<MyClass> p3 = p2;
            shared_ptr<int> p4;	//空指针
    访问：  int x = *p1;		//从指针访问对象
            int y = p2->val;	//访问成员变量
    销毁对象：
            p2和p3指向同一对象，当两者均出作用域才会被销毁

    引用计数：p1.use_count （= 0 时 销毁对象）

            #include <iostream>
            using namespace std;

            template <typename T> 
            class SmartPtr;  //声明智能指针模板类
                
            template <typename T>
            class U_Ptr {   //辅助指针
            private:
            friend class SmartPtr<T>;
                            //SmartPtr是U_Ptr的友元类
            U_Ptr(T *ptr) :p(ptr), count(1) { }
            ~U_Ptr() { delete p; }
            
            int count;   
            T *p;           //实际数据存放                                                     
            };

            template <typename T>
            class SmartPtr { //智能指针
            U_Ptr<T> *rp;
            public:
            SmartPtr(T *ptr) :rp(new U_Ptr<T>(ptr)) { }
            SmartPtr(const SmartPtr<T> &sp) :rp(sp.rp) {
                ++rp->count; 
            }
            SmartPtr& operator=(const SmartPtr<T>& rhs) {
                ++rhs.rp->count; 
                if (--rp->count == 0) //减少自身所指rp的引用计数 pA = pB
                    delete rp; //删除所指向的辅助指针
                rp = rhs.rp;
                return *this;
            }
            ~SmartPtr() {
                if (--rp->count == 0)
                delete rp;
            }

    其他用法    
            p.get()	获取裸指针
            p.reset()	清除指针并减少引用计数
            static_pointer_cast<int>(p) 
                转为int类型指针(和static_cast类似，无类型检查）
            dynamic_pointer_cast<Base>(p)
                转为int类型指针(和dynamic_cast类似，动态类型检查）
    注意！
            不能使用同一裸指针初始化多个智能指针
                int* p = new int();  
                shared_ptr<int> p1(p); 
                shared_ptr<int> p2(p);
                // 会产生多个辅助指针！ 
            不能直接使用智能指针维护对象数组        @@@@@@
                所有的实现都是delete p;
                删除数组需要delete[] p;




智能指针不总是智能

        #include <memory>
        #include <iostream>
        using namespace std;

        class Child;
        class Parent {
            shared_ptr<Child> child;
        public:
            Parent() {cout << "parent constructing" << endl; }
            ~Parent() {cout << "parent destructing" << endl; }
            void setChild(shared_ptr<Child> c) {
                child = c;
            }
        };
        class Child {
            shared_ptr<Parent> parent;
        public:
            Child() {cout << "child constructing" << endl; }
            ~Child() {cout << "child destructing" << endl; }
            void setParent(shared_ptr<Parent> p) {
                parent = p;
            }
        };

        void test() {
            shared_ptr<Parent> p(new Parent());
            shared_ptr<Child> c(new Child());
            p->setChild(c);
            c->setParent(p);
            //p和c被销毁
        }

        int main()
        {
            test();
            return 0;

        }
            //结果：只有构造，没有析构（p和c都是）


弱引用weak_ptr（不增加use_count）
    创建
        shared_ptr<int> sp(new int(3));
        weak_ptr<int> wp1 = sp;
    用法
        wp.use_count()	//获取引用计数
        wp.reset()			//清除指针
        wp.expired()		//检查对象是否无效
        sp = wp.lock()	//从弱引用获得一个智能指针

            #include <memory>
            #include <iostream>
            using namespace std;
            int main()
            {
            std::weak_ptr<int> wp;
            {
            auto sp1 = std::make_shared<int>(20);
            wp = sp1;
            cout << wp.use_count() << endl;	//1
            auto sp2 = wp.lock();	//从弱引用中获得一个shared_ptr
            cout << wp.use_count() << endl;	//2
            sp1.reset();							//sp1释放指针
            cout << wp.use_count() << endl;	//1
            }	//sp2销毁
            cout << wp.use_count() << endl;	//0
            cout << wp.expired() << endl;	  //检查弱引用是否失效：True
                return 0;
            }


独享所有权unique_ptr(保证一个对象只被一个指针引用)
            #include <memory>
            #include <utility>
            using namespace std;
            int main() {
            auto up1 = std::make_unique<int>(20);
            //unique_ptr<int> up2 = up1; 
                        //错误，不能复制unique指针
            unique_ptr<int> up2 = std::move(up1);
                        //可以移动unique指针
            int* p = up2.release();
                        //放弃指针控制权，返回裸指针            @@@
            delete p;
            return 0;
            }           



优点
    智能指针可以帮助管理内存，避免内存泄露
    区分unique_ptr和shared_ptr能够明确语义
    在手动维护指针不可行、复制对象开销太大时，智能指针是唯一选择。

缺点
    引用计数会影响性能
    智能指针不总是智能，需要了解内部原理
    需要小心   环状结构   和   数组指针                         @@@



*/
#include <memory>
#include <iostream>
#include <stdlib.h>
using namespace std;

class Child;
class Parent {
    shared_ptr<Child> child;
public:
    Parent() {cout << "parent constructing" << endl; }
    ~Parent() {cout << "parent destructing" << endl; }
    void setChild(shared_ptr<Child> c) {
        child = c;
    }
};
class Child {
    // shared_ptr<Parent> parent;
    weak_ptr<Parent> parent;
public:
    Child() {cout << "child constructing" << endl; }
    ~Child() {cout << "child destructing" << endl; }
    void setParent(shared_ptr<Parent> p) {
        parent = p;
    }
};

void test() {
    shared_ptr<Parent> p(new Parent());
    shared_ptr<Child> c(new Child());
    p->setChild(c);
    c->setParent(p);
	//p和c被销毁
}

int main()
{
    test();
    return 0;
}


//parent constructing
//child constructing
//没有destructing,内存泄漏
    //因为Parent 与 Child 里的智能指针互相指向对方，计数保持在0
