
#include <iostream>
using namespace std;

enum class Zone { Inner, Middle, Outer };

constexpr long long INNER_FARE = 1000;
constexpr long long MIDDLE_FARE = 2000;
constexpr long long OUTER_FARE = 3000;
constexpr int SURCHARGE = 20;
constexpr long long MIN_BALANCE = 5000;

int main() {
    Zone z = Zone::Inner;
    long long fare = INNER_FARE;

    if (z == Zone::Inner)
        fare = INNER_FARE;

    cout << "Base fare: " << fare << " paise\n";
    cout << "Peak surcharge: " << SURCHARGE << "%\n";
    cout << "Minimum balance: " << MIN_BALANCE
         << " paise\n";

    return 0;
}
