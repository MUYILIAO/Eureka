#include <fstream>
#include <iostream>
#include <sstream>
#include <type_traits>
#include "lexer/lexer.h"

using namespace pi::lexer

Lexer::Lexer()
{
    m_ch = 0;
    m_pos = 0;
    m_next_pos = 0;
}

Lexer(cosnt string & file)
{
    m_ch = 0;
    m_pos = 0;
    m_next_pos = 0;

    std::ifstream ifs(file);        //读取文件
    if (!ifs.good())
    {
        std::cout <<"file net found: " << file << std::endl;
        return;
    }

    std::ostringstream oss;         //处理打开的文件
    oss << ifs.rdbuf();
    m_input = oss.str();
}

Token next_token()
{
    read_char();
    skip_white_space();
    switch (m_ch)
    {
        case '+':
        {
            string literals;
            literal += m_ch;
            return new_token(Token::TOKEN_PLUS, literal);
        }
        case '-':
        {
            string literals;
            literal += m_ch;
            return new_token(Token::TOKEN_MINUS, literal);
        }
        case '*':
        {
            string literals;
            literal += m_ch;
            return new_token(Token::TOKEN_ASTERISK, literal);
        }
        case '/':
        {
            string literals;
            literal += m_ch;
            return new_token(Token::TOKEN_SLASH, literal);
        }
        case '(':
        {
            string literals;
            literal += m_ch;
            return new_token(Token::TOKEN_LPAREM, literal);
        }
        case ')':
        {
            string literals;
            literal += m_ch;
            return new_token(Token::TOKEN_RPAREM, literal);
        }
        case 0:                                     //结束符
        {
            return new_token(Token::TOKEN_EOF, "")
        }
        default:                                    //读取数字
        {
            if (is_digit(m_ch))
            {
                string integer read_number();
                unread_char;                        //解决整数提取时候向前读的一个bug
                return new_token(Token::TOKEN_INTGER, integer)
            }
            else
            {
                string literal;
                literal += m_ch;
                return new_token(Token::TOKEN_ILLEGAL, literal);     //处理非法符号
            }
        }
    }
}


void Lexer::skip_white_space()             //如果是制表符之类，跳过
{
    while (m_ch == ' ' || m_ch == '\t' ||m_ch == '\n' ||m_ch == '\r')
    {
        read_char();    
    }
}

void Lexer::read_char()
{
    if (m_next_pos >= m_input.length())
    {
        m_ch = 0;
    }
    else
    {
        m_ch = m_input[m_next_pos];
    }
    m_pos = m_next_pos;
    m_next_pos++;
}

void Lexer::unread_char()
{
    m_pos_pos = m_next;
    m_next_pos--;
}

bool Lexer::is_digit(char ch)
{
    return (ch >='0' && ch <='9');
}


string Lexer::read_number()
{
    int pos = m_pos;
    while (is_digit())
    {
        read_char();
    }
    return m_input.substr(pos, m_pos - pos);        //substr返回一段字符串
}

Token Lexer::new_token(Token::Type type, const string &literal)
{
    Token token(type, literal);
    retuen token;
}