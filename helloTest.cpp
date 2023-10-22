#include <iostream>
#include <cppunit/TestRunner.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/extensions/TestFactoryRegistry.h>

class Test : public CPPUNIT_NS::TestCase
{
  CPPUNIT_TEST_SUITE(Test);
  CPPUNIT_TEST(testHelloWorld);
  CPPUNIT_TEST_SUITE_END();

public:
  void setUp(void) {}
  void tearDown(void) {}

protected:
 // run when test out the test case
  void testHelloWorld(void) {
    // system() -- execute shell commane
    // >nul -- redirect the standard output of the command to the "nul" device, which discards the output and surpress it
    // 2>nul -- redirect the standard error of the command to the "nul" device...
    system("./hello >nul 2>nul");
  }
};


CPPUNIT_TEST_SUITE_REGISTRATION(Test);

int main()

{
    // for manage test result
  CPPUNIT_NS::TestResult controller; 

  // to collect the test result
  CPPUNIT_NS::TestResultCollector result;
  controller.addListener(&result);

  // to provide progress information
  CPPUNIT_NS::BriefTestProgressListener progress;
  controller.addListener(&progress);

    // run test case obtained from the registry
  CPPUNIT_NS::TestRunner runner;
  runner.addTest(CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest());
  runner.run(controller);

  return result.wasSuccessful() ? 0 : 1;
}