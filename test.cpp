#include <algorithm>
#include <functional>

#include <iostream>

// nPnç¸º?½®é¬??¿½è›»åŠ±â†“èŸ‡?½¾ç¸ºåŠ±â€»èœ??½¦é€??¿½ç¹§è²žï½®æº¯?½¡å¾Œâ??ç¹§?¿½
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
