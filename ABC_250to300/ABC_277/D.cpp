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
#define rep(i, n)   for (int i = 0; i < (int)(n); i++)
#define mod107(m)   m % 1000000007
#define mod998(m)   m % 998244353
#define modab(a, b) a % b
typedef long long int                  ll;
typedef vector<ll>                     vll;
typedef vector<vector<ll>>             vvll;
typedef vector<vector<vector<ll>>>     vvvll;
typedef vector<int>                    vi;
typedef vector<vector<int>>            vvi;
typedef vector<vector<vector<int>>>    vvvi;
typedef vector<float>                  vf;
typedef vector<vector<float>>          vvf;
typedef vector<vector<vector<float>>>  vvvf;
typedef vector<double>                 vd;
typedef vector<vector<double>>         vvd;
typedef vector<vector<vector<double>>> vvvd;
typedef vector<string>                 vs;
typedef vector<vector<string>>         vvs;
typedef pair<ll, ll>                   pll;
typedef pair<ll, string>               pls;
typedef pair<string, ll>               psl;
typedef pair<int, int>                 pii;

int main() {
    bool debug = false;

    ll n, m;
    cin >> n >> m;

    vi  arr(n);
    vvi mods(m);
    ll  hoge;
    rep(i, n) {
        cin >> arr[i];
        mods[arr[i] % m].emplace_back(arr[i]);
    }

    ll min_size = 200005;
    rep(i, m) {
        min_size = std::min(min_size, (ll)mods[i].size());
        sort(mods[i].begin(), mods[i].end());
    }

    if (debug) {
        rep(i, m) {
            cout << "i:" << i << " -- ";
            rep(j, mods[i].size()) {
                cout << mods[i][j] << " ";
            }
            cout << endl;
        }
    }

    // ‰ò‚ðo‚·
    vector<pii> katamari;
    int         start = -1;
    // cout << endl;
    rep(i, m) {
        // cout << "i:" << i << " s:" << start << endl;
        if (mods[i].size() - min_size <= 0) {
            if (start == -1) continue;
            katamari.emplace_back(pii(start, i - 1));
            start = -1;
        } else {
            if (start == -1) {
                start = i;
                continue;
            }
        }
    }
    if (katamari.size() == 0) {
        katamari.emplace_back(pii(0, m - 1));
    } else if (start != -1) {
        if (katamari[0].first != 0)
            katamari.emplace_back(pii(start, m - 1));
        else
            katamari[0].first = start;
    }

    if (debug) {
        cout << "\nstart‚Æfinish" << endl;
        rep(i, katamari.size()) {
            cout << "s:" << katamari[i].first << " f:" << katamari[i].second << endl;
        }
    }

    // ‚Æ‚è‚ ‚¦‚¸‘˜a‚Æˆø‚¯‚é‚¾‚¯ˆø‚­
    ll sum_arr = 0;
    rep(i, m) {
        for (int j = min_size; j < mods[i].size(); ++j)
            sum_arr += mods[i][j];
    }

    if (debug) cout << "sum_arr:" << sum_arr << " min_size:" << min_size << endl;

    ll         ans = sum_arr;
    vector<ll> katamari_sum;
    rep(i, katamari.size()) {
        ll k_sum = 0;
        for (int j = katamari[i].first; true; j = (j + 1) % m) {
            for (int k = min_size; k < mods[j].size(); ++k) {
                k_sum += mods[j][k];
            }
            // if (mods[j].size() > min_size) k_sum += mods[j][min_size + 1];f

            if (j == katamari[i].second) break;
        }
        // katamari_sum.emplace_back(k_sum);
        ans = min(ans, sum_arr - k_sum);
    }

    // rep(i, katamari_sum.size()) {
    //     // cout << "katamari no:" << i << " sum:" << katamari_sum[i] << endl;
    //     ans = min(ans, sum_arr - katamari_sum[i]);
    // }

    cout << ans << endl;

    return 0;
}