#pragma once

#include <string>

namespace coffee {

class Beverage {
public:
  Beverage(double cost, const std::string &description)
      : cost(cost), description(description) {}
  virtual ~Beverage() {}

  virtual std::string getDescription() const { return description; }
  virtual double getCost() const { return cost; }

protected:
  double cost;
  std::string description;
};

} // namespace coffee
