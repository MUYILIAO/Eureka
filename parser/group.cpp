#include "parser/parser.h"

using namespace pi::parser;

std::shared_ptr<Expression> Parser::parse_group()
{
    next_token();
    auto e = parse_expression(LOWEST);
    if (!expect_peek_token(Token::TOKEN_RPAREN))
    {
        return nullptr;
    }
    return e;
}