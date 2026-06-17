#include <iostream>
#include <vector>

enum class TokenType{
    INIT_VER,
    VER_NAME,
    VER_ASSIGN,
    VER_VALUE,
    
    SEMICOLOM
};

struct Token{
    TokenType token;
    std::string value;
};

std::vector<Token> Lexer(const std::string &source){
    std::vector<Token> token;
    int i = 0;
    while (i < source.size()){  
        // skip empty
        if(isspace(source[i])) i++;

        // Veriable initialization
    }    

    return token;
}