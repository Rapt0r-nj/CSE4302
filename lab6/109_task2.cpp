#include<bits/stdc++.h>
using namespace std;

using ll = long long;
#define en "\n"
#define fir(_o) for(int i=0;i<_o;++i)
#define fjr(_o) for(int j=0;j<_o;++j)

class Coordinate{
  float x, y;
public:
  Coordinate():x(0),y(0){}
  Coordinate(float _x,float _y):x(_x),y(_y){}
  ~Coordinate(){}
  void display() const {cout<<x<<" "<<y<<en;}
  float operator-(const Coordinate& c) const {return sqrt(pow(x-c.x, 2)+pow(y-c.y, 2));}
  float getDistance() const {return sqrt(x*x+y*y);}
  void move_x(float val){x+=val;}
  void move_y(float val){y+=val;}
  void move(float xv, float yv){x+=xv; y+=yv;}
  bool operator==(const Coordinate& c) const {return x==c.x and y==c.y;}
  bool operator!=(const Coordinate& c) const {return !(*this==c);}
  bool operator>(const Coordinate& c) const {return getDistance()>c.getDistance();}
  bool operator<(const Coordinate& c) const {return getDistance()<c.getDistance();}
  bool operator>=(const Coordinate& c) const {return getDistance()>=c.getDistance();}
  bool operator<=(const Coordinate& c) const {return getDistance()<=c.getDistance();}
};

int randm(){
  static ll seed=1e9+7;
  seed*=(998244353);
  return abs(seed%54312);
}

void randomAssignment(Coordinate c[],int n){
  fir(n) c[i]=Coordinate(randm()%101-50, randm()%101-50);
}

void sort(Coordinate c[],int n){
  sort(c, c+n, [&](const Coordinate& a,const Coordinate& b){return a.getDistance()<b.getDistance();});
}

float highest(Coordinate c[],int n){
  float mx=0;
  fir(n) fjr(i) mx=max(mx, c[i]-c[j]);
  return mx;
}

float lowest(Coordinate c[],int n){
  float mx=99999;
  fir(n) fjr(i) mx=min(mx, c[i]-c[j]);
  return mx;
}

void Stat(Coordinate c[], int n){
  fir(10){
    cout<<"point "<<i<<" "<<en;
    c[i].display();
  }
  cout<<"max distance of two points "<<highest(c, n)<<en;
  cout<<"min distance of two points "<<lowest(c, n)<<en;

}

int main(){
  Coordinate cord[10];
  randomAssignment(cord,10);
  Stat(cord, 10);
  return 0;
}

