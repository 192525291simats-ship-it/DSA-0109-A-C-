
#include <iostream>
using namespace std;

class FareTable {
public:
    static int getFare(int zone) {
        switch (zone) {
            case 1: return 1000;
            case 2: return 2000;
            case 3: return 3000;
            default: return -1;
        }
    }
};

class SmartCard {
private:
    long long balance;

public:
    SmartCard(long long b) : balance(b) {}

    bool canTravel(long long fare) {
        return fare >= 0 && balance - fare >= 5000;
    }

    void deduct(long long fare) {
        if (canTravel(fare))
            balance -= fare;
        else
            cout << "Journey denied\n";
    }

    long long getBalance() const {
        return balance;
    }
};

class Journey {
public:
    int zone;
    bool peak;

    Journey(int z, bool p) : zone(z), peak(p) {}

    long long calculateFare() const {
        int base = FareTable::getFare(zone);
        if (base < 0) return -1;
        return peak ? base + base * 20 / 100 : base;
    }
};

int main() {
    SmartCard card(10000);
    Journey trip(1, false);

    long long fare = trip.calculateFare();

    if (card.canTravel(fare)) {
        card.deduct(fare);
        cout << "Fare in paise: " << fare << '\n';
        cout << "Balance in paise: "
             << card.getBalance() << '\n';
    } else {
        cout << "Journey denied\n";
    }

    return 0;
}
