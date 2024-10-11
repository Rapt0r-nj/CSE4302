#ifndef C__
#define C__ 

class Fahrenheit;
class Kelvin;

class Celsius{
  float t;
public:
  Celsius();
  Celsius(float _t);
  void assign(float _t);
  void display() const;
  operator Fahrenheit() const;
  operator Kelvin() const;
};

#endif
