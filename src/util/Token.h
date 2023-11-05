// Класс Token представляет токен в библиотеке токенизации.
// Created by saintedlittle on 05.11.2023.

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
        // Типы токенов
        enum Type {
            OPERATOR,      // Унарный/бинарный оператор
            LParanthesis, // Открывающая скобка
            RParanthesis, // Закрывающая скобка
            INT_LITERAL,   // Целое число
            FLOAT_LITERAL, // Число с плавающей точкой
            FUNCTION,      // Функция
            SEPARATOR      // Разделитель аргументов функции
        };

        // Ассоциативность операторов
        enum OperatorAssociativity {
            NONE,  // Токен не является оператором
            RIGHT, // Правоассоциативный оператор
            LEFT   // Левоассоциативный оператор
        };

        /**
         * Конструктор класса Token.
         * @param token Строковое представление токена.
         * @param type Тип токена (оператор, скобка, число и т. д.).
         * @param asc Ассоциативность оператора (RIGHT, LEFT) по умолчанию NONE.
         */
        Token(string token, Type type, OperatorAssociativity asc = NONE);

        /**
         * Возвращает приоритет оператора.
         * @return Приоритет оператора.
         */
        int getPrecendance() const;

        /**
         * Получает тип токена.
         * @return Тип токена (OPERATOR, LParanthesis и т. д.).
         */
        const Type& getType() const  { return type; }

        /**
         * Получает ассоциативность оператора.
         * @return Ассоциативность оператора (RIGHT, LEFT, NONE).
         */
        const OperatorAssociativity& getAsc() const { return opAsc; }

        /**
         * Получает строковое представление токена.
         * @return Строковое представление токена.
         */
        const string& getStr() const { return str; }

    private:
        Type type;                   // Тип токена
        OperatorAssociativity opAsc; // Ассоциативность оператора
        string str;                  // Строковое представление токена
    };

} // namespace tokenizer

#endif //TOKENIZER_TOKEN_H
