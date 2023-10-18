#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }

    if (n == 4) {
        cout << "2 4 1 3" << endl;
        return 0;
    }

    if (n < 4) {
        cout << "NO SOLUTION" << endl;
        return 0;
    }

    for (int i = 1; i < n / 2 + 1; i++) {
        if (n % 2)
            cout << i << ' ' << i + n / 2 + 1 << ' ';
        else
            cout << i << ' ' << i + n / 2 << ' ';
    }

    if (n % 2)
        cout << n / 2 + 1;

    return 0;
}