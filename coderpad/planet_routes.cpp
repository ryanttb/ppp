// https://app.coderpad.io/P7MXZQ9H

#include <cstddef>
#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <tuple>
#include <set>
#include <cmath>

using namespace std;

enum PlanetType{
  Food, Metal
};

const vector<string> PLANET_TYPES = {"F", "M"};

class Planet {
public:
  Planet(double x, double y, double z, PlanetType type, const string& name) :
    _x{x}, _y{y}, _z{z}, _type{type}, _name{name} { }

  string name() const {
    return _name;
  }

  string toString() const {
    return _name + " (" + PLANET_TYPES[_type] + ") " +
      "[" + to_string(_x) + ", " + to_string(_y) + ", " + to_string(_z) + "]";
  }

  double distanceTo(const Planet& p) const {
    return sqrt(pow(_x - p._x, 2) + pow(_y - p._y, 2) + pow(_z - p._z, 2));
  }

  bool setNearest(Planet* p, double distance) {
    if (p->_type != _type && (!_nearest || distance < _nearestDistance)) {
      cout << "setNearest " << name() << " => " << p->name() << "(" << distance << ")" << endl;
      _nearestDistance = distance;
      _nearest = p;
      return true;
    }
    return false;
  }

  friend ostream& operator<<(ostream& os, Planet& p) {
    os << p.toString();
    return os;
  }

private:
  double _x;
  double _y;
  double _z;

  Planet* _nearest{nullptr};
  double _nearestDistance{1.0};

  PlanetType _type;
  string _name;
};

typedef tuple<double, Planet*, Planet*> Route;
inline bool operator<(const Route& a, const Route& b) {
    // Compare by distance first
    if (get<0>(a) != get<0>(b)) {
        return get<0>(a) < get<0>(b);
    }
    return false;
}

int main() {
  vector<Planet> foodPlanets = {
    Planet{0.0, 0.0, 0.0, PlanetType::Food, "Food 1"},
    Planet{5.0, -23.0, 14.0, PlanetType::Food, "Food 2"}
  };

  vector<Planet> metalPlanets = {
    Planet{-9.0, 4.0, 11.0, PlanetType::Metal, "Metal 2"},
    Planet{1.0, 1.0, 1.0, PlanetType::Metal, "Metal 1"}
  };

  vector<Planet> planets = {*foodPlanets.begin(), *metalPlanets.begin()};

  cout << "All Planets:" << endl;
  for (auto& p : planets) {
    cout << p << endl;
  }
  cout << endl;

  set<Route> routes;

  for (auto& fp : foodPlanets) {
    for (auto& mp : metalPlanets) {
      double d = fp.distanceTo(mp);
      routes.insert({d, &fp, &mp});
      cout << fp.name() << " => " << mp.name() << " (" << to_string(fp.distanceTo(mp)) << ")" << endl;
    }
  }

  cout << endl;

  cout << "Routes:" << endl;
  for (auto& r : routes) {
    cout << get<1>(r)->name() << " => " << get<2>(r)->name() << " (" << to_string(get<0>(r)) << ")" << endl;

    double d = get<0>(r);
    auto* p1 = get<1>(r);
    auto* p2 = get<2>(r);
    p1->setNearest(p2, d);
    p2->setNearest(p1, d);
  }

  return 0;
}
