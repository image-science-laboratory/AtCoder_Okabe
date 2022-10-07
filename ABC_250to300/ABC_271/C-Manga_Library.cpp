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
    ll n, t;
    cin >> n;
    vll manga(n);

    deque<ll> deq;
    rep(i, n) {
        scanf("%lld", &t);
        manga[i] = t;
    }
    sort(manga.begin(), manga.end());
    rep(i, n) {
        deq.push_back(manga[i]);
    }

    ll cnt = -1;
    for (int i = 1; true; ++i) {
        // cout << "size:" << deq.size() << " ";
        // for (auto it : deq)
        //     cout << it << " ";
        // cout << endl;

        if (deq.size() <= 0 || (deq.front() != i && deq.size() == 1)) {
            cout << i - 1 << endl;
            return 0;
        }
        if (deq.front() != i && deq.size() == 2) {
            cout << i << endl;
            return 0;
        }

        if (deq.front() != i) {
            deq.pop_back();
            deq.pop_back();
        } else {
            deq.pop_front();
            while (deq.front() == i) {
                deq.pop_front();
                deq.push_back(cnt);
                cnt -= 1;
            }
        }
    }

    return 0;
}