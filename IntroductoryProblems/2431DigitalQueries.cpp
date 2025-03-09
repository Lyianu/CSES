#include <iostream>
using namespace std;

typedef long long ll;

ll decbits[50];
ll contain[50];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (ll i = 1; i < 18; i++) {
      decbits[i] = 9;
      for (ll j = 1; j < i; j++) {
        decbits[i] *= 10;
      }
      decbits[i] *= i;
      decbits[i] += decbits[i-1];

      contain[i] = 9;
      for (ll j = 1; j < i; j++)
      {
        contain[i] *= 10;
      }
      contain[i] += contain[i-1];
    }

    for (ll i = 1; i <= 50; i++)
    {
      // cout << i << ' ' << decbits[i] << endl;
    }

    int q;
    cin >> q;
    while (q--) {
      ll k;
      cin >> k;

      int i;
      for (i = 1; i < 19; i++)
      {
        if (decbits[i] > k)
        {
          break;
        }
      }
      // cout << i;
      k -= decbits[i-1];
      ll num = k / i;
      ll base = 1;
      for (int l = 0; l < i-1; l++)
      {
        base *= 10;
      }
      ll remain = k % i;
      num += contain[i-1] + (remain > 0);
      if (remain == 0)
      {
        cout << num % 10 << endl;
        continue;
      }
      //cout << num << " " << remain << endl;
      for (int l = 0; l < i - remain; l++)
      {
        num /= 10;
      }
      cout << num % 10 << endl;;
    }


    return 0;
}