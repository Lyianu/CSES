#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <queue>
using namespace std;

typedef long long ll;

int n, m;

struct dsu {
    vector<int> par;
    explicit dsu(int n) : par(n) {
        iota(par.begin(), par.end(), 0);
    }

    int find(int a) {
        if (par[a] == a) {
            return a;
        }
        return par[a] = find(par[a]);
    }

    void unite(int a, int b) {
        par[find(b)] = find(a);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    dsu d(n+1);

    int united = 0;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        if (d.find(a) == d.find(b)) {
            continue;
        }

        united++;
        d.unite(a, b);
    }

    cout << n - 1 - united << endl;

    set<int> s;
    for (int i = 1; i <= n; i++) {
        s.insert(d.find(i));
    }

    int first = 0;
    for (auto i : s) {
        if (!first) {
            first = i;
            continue;
        }
        cout << i << ' ' << first << endl;
    }

    return 0;
}