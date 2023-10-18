#include <iostream>
using namespace std;

struct BigNum {
    int data[30];
    int length;
};

typedef long long LL;

int main()
{
    int t;
    cin >> t;

    while (t--) {
        int y, x;
        cin >> y >> x;

        // center square
        LL number = (max(x, y) - 1) * (max(x, y) - 1);

        // if x is the bigger one, y decides the outer circle
        if (x == max(x, y)) {
            // numbers goes CCW
            if (x % 2) {
                number += 2 * x - y - 1;
            } else {
                // CW
                number += y;
            }
        } else {
            // CCW
            if (y % 2) {
                number += x;
            } else {
                // CW
                number += 2 * y - x - 1;
            }
        }
        cout << number + 1 << endl;
    }

    return 0;
}