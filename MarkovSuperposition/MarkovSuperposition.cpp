#include <iostream>
#include <fstream>
#include "..\Interpreter\Interpreter.h"

int main()
{
    Interpreter Mark;
    std::ifstream fin("RemLeadZero.txt");
    Mark.loadRules(fin); fin.close();
    string word;
    do
    {
        std::cout << "\nInput a nonempty string if you want to run: ";
        getline(std::cin, word);
        if (word != "")
        {
            std::cout << " P = " << word << '\n';
            string Q = Mark.run(word);
            std::cout << " Q = " << Q << '\n';
            system("pause");
        }
    } while (word != "");
}