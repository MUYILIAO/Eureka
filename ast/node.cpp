#include "ast/node.h"

using namespace pi::ast;

std::map<Mode::Type, string> Node::m_names = {
    {NODE_INTEGER,                "Integer"},
    {NODE_INFIX,                  "Infix"},
    {NODE_EXPRESSION_STATEMENT,   "ExpressionStatement"},
    {NODE_PROGRAM,                "program"},
};

String Node::name() const
{
    auto it = m_names.find(m_type);
    if (it != m_names.end())
    {
        return it->second;
    }
    return "";
}