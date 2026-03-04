#include "Substitution.h"

void Substitution::printOn(ostream& os) const
{
	os << left << " --> " << right << '\n';
}

Continuation Substitution::applyTo(string& s) const
{
	unsigned pos = s.find(left);
	if (pos == string::npos) return Continuation::next;
	s.erase(pos, left.length()).insert(pos, right);
	return this->next_rule();
}

ostream& operator<<(ostream& os, const Continuation& c)
{
	switch (c)
	{
	case Continuation::first: os << "first"; break;
	case Continuation::next: os << "next"; break;
	case Continuation::last: os << "last"; break;
	default: os << "Continuation::Error"; break;
	}
	return os;
}

ostream& operator<<(ostream& os, const Substitution& sub)
{
	sub.printOn(os);
	return os;
}

void FinalSubstitution::printOn(ostream& os) const
{
	os << left << " ->. " << right << '\n';
}
