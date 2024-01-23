#pragma once

#include "Beverage.h"

namespace coffee {

class BeverageFactory {
public:
  Beverage *createHouseBlend() const { return create("House Blend", 1.2); }
  Beverage *createDarkRoast() const { return create("Dark Roast", 1.5); }
  Beverage *createDecaf() const { return create("Decaf", 1.9); }
  Beverage *createEspresso() const { return create("Espresso", 2.0); }

protected:
  Beverage *create(const std::string &description, double cost) const {
    return new Beverage(cost, description);
  }
};

} // namespace coffee
