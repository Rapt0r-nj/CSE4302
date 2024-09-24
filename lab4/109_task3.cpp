#include<bits/stdc++.h>
using namespace std;

using ll = long long;
#define en "\n"

class BankAccount {
  ll accNum;
  string name;
  bool type;
  ll balance;
  ll const minBalance;
  static ll totAcc;
  static ll ActAcc;
  static ll totTax;
public:
  BankAccount(ll a, string b, string t, ll d, ll e) : 
    accNum(a),
    name(b),
    type(t=="current"),
    balance(d),
    minBalance(e) {
    totAcc++;
    ActAcc++;
  }

  void showInfo(){
    cout<<accNum<<en;
    cout<<name<<en;
    cout<<(type? "current": "savings")<<en;
    cout<<"balance "<< balance<<en;
  }
  
  void showBalance(){
    cout<<"balance "<< balance<<en;
  }
  
  void deposit(ll a){
    balance+=a;
    cout<<"balance updated"<<en;
  }
  
  void withdraw(ll a){
    if(balance-a<minBalance){
      cout<<"Not enough balance"<<en;
      return;
    }
    balance-=a;
    cout<<"balance updated"<<en;
  }
  
  void giveInterest(){
    cout<<"// HARAM //"<<en;
    ll intr=(balance*3)/100;
    ll tax=intr/10;
    balance+=intr-tax;
    cout<<intr<<" added to balance"<<en;
    totTax+=tax;
    cout<<"// HARAM //"<<en;
  }
  
  void giveInterest(int a){
    cout<<"// HARAM //"<<en;
    ll intr=(balance*a)/100;
    ll tax=intr/10;
    balance+=intr-tax;
    cout<<intr<<" added to balance"<<en;
    totTax+=tax;
    cout<<"// HARAM //"<<en;
  }
  
  static ll getTotTax(){
    return totTax;
  }
  
  static ll getTotAcc(){
    return totAcc;
  }
  
  static ll getActAcc(){
    return ActAcc;
  }
  
  friend void displayStat();

  ~BankAccount(){
    cout<<"acc of mr. "<<name<<" with acc no. "<<accNum<<
      " is destroyed with balance "<< balance<<en;
    ActAcc--;
  }
};

ll BankAccount::totAcc = 0;
ll BankAccount::ActAcc = 0;
ll BankAccount::totTax = 0;

void displayStat(){
  cout<<"total acc "<<BankAccount::getTotAcc()<<en;
  cout<<"active acc "<<BankAccount::getActAcc()<<en;
  cout<<"total tax "<<BankAccount::getTotTax()<<en;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  BankAccount b(1, "kabir", "savings", 1000, 100);
  b.giveInterest(5);
  cout<<BankAccount::getTotTax()<<en;
  b.showInfo();
}

