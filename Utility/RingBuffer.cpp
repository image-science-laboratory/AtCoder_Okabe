#include "../_CppTemplate.cpp"

// バグがあるかも

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