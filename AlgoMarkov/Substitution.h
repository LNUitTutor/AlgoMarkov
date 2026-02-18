#pragma once
#include <string>
#include <iostream>
using std::string;
using std::ostream;

enum class Continuation { first, next, last };
ostream& operator<<(ostream& os, const Continuation& c);

class Substitution
{
protected:
	string left, right;
	virtual Continuation next_rule() const
	{
		return Continuation::first;
	}
public:
	Substitution(string l, string r): left(l), right(r) {}
	Substitution(const char* l, const char* r) : left(l), right(r) {}
	Substitution(const char* l) : left(l), right("") {}
	virtual void printOn(ostream& os) const;
	Continuation applyTo(string& s) const;
};

class FinalSubstitution :public Substitution
{
private:
	virtual Continuation next_rule() const override
	{
		return Continuation::last;
	}
public:
	FinalSubstitution(string l, string r) : Substitution(l, r) {}
	FinalSubstitution(const char* l, const char* r) : Substitution(l, r) {}
	FinalSubstitution(const char* l) : Substitution(l, "") {}
	virtual void printOn(ostream& os) const;
};

ostream& operator<<(ostream& os, const Substitution& sub);