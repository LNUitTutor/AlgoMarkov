#include <iostream>
#include <fstream>
#include "Substitution.h"
#include "Interpreter.h"

int main()
{
    Interpreter Mark;
    std::ifstream fin("Euclid.txt");
    Mark.loadRules(fin);
    fin.close();
    std::cout << Mark << '\n';

    string P("1111-111111");
    std::cout << " P = " << P << '\n';
    string Q = Mark.run(P);
    std::cout << " Q = " << Q << '\n';
    system("pause");
    /*
    P = "111111111-111";
    std::cout << "\n P = " << P << '\n';
    Q = Mark.run(P);
    std::cout << " Q = " << Q << '\n';
    system("pause");

    P = "11111111111111-111111111111111111111";
    std::cout << "\n P = " << P << '\n';
    Q = Mark.run(P);
    std::cout << " Q = " << Q << '\n';
    system("pause");

    fin.open("Increment.txt");
    Mark.loadRules(fin);
    fin.close();
    std::cout << Mark << '\n';
    system("pause");

    P = "1998";
    std::cout << "\n P = " << P << '\n';
    for (int i = 0; i < 5; ++i)
    {
        P = Mark.run(P);
        std::cout << " Q = " << P << '\n';
        system("pause");
    }
*/
    fin.open("UnaryToDecimal.txt");
    Mark.loadRules(fin);
    fin.close();
    std::cout << Mark << '\n';
    system("pause");

    P = "|||||||||||||||||||||||||||||||||||";
    std::cout << "\n P = " << P << '\n';
    Q = Mark.run(P);
    std::cout << " Q = " << Q << '\n';
    system("pause");

    P = "||||||||||||||-|||||||||||||||||||||";
    std::cout << "\n P = " << P << '\n';
    Q = Mark.run(P);
    std::cout << " Q = " << Q << '\n';
    system("pause");
    P = string(125, '|');
    std::cout << "\n P = " << P << '\n';
    Q = Mark.run(P);
    std::cout << " Q = " << Q << '\n';
    system("pause");

    fin.open("BubbleSort.txt");
    Mark.loadRules(fin);
    fin.close();
    std::cout << Mark << '\n';
    system("pause");

    P = "221333211";
    std::cout << "\n P = " << P << '\n';
    Q = Mark.run(P);
    std::cout << " Q = " << Q << '\n';
    system("pause");

    P = "824391576";
    std::cout << "\n P = " << P << '\n';
    Q = Mark.run(P);
    std::cout << " Q = " << Q << '\n';
    system("pause");
}
