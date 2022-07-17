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
  int n;
  cin >> n;
  int *arr = new int[n];
  rep(i, n) scanf("%d", &arr[i]);

  int range = 2 * 100000 + 10;
  int **prefix = new int *[range];
  rep(i, range) prefix[i] = new int[n + 1]{0};

  rep(j, n) {
    rep(i, range) { prefix[i][j + 1] = prefix[i][j]; }
    prefix[arr[j]][j + 1] += 1;
  }

  // rep(i, 10) {
  //   cout << i << " : ";
  //   rep(j, n + 1) cout << prefix[i][j] << " ";
  //   cout << endl;
  // }
  // return 0;

  int q;
  cin >> q;
  rep(qq, q) {
    int l, r, x;
    scanf("%d %d %d", &l, &r, &x);

    cout << prefix[x][r] - prefix[x][l - 1] << endl;
  }

  return 0;
}