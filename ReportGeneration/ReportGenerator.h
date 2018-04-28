#pragma once

#include <iostream>
#include <fstream>

#include "../TestResult.h"

class ReportGenerator
{
public:
    ReportGenerator();
    ~ReportGenerator();

    void GenerateReport(FinalResult finalResult);
private:

    std::string _GenerateFileName();
    void _WriteHeader(std::ofstream &file);
    void _WriteSuiteResult(std::ofstream &file, TestSuiteResult suiteResult);
    void _WriteFooter(std::ofstream &file);
};
