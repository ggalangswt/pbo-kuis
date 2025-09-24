// Anggota Kelompok:
// 1. Diaz Amantajati Susilo (24/545483/TK/60678)
// 2. Galang Swastika Ramadhan (24/538251/TK/59692)
#include <bits/stdc++.h>
using namespace std;
class Transport {
    public:
    virtual int fare(int d) const = 0;
    virtual ~Transport() = default;
    };
class Car : public Transport {
    public:
    int fare(int d) const override {
        return 100 + 10 * d;
    }
};
class Bus : public Transport {
    public:
    int fare(int d) const override {
        return 50 + 8 * d;
    }
};
class Train : public Transport {
    public:
    int fare(int d) const override {
        if (d <= 50) return 200 + 3 * d;
        return 200 + 3 * 50 + 2 * (d - 50);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q; cin >> Q;
    while (Q--) {
        string type; int d; cin >> type >> d;

        unique_ptr<Transport> t;
        if (type == "CAR") t = make_unique<Car>();
        else if (type == "BUS") t = make_unique<Bus>();
        else if (type == "TRAIN") t = make_unique<Train>();
        cout << t->fare(d) << "\n";
    }
    return 0;
}