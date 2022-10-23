#include <algorithm>
#include <cmath>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <stack>
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

typedef struct data {
    int depth;
    int x;
    int y;
    data(int depth, int y, int x) {
        depth = depth;
        x     = x;
        y     = y;
    }
} Data;

int main() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> arr(n);
    rep(i, n) scanf("%d", &arr[i]);

    unordered_map<Data, int> memo;
    queue<Data>              que;

    que.push(Data(0, 0, arr[i]));
    memo[Data(0, 0, arr[i])] = 0;
    while (que.size() > 0) {
        data hoge = que.front();
        que.pop();
    }

    return 0;
}