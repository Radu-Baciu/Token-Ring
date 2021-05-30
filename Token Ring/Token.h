#pragma once
#include <iostream>
#include <string>
#include <vector>
class Token
{
private:
	std::string sourceIP;
	std::string destinationIP;
	std::string message;
	bool reachedDestination;
	bool isFree;
	std::vector<std::string> history;
	int compNr;
public:
	Token(std::string source, std::string destination, std::string msg, int nrComp);
	void parse(std::string computerA, std::string computerB);
	bool getIsFree();
	friend std::ostream& operator<<(std::ostream& os, Token& token);
};
std::ostream& operator<<(std::ostream& os, Token& token);

