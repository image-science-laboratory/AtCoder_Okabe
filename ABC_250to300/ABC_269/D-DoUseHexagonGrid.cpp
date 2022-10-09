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

// Union-Find
struct UnionFind {
    vector<int> par, rank, siz;

    // 構造体の初期化
    UnionFind(int n) : par(n, -1), rank(n, 0), siz(n, 1) {}

    // 根を求める
    int root(int x) {
        if (par[x] == -1)
            return x; // x が根の場合は x を返す
        else
            return par[x] = root(par[x]); // 経路圧縮
    }

    // x と y が同じグループに属するか (= 根が一致するか)
    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    // x を含むグループと y を含むグループを併合する
    bool unite(int x, int y) {
        int rx = root(x), ry = root(y); // x 側と y 側の根を取得する
        if (rx == ry) return false;     // すでに同じグループのときは何もしない
        // union by rank
        if (rank[rx] < rank[ry]) swap(rx, ry); // ry 側の rank が小さくなるようにする
        par[ry] = rx;                          // ry を rx の子とする
        if (rank[rx] == rank[ry]) rank[rx]++;  // rx 側の rank を調整する
        siz[rx] += siz[ry];                    // rx 側の siz を調整する
        return true;
    }

    // x を含む根付き木のサイズを求める
    int size(int x) {
        return siz[root(x)];
    }
};

int main() {
    ll n;
    cin >> n;

    vvll      masu(2022, vll(2022, false));
    UnionFind uf;

    return 0;
}