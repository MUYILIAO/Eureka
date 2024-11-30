#pragma once

#include "ast/node.h"

//中缀表达式
namespace pi
{
    namespace ast
    {
        class Infix : public Expression
        {
        public:
            Infix() : Expression(NODE_INFIX) {}
            ~Infix() {}

        public:                                                 //public是为了操作这个类的数据成员方便，原则上应该私有，然后使用get\set之类的方法进行操作
            string m_operator;                                  //运算符
            //Expression * m_left;                              //左边的表达式
            //Expression * m_right;                             //右边的表达式
            std::shared_ptr<Expression> m_left;                 //为了内存管理方便，使用智能指针,头文件为memory
            std::shared_ptr<Expression> m_right;               
        };

    }

}