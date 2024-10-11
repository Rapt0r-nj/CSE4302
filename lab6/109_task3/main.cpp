#include <bits/stdc++.h>
#include "celsius.h"
#include "kelvin.h"
#include "fahrenheit.h"

using namespace std;

int main(){
  Celsius c=Celsius(300.0);
  Kelvin k=c;
  k.display();
}
