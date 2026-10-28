
#include <iostream>
using namespace std;

enum class Zone { Inner, Middle, Outer, Airport };

constexpr long long FARES[] = {1000, 2000, 3000, 6000};

int zoneIndex(Zone z) {
    switch (z) {
        case Zone::Inner: return 0;
        case Zone::Middle: return 1;
        case Zone::Outer: return 2;
        case Zone::Airport: return 3;
        default: return -1;
    }
}

long long calculateFare(Zone z, bool peak, bool weekend) {
    int index = zoneIndex(z);
    if (index < 0) return -1;

    long long f = FARES[index];

    if (weekend)
        f = f * 90 / 100;
    else if (peak)
        f = f * 120 / 100;

    return f;
}

class Pass {
private:
    Zone zone1, zone2;

public:
    Pass(Zone a, Zone b) : zone1(a), zone2(b) {}

    bool isValidFor(Zone z) const {
        return z == zone1 || z == zone2;
    }
};

class SmartCard {
private:
    long long balance;

public:
    SmartCard(long long b) : balance(b) {}

    bool pay(long long fare) {
        if (fare < 0 || balance - fare < 5000)
            return false;

        balance -= fare;
        return true;
    }

    long long getBalance() const {
        return balance;
    }
};

int main() {
    SmartCard card(20000);
    Pass monthlyPass(Zone::Inner, Zone::Airport);

    Zone trips[] = {
        Zone::Inner, Zone::Middle,
        Zone::Airport, Zone::Outer
    };

    bool peak[] = {true, true, false, false};
    bool weekend[] = {false, true, false, true};

    for (int i = 0; i < 4; i++) {
        cout << "Journey " << i + 1 << ": ";

        if (monthlyPass.isValidFor(trips[i])) {
            cout << "Monthly pass used\n";
            continue;
        }

        long long f = calculateFare(trips[i], peak[i], weekend[i]);

        if (card.pay(f))
            cout << "Fare = " << f << " paise\n";
        else
            cout << "Journey denied\n";
    }

    cout << "Final balance: " << card.getBalance()
         << " paise\n";

    return 0;
}
