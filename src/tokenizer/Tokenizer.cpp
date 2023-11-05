// Created by saintedlittle on 05.11.2023.
//

#include "Tokenizer.h"

namespace tokenizer {

    void tokenize(const string &expr, vector<Token> &tokens) {
        State state = S0;

        string validOperators = "+-*^/";

        bool isDigit, isLetter, isOp, isParanth, isPoint, isSep, isLParanth, isRParanth;

        string buffer;
        Token::Type bufferTokenType = Token::INT_LITERAL;

        for (auto& s : expr) {
            // Определяем тип символа
            isDigit = isdigit(s);
            isLetter = isalpha(s);
            isLParanth = s == '(';
            isRParanth = s == ')';
            isParanth = isLParanth || isRParanth;
            isPoint = s == '.';
            isSep = s == ',';
            isOp = validOperators.find(s) != string::npos;

            // Если тип символа неопределен, значит ошибка в синтаксисе
            if (!(isDigit || isLetter || isParanth || isPoint || isSep || isOp))
                throw Error(format("Unknown symbol: {}", s), Error::Syntax);

            // Смена состояния
            switch(state) {
                case S0:
                    if (isOp || isParanth)
                        state = S1;
                    else if (isDigit)
                        state = S2;
                    else if (isLetter)
                        state = S4;
                    else if (isPoint || isSep)
                        throw Error(format("Unexpected symbol: \"{}\"", s), Error::Syntax);
                    break;
                case S1:
                    if (isDigit)
                        state = S2;
                    else if (isLetter)
                        state = S4;
                    else if (isPoint || isSep)
                        throw Error(format("Unexpected symbol: \"{}\"", s), Error::Syntax);
                    break;
                case S2:
                    bufferTokenType = Token::INT_LITERAL;
                    if (isPoint)
                        state = S3;
                    else if (isParanth || isOp || isSep)
                        state = S5;
                    else if (isLetter)
                        throw Error(format("Unexpected symbol: \"{}\"", s), Error::Syntax);
                    break;
                case S3:
                    bufferTokenType = Token::FLOAT_LITERAL;
                    if (isParanth || isOp || isSep)
                        state = S5;
                    else if (isPoint)
                        throw Error(format("Unexpected symbol: \"{}\"", s), Error::Syntax);
                    break;
                case S4:
                    bufferTokenType = Token::FUNCTION;
                    if(isLParanth)
                        state = S5;
                    else if(isOp || isRParanth || isSep)
                        throw Error(format("Unexpected symbol \"{}\"", s), Error::Syntax);
                    break;
                case S5:
                    if (isParanth || isOp)
                        state = S1;
                    else if (isDigit)
                        state = S2;
                    else if (isLetter)
                        state = S4;
                    else if (isPoint || isSep)
                        throw Error(format("Unexpected symbol: \"{}\"", s), Error::Syntax);
                    break;
                default:
                    break;
            }

            auto tokenize_Op_Paranth_Sep = [&]() {
                if (isOp) {
                    // обработка unary negation
                    if(tokens.empty() || tokens[tokens.size()-1].getType() == Token::LParanthesis)
                        tokens.emplace_back(string{s}, Token::OPERATOR, Token::RIGHT);
                    else
                        tokens.emplace_back(string{s}, Token::OPERATOR, Token::LEFT);
                }
                else if (isParanth) {
                    tokens.emplace_back(string{s}, isRParanth ? Token::RParanthesis : Token::LParanthesis);
                }
                else if (isSep) {
                    tokens.emplace_back(string{s}, Token::SEPARATOR);
                }
            };

            // Действия
            switch (state) {
                case S1:
                    tokenize_Op_Paranth_Sep();
                    break;
                case S2: case S3: case S4:
                    buffer.push_back(s);
                    break;
                case S5:
                    tokens.emplace_back(buffer, bufferTokenType);
                    buffer.clear();
                    tokenize_Op_Paranth_Sep();
                    break;
            }
        }

        if(!buffer.empty())
            tokens.emplace_back(buffer, bufferTokenType);
    }

} // namespace tokenizer
