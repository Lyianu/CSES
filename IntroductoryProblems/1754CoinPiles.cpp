#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        if (a == b) {
            if (!(a % 3))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
            continue;
        }
        if (a > b) {
            int tmp = a;
            a = b;
            b = tmp;
        }

        a -= b - a;
        if (!(a % 3) && a >= 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}