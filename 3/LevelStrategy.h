#pragma once
#include <string>

class LevelStrategy
{
protected:
    //基础奖金
    int base_salary;
public:
    //成员函数
    int get_base_salary();
    virtual void calc_base_salary() = 0;
};

class P1LStrategy : public LevelStrategy
{
public:
    void calc_base_salary() override;
};

class P2LStrategy : public LevelStrategy
{
public:
    void calc_base_salary() override;
};

class P3LStrategy : public LevelStrategy
{
public:
    void calc_base_salary() override;
};