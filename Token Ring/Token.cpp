#include "Token.h"

Token::Token(std::string source, std::string destination, std::string msg, int nrComp)
{
	sourceIP = source;
	destinationIP = destination;
	message = msg;
	reachedDestination = false;
	isFree = false;
	compNr = nrComp;
}

void Token::parse(std::string computerA, std::string computerB)
{
	history.push_back(computerA);
	if (computerA.compare(destinationIP) == 0)
	{
		reachedDestination = true;
	}
	if (history.size() == compNr + 1)
	{
		isFree = true;
	}
}

bool Token::getIsFree()
{
	return isFree;
}

std::ostream& operator<<(std::ostream& os, Token& token)
{
	std::cout << "(" << token.sourceIP << ", " << token.destinationIP << ", "  << token.message << ", "<< token.reachedDestination << ", " << token.isFree << ", [";
	for (auto x : token.history)
		std::cout << x << ", ";
	std::cout << "])" << std::endl;
	return os;
}
