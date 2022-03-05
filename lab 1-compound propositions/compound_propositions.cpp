#include <iostream>
#include <cmath>
#include <vector>

int numberOfColumns = 0, numberOfRows = 0;
std::vector<std::vector<char>> input;

enum proposition
{
    CONJUNCTION = 0,
    DISJUNCTION = 1,
    NEGATION = 2,
    IMPLICATION = 3,
    BIIMPLICATION = 4
};

bool countChecker(int count, int p)
{
    if ((p == CONJUNCTION || p == DISJUNCTION) && count < 2)
    {
        std::cout << "This proposition requires at least 2 input variables\n";
        return false;
    }
    if ((p == IMPLICATION || p == BIIMPLICATION) && count != 2)
    {
        std::cout << "This proposition requires only 2 input variables\n";
        return false;
    }
    return true;
}

void printConjunction()
{
    std::cout << "The truth table of conjunction is: \n";
    for (int i = 0; i < numberOfColumns; i++)
    {
        std::cout << static_cast<char>(65 + i) << "\t";
    }
    std::cout << "Output(y)" << std::endl;
    for (int i = 0; i < numberOfRows; i++)
    {
        bool notAND = false;
        for (int j = 0; j < numberOfColumns; j++)
        {
            if (!notAND)
            {
                notAND = input[j][i] == 'F' ? true : false;
            }
            std::cout << input[j][i] << "\t";
        }
        std::cout << (notAND ? 'F' : 'T') << std::endl;
    }
}

void printDisjunction()
{
    std::cout << "The truth table of disjunction is: \n";
    for (int i = 0; i < numberOfColumns; i++)
    {
        std::cout << static_cast<char>(65 + i) << "\t";
    }
    std::cout << "Output(y)" << std::endl;
    for (int i = 0; i < numberOfRows; i++)
    {
        bool Not_OR = true;
        for (int j = 0; j < numberOfColumns; j++)
        {
            if (Not_OR)
            {
                Not_OR = input[j][i] == 'T' ? false : true;
            }
            std::cout << input[j][i] << "\t";
        }
        std::cout << (Not_OR ? 'F' : 'T') << std::endl;
    }
}

void printNegation()
{
    std::cout << "The truth table of negation is: \n";
    for (int i = 0; i < numberOfColumns; i++)
    {
        char label = 65 + i;
        std::cout << label << "\t"
                  << "!" << label << '\t';
    }
    std::cout << std::endl;
    for (int i = 0; i < numberOfRows; i++)
    {
        for (int j = 0; j < numberOfColumns; j++)
        {
            std::cout << input[j][i] << "\t" << (input[j][i] == 'T' ? 'F' : 'T') << "\t";
        }
        std::cout << std::endl;
    }
}

void printImplication()
{
    std::cout << "The truth table of implication is: \n";
    std::cout << "A\tB\tA->B" << std::endl;
    for (int i = 0; i < numberOfRows; i++)
    {
        char impl = 'T';
        if (input[0][i] == 'T' && input[1][i] == 'F')
        {
            impl = 'F';
        }
        std::cout << input[0][i] << '\t' << input[1][i] << "\t" << impl << std::endl;
    }
}

void printBiImplication()
{
    std::cout << "The truth table of implication is: \n";
    std::cout << "A\tB\tA<->B" << std::endl;
    for (int i = 0; i < numberOfRows; i++)
    {
        char biimpl = 'F';
        if (input[0][i] == input[1][i])
        {
            biimpl = 'T';
        }
        std::cout << input[0][i] << '\t' << input[1][i] << "\t" << biimpl << std::endl;
    }
}

int main()
{
    int selectedOption = 0;
    char answer;
    std::cout << "Enter number of input variables" << std::endl;
    std::cin >> numberOfColumns;
    numberOfRows = pow(2, numberOfColumns);
    for (int i = 0; i < numberOfColumns; i++)
    {
        char label = 65 + i;
        std::cout << "Enter values for column " << label << std::endl;
        std::vector<char> row;
        for (int j = 0; j < numberOfRows; j++)
        {
            char temp;
            std::cin >> temp;
            temp == '0' ? temp = 'f' : temp == '1' ? temp = 't'
                                                   : temp = temp;
            row.push_back(toupper(temp));
        }
        input.push_back(row);
    }
    do
    {
        std::cout << "Select a compound proposition: " << std::endl;
        std::cout << "0. Conjunction\n1. Disjunction\n2. Negation\n3. Implication\n4. Bi-Implication\n";
        std::cin >> selectedOption;
        if (!countChecker(numberOfColumns, selectedOption))
            goto skipOnce;
        switch (selectedOption)
        {
        case CONJUNCTION:
            printConjunction();
            break;
        case DISJUNCTION:
            printDisjunction();
            break;
        case NEGATION:
            printNegation();
            break;
        case IMPLICATION:
            printImplication();
            break;
        case BIIMPLICATION:
            printBiImplication();
            break;
        default:
            return 0;
        }
    skipOnce:
        std::cout << "\nCheck another proposition? (y/n)" << std::endl;
        std::cin >> answer;
    } while (tolower(answer) == 'y');
    return 0;
}