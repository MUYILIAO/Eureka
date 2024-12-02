#include "parser/parser.h"
using namespace pi::parser;

std::map<Token::Type, int> Parser::m_precedences =
{   
    {Token::TOKEN_PLUS,         SUM},
    {Token::TOKEN_MINUS,        SUM},
    {Token::TOKEN_ASTERISK,     PRODUCT},
    {Token::TOKEN_SLASH,        PRODUCT},

};

//碰到相应符号，调用回调函数
std::map<Token::Type, Parser::prefix_parse_fn> Parser::m_predix_parse_fns =
{
    {Token::TOKEN_INTEGER,          &Parser::parse_integer},
    {Token::TOKEN_LPAREN,           &Parser::parse_group},          //提升优先级，当作一个子树来处理
};

std::map<Token::Type, Parser::infix_parse_fn> Parser::m_indix_parse_fns =
{
    {Token::TOKEN_PLUS,         &Parser::parse_infix},
    {Token::TOKEN_MINUS,        &Parser::parse_infix},
    {Token::TOKEN_ASTERISK,     &Parser::parse_infix},
    {Token::TOKEN_SLASH,        &Parser::parse_infix},
}; 

Parser::Parser()
{
}

Parser::~Parser()
{
}

Parser::Parser(const std::shared_ptr<Lexer> & lexer)
{
    //初始化的时候，设置当前符号和下一个符号
    next_token;
    next_token;
}

void Parser::next_token()
{
    m_curr = m_peek;
    m_peek = m_lexer->next_token();
}

bool Parser::curr_token_is(Token::Type type)
{
    return m_curr.type() == type;
}

bool Parser::peek_token_is(Token::Type type)
{
    return m_peek.type() == type;
}

bool Parser::expect_peek_token(Token::Type type)
{
    if (peek_token_is(type))
    {
        next_token();
        return true;
    }
    else
    {
        peek_error(type);
        return false;
    }
}

bool Parser::peek_error(Token::Type type)
{
    std::ostringstream oss;             //输出错误至字符串流里面
    oss << "expected next token to be" << type << ", got " << m_peek.type() << "instead;";
    m_errors.push_back(oss.str());      //把错误保存在m_errors
}

//当前符号的优先级
int Parser::curr_token_precedence()
{
    auto it = m_precedences.find(m_curr.type());
    if (it != m_precedences.end())
    {
        return it->second;
    }
    return LOWEST;
}

//下一个符号的优先级
int Parser::peek_token_precedence()
{
    auto it = m_precedences.find(m_peek.type());
    if (it != m_precedences.end())
    {
        return it->second;
    }
    return LOWEST;
}

//没有找到前缀表达式时，记录一条错误
void Parser::no_prefix_parse_fn_error(Token::Type type)
{
    std::ostringstream oss;
    oss << "no predix parse function for " << type;
    m_errors.push_back(oss.str());
}