#pragma once

#include "token/token.h"
using namespace pi::token;

#include <string>
#include <map>

using std::string;

//词法分析器
namespace pi
{
    namespace lexer
    {
        class Lexer
        {
            public:
                Lexer();
                Lexer(const string & file);
                ~Lexer()= default;

                Token next_token();                 //最重要，唯一被下阶段语法分析器调用，提取各个符号

            private:
                void skip_white_space();            //忽略某些空白符 
                void read_char();                   //读取下一个字符
                void unread_char();                 //为了后续操作方便
                bool is_digit(char ch);             //判断当前字符是否是数字
                string read_number();               //返回整数
                Token new_token(Token::Type type, const string &literal);   //创建一个token

            private:
                string        m_input;            //file文件里的文本内容
                char          m_ch;               //当前遍历到的字符
                int           m_pos;              //当前字符的位置
                int           m_next_pos;         //下一个字符的位置
        };
    }
}