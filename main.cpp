#include "include/include.hpp"
#include "include/lexer.hpp"

void CheckProgram(std::string type, std::string value);

int main()
{
    const std::string source = "-";
    std::vector<Tokens> tokens = Lexer(source);

    for (int i = 0; i < tokens.size(); i++)
    {
        const std::string value = tokens[i].value;

        switch (tokens[i].type)
        {
            // Data types
            case 0: CheckProgram("int", value); break;
            case 1: CheckProgram("str", value); break;
            case 2: CheckProgram("boolean", value); break;

            // arthmetic operations
            case 3: CheckProgram("ADDITION", value); break;
            case 4: CheckProgram("SUBTRACTION", value); break;
            case 5: CheckProgram("MULTIPLICATION", value); break;
            case 6: CheckProgram("DIVISION", value); break;
        }
    }
}

void CheckProgram(std::string type, std::string value)
{
    std::cout << type << '-' << value << ',' << '\n';
}