#include <iostream>
#include <vector>

#include "tokenizer/Tokenizer.h"

using namespace std;
using namespace tokenizer;

int main() {
    vector<Token> tokensInfix;

    string expr = "log2(23)+(2/(3.14))*(sqrt(0.1*10^(-3)/0.02))";
    cout << "Expression: " << expr << endl;

    try {
        tokenize(expr, tokensInfix);
        // Красиво печатаем токены в консоль
        for (auto& i : tokensInfix) {
            string type, asc;
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
                    type = "OPERATOR";
                    break;
            }

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
            cout << i.getStr() << "\t\t" << type << "\t\t" << asc << "\n";
        }

    }
    catch (Error &e) {
        cerr << e.what() << "\n";
        exit(-1);
    }
    catch (const exception& e) {
        cerr << e.what() << '\n';
        exit(-1);
    }

    return EXIT_SUCCESS;
}