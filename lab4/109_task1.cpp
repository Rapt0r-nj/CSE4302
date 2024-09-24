#include<bits/stdc++.h>
using namespace std;

using ll =  long long;
#define en "\n"

class Calculator {
  ll curState;
  
public:
  Calculator() : curState(0) {}
  Calculator(ll i) : curState(i) {}

  void add(ll i) {curState+=i;}
  void subtract(ll i) {curState-=i;}
  void multiply(ll i) {curState*=i;}
  ll devideBy(ll i) {
    if(!i){
      cout<<"Invalid Arg"<<en;
      return LLONG_MIN;
    }
    ll r=curState%i;
    curState/=i;
    return r;
  }

  void clear(){curState=0;}
  void display(){cout<<curState<<en;}

  ~Calculator(){
    display();
    cout<<"Destructor of the calculator object is called"<<en;
  }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  Calculator c(5);
  c.add(7);
  cout<<c.devideBy(5)<<en;
  c.display();
}

