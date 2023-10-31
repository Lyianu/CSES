#include <iostream>
using namespace std;

typedef long long LL;

LL f[1100000];

int main()
{
    f[1] = 1;
    f[2] = 2;
    f[3] = 4;
    f[4] = 8;
    f[5] = 16;
    f[6] = 32;
    int n;
    cin >> n;

    for (int i = 7; i <= n; i++) {
        for (int j = i - 6; j < i; j++)
            f[i] += f[j];
        f[i] %= LL(1e9) + 7;
    }

    cout << f[n] << endl;
    
    return 0;
}