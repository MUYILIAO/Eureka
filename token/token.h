#pragma once

#include <string>
#include <map>

using std::string;


namespace pi
{
    namespace token
    {
        class Token
        {
        public:
            enum Type
            {
                TOKEN_ILLEGAL = 0,   //illegal   非法输入
                TOKEN_EOD,          //eof       结束
                TOKEN_INTEGER,      //integer   整数
                TOKEN_PLUS,         // +        加减乘除
                TOKEN_MINUS,        // -
                TOKEN_ASTERISK,     // *
                TOKEN_SLASH,        // /
                TOKEN_LPAREN,       // (        括号
                TOKEN_RPAREN,       // )
                TOKEN_SEMICOLON,    // ;        分号
            };

            Token();
            Token(Type type, const string & literal);

            ~Token() = default;

            //成员方法
            Type type() const;      //获取类型
            string name() const;    //获取名称
            string literal() const;    //获取自变量

            Token & operator = (const Token & other);   //赋值

            void show() const;          //查看具体的token内容


            private:
                //成员数据
                Type m_type;            //类型
                string m_literal;       //自变量

                static std::map<Type, string> m_names;  //类型和自变量的映射
        };
    }
}