#ifndef SYMBOL_HPP
#define SYMBOL_HPP

#include <set>
#include <string>
#include <string_view>

#include "literal.hpp"

static const std::set<std::string_view> ACTIONS = {"set", "maximize", "minimize"};
static const std::set<std::string_view> SIGNALS = {"created"};
static const std::set<std::string_view> KEYWORDS = {"equals", "contains", "if", "else", "then", "on"};
static const std::set<std::string_view> OPERATORS = {"&", "|", "!"};
static const std::set<std::string_view> STRUCTURES = {"(", ")"};

class symbol_t
{
public:
    enum class type_t
    {
        END_OF_LINE,
        END_OF_TEXT,
        IDENTIFIER,
        LITERAL,
        OPERATOR,
        KEYWORD,
        STRUCTURAL,
        SIGNAL,
        ACTION,
    };

    using value_t = literal_t::value_t;

    symbol_t(type_t t);
    symbol_t(const literal_t &literal);

    std::string to_string() const;

    type_t type;
    literal_t::type_t literal_type;
    value_t value;
};


#endif // SYMBOL_HPP