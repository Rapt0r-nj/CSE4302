#include<bits/stdc++.h>
using namespace std;

using ll = long long;

class Counter {
  ll cnt, stp;
public:
  Counter() : cnt(0), stp(1) {}
  
  void setIncrementStep(ll s){
    stp=s;
  }
  
  ll getCount(){
    return cnt;
  }
  
  void increment(){
    cnt+=stp;
  }
  
  void resetCount(){
    cnt=0;
  }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  Counter c;
  c.setIncrementStep(5);
  c.increment();
  cout<<c.getCount()<<"\n";
  
  c.increment();
  cout<<c.getCount()<<"\n";
  
  c.resetCount();
  cout<<c.getCount()<<"\n";
}

