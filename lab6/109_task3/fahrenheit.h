#ifndef F__
#define F__

class Celsius;
class Kelvin;

class Fahrenheit{
  float t;
public:
  Fahrenheit();
  Fahrenheit(float _t);
  void assign(float _t);
  void display() const;
  operator Celsius() const;
  operator Kelvin() const;
};

#endif 
