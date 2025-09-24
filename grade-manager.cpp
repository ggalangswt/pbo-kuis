#include <iostream>

using namespace std;
class Student {
private:
int id;
string name;
vector<int> grades;
public:
Student(int student_id, const string& student_name)
: id(student_id), name(student_name) {}
int get_id() const {}
string get_name() const {}
void add_grade(int grade) {
}
double calculate_sum() const {
}
bool has_grades() const {
}
};
class GradeManager {
private:
vector<Student> students;
map<int, int> id_to_index;
public:
void add_student(int id, const string& name) {
}
void add_grade(int id, int grade) {
}
void show_sum(int id) {
}
void list_all_students() {
  }
};
int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
int Q;
cin >> Q;
GradeManager manager;
for (int i = 0; i < Q; i++) {
string operation;
cin >> operation;
}
return 0;
}