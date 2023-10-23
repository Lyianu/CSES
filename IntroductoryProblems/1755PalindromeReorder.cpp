#include <iostream>
#include <cstdio>
using namespace std;

int count[100];

int main()
{
    int c;
    while ((c = getchar()) != EOF && c != '\n')
        count[c]++;
    
    int oddCount = 0;
    int oddNum = 0;
    for (int i = 'A'; i <= 'Z'; i++)
        if (count[i] % 2) {
            oddCount++;
            count[i]--;
            oddNum = i;
        }
    
    if (oddCount > 1) {
        cout << "NO SOLUTION" << endl;
        return 0;
    }

    for (int i = 'A'; i <= 'Z'; i++)
        for (int j = 0; j < count[i] / 2; j++)
            putchar(i);

    if (oddCount)
        putchar(oddNum);

    for (int i = 'Z'; i >= 'A'; i--)
        for (int j = 0; j < count[i] / 2; j++)
            putchar(i);

    return 0;
}