#include "savingsAcc.h"

int main() {
  SavingsAccount accounts[100]={SavingsAccount(), };
  for(int i=0; i<5; i++){
    //EditInformationByKeyboard(accounts[i]);
  }
  for(int i=5; i<100; i++){
    generateInformationRandom(&accounts[i]); 
  }
  sort(accounts, accounts+100, [](SavingsAccount a, SavingsAccount b){return a.getAccName() < b.getAccName();});

  ShowInterestAll(accounts);
  cout<<rand()<<endl;
}

