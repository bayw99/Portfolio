#include "health.h"
#include "dog.h"
#include "gtest/gtest.h"

using namespace std;
using namespace go;

// https://github.com/google/googletest/blob/master/googletest/docs/primer.md
TEST(Dog, Defaults) {
  Dog dog("black");
  ASSERT_EQ(dog.getColor(),"black");
  ASSERT_EQ(dog.getArms().getAgility(),Health::DEFAULT_AGILITY);
  ASSERT_EQ(dog.getLegs().getAgility(),Health::DEFAULT_AGILITY);    
}

TEST(Dog, Specific) {
  double testAgility = 6.0;
  Dog dog("black",testAgility);
  ASSERT_EQ(dog.getColor(),"black");
  ASSERT_EQ(dog.getArms().getAgility(),testAgility);
  ASSERT_EQ(dog.getLegs().getAgility(),testAgility);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}