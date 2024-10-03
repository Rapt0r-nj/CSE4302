#include "savingsAcc.h"

SavingsAccount::SavingsAccount(){
  accName = "";
  address = "";
  annualInterestRate = 0.03;
  currentBalance = 0.0;
  minBalance = 0.0;
}

string SavingsAccount::getAccName() const {return accName;}
string SavingsAccount::getAddress() const {return address;}
double SavingsAccount::getAnnualInterestRate() const {return annualInterestRate;}
double SavingsAccount::getCurrentBalance() const {return currentBalance;}


void SavingsAccount::setAccName(string a) {accName = a;}
void SavingsAccount::setAddress(string b) {address = b;}
void SavingsAccount::setAnnualInterestRate(double a) {annualInterestRate = a;}
void SavingsAccount::setCurrentBalance(double a) {currentBalance = a;}

void SavingsAccount::deposit(double a) {currentBalance += a;}

void SavingsAccount::withdraw(double a) {
  if(currentBalance >= a) {
    currentBalance -= a;
    minBalance=min(minBalance, currentBalance);
  }
  else{
    cout<<"YOU POOR"<<endl;
  }
}

double SavingsAccount::calculateInterest(int periodInMonths) const {
  double monthlyRate = annualInterestRate / 12 / 100;
  return minBalance * monthlyRate * periodInMonths;
}

void SavingsAccount::disburseInterest(int periodInMonths) {
  double interest = calculateInterest(periodInMonths);
  deposit(interest);
  minBalance = currentBalance;
}

void EditInformationByKeyboard(SavingsAccount &acc) {
  string name, address;
  double interestRate, balance;
  
  cout << "Enter Name: "; getline(cin, name);
  cout << "Enter Address: "; getline(cin, address);
  cout << "Enter Interest Rate: "; cin >> interestRate;
  cout << "Enter Current Balance: "; cin >> balance;
  cin.ignore();
  
  acc.setAccName(name);
  acc.setAddress(address);
  acc.setAnnualInterestRate(interestRate);
  acc.setCurrentBalance(balance);
}

void generateInformationRandom(SavingsAccount &acc) {
  static long long prime = 1e9+7;
  static int intr = 60;
  string name = to_string((prime*998244353)%10000);
  string address = to_string((prime*99824353)%10000);
  
  double interestRate = ((intr*9889)%100)/100;
  double balance = ((intr*989+123)%100)/100;

  prime*=909; prime%=1000000000;
  intr*=89; intr%=100;
  
  acc.setAccName(name);
  acc.setAddress(address);
  acc.setAnnualInterestRate(interestRate);
  acc.setCurrentBalance(balance);
}

void ShowInterestAll(SavingsAccount ar[]){
  cout<<"Enter month: "<<endl;
  int m; cin>>m;

  for(int i=0; i<100; i++){
    cout<<"Acc "<<i<<": "<<ar[i].calculateInterest(m)<<endl;
  }
  cout<<"proceed? y/N"<<endl;
  string s; cin>>s;
  if(s=="y") for(int i=0; i<100; i++) ar[i].disburseInterest(m);
  else cout<<"tata"<<endl;
}

