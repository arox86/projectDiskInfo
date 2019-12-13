#include "stdafx.h"
#include "BubblePlotHandler.h"
#include <fstream>
#include <sstream>

#define BUBBLEHTML	"CdiResource\bubble\bubblePlot.html"
#define DATAPATH	"Smart\testData.csv"

int BubblePlotHandler::makeHTML()
{
	std::stringstream	html_data;

	html_data << "";

	std::fstream		html_script_file(BUBBLEHTML, std::ios::out | std::ios::trunc);

	if (html_script_file.is_open() && !html_script_file.bad())
	{
		html_script_file << "<!doctype html>" 
			<< "<html>"
			<< "<head>"
			<< "<title>Bubble Chart< / title>"
			<< "<script src = \"Chart.bundle.js\">< / script>"
			<< "<script src = \"utils.js\">< / script>"
			<< "<style type = \"text/css\">"
			<< "canvas{"
			<< "	-moz - user - select: none;"
			<< "	-webkit - user - select: none;"
			<< "	-ms - user - select: none;"
			<< "}"
			<< "</style>"
			<< "</head>"
			<< "<body>"
			<< "	<div id = \"container\" style = \"width: 75%;\">"
			<< "		<canvas id = \"canvas\">< / canvas>"
			<< "	</div>"
			<< "<script>"
			<< "	var DEFAULT_DATASET_SIZE = 7;"
			<< "	var addedCount = 0;"
			<< "	var color = Chart.helpers.color;"
			<< "	var bubbleChartData = {"
			<< "		animation: {"
			<< "			duration: 10000"
			<< "		},"
			<< "	datasets : [{"
			<< "		label: 'My First dataset',"
			<< "		backgroundColor : color(window.chartColors.red).alpha(0.5).rgbString(),"
			<< "		borderColor : window.chartColors.red,"
			<< "		borderWidth : 1,"
			<< "		data : ["
			<< html_data.str()
			<< "]"
			<< "}]"
			<< "};"
			<< "window.onload = function() {"
			<< "var ctx = document.getElementById('canvas').getContext('2d');"
			<< "window.myChart = new Chart(ctx, {"
			<< "	type: 'bubble',"
			<< "	data : bubbleChartData,"
			<< "	xAxisID : 'bottom',"
			<< "	yAxisID : 'left',"
			<< "	options : {"
			<< "		scales: {"
			<< "			xAxes: [{"
			<< "				scaleLabel: {"
			<< "					display: true,"
			<< "					labelString : 'x-Achse'"
			<< "				},"
			<< "				id : 'bottom',"
			<< "				type : 'linear',"
			<< "				position : 'bottom'"
			<< "			}] ,"
			<< "			yAxes: [{"
			<< "				scaleLabel: {"
			<< "					display: true,"
			<< "					labelString : 'y-Achse'"
			<< "				},"
			<< "				id : 'left',"
			<< "				type : 'linear',"
			<< "				position : 'left'"
			<< "			}]"
			<< "		},"
			<< "		responsive: true,"
			<< "	title : {"
			<< "			display: true,"
			<< "			text : 'Temperature/Lebenszeit'"
			<< "		},"
			<< "		tooltips : {"
			<< "			mode: 'point'"
			<< "		}"
			<< "	}"
			<< "	});"
			<< "} ;"
			<< "var colorNames = Object.keys(window.chartColors);"
			<< "</script>"
			<< "</body>"
			<< "</html>";
	}
	else
	{
		return 1;
	}


	html_script_file.close();
	
	return 0;
}

/*
 * getting data from a file. duh
 */
std::vector<std::string>* BubblePlotHandler::getDataFromFile(std::string path)
{
	std::fstream				fs(path);
	std::vector<std::string>	data;

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

			data.push_back(temp_stringstream.str());
		}
	}
	return &data;
}
