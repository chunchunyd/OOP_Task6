#pragma once
#include <string>
#include "PerformStrategy.h"
#include "LevelStrategy.h"


class Calculator
{   
    //储存数据的成员变量
    int m_base,m_bonus; //基础，基础+bonus
    //获取各类不同信息的策略类
    PerformStrategy * m_pStrategy;
    LevelStrategy * m_lStrategy;

public:
    //构造函数
    Calculator(LevelStrategy * ls, PerformStrategy * ps);

    //成员函数
    int get_base();
    int get_total(int bs);
};