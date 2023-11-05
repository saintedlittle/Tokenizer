#include <iostream>
#include <vector>
#include "tokenizer/Tokenizer.h"  // Подключаем заголовочный файл для токенизации

using namespace std;
using namespace tokenizer;

int main() {
    vector<Token> tokensInfix;  // Вектор для хранения токенов

    string expr;
    cout << "Specify expression: ";
    getline(cin, expr);  // Запрашиваем у пользователя ввод выражения
    cout << "Expression: " << expr << endl;  // Выводим введенное выражение

    try {
        tokenize(expr, tokensInfix);  // Выполняем токенизацию введенного выражения

        // Красиво выводим токены в консоль
        for (auto& i : tokensInfix) {
            string type, asc;

            // Определяем тип токена и присваиваем соответствующую строку
            switch (i.getType()) {
                case Token::OPERATOR:
                    type = "OPERATOR";
                    break;
                case Token::LParanthesis:
                    type = "LParanthesis";
                    break;
                case Token::RParanthesis:
                    type = "RParanthesis";
                    break;
                case Token::INT_LITERAL:
                    type = "INT_LITERAL";
                    break;
                case Token::FLOAT_LITERAL:
                    type = "FLOAT_LITERAL";
                    break;
                case Token::FUNCTION:
                    type = "FUNCTION";
                    break;
                case Token::SEPARATOR:
                    type = "SEPARATOR";
                    break;
            }

            // Определяем ассоциативность токена и присваиваем соответствующую строку
            switch (i.getAsc()) {
                case Token::NONE:
                    asc = "NONE";
                    break;
                case Token::RIGHT:
                    asc = "RIGHT";
                    break;
                case Token::LEFT:
                    asc = "LEFT";
                    break;
            }

            // Выводим токен, его тип и ассоциативность
            cout << i.getStr() << "\t\t" << type << "\t\t" << asc << "\n";
        }

    }
    catch (Error &e) {
        cerr << e.what() << "\n";  // Обработка ошибок и вывод сообщения об ошибке
        exit(-1);  // Завершаем программу с кодом ошибки
    }
    catch (const exception& e) {
        cerr << e.what() << '\n';  // Обработка исключений стандартной библиотеки
        exit(-1);  // Завершаем программу с кодом ошибки
    }

    return EXIT_SUCCESS;  // Завершаем программу с кодом успешного выполнения
}
