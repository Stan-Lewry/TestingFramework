#pragma once

#include "TestSuite.h"
#include <iostream>
#include <list>
#include <vector>

class TestRunner
{
public:
    static TestRunner& getInstance()
    {
	static TestRunner instance;
	return instance;
    }

    void RegisterTestSuite(TestSuite* t)
    {
	callbackList.push_back(t);
    }

    FinalResult RunAllTestSuites()
    {
	FinalResult finalResult;
	
	for(auto suite : callbackList)
	{
	    suite->RunSuite();
	    finalResult.suiteResults.push_back(suite->suiteResult);
	}

	return finalResult;
    }
    
private:
    TestRunner(){}
    TestRunner(TestRunner const&);
    void operator=(TestRunner const&);

    std::list<TestSuite*> callbackList;
};
