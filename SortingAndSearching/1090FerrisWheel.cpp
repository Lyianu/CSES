#include <iostream>
#include <queue>
using namespace std;

int main() 
{ 
    ios::sync_with_stdio(false);
    int n, x;
    cin >> n >> x;
    priority_queue<int> maxpq;
    priority_queue<int, vector<int>, greater<int> > minpq;

    int tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        maxpq.push(tmp);
        minpq.push(tmp);
    }
    
    int ok = 0;
    int cnt = 0;
    while (ok < n) {
        int larger = maxpq.top();
        maxpq.pop();
        ok++;
        if (larger + minpq.top() <= x) {
            ok++;
            minpq.pop();
        }
        cnt++;
    }
    cout << cnt << endl;

    return 0;     
}