#include "include.hpp"

enum TokenTypes
{
    // DataTpes
    TYPE_INT,
    TYPE_STRING,
    TYPE_BOOLEAN,

    OPERATION_ADDITON,
    OPERATION_SUBTRACTION,
    OPERATION_MULTIPLICATION,
    OPERATION_DIVISION,
};

struct Tokens
{
    TokenTypes type;
    std::string value;
};

std::vector<Tokens> Lexer(const std::string &source)
{
    std::vector<Tokens> tokens;
    int i = 0;
    while (i < source.size())
    {
        // Remove empty strings

        // DataTypes

        // --Intiger
        if (isdigit(source[i]))
        {
            int start = i;
            // Skip over Num
            i++;

            while (isdigit(source[i]) && !isspace(source[i]))
            {
                i++;
            }
            tokens.push_back({{TYPE_INT}, {source.substr(start, i - start)}});
        }

        // --Strings
        if (source[i] == '"')
        {
            int start = i;
            // Skip over String
            i++;

            while (source[i] != '"')
            {
                i++;
            }
            tokens.push_back({{TYPE_STRING}, {source.substr(start, i - start + 1)}});
            i++; // move on from the string
        }

        // --Booleans
        if (source[i] == 't' || source[i] == 'f')
        {
            std::string trueCheck = "true";
            std::string falseCheck = "false";

            int j = 0;

            if (source[i] == 't')
            {
                while (source[i] == trueCheck[j] && j < trueCheck.size())
                {
                    j++;
                    i++;
                }
                if (j == trueCheck.size())
                    tokens.push_back({{TYPE_BOOLEAN}, {'1'}});
            }
            else
            {
                while (source[i] == falseCheck[j] && j < falseCheck.size())
                {
                    j++;
                    i++;
                }
                if (j == falseCheck.size())
                    tokens.push_back({{TYPE_BOOLEAN}, {'0'}});
            }
        }

        // arthmetic operations
        if (source[i] == '-' || source[i] == '+' || source[i] == '/' || source[i] == '*')
        {
            tokens.push_back({{OPERATION_SUBTRACTION}, {'-'}});
            // switch (source[i])
            // {
            // case '-': tokens.push_back({{OPERATION_SUBTRACTION}, {'-'}}); break;
            // case '+': tokens.push_back({{OPERATION_ADDITON}, {'+'}}); break;

            // case '*': tokens.push_back({{OPERATION_DIVISION}, {'*'}}); break;
            // case '/': tokens.push_back({{OPERATION_MULTIPLICATION}, {'/'}}); break;
            // }
        }

        // Move on
        if (isspace(source[i])) { i++; }
    }

    return tokens;
}