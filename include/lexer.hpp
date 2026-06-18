#include "include.hpp"

enum struct TokenType{
    VERIABLE
};
struct Token{
    TokenType type;
    std::string value;
};

std::vector<Token> Lexer(const std::string &source){
    int i = 0;
    std::vector<Token> token;

    while(i < source.size()){
        if(isspace(source[i])) i++; continue;

        // declare Veriable
        if(source.substr(i,i+2) == "ver"){
            token.push_back({{TokenType::VERIABLE}, "ver"});
            continue;
        }
    }

    return token;
}