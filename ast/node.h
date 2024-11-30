/*所有结点的抽象*/
#pragma once

#include <memory>       //为了内存管理方便，使用智能指针
#include <list>         //储存program这个根节点的其他语句

#include "token/token.h"

using namespace pi::token;

namespace pi
{
    namespace ast
    {   
        //所有结点的抽象
        class Node
        {
        public:
            enum type
            {
                NODE_INTEGER = 0,
                NODE_INFIX,                            //中缀表达式
                NODE_EXPRESSION_STATEMENT,             //表达式、语句，为了语法树完整做的包装转换
                NODE_PROGRAM,                          //根节点
            };

            Node() {}
            Node(Type type) : m_type(type) {}
            virtual ~Node() {}
            
            //获取抽象节点树的类型和名称
            Type type() const { return m_type; }
            string name() const;

        public:
            Type m_type;
            Token m_token;                              //如果是数字类型就调用INTEGER,如果是加减乘除类型等就调用中缀表达式
            static std::map<Type, string> m_names;      //静态枚举类型和名称

        };

        //表达式，大致就是数字和加减乘除之类的
        class Expression :public Node
        {
        public:
            Expression() :Node() {}
            Expression(Type type) :Node(type) {}
            ~Expression() {}
        };

        //语句
        class Statement :public Node
        {
        public:
            Statement() :Node() {}
            Statement(Type type) :Node(type) {}
            ~Statement() {}
        };
        
    }
    
}