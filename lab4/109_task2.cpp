#include<bits/stdc++.h>
using namespace std;

using ll =  long long;
#define en "\n"

class Flight {
  ll flightNum;
  string dest;
  double distance;
  double mxFC;
  
public:
  Flight(ll a, string b, double c, double d) : 
    flightNum(a),
    dest(b),
    distance(c),
    mxFC(d){}

  double calFuel(){
    return (distance<=1000.0? 500: (distance<=2000? 1100: 2200));
  }
  void feedInfo(ll a, string b, double c, double d){
    flightNum=a;
    dest=b;
    distance=c;
    mxFC=d;
  }
  void showInfo(){
    cout<<"Flight Num: "<<flightNum<<en;
    cout<<"dest: "<<dest<<en;
    cout<<"distance: "<<distance<<en;
    cout<<"max fuel capacity: "<<mxFC<<en;
    cout<<(
      mxFC<calFuel()?
      "Not enough fuel":
      "All good"
    )<<en;
  }

};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  Flight f(0, "dhaka", 24.5, 1000);
  f.feedInfo(911, "washington DC", 1000, 10000);
  f.showInfo();
}

