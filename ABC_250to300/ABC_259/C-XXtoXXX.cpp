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

vector<pair<char, int>> MakeArr(string s) {
  vector<pair<char, int>> arr;
  char prev = 0;
  rep(i, s.size()) {
    char c = s[i];
    if (c == prev) {
      arr[arr.size() - 1].second += 1;
    } else {
      auto ngo = pair<char, int>{c, 1};
      arr.emplace_back(ngo);
      prev = c;
    }
  }
  return arr;
}

int main() {
  string s, t;
  cin >> s >> t;

  auto sarr = MakeArr(s);
  auto tarr = MakeArr(t);
  cout << "ngo" << endl;

  return 0;
}