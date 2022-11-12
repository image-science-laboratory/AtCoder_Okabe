#include <algorithm>
#include <functional>
#include <iostream>
#include <set>
using namespace std;
int main() {
    std::set<int> st{3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    for (auto itr = st.begin(); itr != st.end(); ++itr) {
        std::cout << *itr << "\n"; // イテレータの指す先のデータを表示
    }

    auto it = st.find(4);
    cout << it - st.begin() << endl;
}