#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> v(n+1);
    for (int i = 1; i <= n; i++) {
        std::cin >> v[i];
    }

    long long maxValue = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            for (int k = j + 1; k <= n; k++) {
                for (int l = k + 1; l <= n; l++) {
                    maxValue = std::max(maxValue, 1ll * (v[i] ^ v[j]) * (1ll * v[k] + v[l]));

                }
            }
        }
    }

    std::cout << maxValue << std::endl;
    return 0;
}


