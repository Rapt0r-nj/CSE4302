#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H

#include <bits/stdc++.h>

using namespace std;

class SavingsAccount {
  string accName;
  string address;
  double annualInterestRate;
  double currentBalance;
  double minBalance;

public:
  SavingsAccount();
  
  string getAccName() const;
  string getAddress() const;
  double getAnnualInterestRate() const;
  double getCurrentBalance() const;
  
  void setAccName(string a);
  void setAddress(string b);
  void setAnnualInterestRate(double a);
  void setCurrentBalance(double a);
  
  void deposit(double a);
  void withdraw(double a);
  
  double calculateInterest(int periodInMonths) const;
  void disburseInterest(int periodInMonths);
};

void EditInformationByKeyboard(SavingsAccount &acc);
void generateInformationRandom(SavingsAccount &acc);
void ShowInterestAll(SavingsAccount ar[]);
void ShowAllAlphabetically(SavingsAccount ar[]);

#endif // SAVINGS_ACCOUNT_H

