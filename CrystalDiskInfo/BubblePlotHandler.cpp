#include "stdafx.h"
#include "BubblePlotHandler.h"
#include <fstream>
#include <sstream>
#include <iostream>

#define BUBBLEEXPORT		"CdiResource/bubble/bubblePlot.html"
#define BUBBLEIMPORT1		"CdiResource/bubble/bubbleScript_1.txt"
#define BUBBLEIMPORT2		"CdiResource/bubble/bubbleScript_2.txt"
#define BUBBLESIZE			3

int BubblePlotHandler::makeHTML()
{
	std::stringstream	html_data;

	std::vector<std::string> dataX = *getDataFromFile("Smart/testData/Temperature.csv");
	std::vector<std::string> dataY = *getDataFromFile("Smart/testData/HostWrites.csv");

	// format the data
	for (int i = 1; i <= (((dataX.size()) < (dataY.size())) ? (dataX.size()) : (dataY.size())); i++)
	{
		if (i != 1)
			html_data << ",";

		html_data << "{"
			<< "\t\t\t\t\t\nx: " << dataX[i - 1] << ","
			<< "\t\t\t\t\t\ny: " << dataY[i - 1] << ","
			<< "\t\t\t\t\t\nr: " << 5 + 2 * i
			<< "\t\t\t\t\n}";
	}

	//file read and write stuff for script building
	std::ofstream		html_script_export(BUBBLEEXPORT, std::ios::trunc);
	std::ifstream		html_script_import1(BUBBLEIMPORT1, std::ios::in);
	std::ifstream		html_script_import2(BUBBLEIMPORT2, std::ios::in);

	std::string html_fst_half;
	// read first half of script
	{
		std::stringstream s;
		s << html_script_import1.rdbuf();
		html_fst_half = s.str();
	}
	std::string html_snd_half;
	// read second half of script
	{
		std::stringstream s;
		s << html_script_import2.rdbuf();
		html_snd_half = s.str();
	}
	html_script_import1.close();
	html_script_import2.close();

	if (!html_script_export.bad())
	{
		// build script with data
		html_script_export << html_fst_half << html_data.str() << html_snd_half;
	}
	else
	{
		return 1;
	}

	html_script_export.close();

	return 0;
}

/*
 * getting data from a file. duh
 */
std::vector<std::string>* BubblePlotHandler::getDataFromFile(std::string path)
{
	std::fstream				fs(path, std::ios::in);
	auto data = new std::vector<std::string>;

	if (!fs.bad())
	{
		std::string line, word, temp;

		data->clear();
		while (!fs.eof())
		{

			std::getline(fs, line);
			std::stringstream s(line);

			while (std::getline(s, word, ','))
			{
				if (word.size() < 8)
					data->push_back(word);
			}

		}
	}
	return data;
}
