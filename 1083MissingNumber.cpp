#include <iostream>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    long long sum = 0;
    for (int i = 0; i < n - 1; i++) {
        int tmp;
        cin >> tmp;
        sum += tmp;
    }

    cout << ((1 + n) * n) / 2 - sum << endl;


    return 0;
}