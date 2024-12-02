#pragma once

#include "lexer/lexer.h"
using namespace pi::lexer;

#include "ast/header.h"
using namespace pi::ast;

namespace pi
{
    namespace parser
    {
        class Parser
        {
        public:
            enum Precedence         //运算符优先级
            {
                LOWEST = 0,         //最低
                SUM,                //加减法，次一级
                PRODUCT,            //乘除，高一级
            };

            Parser();
            Parser(const std::shared_ptr<Lexer> & lexer);
            ~Parser();

            void next_token();                          //向后遍历的函数
            bool curr_token_is(Token::Type type);       //判断当前token是否是某一种类型
            bool peek_token_is(Token::Type type);       //判断下一个token是否是某一种类型
            bool expect_peek_token(Token::Type type);   //期待下一个token是否是某一种类型，因为当前符号和下一个符号有逻辑关联
            void peek_error(Token::Type type);          //下一个token类型与期待中的不一致时，记录一条错误信息

            int curr_token_precedence();                //当前符号的优先级
            int peek_token_precedence();                //下一个符号的优先级
            void no_prefix_parse_fn_error(Token::Type type);    //没有找到前缀表达式时，记录一条错误
            std::list<string> & errors();               //储存解析过程中的所有错误

            //前缀表达式构建函数原型的定义
            //typedef Expression* (Parser::*prefix_parse_fn)(void);
            typedef std::shared_ptr<Expression> (Parser::*prefix_parse_fn)(void);

            //中缀表达式构建函数原型的定义
            //typedef Expression* (Parser::*infix_parse_fn)(Expression* left);
            typedef std::shared_ptr<Expression> (Parser::*infix_parse_fn)(const std::shared_ptr<Expression> & left);

            //这个环节最重要的一个函数，提取两个括号中间的内容，来构建成一个子树
            std::shared_ptr<Expression> parse_expression(int precedence);

            //根节点,对外提供的接口
            std::shared_ptr<Program> parse_program();
            
            std::shared_ptr<Statement> parse_statement();
            std::shared_ptr<ExpressionStatement> parse_expression_statement();

            //prefix
            std::shared_ptr<Expression> parse_integer();
            std::shared_ptr<Expression> parse_group();
            //infix
            std::shared_ptr<Expression> parse_infix(const std::shared_ptr<Expression> & left);
        
        private:
            std::shared_ptr<Lexer> m_lexer;         //智能指针
            Token m_curr;                           //当前符号
            Token m_peek;                           //下一个符号
            std::list<string> m_errors;             //储存错误
            static std::map<Token::Type, int> m_precedences;                    //符号类型和优先级之间的映射关系
            static std::map<Token::Type, prefix_parse_fn> m_predix_parse_fns;   //符号和前缀表达式之间的映射关系
            static std::map<Token::Type, infix_parse_fn> m_indix_parse_fns;     //符号和中缀表达式之间的映射关系

        };
    }
}
