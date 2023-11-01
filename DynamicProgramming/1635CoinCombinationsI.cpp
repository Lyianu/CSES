#include <iostream>
using namespace std;

typedef long long LL;

LL f[1100000];
int coin[200];

int main()
{
    int n, x;
    cin >> n >> x;

    for (int i = 0; i < n; i++) {
        cin >> coin[i];
        f[coin[i]] = 1;
    }

    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < n; j++) {
            if (i - coin[j] >= 0) {
                f[i] += f[i-coin[j]];
                f[i] %= LL(1e9 + 7);
            }
        }
    }

    cout << f[x] << endl;

    return 0;
}