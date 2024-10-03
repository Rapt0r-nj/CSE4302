#include "employee.h"
#include <iostream>
using namespace std;

int main() {
  Employee emp1, emp2;

  cout << "Enter details for Employee 1:" << endl;
  emp1.setInfo();

  cout << "\nEnter details for Employee 2:" << endl;
  emp2.setInfo();

  cout << "\nInformation for Employee 1:" << endl;
  emp1.getInfo();

  cout << "\nInformation for Employee 2:" << endl;
  emp2.getInfo();

  Employee elder = emp1.compareAge(emp2);
  cout << "\nThe elder employee is: " << elder.getName() << endl;

  return 0;
}

