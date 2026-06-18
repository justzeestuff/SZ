#include "include.hpp"
#include "./include/lexer.hpp"

int main(){
    std::string source = "ver zee = 17";
    std::vector<Token> tokens = Lexer(source);
    
    for (int i = 0; i < tokens.size(); i++)
    {
        std::cout << static_cast<int>(tokens[i].type);
    }
    
    return 0;
}