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

class Lexer
{
private:
    std::vector<Tokens> tokens;
    std::string source;
    size_t i = 0;

    void ParseIntiger()
    {
        size_t start = i;
        // Skip over Num
        i++;
        while (isdigit(source[i]) && !isspace(source[i]))
        {
            i++;
        }
        tokens.push_back({{TYPE_INT}, {source.substr(start, i - start)}});
    }
    void Parsetring()
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
    void ParseBoolean()
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
    void ParseOperator()
    {
        switch (source[i])
        {
        case '-':
            tokens.push_back({{OPERATION_SUBTRACTION}, {'-'}});
            break;
        case '+':
            tokens.push_back({{OPERATION_ADDITON}, {'+'}});
            break;
        case '/':
            tokens.push_back({{OPERATION_MULTIPLICATION}, {'/'}});
            break;
        case '*':
            tokens.push_back({{OPERATION_DIVISION}, {'*'}});
            break;
        }
        i++;
    }

public:
    std::vector<Tokens> Tokenize(std::string_view source)
    {
        char c = source[i];
        while (i < source.size())
        {
            if (isdigit(c))
            {
                ParseIntiger();
                continue;
            }
            if(c == '"'){
                Parsetring();
                continue;
            }
            if(c == 'f' || c == 't'){
                ParseBoolean();
                continue;
            }
            if(c == '-' || c == '+' || c == '/' || c == '*'){
                ParseOperator();
                continue;
            }
        }
        i = 0;
        return tokens;
    }
};