#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long int ll;
using namespace std;

int main() {
  int a, b, d;
  cin >> a >> b >> d;

  double th = atan2(b, a);
  th = (th + d / 180.0 * M_PI) % (2 * M_PI);

  return 0;
}