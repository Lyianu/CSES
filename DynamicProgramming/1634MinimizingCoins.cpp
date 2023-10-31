#include <iostream>
#include <cstring>
using namespace std;

int coin[200];
int f[1100000];

int min(int a, int b) {
    return a > b ? b : a;
}

int main()
{
    memset(f, 0x7f, sizeof(f));
    int n, x;
    cin >> n >> x;

    for (int i = 0; i < n; i++) {
        cin >> coin[i];
        f[coin[i]] = 1;
    }

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < n; j++) {
            if (i + coin[j] <= x) {
                f[i + coin[j]] = min(f[i + coin[j]], f[i] + 1);
            }
        }
    }

    // 0x7f memset
    cout << ((f[x] == 2139062143) ? -1 : f[x]) << endl;
    return 0;
}