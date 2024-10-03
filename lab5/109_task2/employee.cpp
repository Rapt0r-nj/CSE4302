#include "employee.h"
#include <iostream>
using namespace std;

Employee::Employee() : name("John Doe"), day(1), month(1), year(2002), salary(10000) {}

void Employee::validateName(std::string& n) const {
  if(n.length() <= 2) n = "John Doe";
}

void Employee::validateDOB(int d, int m, int y) {
  if(y > 2004 || (y == 2004 && m == 10 && d > 3)) {
    day = 1; month = 1; year = 2002;
  }
}

void Employee::validateSalary(long long& s) const {
  if(s < 10000 || s > 100000) s = 10000;
}

void Employee::setName(const std::string& n) {
  std::string tempName = n;
  validateName(tempName);
  name = tempName;
}

void Employee::setDOB(int d, int m, int y) {
  validateDOB(d, m, y);
  day = d; month = m; year = y;
}

void Employee::setSalary(long long s) {
  validateSalary(s);
  salary = s;
}

void Employee::setInfo() {
  std::string n;
  int d, m, y;
  long long s;

  cout << "Enter Name: "; 
  cin >> n; 
  setName(n);

  cout << "Enter DOB (day month year): ";
  cin >> d >> m >> y;
  setDOB(d, m, y);

  cout << "Enter Salary: ";
  cin >> s;
  setSalary(s);
}

std::string Employee::getName() const {
  return name;
}

void Employee::getDOB(int& d, int& m, int& y) const {
  d = day;
  m = month;
  y = year;
}

long long Employee::getSalary() const {
  return salary;
}

void Employee::getInfo() const {
  int d, m, y;
  getDOB(d, m, y);
  
  cout << "Name: " << getName() << endl;
  cout << "DOB: " << d << "-" << m << "-" << y << endl;
  cout << "Salary: " << getSalary() << endl;
}

const Employee Employee::compareAge(const Employee& e) const {
  if (year < e.year || (year == e.year && (month < e.month || (month == e.month && day < e.day))))
    return *this;
  return e;
}

