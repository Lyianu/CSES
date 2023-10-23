#include <iostream>
#include <algorithm>
using namespace std;

int permutation[10];
string s;
int n;
int factorial(int);
void dfs(int);

int alphabet['z' + 10];

int main()
{
    cin >> s;
    n = s.size();

    int sortArray[10];
    for (int i = 0; i < n; i++)
        sortArray[i] = s[i];
    sort(sortArray, sortArray + n);
    for (int i = 0; i < n; i++)
        s[i] = sortArray[i];
    

    int divide = 1;

    for (int i = 0; i < n; i++)
        alphabet[int(s[i])]++;
    for (int i = 'a'; i <= 'z'; i++)
        if (alphabet[i] > 1)
            divide *= factorial(alphabet[i]);

    //cout << divide << endl;
    
    cout << factorial(n) / divide << endl;

    dfs(0);


    return 0;
}

void dfs(int step) {
    if (step == n) {
        for (int i = 'a'; i <= 'z'; i++) {
            // we output the repeatitive characters only in increasing order
            if (alphabet[i] > 1) {
                int last = -1;
                for (int j = 0; j < n; j++) {
                    if (s[permutation[j]] == i) {
                        if (permutation[j] > last)
                            last = permutation[j];
                        else
                            return;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++)
            cout << s[permutation[i]];
        cout << endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        int mark = 0;
        for (int j = 0; j < step; j++)
            if (permutation[j] == i)
                mark++;
        if (mark)
            continue;
        permutation[step] = i;
        dfs(step + 1);
    }
}

int factorial(int n) {
    if (n <= 1)
        return 1;
    return n * factorial(n - 1);
}