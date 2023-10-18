#include <iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;

    // manually switch
    s += " ";
    int size = s.size();
    char last = ' ';
    int max_length = 0;
    int current_length = 0;
    for (int i = 0; i < size; i++) {
        if (s[i] == last)
            current_length++;
        else {
            max_length = max(max_length, current_length);
            current_length = 0;
        }
        last = s[i];
    }

    cout << max_length + 1 << endl;

    return 0;
}