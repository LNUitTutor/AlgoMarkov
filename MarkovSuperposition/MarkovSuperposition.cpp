#include <iostream>
#include <fstream>
#include "..\Interpreter\Interpreter.h"

int main()
{
    Interpreter Dec("Decrement.txt");
    Interpreter Rem("RemLeadZero.txt");
    string word;
    do
    {
        std::cout << "\nInput a nonempty string if you want to run: ";
        getline(std::cin, word);
        if (word != "")
        {
            std::cout << "\n P = " << word << "\n\n";
            string Q = Dec.run(word);
            std::cout << "\n Q = " << Q << "\n\n";
            string R = Rem.run(Q);
            std::cout << "\n R = " << R << "\n\n";
            system("pause");
        }
    } while (word != "");
    Interpreter D2U("DecimalToUnary.txt");
    Interpreter Plus("Plus.txt");
    Interpreter Minus("Minus.txt");
    Interpreter U2D("UnaryToDecimal.txt");
    std::cout << "\n Covert 25\n";
    string a = D2U.run("25");
    std::cout << "\n Covert 15\n";
    string b = D2U.run("15");
    std::cout << "\n Calculate summ\n";
    string summ = Plus.run(a + '+' + b);
    std::cout << "\n Covert summ\n";
    std::cout << "25+15 = " << U2D.run(summ) << '\n';
    std::cout << "\n Calculate diff\n";
    string diff = Minus.run(a + '-' + b);
    std::cout << "\n Covert diff\n";
    std::cout << "25-15 = " << U2D.run(diff) << '\n';
    system("pause");
    std::cout << "\n Decimal to Unary by different algorithms\n";
    a = "40";
    std::cout << "\n P = " << a << '\n';
    b = D2U.run(a);
    std::cout << "\n Q = " << b << "\n    |Q| = " << b.length() << '\n';
    std::ifstream fin("DecToUn.txt");
    D2U.loadRules(fin);
    fin.close();
    std::cout << "\n P = " << a << '\n';
    b = D2U.run(a);
    std::cout << "\n Q = " << b << "\n    |Q| = " << b.length() << '\n';
}