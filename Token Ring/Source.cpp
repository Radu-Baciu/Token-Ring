#include "Token.h"
#include<iostream>
#include <algorithm>
#include <sstream>

bool ipv4Check(std::string& ip)
{
	std::istringstream ss(ip);
	std::string s;
	std::vector<std::string> ipTokens;
	while (std::getline(ss, s, '.'))
		ipTokens.push_back(s);
	if (ipTokens.size() != 4)
		return false;
	for (auto x : ipTokens)
	{
		int number = std::stoi(x);
		if (number >= 256)
			return false;
	}
	return true;
}

bool isUnique(std::string str, std::vector<std::string> vector)
{
	for (auto x : vector)
	{
		if (x.compare(str) == 0)
			return false;
	}
	return true;
}

bool ipChecker(std::string ip, std::vector<std::string> vector)
{
	if (ipv4Check(ip) == true && isUnique(ip, vector) == true)
		return true;
	return false;
}

void clockwiseRing(int sourceComp, int destinationComp, std::string message, int computerCount, std::vector<std::string>computers, Token token)
{
	std::cout << "Tokenul initial: (-,-,-,-,1,-)" << std::endl;
	int iteratii = 0;
	while (iteratii != computerCount + 1)
	{
		token.parse(computers[sourceComp % computerCount], computers[(sourceComp + 1) % computerCount]);
		std::cout << "Computerul " << sourceComp % computerCount << ": " << token;
		if (sourceComp % computerCount == destinationComp % computerCount)
			std::cout << message << std::endl;
		sourceComp++;
		iteratii++;
	}
	std::cout << "Tokenul a fost resetat: (-,-,-,-,1,-)" << std::endl;
}
void counterClockwiseRing(int sourceComp, int destinationComp, std::string message, int computerCount, std::vector<std::string>computers, Token token)
{
	std::cout << "Tokenul initial: (-,-,-,-,1,-)" << std::endl;
	int iteratii = 0;
	while (iteratii != computerCount + 1)
	{
		token.parse(computers[sourceComp % computerCount], computers[(sourceComp + 1) % computerCount]);
		std::cout << "Computerul " << computerCount - (sourceComp % computerCount) - 1 << ": " << token;
		if ((sourceComp) % computerCount == destinationComp % computerCount)
			std::cout << message << std::endl;
		sourceComp++;
		iteratii++;
	}
	std::cout << "Tokenul a fost resetat: (-,-,-,-,1,-)" << std::endl;
}

int main()
{
	int computerCount;
	std::vector<std::string> computers;
	std::vector<std::string> invertedComputers;
	int sourceComp;
	int destinationComp;
	std::string message;

	std::cout << "Introduceti numarul de calculatoare: ";
	std::cin >> computerCount;
	for (int i = 0; i < computerCount; i++)
	{
		std::string comp;
		std::cout << "Introduceti IP-ul calculatorului #" << i << ": ";
		std::cin >> comp;
		while (ipChecker(comp, computers) == false)
		{
			std::cout << "IP INVALID" << std::endl;
			std::cout << "Introduceti IP-ul calculatorului #" << i << ": ";
			std::cin >> comp;
		}
		computers.push_back(comp);
		invertedComputers.push_back(comp);
	}
	std::reverse(invertedComputers.begin(), invertedComputers.end());

	int isOpen = 1;
	while (isOpen == 1)
	{
		int sens;
		std::cout << "Introduceti calculatorul sursa: ";
		std::cin >> sourceComp;
		std::cout << "Introduceti calculatorul destinatie: ";
		std::cin >> destinationComp;
		std::cout << "Introduceti mesajul: ";
		std::cin >> message;
		std::cout << "Introduceti sensul (0 -> clockwise, 1 -> counter-clockwise):";
		std::cin >> sens;
		while (sens != 0 && sens != 1)
		{
			std::cout << "SENS INVALID" << std::endl;
		}
		if (sens == 0)
		{
			Token token(computers[sourceComp], computers[destinationComp], message, computerCount);
			clockwiseRing(sourceComp, destinationComp, message, computerCount, computers, token);
		}
		else
		{
			Token token(invertedComputers[destinationComp], invertedComputers[sourceComp], message, computerCount);
			counterClockwiseRing( destinationComp, sourceComp, message, computerCount, invertedComputers, token);
		}
		std::cout << "Continuati? (1 -> da)" << std::endl;
		std::cin >> isOpen;
	}
	return 0;
}