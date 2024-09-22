#include<bits/stdc++.h>
using namespace std;

class Temperature{
  double temp;
  string unit;
public:
  Temperature() : temp(0), unit("Celsius"){}
  
  void assign(double t, string u){
    if(u!="Celsius" and u!="Fahrenheit" and u!="Kelvin"){
      cout<<"Invalid unit\n";
      return;
    }
    if((u=="Celsius" and t<-273.15) or (u=="Fahrenheit" and t<-459.67) or (u=="Kelvin" and t<0)){
      cout<<"Temperature below absolute zero\n";
      return;
    }
    temp=t;
    unit=u;
  }
  
  double convert(string target){
    if(target=="Celsius"){
      if(unit=="Fahrenheit") return (temp-32)*5/9;
      if(unit=="Kelvin") return temp-273.15;
      return temp;
    }
    if(target=="Fahrenheit"){
      if(unit=="Celsius") return temp*9/5+32;
      if(unit=="Kelvin") return (temp-273.15)*9/5+32;
      return temp;
    }
    if(target=="Kelvin"){
      if(unit=="Celsius") return temp+273.15;
      if(unit=="Fahrenheit") return (temp-32)*5/9+273.15;
      return temp;
    }
    cout<<"Invalid target unit\n";
    return temp;
  }
  
  void print(){
    cout<<"The temperature is "<<temp<<" "<<unit<<"\n";
  }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  Temperature t;
  t.assign(100, "Celsius");
  t.print(); 
  
  cout<<t.convert("Fahrenheit")<<"\n";
  
  t.assign(-500, "Celsius"); 
  
  t.assign(100, "Kelvin");
  t.print(); 
  
  cout<<t.convert("Celsius")<<"\n";
}


