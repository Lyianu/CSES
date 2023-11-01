#include <iostream>
#include <cstring>
using namespace std;

int f[1100000];

int min(int a, int b) {
    return a > b ? b : a;
}

int main()
{
    int n;
    cin >> n;

    memset(f, 0x7f, sizeof(f));
    for (int i = 1; i <= 9; i++)
        f[i] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 9; j++) {
            int s = i + j;
            int s_ = s;
            while (s) {
                if (s % 10 == j) {
                    f[s_] = min(f[s_], f[i] + 1);
                    break;
                }
                s /= 10;
            }
        }
    }

    cout << f[n] << endl;

    return 0;
}