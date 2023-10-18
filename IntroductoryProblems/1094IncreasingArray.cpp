#include <iostream>
using namespace std;

typedef long long LL;

int main()
{
    int n;
    cin >> n;

    LL last = 0;
    LL count = 0;
    for (int i = 0; i < n; i++) {
        LL current;
        cin >> current;
        if (current < last) {
            count += last - current;
        } else {
            last = current;
        }
    }

    cout << count << endl;

    return 0;
}