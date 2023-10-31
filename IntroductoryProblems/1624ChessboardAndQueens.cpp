#include <iostream>
using namespace std;

int board[10][10];
int sol[10][10];
int count;

bool isLegal(int, int);
int solutions(int, int);

int main()
{
    for (int y = 1; y <= 8; y++)
        for (int x = 1; x <= 8; x++) {
            char tmp;
            cin >> tmp;
            if (tmp == '.') {
                board[y][x] = 0;
            } else {
                board[y][x] = 1;
            }
        }

    int c = 0;
    for (int i = 1; i <= 8; i++) {
        if (isLegal(1, i)) {
            sol[1][i] = 1;
            c += solutions(1, i);
            sol[1][i] = 0;
        }
    }
    cout << c << endl;

    return 0;
}

int solutions(int step, int pos) {
    if (step == 8) {
        return 1;
    }
    int c = 0;
    for (int i = 1; i <= 8; i++) {
        if (isLegal(step + 1, i)) {
            sol[step + 1][i] = 1;
            c += solutions(step + 1, i);
            sol[step + 1][i] = 0;    
        }
    }
    return c;
}

bool isLegal(int step, int pos) {
    if (board[step][pos])
        return false;
    for (int i = 1; i < step; i++) {
        if (sol[i][pos])
            return false;
        int diff = step - i;
        if (pos - diff > 0 && pos - diff < 9 && sol[i][pos-diff])
            return false;
        if (pos + diff > 0 && pos + diff < 9 && sol[i][pos+diff])
            return false;
    }
    return true;
}