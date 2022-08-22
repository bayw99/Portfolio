#include "../include/gastank.h"
#include "gtest/gtest.h"

using namespace std;
using namespace go;

// https://github.com/google/googletest/blob/master/googletest/docs/primer.md
TEST(Gas, Defaults) {
  Gas gas;
  ASSERT_EQ(gas.getGallons(),Gas::DEFAULT_GALLONS);  
  ASSERT_EQ(gas.getTanksize(),Gas::DEFAULT_TANK);
  ASSERT_EQ(gas.hasMiles(), false);
  ASSERT_EQ(gas.isEmpty(), Gas::DEFAULT_GALLONS == 0.0);
}

TEST(Gas, NegativeGallons) {
  double testTanksize = 4.5;
  double testGallons = -1.0;
  ASSERT_THROW(Gas(testTanksize,testGallons), std::invalid_argument);
}

TEST(Gas, Specific) {
  double testTanksize = 4.5;
  double testGallons = Gas::TOTAL_MILES/50;
  Gas gas(testTanksize, testGallons);

  ASSERT_EQ(gas.getGallons(),testGallons);
  ASSERT_EQ(gas.getTanksize(),testTanksize);
  ASSERT_EQ(gas.hasMiles(), false);
  ASSERT_EQ(gas.isEmpty(), false);
}

TEST(Gas, Empty) {
  double testGallons = Gas::TOTAL_MILES / 50;
  Gas gas;
  gas.setGallons(testGallons);
  ASSERT_EQ(gas.getGallons(), testGallons);
  ASSERT_EQ(gas.isEmpty(), false);
  gas.setGallons(0.0);
  ASSERT_EQ(gas.isEmpty(), true);
}

TEST(Gas,Miles) {
  Gas gas;
  
  gas.setGallons(Gas::TOTAL_MILES / 50);
  ASSERT_EQ(gas.isEmpty(), false);
  ASSERT_EQ(gas.hasMiles(), false);
  gas.setGallons(Gas::TOTAL_MILES);
  ASSERT_EQ(gas.getGallons(), 0.0);
  ASSERT_EQ(gas.isEmpty(), true);
  ASSERT_EQ(gas.hasMiles(), true);
  gas.setGallons(Gas::TOTAL_MILES / 50);
  ASSERT_EQ(gas.getGallons(), 0.0);
  ASSERT_EQ(gas.isEmpty(), true);
  ASSERT_EQ(gas.hasMiles(), true);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

