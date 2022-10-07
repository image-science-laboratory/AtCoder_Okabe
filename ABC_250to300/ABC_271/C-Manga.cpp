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

using namespace std;
const double PI = 3.141592653589793;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long int              ll;
typedef vector<ll>                 vll;
typedef vector<vector<ll>>         vvll;
typedef vector<vector<vector<ll>>> vvvll;

int main() {
    ll  n;
    vll manga(n);
    rep(i, n) scanf("%lld", &manga[i]);

    bool *flag            = new bool[n + 1];
    rep(i, n + 1) flag[i] = false;

    ll count = 0;
    rep(i, n) {
        if (manga[i] > n || flag[manga[i]] == true) count += 1;
        if (manga[i] <= n) flag[manga[i]] = true;
    }

    return 0;
}