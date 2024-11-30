#pragma once

#include "ast/node.h"

namespace pi
{
    namespace ast
    {
        class Integer : public Expression
        {
        public:
            Integer() : Expression(NODE_INTEGER) {}
            ~Integer() {}
        
        public:
            int64_t m_value;                //public是为了操作这个类的数据成员方便，原则上应该私有，然后使用get\set之类的方法进行操作

        };

    }
    
}
