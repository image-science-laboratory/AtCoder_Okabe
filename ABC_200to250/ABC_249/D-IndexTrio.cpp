#include <algorithm>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
const double PI = 3.141592653589793;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long int ll;
using namespace std;

int main() {
  ll MAX = 100005;
  ll n;
  cin >> n;
  unordered_map<ll, bool> hash;
  ll *counts = new ll[MAX]{0};
  rep(i, n) {
    ll tmp;
    scanf("%lld", &tmp);
    hash[tmp] = true;
    counts[tmp] += 1;
  }

  vector<vector<ll>> eratos(MAX + 1, vector<ll>(0));
  for (int i = 2; i <= MAX; ++i) {
    for (int j = i + i; j <= MAX; j += i) {
      // if (i * i <= j)
      eratos[j].emplace_back(i);
    }
  }

  rep(i, 30) {
    cout << "i:" << i << " ";
    rep(j, eratos[i].size()) cout << eratos[i][j] << " ";
    cout << endl;
  }

  ll ans = 0;
  unordered_map<ll, bool> tansaku;
  for (auto it1 = hash.begin(); it1 != hash.end(); ++it1) {
    ll a = it1->first;
    ll an = counts[a];

    if (counts[1] >= 1) {
      if (an == 2)
        ans += 3;
      else if (an >= 3)
        ans += an * (an - 1) / 2 * 3;
    }
    // ans += counts[1] * an * (an - 1) / 2;
    cout << "a:" << a << " an" << an << " eratossize:" << eratos[a].size()
         << " ans:" << ans << endl;

    rep(j, eratos[a].size()) {
      ll b = eratos[a][j];
      ll bn = counts[b];
      ll c = a / b;
      ll cn = counts[c];
      cout << " b:" << b << " c:" << c << " bn:" << bn << " cn:" << cn;

      if (b == c) {
        ans += an * bn * (bn - 1) / 2;
      } else {
        ans += an * bn * cn * 3;
      }
      cout << " ans:" << ans << endl;
    }
  }
  cout << ans << endl;

  return 0;
}