
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    const long long farePaise = 1001; // Rs 10.01
    const double fareRupees = 10.01;
    long long counts[] = {20000, 500000, 3000000};

    cout << fixed << setprecision(2);

    for (long long n : counts) {
        long long totalPaise = n * farePaise;
        double totalRupees = n * fareRupees;

        cout << "Journeys: " << n << '\n';
        cout << "Integer-paise total: Rs "
             << totalPaise / 100 << '.'
             << setw(2) << setfill('0') << totalPaise % 100
             << setfill(' ') << '\n';
        cout << "Double total: Rs " << totalRupees << '\n';
        cout << "Long long total in paise: "
             << totalPaise << "\n\n";
    }

    cout << "INT_MAX: " << 2147483647 << '\n';
    cout << "3 million journeys exceed int capacity "
         << "when storing the paise total.\n";

    return 0;
}
