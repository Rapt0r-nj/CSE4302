#include<bits/stdc++.h>
using namespace std;

using ll =  long long;

class Time {
  ll hr, mn, sc;
  
public:
  Time() : hr(0), mn(0), sc(0) {}
  
  ll hours(){
    return hr;
  }
  
  ll minutes(){
    return mn;
  }
  
  ll seconds(){
    return sc;
  }
  
  void reset(ll h, ll m, ll s){
    hr = h % 24;
    mn = m % 60;
    sc = s % 60;
  }
  
  void advance(ll h, ll m, ll s){
    sc += s;
    mn += m+sc/60;
    hr += h+mn/60;
    
    sc %= 60;
    mn %= 60;
    hr %= 24;
  }
  
  void print(){
    cout<<hr<<":"<<mn<<":"<<sc<<"\n";
  }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  Time t;
  t.reset(23, 59, 59);
  t.print();
  
  t.advance(0, 0, 1);
  t.print();
  
  t.reset(12, 30, 45);
  t.advance(1, 40, 30);
  t.print();
}

