#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
const double PI = 3.14159265358979;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long int ll;
using namespace std;

int main() {
  int a, b, d;
  cin >> a >> b >> d;

  double th = atan2(b, a);
  th = fmod(th + d / 180.0 * PI, 2 * PI);
  double r = sqrt(a * a + b * b);

  cout << r * cos(th) << " " << r * sin(th) << endl;
  return 0;
}