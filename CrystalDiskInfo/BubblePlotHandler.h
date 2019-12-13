#pragma once

#include "AtaSmart.h"
#include <iosfwd>
#include <string>
#include <vector>

class BubblePlotHandler : public CAtaSmart
{
public:
	int makeHTML();
private:
	std::vector<std::string>* getDataFromFile(std::string path);
};

