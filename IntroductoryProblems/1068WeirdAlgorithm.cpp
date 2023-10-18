#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    stringstream ss;

    ss << n;

    int count = 0;
    while (n != 1) {
        if (n % 2)
            n = n * 3 + 1;
        else
            n /= 2;
        count++;
        //cout << '\r' << count;
        ss << ' ' << n;
    }

    string s;
    s = ss.str();
    cout << s;
    //cout << count;

    return 0;
}