
#include <iostream>
using namespace std;

// Procedural approach
bool proceduralCanTravel(long long balance, long long fare) {
    return fare >= 0 && balance - fare >= 5000;
}

// Object-oriented approach
class SmartCard {
private:
    long long balance;

public:
    SmartCard(long long b) : balance(b) {}

    bool canTravel(long long fare) const {
        return fare >= 0 && balance - fare >= 5000;
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
    long long balance = 10000;
    long long fare = 2000;

    if (proceduralCanTravel(balance, fare)) {
        balance -= fare;
        cout << "Procedural balance: " << balance << '\n';
    }

    SmartCard card(10000);

    if (card.deduct(fare))
        cout << "OOP balance: " << card.getBalance() << '\n';

    return 0;
}
