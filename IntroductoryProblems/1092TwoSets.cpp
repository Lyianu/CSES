#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    // (n + 1)*n / 2 % 2 == 1
    if ((n & 3) != 0b11 && (n & 3)) {
        cout << "NO" << endl;
        return 0;
    }
    else 
        cout << "YES" << endl;

    // 1 2 for G1, 3 for G2
    if (n % 2) {
        // G1:
        cout << n / 2 + 1 << endl;
        cout << "1 2";
        for (int i = 4; i <= 3 + (n - 3) / 4; i++) {
            cout << ' ' << i;
        }
        for (int i = n + 1 - ((n - 3) / 4); i <= n; i++) {
            cout << ' ' << i;
        }

        cout << endl << n / 2 << endl;

        // G2:
        cout << "3";
        for (int i = 4 + (n - 3) / 4; i <= n - (n - 3) / 4; i++) {
            cout << ' ' << i;
        }
    } else {
        cout << n / 2 << endl;
        for (int i = 1; i <= n / 4; i++) {
            cout << i << ' ';
        }
        for (int i = 3 * n / 4 + 1; i <= n; i++) {
            cout << i << ' ';
        }

        cout << endl << n / 2 << endl;

        for (int i = n / 4 + 1; i <= 3 * n / 4; i++) {
            cout << i << ' ';
        }
    }

    cout << endl;

    return 0;
}