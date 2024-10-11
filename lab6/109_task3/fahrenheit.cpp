
#include <bits/stdc++.h>
#include "fahrenheit.h"
using namespace std;
  
Fahrenheit::Fahrenheit():t(32){}
Fahrenheit::Fahrenheit(float _t){t=(_t< -459.67)? -459.67: _t;}
Fahrenheit::void assign(float _t){t=(_t< -459.67)? -459.67: _t;}
Fahrenheit::void display() const{cout<<"Temperature is "<<t<<" Fahrenheit"<<en;}
Fahrenheit::operator Celsius() const{return Celsius((t-32)*5/9);}
Fahrenheit::operator Kelvin() const{return Celsius((t-32)*5/9);}
};
