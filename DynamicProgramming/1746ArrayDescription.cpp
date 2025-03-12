#include <iostream>
using namespace std;

typedef long long ll;

ll mod = 1e9+7;

ll add(ll a, ll b) {
    return a  + b % mod;
}

ll dp[110000][110];

int arr[110000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    if (arr[1])
        dp[1][arr[1]] = 1;
    else
        for (int i = 1; i <= m; i++) {
            dp[1][i] = 1;
        }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= m; j++) {
            int next = arr[i+1];
            dp[i+1][j+1] = add(dp[i][j] * (arr[i] == j || arr[i] == 0) * (next == 0 || abs(next - j) <= 1), dp[i+1][j+1]);
            dp[i+1][j] = add(dp[i][j] * (arr[i] == j || arr[i] == 0) * (next == 0 || abs(next - j) <= 1), dp[i+1][j]);
            dp[i+1][j-1] = add(dp[i][j] * (arr[i] == j || arr[i] == 0) * (next == 0 || abs(next - j) <= 1), dp[i+1][j-1]);
        }
    }

    ll result = 0;
    if (arr[n])
        result = dp[n][arr[n]];
    else
        for (int i = 1; i <= m; i++)
            result = add(result, dp[n][i]);

    cout << result % mod << endl;

    return 0;
}