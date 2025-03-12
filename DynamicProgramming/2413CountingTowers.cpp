#include <iostream>
using namespace std;

typedef long long ll;

ll A[1100000], B[1100000];

int mod = 1e9+7;

ll mul(ll a, ll b) {
    return ((a % mod) * (b % mod)) % mod;
}

ll add(ll a, ll b) {
    return (a + b) % mod;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    A[1] = 1;   // |_ _|
    B[1] = 1;   // |_|_|

    for (int i = 1; i < 1000010; i++) {
        A[i + 1] = add(mul(2, A[i]), B[i]);
        B[i + 1] = add(mul(4, B[i]), A[i]);
    }

    while (t--) {
        int n;
        cin >> n;

        cout << add(A[n], B[n]) << endl;
    }

    return 0;
}