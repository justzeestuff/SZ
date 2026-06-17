#include <iostream>
#include "../include/lexer.hpp"

int main(){
    std::string source = "ver zee = 17;";
    std::vector<Token> token = Lexer(source);

    int i = 0;
    while (i < source.size()){
        i++;
        std::cout << "["<< token[i].value << "]";
    }
}