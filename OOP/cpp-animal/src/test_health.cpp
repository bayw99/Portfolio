#include "health.h"
#include "gtest/gtest.h"

using namespace std;
using namespace go;

// https://github.com/google/googletest/blob/master/googletest/docs/primer.md
TEST(Health, Defaults) {
  Health health;
  ASSERT_EQ(health.getStrength(),Health::DEFAULT_STRENGTH);
  ASSERT_EQ(health.getAgility(),Health::DEFAULT_AGILITY);
  ASSERT_EQ(health.hasBad(), true);
  ASSERT_EQ(health.isDead(), Health::DEFAULT_STRENGTH == 0.0);
}

TEST(Health, NegativeStrength) {
  double testAgility = 5.0;
  double testStrength = -1.0;
  ASSERT_THROW(Health(testAgility,testStrength), std::invalid_argument);
}

TEST(Health, Specific) {
  double testAgility = 5.0;
  double testStrength = Health::BAD_STRENGTH/2.0;
  Health health(testAgility, testStrength);

  ASSERT_EQ(health.getStrength(),testStrength);
  ASSERT_EQ(health.getAgility(),testAgility);
  ASSERT_EQ(health.hasBad(), false);
  ASSERT_EQ(health.isDead(), false);
}

TEST(Health, Dead) {
  double testStrength = Health::BAD_STRENGTH/2.0;
  Health health;
  health.setStrength(testStrength);
  ASSERT_EQ(health.getStrength(), testStrength);
  ASSERT_EQ(health.isDead(), false);
  health.setStrength(0.0);
  ASSERT_EQ(health.isDead(), true);
}

TEST(Health,Bad) {
  Health health;
  
  health.setStrength(Health::BAD_STRENGTH / 2.0);
  ASSERT_EQ(health.isDead(), false);
  ASSERT_EQ(health.hasBad(), true);
  health.setStrength(Health::BAD_STRENGTH);
  ASSERT_EQ(health.getStrength(), 2.0);
  ASSERT_EQ(health.isDead(), false);
  ASSERT_EQ(health.hasBad(), true);
  health.setStrength(Health::BAD_STRENGTH/ 2.0);
  ASSERT_EQ(health.getStrength(), 1.0);
  ASSERT_EQ(health.isDead(), false);
  ASSERT_EQ(health.hasBad(), true);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


