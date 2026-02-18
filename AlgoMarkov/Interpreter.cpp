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
    while (curr < count_rules)
    {
        Continuation res = rules[curr]->applyTo(P);
        switch (res)
        {
        case Continuation::first:
            std::cout << curr << ": " << P << '\n';
            curr = 0;
            break;
        case Continuation::next: ++curr;
            break;
        case Continuation::last:
            std::cout << curr << ": " << P << '\n';
            curr = count_rules;
            break;
        default:
            break;
        }
    }
    return P;
}

void Interpreter::printOn(ostream& os) const
{
	os << "------------------------------\n";
    for (int i = 0; i < count_rules; ++i)
    {
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
