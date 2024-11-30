#pragma once

#include "ast/node.h"

//根节点，里面包含的是一条语句，表达式Expression通过expression_statement.h文件中的方法包装成语句Statement后也可以兼容
namespace pi
{
    namespace ast
    {
        class Program : public Statement
        {
        public:
            Program() : Statement(NODE_PROGRAM) {}
            ~Program() {}

        public:
            //std::list<Statement *> m_statements;
            std::list<std::shared_ptr<Statement>> m_statements;             //还是为了方便内存管理

        };

    }

}