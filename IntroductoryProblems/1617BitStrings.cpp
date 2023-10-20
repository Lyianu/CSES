#include <iostream>
using namespace std;

typedef long long LL;

const LL MOD = 1e9 + 7;

// returns 2^n (base == 2)
LL binexp(LL n) {
    if (n == 0) {
        return 1;
    }
    if (n == 1) {
        return 2;
    }
    if (n % 2) {
        return 2 * binexp(n / 2) * binexp(n / 2) % MOD;
    }
    return binexp(n / 2) * binexp(n / 2) % MOD;
}

int main()
{
    LL n;
    cin >> n;
    cout << binexp(n) << endl;
}