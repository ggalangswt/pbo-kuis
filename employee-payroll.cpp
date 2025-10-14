// Anggota Kelompok:
// 1. Diaz Amantajati Susilo (24/545483/TK/60678)
// 2. Galang Swastika Ramadhan (24/538251/TK/59692)

#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

class Employee {
 protected:
  string name;

 public:
  Employee(const string& name) : name(name) {}
  virtual long long salary() const = 0;
  string get_name() const {
    return name;
  }
  virtual ~Employee() {};
};
class FullTime : public Employee {
  int baseSalary;
  int bonus;

 public:
  FullTime(const string& name, int base, int bonus)
      : Employee(name), baseSalary(base), bonus(bonus) {}
  long long salary() const override {
    return (long long)baseSalary + bonus;
  }
};

class PartTime : public Employee {
  int hourlyRate;
  int hours;

 public:
  PartTime(const string& name, int rate, int hours)
      : Employee(name), hourlyRate(rate), hours(hours) {}
  long long salary() const override {
    return (long long)hourlyRate * hours;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int Q;
  cin >> Q;

  vector<unique_ptr<Employee>> v;
  int run = 0;
  while(Q--) {
    string type;
    cin >> type;
    run++;

    if(type == "FULLTIME") {
      string name;
      int base, bonus;
      cin >> name >> base >> bonus;
      int sha = v.size();
      v.push_back(make_unique<FullTime>(name, base, bonus));
    } else if(type == "PARTTIME") {
      string name;
      int rate, hours;
      cin >> name >> rate >> hours;
      int sha = v.size();
      v.push_back(make_unique<PartTime>(name, rate, hours));
    }
  }

  for(auto& e : v) {
    cout << e->get_name() << ": " << e->salary() << "\n";
  }
}