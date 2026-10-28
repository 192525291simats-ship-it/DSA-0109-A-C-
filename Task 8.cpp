
#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

int main() {
    double rupees;

    while (true) {
        cout << "Enter fare in rupees: ";

        if (cin >> rupees && rupees >= 0)
            break;

        cout << "Invalid input. Try again.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << fixed << setprecision(2);
    cout << "Fare: Rs " << rupees << '\n';

    return 0;
}
