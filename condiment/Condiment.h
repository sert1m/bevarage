#pragma once

#include "Beverage.h"

namespace coffee {

class CondimentDecorator : public Beverage {
public:
  CondimentDecorator(Beverage *bevarage, double cost,
                     const std::string &description)
      : Beverage(cost, description), beverage(bevarage) {}

  virtual ~CondimentDecorator() {
    if (beverage)
      delete beverage;
    beverage = NULL;
  }

  std::string getDescription() const override {
    if (!beverage)
      return description;

    return beverage->getDescription() + ", " + description;
  }

  double getCost() const override {
    if (!beverage)
      return cost;

    return beverage->getCost() + cost;
  }

protected:
  Beverage *beverage;
};

} // namespace coffee