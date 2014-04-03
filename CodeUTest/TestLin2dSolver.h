
#include <iostream>
#include <cppunit\TestFixture.h>
#include <cppunit\TestAssert.h>
#include <cppunit\TestCaller.h>
#include <cppunit\TestSuite.h>
#include <cppunit\TestCase.h>

#include "..\Code\Vector.h"

using namespace std;

class TestVector : public CppUnit::TestFixture 
{
private:
	hb::Vector *vector;
public:
	TestVector () : vector(NULL) {}
	virtual ~TestVector() 
	{
		delete vector;
	}

	static CppUnit::Test *suite() 
	{
		CppUnit::TestSuite *suiteOfTests = new CppUnit::TestSuite("TestVector");

		suiteOfTests->addTest(new CppUnit::TestCaller<TestVector>("Test1.",
				&TestVector::Distance0 ));

		suiteOfTests->addTest(new CppUnit::TestCaller<TestVector>("Test2.",
				&TestVector::Distance1 ));

		return suiteOfTests;
	}

	/// Setup method
	void setUp() {}

	/// Teardown method
	void tearDown() {}

protected:
	void Distance0() 
	{
		hb::Vector v=hb::Vector(0,0);
		float dist=v.Distance();
		float dist_expected = 0;
		CPPUNIT_ASSERT( dist_expected==dist);
	}

	void Distance1() 
	{
		hb::Vector v=hb::Vector(0,0);
		float dist=v.Distance();
		float dist_expected = 0;
		CPPUNIT_ASSERT( dist_expected==dist);
	}


};
