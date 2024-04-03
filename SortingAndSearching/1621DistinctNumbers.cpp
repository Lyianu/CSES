#include <iostream>
#include <set>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  set<int> values;
  int n;
  cin >> n;
  int in;
  for (int i = 0; i < n; i++) {
    cin >> in;
    values.insert(in);
  }
  int count = 0;
  for (auto &x : values) {
    count++;
    // cout << x << endl;
  }

  cout << count << endl;

  return 0;
}
