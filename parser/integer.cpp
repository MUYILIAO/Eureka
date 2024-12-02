#include "parser/parser.h"

using namespace pi::parser;

//防止parser.cpp太大了，单独定义构造重要函数
std::shared_ptr<Expression> Parser::parse_integer()     //返回对象是ats/integer.h中定义的Integer类型的节点
{
    std::shared_ptr<Integer> e(new Integer());
    e->m_token = m_curr;
    e->m_value = std::atol(m_curr.literal().c_str());   //把当前自变量从字符串切换为整数
    /*
    literal() 函数的返回值通常是一个字符串，表示某种文本内容。
    c_str() 是一个 C++ 标准库的成员函数，它将 std::string 类型的字符串转换为 C 风格的字符串（即字符数组 const char*）。
    std::atol() 是一个标准库函数，用于将 C 风格字符串（const char*）转换为长整型（long），
    它的返回值是 long 类型。如果字符串的内容无法转换为有效的数字，atol 会返回 0。
    */
    return e;
};