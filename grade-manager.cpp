// Anggota Kelompok:
// 1. Diaz Amantajati Susilo (24/545483/TK/60678)
// 2. Galang Swastika Ramadhan (24/538251/TK/59692)

#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Student {
 private:
  int id;
  string name;
  vector<int> grades;

 public:
  Student(int student_id, const string& student_name)
      : id(student_id), name(student_name) {}
  int get_id() const {
    return id;
  }

  string get_name() const {
    return name;
  }

  void add_grade(int grade) {
    if(0 <= grade && grade <= 100) {
      grades.push_back(grade);
    }
  }

  double calculate_sum() const {
    double s = 0;
    for(int g : grades) s += g;
    return s;
  }

  bool has_grades() const {
    return !grades.empty();
  }
};

class GradeManager {
 private:
  vector<Student> students;
  map<int, int> id_to_index;

 public:
  void add_student(int id, const string& name) {
    if(id_to_index.count(id)) return;
    int sha = (int)students.size();
    students.emplace_back(id, name);
    id_to_index[id] = sha;
  }

  void add_grade(int id, int grade) {
    auto it = id_to_index.find(id);
    if(it == id_to_index.end()) return;
    students[it->second].add_grade(grade);
  }

  void show_sum(int id) {
    auto it = id_to_index.find(id);
    if(it == id_to_index.end()) {
      return;
    }
    const Student& student = students[it->second];
    if(!student.has_grades()) {
      cout << "No grades available.\n";
      return;
    }
    cout << student.get_name() << ": " << student.calculate_sum() << "\n";
  }

  void list_all_students() {
    for(const Student& student : students) {
      cout << student.get_name() << ": " << student.calculate_sum() << "\n";
    }
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int Q;
  cin >> Q;

  GradeManager manager;
  for(int i = 0; i < Q; i++) {
    string operation;
    cin >> operation;

    string run = operation;
    if(run == "ADD") {
      int id;
      string name;
      cin >> id >> name;
      manager.add_student(id, name);
    } else if(run == "GRADE") {
      int id, grade;
      cin >> id >> grade;
      manager.add_grade(id, grade);
    } else if(run == "SUM") {
      int id;
      cin >> id;
      manager.show_sum(id);
    } else if(run == "LIST") {
      manager.list_all_students();
    }
  }
  return 0;
}