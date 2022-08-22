#include "../include/gastank.h"
#include "../include/motorcycle.h"
#include "gtest/gtest.h"

using namespace std;
using namespace go;

// https://github.com/google/googletest/blob/master/googletest/docs/primer.md
TEST(Motorcycle, Defaults) {
  Motorcycle motorcycle("red");
  ASSERT_EQ(motorcycle.getColor(),"red");
  ASSERT_EQ(motorcycle.getTank().getGallons(),Gas::DEFAULT_GALLONS);    
}

TEST(Motorcycle, Specific) {
  double testGallons = 4.5;
  Motorcycle motorcycle("blue",testGallons);
  ASSERT_EQ(motorcycle.getColor(),"blue");
  ASSERT_EQ(motorcycle.getTank().getGallons(),testGallons);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

