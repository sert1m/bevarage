#include <gtest/gtest.h>
#include <memory>

#include "BeverageFactory.h"
#include "Condiment.h"
#include "CondimentFactory.h"

using namespace coffee;

class CoffeTest : public ::testing::Test {
protected:
  double e = 0.01;
  BeverageFactory beverageFactory;
  CondimentFactory condimentFactory;
};

TEST_F(CoffeTest, beverageTest) {
  auto drink = std::shared_ptr<Beverage>(beverageFactory.createEspresso());
  EXPECT_EQ(drink->getDescription(), "Espresso");
  EXPECT_NEAR(drink->getCost(), 2.0, e);

  drink = std::shared_ptr<Beverage>(beverageFactory.createDecaf());
  EXPECT_EQ(drink->getDescription(), "Decaf");
  EXPECT_NEAR(drink->getCost(), 1.9, e);

  drink = std::shared_ptr<Beverage>(beverageFactory.createDarkRoast());
  EXPECT_EQ(drink->getDescription(), "Dark Roast");
  EXPECT_NEAR(drink->getCost(), 1.5, e);

  drink = std::shared_ptr<Beverage>(beverageFactory.createHouseBlend());
  EXPECT_EQ(drink->getDescription(), "House Blend");
  EXPECT_NEAR(drink->getCost(), 1.2, e);
}

TEST_F(CoffeTest, condimentTest) {
  auto condiment =
      std::shared_ptr<Beverage>(condimentFactory.addMocha(nullptr));
  EXPECT_EQ(condiment->getDescription(), "Mocha");
  EXPECT_NEAR(condiment->getCost(), 0.4, e);

  condiment = std::shared_ptr<Beverage>(condimentFactory.addSoy(nullptr));
  EXPECT_EQ(condiment->getDescription(), "Soy");
  EXPECT_NEAR(condiment->getCost(), 0.55, e);

  condiment = std::shared_ptr<Beverage>(condimentFactory.addSteamedMilk(nullptr));
  EXPECT_EQ(condiment->getDescription(), "Steamed Milk");
  EXPECT_NEAR(condiment->getCost(), 0.2, e);

  condiment = std::shared_ptr<Beverage>(condimentFactory.addSugar(nullptr));
  EXPECT_EQ(condiment->getDescription(), "Sugar");
  EXPECT_NEAR(condiment->getCost(), 0.1, e);
}

TEST_F(CoffeTest, espressoWithMilkAndSugar) {
  auto drink = beverageFactory.createEspresso();
  drink = condimentFactory.addSteamedMilk(drink);
  drink = condimentFactory.addSugar(drink);

  EXPECT_EQ(drink->getDescription(), "Espresso, Steamed Milk, Sugar");
  EXPECT_NEAR(drink->getCost(), 2.3, e);

  delete drink;
}

TEST_F(CoffeTest, darkRoastWithDoubleMocha) {
  auto drink = beverageFactory.createDarkRoast();
  drink = condimentFactory.addMocha(drink);
  drink = condimentFactory.addMocha(drink);

  EXPECT_EQ(drink->getDescription(), "Dark Roast, Mocha, Mocha");
  EXPECT_NEAR(drink->getCost(), 2.3, e);

  delete drink;
}

TEST_F(CoffeTest, houseBlendWithSoy) {
  auto drink = beverageFactory.createHouseBlend();
  drink = condimentFactory.addSoy(drink);

  EXPECT_EQ(drink->getDescription(), "House Blend, Soy");
  EXPECT_NEAR(drink->getCost(), 1.75, e);

  delete drink;
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}