// Anggota Kelompok:
// 1. Diaz Amantajati Susilo (24/545483/TK/60678)
// 2. Galang Swastika Ramadhan (24/538251/TK/59692)

#include <iostream>
#include <string>
class FuelTank {
    private:
    long long fuel;
    bool isFuelPositive(){
        if(fuel < 0) return false;
        else return true;
    }
    bool canTravel (long long fuel_needed){
        if (fuel_needed >= fuel) return false;
        else return true;
    }

    public:
    FuelTank(long long initial_fuel) : fuel(initial_fuel) {}
    void refuel (long long add_fuel) {
        fuel += add_fuel;
    }
    void travel (long long reduce_fuel) {
        if (canTravel(reduce_fuel)){
            fuel -= reduce_fuel;
        } else {
            return;
        }
    }
    long long report (int x) {
        if (isFuelPositive() && x == 0){
            std::cout << fuel << "\n";
            return fuel;
        } 
        else return -1;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    long long initial_fuel;
    int Q;
    std::cin >> initial_fuel >> Q;
    FuelTank roket(initial_fuel);
    for (int i = 0; i < Q; ++i) {
        std::string operation;
        int x;
        std::cin >> operation >> x;
        if (operation == "REFUEL") {
            roket.refuel(x);
        } else if (operation == "TRAVEL") {
            roket.travel(x);
        } else if (operation == "REPORT") {
            roket.report(x);
        }
    }
    return 0;
}