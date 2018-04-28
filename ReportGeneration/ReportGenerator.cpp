#include <chrono>
#include <ctime>
#include <cstring>
#include <sstream>

#include "ReportGenerator.h"


ReportGenerator::ReportGenerator()
{
}

ReportGenerator::~ReportGenerator()
{
}

void ReportGenerator::GenerateReport(FinalResult finalResult)
{
    std::ofstream file;
    std::string fileName = _GenerateFileName();
    file.open(fileName);

    _WriteHeader(file);

    file << "<br>\n";
    file << "<b>" << fileName << "</b>\n";
    file << "<br><hr><br>\n";

    for (auto suiteResult : finalResult.suiteResults)
    {
	_WriteSuiteResult(file, suiteResult);
    }

    _WriteFooter(file);

    file.close();
}

std::string ReportGenerator::_GenerateFileName()
{
    char ret[1000];
    std::time_t time = std::time(0);
    struct tm* p = std::localtime(&time);
    strftime(ret, 1000, "Reports/Test-Report-%H-%M-%S-%A-%B-%d-%Y.html", p);
    std::string retStr(ret);
    return retStr;
}

void ReportGenerator::_WriteHeader(std::ofstream &file)
{
    file << "<!DOCTYPE html>\n";
    file << "<html>\n";
    file << "<head>\n";
    file << "</head>\n";
    file << "<body>\n";
    file << "<pre>\n";
    file << " _____ _____ _____ _____  ______ ___________ ___________ _____ \n";
    file << "|_   _|  ___/  ___|_   _| | ___ \\  ___| ___ \\  _  | ___ \\_   _|\n";
    file << "  | | | |__ \\ `--.  | |   | |_/ / |__ | |_/ / | | | |_/ / | |  \n";
    file << "  | | |  __| `--. \\ | |   |    /|  __||  __/| | | |    /  | |  \n";
    file << "  | | | |___/\\__/ / | |   | |\\ \\| |___| |   \\ \\_/ / |\\ \\  | |  \n";
    file << "  \\_/ \\____/\\____/  \\_/   \\_| \\_\\____/\\_|    \\___/\\_| \\_| \\_/  \n";
    file << "</pre>\n";
}

void ReportGenerator::_WriteSuiteResult(std::ofstream &file, TestSuiteResult suiteResult)
{
    file << "<h2>" << suiteResult.className << "</h2>\n";
    file << "<table border=\"1\">\n";
    file << "<th><b>#</b></th>\n";
    file << "<th><b>Test name:</b></th>\n";
    file << "<th><b>Expected:</b></th>\n";
    file << "<th><b>Actual:</b></th>\n";
    file << "<th><b>Result:</b></th>\n";
    int testCount = 0;
    int totalPassed = 0;
    for (auto result : suiteResult.results)
    {
	testCount += 1;
	file << "<tr>\n";
	file << "<th>" << testCount << "</th>\n";
	file << "<th>" << result.testName << "</th>\n";
	file << "<th>" << result.expected << "</th>\n";
	file << "<th>" << result.actual << "</th>\n";
	if (result.passed)
	{
	    totalPassed += 1;
	    file << "<th>PASS</th>\n";
	}
	else
	{
	    file << "<th>FAIL</th>\n";
	}
	file << "</tr>\n";
    }
    file << "</table>\n";
    file << "<p>" << testCount << " tests run. " << totalPassed << " tests passed</p>\n";
    if (totalPassed == testCount)
    {
	file << "Congratulations, all test passed!\n";
    }

    file << "<hr>\n";
}

void ReportGenerator::_WriteFooter(std::ofstream &file)
{
    file << "</body>\n";
    file << "</html>\n";
}
