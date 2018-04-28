#include "TestSuite.h"
#include "TestRunner.h"
#include "TestResult.h"

#include "ReportGeneration/ReportGenerator.h"

int main(int argc, char* argv[])
{
    
    TestRunner& testRunner = TestRunner::getInstance();
    ReportGenerator reportGenerator;
    reportGenerator.GenerateReport(testRunner.RunAllTestSuites());
    
    return 0;
};
