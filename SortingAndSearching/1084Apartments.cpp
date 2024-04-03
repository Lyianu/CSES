#include <algorithm>
#include <iostream>
using namespace std;

int aptms[210000], aplcs[210000];

int abs(int x) { return x > 0 ? x : -x; }

int main() {
  int n, m, k;
  ios::sync_with_stdio(false);
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    cin >> aplcs[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> aptms[i];
  }
  sort(aptms, aptms + m);
  sort(aplcs, aplcs + n);

  int cnt = 0;
  int apt = 0, apl = 0;

  while (true) {
    if (apt >= m || apl >= n)
      break;
    if (abs(aptms[apt] - aplcs[apl]) <= k) {
      // cout << "aptms: " << aptms[apt] << " aplcs: " << aplcs[apl] << endl;
      cnt++;
      apt++;
      apl++;
    } else if (aptms[apt] > aplcs[apl] + k) {
      // cout << "apl++: apt: " << aptms[apt] << ' ' << aplcs[apl] << endl;
      apl++;
    } else if (aptms[apt] < aplcs[apl] - k) {
      // cout << "apt++: apt: " << aptms[apt] << ' ' << aplcs[apl] << endl;
      apt++;
    }
  }
  cout << cnt << endl;

  return 0;
}
