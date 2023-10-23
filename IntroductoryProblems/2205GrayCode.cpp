#include <iostream>
using namespace std;

int code[20];
void dfs(int, int, int);

int main()
{
    int n;
    cin >> n;
    if (n == 1) {
        cout << "0\n1\n";
        return 0;
    }
    if (n < 1) {
        return 0;
    }
    dfs(n, n, 0);

    return 0;
}

void dfs(int n, int step, int reverse) {
    if (step == 2) {
        if (reverse) {
            for (int i = n; i > 2; i--)
                cout << code[i];
            cout << "00" << endl;
            for (int i = n; i > 2; i--)
                cout << code[i];
            cout << "01" << endl;
            for (int i = n; i > 2; i--)
                cout << code[i];
            cout << "11" << endl;
            for (int i = n; i > 2; i--)
                cout << code[i];
            cout << "10" << endl;
        } else {
            for (int i = n; i > 2; i--)
                cout << code[i];
            cout << "10" << endl;
            for (int i = n; i > 2; i--)
                cout << code[i];
            cout << "11" << endl;
            for (int i = n; i > 2; i--)
                cout << code[i];
            cout << "01" << endl;
            for (int i = n; i > 2; i--)
                cout << code[i];
            cout << "00" << endl;
        }
        
    } else {
        if (reverse) {
            code[step] = 0;
            dfs(n, step - 1, 0);
            code[step] = 1;
            dfs(n, step - 1, 1);
        } else {
            code[step] = 1;
            dfs(n, step - 1, 0);
            code[step] = 0;
            dfs(n, step - 1, 1);
        }
    }
}