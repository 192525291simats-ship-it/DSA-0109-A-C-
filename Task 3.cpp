
#include <iostream>
#include <climits>
using namespace std;

int main() {
    int zone = 1;
    long long farePaise = 1000;
    long long balancePaise = 10000;
    double fareRupees = static_cast<double>(farePaise) / 100;
    bool valid = true;
    char symbol = 'R';

    cout << "Size of int: " << sizeof(int) << " bytes\n";
    cout << "Size of long long: "
         << sizeof(long long) << " bytes\n";
    cout << "Size of double: " << sizeof(double) << " bytes\n";
    cout << "Size of bool: " << sizeof(bool) << " bytes\n";

    cout << "INT_MAX: " << INT_MAX << '\n';
    cout << "Fare in rupees: " << fareRupees << '\n';
    cout << "Balance in paise: " << balancePaise << '\n';
    cout << "Zone: " << zone << '\n';
    cout << "Valid: " << valid << '\n';
    cout << "Currency symbol: " << symbol << '\n';

    return 0;
}
