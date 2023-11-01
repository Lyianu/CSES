#include <iostream>
using namespace std;

typedef long long LL;

char board[1100][1100];
LL paths[1100][1100];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> board[i];

    // for (int i = 1; i <= n; i++)
    //     cout << board[i] << endl;

    paths[0][0] = 1;
    for (int y = 1; y <= n; y++) {
        for (int x = 0; x < n; x++) {
            if (board[y][x] == '.')
                if (x)
                    paths[y][x] = (paths[y-1][x] + paths[y][x-1]) % LL(1e9+7);
                else
                    paths[y][x] = paths[y-1][x] % LL(1e9+7);
        }
    }
    
    cout << paths[n][n-1] << endl;

    return 0;
}

