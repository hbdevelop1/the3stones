

#include <iostream>
#include <cppunit/TestSuite.h>
#include <cppunit/ui/text/TestRunner.h>

#include "TestLin2dSolver.h"

using namespace std;


int main() 
{
	CppUnit::TextUi::TestRunner runner;

	cout << "Creating Test Suites:" << endl;
	runner.addTest(TestLin2dSolver::suite());
	cout<< "Running the unit tests."<<endl;
	runner.run();

	return 0;
}
