#pragma once

#include "Beverage.h"

namespace coffee {

class CondimentFactory {
public:
  Beverage *addSteamedMilk(Beverage *bevarage) const {
    return create(bevarage, "Steamed Milk", 0.2);
  }

  Beverage *addMocha(Beverage *bevarage) const {
    return create(bevarage, "Mocha", 0.4);
  }

  Beverage *addSoy(Beverage *bevarage) const {
    return create(bevarage, "Soy", 0.55);
  }

  Beverage *addWhip(Beverage *bevarage) const {
    return create(bevarage, "Whip", 0.7);
  }

  Beverage *addSugar(Beverage *bevarage) const {
    return create(bevarage, "Sugar", 0.1);
  }

protected:
  Beverage *create(Beverage *bevarage, std::string description,
                   double cost) const {
    return new CondimentDecorator(bevarage, cost, description);
  }
};

} // namespace coffee
