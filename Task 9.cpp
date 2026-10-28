
#include <iostream>
using namespace std;

long long calculateFare(int zone, bool peak) {
    long long base;

    switch (zone) {
        case 1: base = 1000; break;
        case 2: base = 2000; break;
        case 3: base = 3000; break;
        default: return -1;
    }

    if (peak)
        base += base * 20 / 100;

    return base;
}

bool canTravel(long long balance, long long fare) {
    return fare >= 0 && balance - fare >= 5000;
}

int main() {
    int zones[] = {1, 2, 3, 1, 4};
    bool peaks[] = {false, false, false, true, false};

    for (int i = 0; i < 5; i++) {
        long long f = calculateFare(zones[i], peaks[i]);

        cout << "Test " << i + 1 << ": ";

        if (f < 0) {
            cout << "Invalid zone\n";
        } else {
            cout << "Fare = " << f << " paise\n";
            cout << (canTravel(10000, f)
                     ? "Journey allowed\n"
                     : "Journey denied\n");
        }
    }

    return 0;
}
