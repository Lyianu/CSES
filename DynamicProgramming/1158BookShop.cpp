#include <iostream>
using namespace std;

int h[1100];
int s[1100];
int f[110000];

int main()
{
    int n, x;
    cin >> n >> x;

    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    for (int i = 0; i < n; i++) {
        for (int l = x; l >= h[i]; l--)
            f[l] = max(f[l], f[l - h[i]] + s[i]);
    }

    cout << f[x] << endl;

    return 0;
}