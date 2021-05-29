#pragma once
#include <string>

class PerformStrategy
{
protected:
    //成员变量
    double p_perform;       //绩效
    int bonus_salary;       //bonus,向下取整
public:
    //构造函数
    PerformStrategy(double perform);

    //成员函数
    int get_bonus_salary();
    virtual void calc_bonus_salary(int bs) = 0;
};

class sPerformStrategy : public PerformStrategy
{
public:
    using PerformStrategy::PerformStrategy;
    void calc_bonus_salary(int bs) override;
};

class mPerformStrategy : public PerformStrategy
{
public:
    using PerformStrategy::PerformStrategy;
    void calc_bonus_salary(int bs) override;
};

class lPerformStrategy : public PerformStrategy
{
public:
    using PerformStrategy::PerformStrategy;
    void calc_bonus_salary(int bs) override;
};