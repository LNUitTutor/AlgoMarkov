#include "Interpreter.h"

void Interpreter::clear()
{
	for (int i = 0; i < count_rules; ++i) delete rules[i];
	delete[] rules;
}

Interpreter::~Interpreter()
{
    clear();
}

void Interpreter::loadRules(std::istream& stin)
{
    clear();
	(stin >> count_rules).get();
	rules = new Substitution* [count_rules];
	char kind; string left, right;
	for (int i = 0; i < count_rules; ++i)
	{
		(stin >> kind >> left >> right).get();
        if (left == "_/\\_") left = "";
        if (right == "_/\\_") right = "";
		if (kind != '.') rules[i] = new Substitution(left, right);
		else rules[i] = new FinalSubstitution(left, right);
	}
}

string Interpreter::run(string P)
{
    int curr = 0;
    int steps = 0;
    while (curr < count_rules)
    {
        char answer;
        Continuation res = rules[curr]->applyTo(P);
        switch (res)
        {
        case Continuation::first:
            ++steps;
            std::cout.width(2);
            std::cout << curr << ": " << P << '\n';
            curr = 0;
            break;
        case Continuation::next: ++curr;
            break;
        case Continuation::last:
            std::cout.width(2);
            std::cout << curr << ": " << P << '\n';
            curr = count_rules;
            break;
        default:
            break;
        }
        if (steps >= 100)
        {
            std::cout << "More or equal 100 productions were executed. Do you want to continue (y/n)? ";
            std::cin >> answer;
            if (answer == 'y') steps = 0;
            else curr = count_rules;
        }
    }
    return P;
}

void Interpreter::printOn(ostream& os) const
{
	os << "------------------------------\n";
    for (int i = 0; i < count_rules; ++i)
    {
        os.width(2);;
        os << i << ") ";
        rules[i]->printOn(os);
    }
	os << "------------------------------\n";
}

ostream& operator<<(ostream& os, const Interpreter& Mark)
{
    Mark.printOn(os);
    return os;
}
