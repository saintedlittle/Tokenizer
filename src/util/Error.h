// Класс Error представляет ошибку внутри библиотеки токенизации.
// Created by saintedlittle on 05.11.2023.

#pragma once

#ifndef TOKENIZER_ERROR_H
#define TOKENIZER_ERROR_H

#include <string>

using namespace std;

class Error : exception {
public:
    enum Type {
        Syntax,  // Ошибка в синтаксисе
        Math     // Ошибка в математической операции
    } type;

    /**
     * Реализация ошибки во время токенизации.
     * @param message Cообщение об ошибке.
     * @param errorType Тип ошибки.
     */
    Error(const string& message, Type errorType) : type{errorType} {
        // В зависимости от типа ошибки, формируем сообщение об ошибке.
        switch (errorType) {
            case Syntax:
                msg = "Syntax Error: " + message;
                break;
            case Math:
                msg = "Math Error: " + message;
                break;
        }
    }

    // Переопределение метода what() для получения сообщения об ошибке.
    string what() {
        return msg;
    }

private:
    string msg;  // Сообщение об ошибке
};

#endif //TOKENIZER_ERROR_H
