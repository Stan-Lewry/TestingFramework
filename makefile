OBJS = TestingFrameworkMain.cpp\
TestSuite.h\
TestRunner.h\
TestResult.h\
ReportGeneration/ReportGenerator.h\
ReportGeneration/ReportGenerator.cpp\
ExampleTestSuites/ExampleTestSuite.cpp\

CC = g++

COMPILER_FLAGS = -w -std=c++11

OBJ_NAME = Tests

all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) -o $(OBJ_NAME)
	./$(OBJ_NAME)
