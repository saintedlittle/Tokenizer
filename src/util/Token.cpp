//
// Created by saintedlittle on 05.11.2023.
//
#include "Token.h"

#include <utility>


tokenizer::Token::Token(string token, tokenizer::Token::Type type, tokenizer::Token::OperatorAssociativity asc) : type{type} , str{std::move(token)} {
    if (type == OPERATOR && asc == NONE)
        throw logic_error("Associativity required!");

        // если токен - НЕ оператор, но ассоциативность задана - ошибка
    else if (type != OPERATOR && asc != NONE)
        throw logic_error("Non-operator token can't have an associativity!");

    opAsc = asc;
}

int tokenizer::Token::getPrecendance() const {
    static map<string, int> op_leftAssociative = {
                    {"+", 2},
                    {"-", 2},
                    {"/", 3},
                    {"*", 3},
                    {"^", 5}
    };


    static map<string, int> op_rightAssociative = {
                    {"-", 4} // унарное отрицание
    };

    // В зависимости от ассоциативности один и тот же символ означает разные операторы
    switch (opAsc) {
        case LEFT:
            // Если str является ключом map-а, значит мы знаем такой оператор
            if(op_leftAssociative.contains(str)) return op_leftAssociative[str];
            else throw Error("Unknown Operator!", Error::Syntax);
        case RIGHT:
            if(op_rightAssociative.contains(str)) return op_rightAssociative[str];
            else throw Error("Unknown Operator!", Error::Syntax);
        case NONE:
            throw logic_error(format("Token \"{}\" is not an operator, impossible.", str));
    }

    throw logic_error(format("Token \"{}\" is not an operator, impossible.", str));

}