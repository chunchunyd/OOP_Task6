#pragma once
#include <list>
#include <vector>
#include <iostream>
#include <memory>

#include "CustomClass.h"

class Object;

class Content
{
public:
	virtual void output(std::ostream& out){ //virtual function for output
		std::cout << "the operator is not supported for this type." << std::endl;	//沒有重寫覆蓋説明不支持
	}
};

class IntContent: public Content
{
private:
	int x;
public:
	IntContent(int _x): x(_x) {}
	void output(std::ostream& out){ //???-->不能加const
		out << x;
	}
	void operator+=(int y){
		x += y;
	}
};

class StringContent: public Content
{
private:
	std::string x;
public:
	StringContent(std::string _x): x(_x) {}
	void output(std::ostream& out){ 
		out << x;
	}
	void operator+=(std::string y){
		x += y;
	}
};

// The following codes are not working
class VectorContent: public Content
{
private:
	std::vector<Object> x; //Object is not defined???	-->	先声明
public:
	VectorContent(const std::vector<Object>& _x): x(_x) {}
};


class CustomContent: public Content
{
private:
	CustomClass x;
public:
	CustomContent(const CustomClass& _x): x(_x) {}
};



class Object
{
private:
	std::shared_ptr<Content> pt;

public:
//构造函数	
	Object() {}
	Object(int x) {
		pt = std::make_shared<IntContent>(x); // where to delete? maybe use std::shared_ptr?
	}
	Object(const std::string &x):pt(new StringContent(x)){
	}
	Object(const CustomClass &x):pt(std::make_shared<CustomContent>(x)){
	}
	// The following codes are not working
	// Object(const std::vector<Object> &x){
	// 	pt = new VectorContent(x);
	// }
	
//析构函数
	~Object(){
		pt.reset();
	}


	friend std::ostream& operator<<(std::ostream& out, const Object& obj) {
		obj.pt->output(out);
		return out;
	}

	Object& operator+=(int y){
		*std::dynamic_pointer_cast<IntContent>(pt)+=y;			//基类、派生类的智能指针相互转化
		return *this;
	}
	Object& operator+=(const std::string &y){
		std::dynamic_pointer_cast<StringContent>(pt)->operator+=(y);
		return *this;
	}

	//need more operators......
};
