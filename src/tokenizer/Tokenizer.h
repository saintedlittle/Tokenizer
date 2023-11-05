//
// Created by saintedlittle on 05.11.2023.
//

#pragma once

#ifndef TOKENIZER_TOKENIZER_H
#define TOKENIZER_TOKENIZER_H

#include <iostream>
#include <vector>
#include <format>
#include <map>
#include <string>

#include "../util/Error.h"
#include "../util/Token.h"

using namespace std;

namespace tokenizer {

    enum State {
        S0, // Стартовое
        S1, // Токенизация скобки/оператора
        S2, // Запись целого числа в буфер
        S3, // Запись floating-point числа в буфер
        S4, // Запись функции в буфер
        S5  // Токенизация записанного числа/функции из буфера
    };

    /**
    * Токенизирует входное выражение и сохраняет токены в векторе.
    *
    * @param expr Входное математическое выражение в виде строки.
    * @param tokens Вектор для хранения токенов.
    */
    void tokenize(const string &expr, vector<Token> &tokens);

} // tokenizer

#endif //TOKENIZER_TOKENIZER_H
