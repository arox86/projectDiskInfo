#include "stdafx.h"
#include "BubblePlotHandler.h"
#include <fstream>
#include <sstream>

#define BUBBLEEXPORT		"CdiResource/bubble/bubblePlot.html"
#define BUBBLEIMPORT1		"CdiResource/bubble/bubbleScript1.txt"
#define BUBBLEIMPORT2		"CdiResource/bubble/bubbleScript2.txt"
#define DATAPATH			"Smart/testData.csv"
#define BUBBLESIZE			3

int BubblePlotHandler::makeHTML()
{
	std::stringstream	html_data;

	std::vector<std::string> dataX = *getDataFromFile("Smart/testData/Temperatures.csv");
	std::vector<std::string> dataY = *getDataFromFile("Smart/testData/HostWrites.csv");
	
	// format the data
	for (int i = 0; i < max(dataX.size(), dataY.size()); i++)
	{
		html_data << "{\n"
			<< "x: " << dataX[i]
			<< "y: " << dataY[i]
			<< "z: " << i / BUBBLESIZE;
	}

	//file read and write stuff for script building
	std::ofstream		html_script_export(BUBBLEEXPORT, std::ios::out | std::ios::trunc);
	std::ifstream		html_script_import1(BUBBLEIMPORT1, std::ios::in);
	std::ifstream		html_script_import2(BUBBLEIMPORT2, std::ios::in);

	// read first half of script
	std::string html_fst_half(	(std::istreambuf_iterator<char>(html_script_import1)),
								(std::istreambuf_iterator<char>()						));
	// read second half of script
	std::string html_snd_half(	(std::istreambuf_iterator<char>(html_script_import1)),
								(std::istreambuf_iterator<char>()						));

	html_script_import1.close();
	html_script_import2.close();
	
	if (html_script_export.is_open() && !html_script_export.bad())
	{
		// build script with data 
		html_script_export << html_fst_half	<< html_data.str() << html_snd_half;
	}
	else
	{
		return 1;
	}

	html_script_export.flush();
	html_script_export.close();
	
	return 0;
}

/*
 * getting data from a file. duh
 */
std::vector<std::string>* BubblePlotHandler::getDataFromFile(std::string path)
{
	std::fstream				fs(path);
	std::vector<std::string>*	data;

	if (fs.is_open() && !fs.bad())
	{
		std::string			temp_string;
		std::stringstream	garbage;
		std::stringstream	temp_stringstream;
		
		while (!fs.eof())
		{
			
			std::getline(fs,					temp_string);
			std::getline(garbage,				temp_string, ',');
			std::getline(temp_stringstream,	temp_string, '\n');

			data->push_back(temp_stringstream.str());
		}
	}
	return data;
}
