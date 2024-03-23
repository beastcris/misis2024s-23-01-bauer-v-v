#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <queuelstpr/queuelstpr.hpp>

TEST_CASE("BASE METHODS") {
  QueueLstPr a;
  float first_num = 0;
  float second_num = 1.5;
  float third_num = 3.0;

  CHECK(a.IsEmpty());
  a.Push(first_num);
  CHECK_EQ(a.Top(), first_num);
  a.Pop();
  CHECK(a.IsEmpty());
}


