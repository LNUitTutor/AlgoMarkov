#include <iostream>
#include <fstream>
//#include <string>
#include "Substitution.h"
#include "Interpreter.h"

int main()
{
    const int kRules = 4;
    const int kWords = 3;
    string fileNames[kRules] = { "BubbleSort.txt", "Euclid.txt", "Increment.txt", "UnaryToDecimal.txt" };
    string words[kRules][kWords] = {
        { "2_2_1_3_3_3_2_1_1", "8_2_4_3_9_1_5_7_6", "2_4_6_8" },  // bubble
        { "111111111-111", "11111111111111-111111111111111111111", "11111-11111" }, // Euclid
        { "1998", "1999", "2000" }, // increment
        { "|||||||||||||||||||||||||||||||||||", "||||||||||||||-|||||||||||||||||||||",
          string(125, '|') } // unary2decimal
    };
    Interpreter Mark;
    std::ifstream fin;
    int answer;
    while (true)
    {
        std::cout << "\nSelect an algorithm from:\n\n";
        for (int i = 0; i < kRules; ++i) std::cout << i << " - " << fileNames[i] << '\n';
        std::cout << kRules << " - to exit\n>> ";
        std::cin >> answer;
        if (answer < 0 || answer >= kRules) break;
        fin.open(fileNames[answer]);
        Mark.loadRules(fin);
        fin.close();
        std::cout << Mark << '\n';
        system("pause");
        for (int i = 0; i < kWords; ++i)
        {
            string P = words[answer][i];
            std::cout << " P = " << P << '\n';
            string Q = Mark.run(P);
            std::cout << " Q = " << Q << '\n';
            system("pause");
        }
        string word;
        std::cout << "\nInput a nonempty string if you want to run: ";
        std::cin.get();  getline(std::cin, word);
        if (word != "")
        {
            std::cout << " P = " << word << '\n';
            string Q = Mark.run(word);
            std::cout << " Q = " << Q << '\n';
            system("pause");
        }
    }
    std::cout << "\n *** Bye! ***\n\n";
}
