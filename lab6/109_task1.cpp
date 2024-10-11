#include<bits/stdc++.h>
using namespace std;

#define en "\n"
#define fir(_o) for(int i=0;i<_o;++i)

class Counter{
  int cnt,step;
public:
  Counter(int s=1){cnt=0; step=s>0? s: 1  ;}
  void setIncrementStep(int s){
    if(cnt==0 and s>0) step=s;
    else cout<<"Can't set increment step"<<en;
  }
  int getCount() const {return cnt;}
  void increment(){cnt+=step;}
  void resetCount(int s=1){cnt=0; step=(s>0? s: 1);}
  Counter operator+(const Counter&x) const {
    Counter r;
    if(step==x.step) r.cnt=cnt+x.cnt, r.step=step;
    else cout<<"Steps not same..Aborting"<<en;
    return r;
  }
  Counter& operator+=(const Counter& x){
    if(step==x.step) cnt+=x.cnt;
    return *this;
  }
  bool operator==(const Counter&x) const {return cnt==x.cnt;}
  bool operator!=(const Counter&x) const {return cnt!=x.cnt;}
  bool operator>(const Counter&x) const {return cnt>x.cnt;}
  bool operator<(const Counter&x) const {return cnt<x.cnt;}
  bool operator>=(const Counter&x) const {return cnt>=x.cnt;}
  bool operator<=(const Counter&x) const {return cnt<=x.cnt;}
  Counter operator++(){++cnt; return *this;}
  Counter operator++(int){Counter t=*this; ++cnt;return t;}
};

void testFunction(const Counter&c){
  cout<<c.getCount()<<en;
}

int main(){

}

