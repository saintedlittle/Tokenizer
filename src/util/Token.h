//
// Created by saintedlittle on 05.11.2023.
//

#pragma once

#ifndef TOKENIZER_TOKEN_H
#define TOKENIZER_TOKEN_H

#include <string>
#include <map>
#include <format>

#include "Error.h"

using namespace std;

namespace tokenizer {

    class Token {
      public:
        // Тип
        enum Type {
            OPERATOR,      // унарный/бинарный оператор
            LParanthesis, // открывающая скобка
            RParanthesis, // закрывающая скобка
            INT_LITERAL,   // целое число
            FLOAT_LITERAL, // число с плавающей точкой 
            FUNCTION,      // функция
            SEPARATOR      // разделитель аргументов функции
        };

        // Ассоциативность
        enum OperatorAssociativity {
            NONE,  // токен - не оператор
            RIGHT, // правоассоциативный
            LEFT   // левоассоциативный
        };

        Token(string token, Type type, OperatorAssociativity asc = NONE);

        // Приоритет
        int getPrecendance() const;

        const Type& getType() const  { return type; }
        const OperatorAssociativity& getAsc() const { return opAsc; }
        const string& getStr() const { return str; }

      private:
        Type type;
        OperatorAssociativity opAsc;
        string str;
    };

} // tokenizator

#endif //TOKENIZER_TOKEN_H
