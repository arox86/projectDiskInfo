#pragma once
#include <string>
#include <vector>

class BubblePlotHandler
{
public:
	int makeHTML();
private:
	std::vector<std::string>* getDataFromFile(std::string path);
};