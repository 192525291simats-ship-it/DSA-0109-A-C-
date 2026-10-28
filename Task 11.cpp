
#include <iostream>
using namespace std;

enum class Zone { Inner, Middle, Outer };

constexpr long long FARES[] = {1000, 2000, 3000};
constexpr long long MIN_BALANCE = 5000;
constexpr int PEAK_PERCENT = 20;

long long calculateFare(Zone zone, bool peak) {
    int index;

    switch (zone) {
        case Zone::Inner: index = 0; break;
        case Zone::Middle: index = 1; break;
        case Zone::Outer: index = 2; break;
        default: return -1;
    }

    long long f = FARES[index];

    if (peak)
        f += f * PEAK_PERCENT / 100;

    return f;
}

class SmartCard {
private:
    long long balance;

public:
    SmartCard(long long initial) : balance(initial) {}

    bool canTravel(long long fare) const {
        return fare >= 0 && balance - fare >= MIN_BALANCE;
    }

    bool deduct(long long fare) {
        if (!canTravel(fare))
            return false;

        balance -= fare;
        return true;
    }

    long long getBalance() const {
        return balance;
    }
};

int main() {
    SmartCard card(10000);
    long long f = calculateFare(Zone::Middle, true);

    if (card.deduct(f))
        cout << "Journey allowed\n";
    else
        cout << "Journey denied\n";

    cout << "Remaining balance: "
         << card.getBalance() << " paise\n";

    return 0;
}
