#include "token/token.h"

using namespace pi::token;

std::map<Token::Type, string> Token::m_names = {
    {TOKEN_ILLEGAL,     "illegal"},
    {TOKEN_EOF,          "eof"},
    {TOKEN_INTEGER,      "integer"},
    {TOKEN_PLUS,         "+"},
    {TOKEN_MINUS,        "-"},
    {TOKEN_ASTERISK,     "*"},
    {TOKEN_SLASH,        "/"},
    {TOKEN_LPAREN,       "("},
    {TOKEN_RPAREN,       ")"},
    {TOKEN_SEMICOLIN,    ";"}, 
};

Token::Token() : m_type(TOKEN_ILLEGAL)
{

}

Token::Token(Type type, const string & literal) :  m_type(type), m_literal(literal)
{
    
}

//获取类型
Token::Type Token::type() const;
{
    return m_type;
}

//获取名称
string Token::name() const;
{
    auto it = m_names.find(m_types);    //调用find查找类型
    if (it != m_name.end())             //map迭代器如果找到答案，就不等于end
    {
        retuen it->second;
    }
    retuen "";
}

//获取自变量
string Token::literal() const;    
{
    return m_literal;
}

//赋值
Token & Token::operator = (const Token & other);
{
    if (this == &other)      //如果相等返回自身
    {
        return *this;
    }
    m_type = other.m_type;
    m_literal = other.mliteral;
    return *this;
}

//查看token具体内容
void Token::show () const
{
    printf("type = %d name = %s literal = %s\n", m_type, name().c_str(), literal().c_str())
}