#include "Calculator.h"
//构造函数
Calculator::Calculator(LevelStrategy *ls, PerformStrategy *ps) : m_pStrategy(ps), m_lStrategy(ls)
{
}

//成员函数
int Calculator::get_base()
{
    m_lStrategy->calc_base_salary();
    m_base = m_lStrategy->get_base_salary();
    return m_base;
}

int Calculator::get_total(int bs)
{
    m_pStrategy->calc_bonus_salary(bs);
    m_bonus = m_pStrategy->get_bonus_salary();
    return m_base + m_bonus;
}
