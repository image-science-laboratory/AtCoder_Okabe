#include <algorithm>
#include <functional>

#include <iostream>

// nPn縺?���??��蛻励↓蟇?��縺励※�??���??��繧貞ｮ溯?��後�??繧?��
void foreach_permutation(int n, std::function<void(int *)> f) {
    int indexes[n];
    for (int i = 0; i < n; i++)
        indexes[i] = i;
    do {
        f(indexes);
    } while (std::next_permutation(indexes, indexes + n));
}

int main() {
    foreach_permutation(3, [](int *indexes) {
        std::cout << indexes[0] << ',' << indexes[1] << ',' << indexes[2] << std::endl;
    });
}
