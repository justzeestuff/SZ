#include <vector>
#include <iostream>
#include <string>

enum struct TokenType
{
    VER_INIT,
    VER_NAME,
    VER_VALUE,

    // operators
    COMMA,
    EQUALS
};
struct Token
{
    TokenType type;
    std::string value;
};

std::vector<Token> Lexer(const std::string &source)
{
    int i = 0;
    std::vector<Token> token;

    while (i < source.size())
    {
        if (isspace((unsigned char)source[i]))
        {
            i++;
            continue;
        }

        // init veriable
        if (source.substr(i, i + 3) == "ver")
        {
            token.push_back({{TokenType::VER_INIT}, "-ver"});
            i += 3;

            // Name
            int nameStart = i;
            while (source[i] != '='){ i++; }
            token.push_back({{TokenType::VER_NAME}, "-name"});

            // Assign symbol
            token.push_back({{TokenType::EQUALS}, "-assign"});
            i++; // skip over symbol

            while (isspace(source[i])){ i++; }
            int valueStart = i;

            while (!isspace(source[i])){ i++; }
            token.push_back({{TokenType::VER_VALUE}, '-' + source.substr(valueStart,i)});
            continue;
        } 

        i++;
    }

    return token;
}