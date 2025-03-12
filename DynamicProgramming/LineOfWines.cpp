#include <iostream>
using namespace std;

typedef long long ll;

int arr[100];

// Year Left Right
int dp[110][110];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <= n; i++) {
        dp[i][i] = n * arr[i];
    }

    for (int interval = 1; interval < n; interval++) {
        for (int start = 1; start + interval <= n; start++) {
            dp[start][start+interval] = max(
                    (n - interval) * arr[start] + dp[start+1][start+interval],
                    (n - interval) * arr[start+interval] + dp[start][start+interval-1]
            );
        }
    }

    cout << dp[1][n] << endl;



    return 0;
}