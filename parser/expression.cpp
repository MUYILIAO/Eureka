//抽象语法树构建和语法分析这个环节最重要的一个函数，提取两个括号中间的内容，来构建成一个子树
//传入值为优先级，返回值为表达式
#include "parser/parser.h"

using namespace pi::parser;

std::shared_ptr<Expression> Parser::parse_expression(int precedence)
{
    //首先在前缀表达式里面查找当前符号
    //一般情况下必须要能找到，到不到就是因为该符号未定义
    auto prefix = m_predix_parse_fns.find(m_curr.type());
    if (prefix == m_predix_parse_fns.end())
    {
        no_prefix_parse_fn_error(m_curr.type());        //没有找到当前的前缀表达式的处理函数
        return nullptr;
    }
    //调用找到的当前前缀表达式回调函数 
    std::shared_ptr<Expression> e = (this->*(prefix->second))();

    //检查下一个符号
    //符号既不是;分号而且优先级小于下一个符号的优先级，那就应该是一个中缀表达式
    while (!peek_token_is(Token::TOKEN_SEMICOLON) && precedence < peek_token_precedence())
    {
        auto infix = m_indix_parse_fns.find(m_peek.type());
        if (infix == m_indix_parse_fns.end())
        {
            return e;           //如果没在中缀表达式的map里找到，那就是一个前缀表达式，返回即可
        }
        next_token();
        
        e = (this->*(prefix->second))(e);       //前面生成的前缀表达式作为参数传入中缀表达式
    }
    return e;

}