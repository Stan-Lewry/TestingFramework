// Example of a test suite

#include "../TestSuite.h"
#include "../TestRunner.h"

// Test suite must extend TestSuite
class ExampleTestSuite : public TestSuite
{
public:

    static ExampleTestSuite& getInstance()
    {
	static ExampleTestSuite instance;
	return instance;
    }

    // Test suite must override the RunSuite function
    // any test you want to run must be called in here
    void RunSuite() override
    {
	// Use the RunTest macro to run your test
	RunTest(ExampleTestAddition_test);

	RunTest(ExampleTestMultiplication_test);

	RunTest(ExampleTestBooleanOr_test);

	RunTest(ExampleTestBooleanAnd_test);
    }
    
private:

    ExampleTestSuite()
    {
	// dont forget to register your class
	_RegisterTestSuite(ExampleTestSuite);
    }
    ExampleTestSuite(TestSuite const&);
    void operator=(ExampleTestSuite const&);

    // Example unit tests

    void ExampleTestAddition_test()
    {
	int x = 4;
	int y = 6;
	int expected = 10;
	int actual = x + y;
	
	AssertEquals(expected, actual);
    }

    void ExampleTestMultiplication_test()
    {
	int x = 4;
	int y = 6;
	int expected = 24;
	int actual = x * y;

	AssertEquals(expected, actual);
    }

    void ExampleTestBooleanOr_test()
    {
	bool x = false;
	bool y = true;
	bool z = (x || y) ? true : false;

	AssertTrue(z);
    }

    void ExampleTestBooleanAnd_test()
    {
	bool x = false;
	bool y = true;
	bool z = (x && y) ? true : false;

	AssertFalse(z);
    }	
    
};

ExampleTestSuite& exampleTestSuite = ExampleTestSuite::getInstance();
