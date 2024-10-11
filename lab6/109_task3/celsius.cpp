
#include <bits/stdc++.h>
#include "celsius.h"
using namespace std;

Celsius:: Celsius():t(0){}
Celsius:: Celsius(float _t){t=(_t< -273.15)? -273.15: _t;}
Celsius:: void assign(float _t){t=(_t< -273.15)? -273.15: _t;}
Celsius::void display() const{cout<<"Temperature is "<<t<<" Celsius"<<en;}
Celsius::operator Fahrenheit() const{return Fahrenheit(t*9/5+32);}
Celsius::operator Kelvin() const{return Kelvin(t+273.15);}
