#pragma once

#include <list>
#include <string>
#include <vector>

typedef struct TestResult
{
    std::string testName;
    std::string expected;
    std::string actual;
    bool passed;
}TestResult;

typedef struct TestSuiteResult
{
    std::string className;
    std::vector<TestResult> results;
}TestSuiteResult;

typedef struct FinalResult
{
    std::vector<TestSuiteResult> suiteResults;
}FinalResult;
