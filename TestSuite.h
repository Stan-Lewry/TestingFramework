#pragma once

#include "TestResult.h"

class TestSuite
{
public:
    virtual void RunSuite() = 0;

    TestSuiteResult suiteResult; 
};

static TestResult theResult;
static TestSuite* theSuite;
static int resultCount = 0;

static bool _AssertTrue(bool value){return value;}
static bool _AssertFalse(bool value){return !value;}
template <typename T> static bool _AssertEquals(T expected, T actual){return (expected == actual) ? true : false;}

#define _RegisterTestSuite(T)\
    theSuite = this;\
    TestRunner::getInstance().RegisterTestSuite(this);\
    theSuite->suiteResult.className = #T;\

#define AssertTrue(_actual)\
    theSuite->suiteResult.results[resultCount].expected = "true";\
    theSuite->suiteResult.results[resultCount].actual = #_actual;\
    theSuite->suiteResult.results[resultCount].passed = _AssertTrue(_actual);\

#define AssertFalse(_actual)\
    theSuite->suiteResult.results[resultCount].expected = "false";\
    theSuite->suiteResult.results[resultCount].actual = #_actual;\
    theSuite->suiteResult.results[resultCount].passed = _AssertFalse(_actual);\

#define AssertEquals(_expected, _actual)\
    theSuite->suiteResult.results[resultCount].expected = #_expected;\
    theSuite->suiteResult.results[resultCount].actual = #_actual;\
    theSuite->suiteResult.results[resultCount].passed = _AssertEquals(_expected, _actual);\

#define RunTest(testFunction)\
    theSuite->suiteResult.results.push_back(theResult);\
    theSuite->suiteResult.results[resultCount].testName = #testFunction;\
    testFunction();\
    resultCount += 1;\
