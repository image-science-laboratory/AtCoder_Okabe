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

class RingBuffer {
  public:
    ll  max_size = 100000000; // 10^8
    ll *buff;
    ll  top    = 0;
    ll  bottom = 0;
    ll  size   = 0;

    RingBuffer() { buff = new ll[max_size]; }
    RingBuffer(ll n) {
        buff     = new ll[n];
        max_size = n;
    }

    ll back() { return buff[bottom]; }

    ll front() { return buff[top]; }

    void push_back(ll n) {
        buff[bottom] = n;
        bottom       = (bottom + 1) % max_size;
        if (top == bottom) call_error();
        size += 1;
    }

    void push_front(ll n) {
        buff[top] = n;
        top       = top > 0 ? top - 1 : max_size - 1;
        if (top == bottom) call_error();
        size += 1;
    }

    ll pop_back() {
        if (size == 0) call_error();

        bottom = bottom > 0 ? bottom - 1 : max_size - 1;
        ll ret = buff[bottom];
        if (bottom < 0) bottom = max_size + bottom;
        size -= 1;
        return ret;
    }

    ll pop_front() {
        if (size == 0) call_error();

        ll ret = buff[top];
        top    = (top + 1) % max_size;
        size -= 1;
        return ret;
    }

    void call_error() {
        if (bottom == top) {
            cout << "Error : 要素数エラー" << endl;
            exit(0);
        }
    }
};

int main() {
    ll n, t;
    cin >> n;
    vll manga(n);

    RingBuffer rb;
    rep(i, n) {
        scanf("%lld", &t);
        manga[i] = t;
    }
    sort(manga.begin(), manga.end());
    rep(i, n) {
        rb.push_back(manga[i]);
    }

    for (int i = 1; true; ++i) {
        // cout << "top:" << rb.top << " bottom:" << rb.bottom << " ";
        // for (int j = rb.top; j < rb.bottom; ++j) {
        //     cout << rb.buff[j] << " ";
        // }
        // cout << endl;

        if (rb.size <= 0 || rb.front() != i && rb.size == 1) {
            cout << i - 1 << endl;
            return 0;
        }

        if (rb.front() != i) {
            rb.pop_back();
            rb.pop_back();
        } else {
            rb.pop_front();
            while (rb.front() == i) {
                rb.pop_front();
                rb.push_back(pow(10, 9) + 5);
            }
        }
    }

    return 0;
}