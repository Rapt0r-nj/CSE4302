#include <bits/stdc++.h>
#include "kelvin.h"
using namespace std;
 
Kelvin::Kelvin():t(273.15){}
Kelvin::Kelvin(float _t){t=(_t< 0)? 0: _t;}
Kelvin::void assign(float _t){t=(_t< 0)? 0: _t;}
Kelvin::void display()const{cout<<"Temperature is "<<t<<" Kelvin"<<en;}
Kelvin::operator Celsius() const{return Celsius(t-273.15);}
Kelvin::operator Fahrenheit() const{return Celsius(t-273.15);}
