// Anggota Kelompok:
// 1. Diaz Amantajati Susilo (24/545483/TK/60678)
// 2. Galang Swastika Ramadhan (24/538251/TK/59692)
#include <bits/stdc++.h>
using namespace std;
class Animal {
    public:
    virtual ~Animal() {}
    virtual string speak() const = 0;
};
class Dog : public Animal {
    public:
    string speak() const override {
        return "Woof";
    }
};
class Cat : public Animal {
    public:
    string speak() const override {
        return "Meow";
    }
};
class Cow : public Animal {
    public:
    string speak() const override {
        return "Moo";
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int Q; cin >> Q;
    while (Q--) {
        string t; cin >> t;
        int k = 1;
        if (cin.peek() == ' ') {
            cin >> k;
        }


        unique_ptr<Animal> run;
        if (t == "DOG"){
            run = make_unique<Dog>();
        } else if (t == "CAT"){
            run = make_unique<Cat>();
        } else if (t == "COW"){
            run = make_unique<Cow>();
        }
        if (k > 0) {
            cout << run->speak();
            for (int i = 1; i < k; i++) {
                cout << " " << run->speak();
            }
        }
        cout << "\n";
    }
    return 0;
}