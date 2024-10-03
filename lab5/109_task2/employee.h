#include <string>

class Employee {
  std::string name;
  int day, month, year;
  long long salary;

  void validateName(std::string& n) const;
  void validateDOB(int d, int m, int y);
  void validateSalary(long long& s) const;
  
public:
  Employee();
  
  void setName(const std::string&);
  void setDOB(int, int, int);
  void setSalary(long long);
  void setInfo();

  std::string getName() const;
  void getDOB(int&, int&, int&) const;
  long long getSalary() const;
  void getInfo() const;

  const Employee compareAge(const Employee&) const;
};

