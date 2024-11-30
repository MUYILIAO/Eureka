#pragma once

#include "ast/node.h"

/*为了抽象语法树结构的完整，把一个表达式Expression包装成语句Statement，从而使其能挂载在根节点program下面*/
/*还有一种思路做法就是只有表达式，没有语句，也就没有这个问题，不需要转换*/
namespace pi
{   
    namespace ast
    {
        class ExpressionStatement : public Statement
        {
        public:
            ExpressionStatement() : Node(NODE_EXPRESSION_STATEMENT) {}
            ~ExpressionStatement() {}
        
        public:
            std::shared_ptr<Expression> m_expression;

        };

    }
    
}
