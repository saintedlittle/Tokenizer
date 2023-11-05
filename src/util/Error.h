//
// Created by saintedlittle on 05.11.2023.
//

#pragma once

#ifndef TOKENIZER_ERROR_H
#define TOKENIZER_ERROR_H

#include <string>

using namespace std;

class Error : exception {
    public:
        enum Type {
            Syntax,
            Math
        } type;

        Error(const string& message, Type errorType) : type{errorType} {
            switch (errorType) {
                case Syntax:
                    msg = "Syntax Error: " + message;
                    break;
                case Math:
                    msg = "Math Error: " + message;
                    break;
            }
        }

        string what() {
            return msg;
        }

    private:
        string msg;
};

#endif //TOKENIZER_ERROR_H
