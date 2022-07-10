#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
const double PI = 3.141592653589793;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long int ll;
using namespace std;

int main() {
  int n;
  string s;
  cin >> n >> s;

  vector<pair<ll, int>> arr(n);
  unordered_map<ll, pair<int, int>> hash;
  rep(i, n) {
    ll w;
    scanf("%lld", &w);
    int pc = -1 * (s[i] - '0');
    arr[i] = {w, pc};

    if (hash.find(w) == hash.end()) hash[w] = {0, 0};
    if (pc == 0)
      hash[w].first += 1;
    else
      hash[w].second += 1;
  }
  sort(arr.begin(), arr.end());

  int oya_max = 0;
  rep(i, n) {
    if (arr[i].second == -1) oya_max += 1;
    cout << "w:" << arr[i].first << " oyako:" << arr[i].second << endl;
  }

  int oyako[2] = {0, 0};
  int ans = 0;
  rep(i, n) {
    ll w = arr[i].first;
    oyako[-1 * arr[i].second] += 1;

    int ok = 0;
    ok += oyako[0];
    ok += oya_max - oyako[1];
    ok -= min(hash[w].first, hash[w].second);
    if (i == n - 1 || arr[i].first != arr[i + 1].first) ans = max(ans, ok);

    cout << "i:" << i << " w:" << w << " pc:" << arr[i].second << endl;
  }
  cout << ans << endl;
  return 0;
}