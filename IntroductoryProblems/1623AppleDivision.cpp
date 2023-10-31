#include <iostream>
using namespace std;

typedef long long LL;
LL input[30];
int perm[30];
int N;
LL closest;
LL sum = 0;

void permutation(int);

int main()
{
    closest = 0;
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> input[i];
    for (int i = 0; i < N; i++)
        sum += input[i];
    permutation(0);

    //cout << closest << endl;
    cout << 2 * abs(sum / 2 - closest) + (sum % 2) << endl;


    return 0;
}

// brute-force
void permutation(int step) {
    if (step == N) {
        LL count = 0;        
        for (int i = 0; i < N; i++) {
            count += LL(perm[i]) * input[i];
        }
        if (abs(count - sum / 2) < abs(closest - sum / 2))
            closest = count;
        return;
    }
    perm[step] = 0;
    permutation(step + 1);
    perm[step] = 1;
    permutation(step + 1);
}