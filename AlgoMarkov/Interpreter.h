#pragma once
#include "Substitution.h"

class Interpreter
{
private:
	Substitution** rules;
	int count_rules;
	void clear();
public:
	Interpreter() :rules(nullptr), count_rules(0) {}
	~Interpreter();
	void loadRules(std::istream& stin);
	string run(string P);
	void printOn(ostream& os) const;
};

ostream& operator<<(ostream& os, const Interpreter& Mark);