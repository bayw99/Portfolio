#include "animal.h"
#include "cat.h"
#include "dog.h"
#include "gtest/gtest.h"

using namespace std;
using namespace go;

// https://github.com/google/googletest/blob/master/googletest/docs/primer.md
TEST(Animal, AsObjects) {
  Animal animal;
  Cat cat;
  cat.isStarting();
  cat.setEnergy(0.0);
  ASSERT_EQ(cat.isMoving(),false);
  animal = cat; 
  ASSERT_EQ(animal.isMoving(),false);
}

TEST(Animal, AsPointers) {
  AnimalPtr animal = AnimalPtr(new Animal());
  CatPtr cat = CatPtr(new Cat());
  cat->moving();
  cat->setEnergy(0.0);
  ASSERT_EQ(cat->isMoving(),false);
  animal = cat; 
  ASSERT_EQ(animal->isMoving(),false);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}