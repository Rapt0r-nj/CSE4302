#ifndef K__
#define K__

class Celsius;
class Fahrenheit;

class Kelvin{
  float t;
public:
  Kelvin();
  Kelvin(float _t);
  void assign(float _t);
  void display()const;
  operator Celsius() const;
  operator Fahrenheit() const;
};
#endif // !K__
