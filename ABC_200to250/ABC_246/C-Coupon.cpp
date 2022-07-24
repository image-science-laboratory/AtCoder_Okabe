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
  ll n, k, x;
  cin >> n >> k >> x;
  vector<ll> arr(n);
  rep(i, n) scanf("%lld", &arr[i]);

  rep(i, n) {
    ll c = min(arr[i] / x, k);
    arr[i] -= c * x;
    k -= c;
  }

  sort(arr.begin(), arr.end());
  for (int i = n - 1; i >= 0; i -= 1) {
    ll c = min(1LL, k);
    arr[i] = max(arr[i] - c * x, 0LL);
    k -= c;
  }

  cout << accumulate(arr.begin(), arr.end(), 0) << endl;

  return 0;
}