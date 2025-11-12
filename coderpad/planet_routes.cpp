// https://app.coderpad.io/P7MXZQ9H

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

enum PlanetType {
  Food, Metal
};

const vector<string> PLANET_TYPES = {"F", "M"};

class Planet {
public:
  Planet(double x, double y, double z, PlanetType type, const string& name) :
    _x{x}, _y{y}, _z{z}, _type{type}, _name{name} { }

  string toString() const {
    return _name + " (" + PLANET_TYPES[_type] + ") " +
      "[" + to_string(_x) + ", " + to_string(_y) + ", " + to_string(_z) + "]";
  }

  double distanceTo(const Planet& p) const {
    return sqrt(pow(_x - p._x, 2) + pow(_y - p._y, 2) + pow(_z - p._z, 2));
  }

private:
  double _x;
  double _y;
  double _z;

  PlanetType _type;
  string _name;
};

// To execute C++, please define "int main()"
int main() {
  vector<Planet> foodPlanets = {
    Planet{0.0, 0.0, 0.0, PlanetType::Food, "Food 1"}
  };

  vector<Planet> metalPlanets = {
    Planet{1.0, 1.0, 1.0, PlanetType::Metal, "Metal 1"}
  };

  vector<Planet&> planets = {*foodPlanets.begin(), *metalPlanets.begin()};

  for (auto& p : planets) {
    cout << p.toString() << endl;
  }

  return 0;
}
