#include <iostream>
using namespace std;

void move(int, int, int, int);
int count;

int main()
{
    int n;
    cin >> n;

    move(n, 1, 3, true);
    cout << count << endl;
    move(n, 1, 3, false);


    return 0;
}

void move(int n, int src, int dest, int mute) {
    if (n == 1) {
        if (!mute)
            cout << src << ' ' << dest << endl;
        count++;
        return;
    }
    move(n - 1, src, 6 - src - dest, mute);
    if (!mute)
        cout << src << ' ' << dest << endl;
    count++;
    move(n - 1, 6 - src - dest, dest, mute);
}