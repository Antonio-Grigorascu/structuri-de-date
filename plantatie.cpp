#include <fstream>
#include <algorithm>
#include <cmath>

const int N_MAX = 501;
const int LOG_MAX = 9;

std::ifstream fin("plantatie.in");
std::ofstream fout("plantatie.out");

int a[N_MAX][N_MAX], maxim[N_MAX][N_MAX][LOG_MAX];

int n, m;


int query(int x1, int y1, int k) {
    int p = (int) std::log2(k);
    int x2 = x1 + k - 1;
    int y2 = y1 + k - 1;

    int max1 = std::max(maxim[x1][y1][p], maxim[x2 - (1 << p) + 1][y1][p]);
    int max2 = std::max(maxim[x1][y2 - (1 << p) + 1][p], maxim[x2 - (1 << p) + 1][y2 - (1 << p) + 1][p]);

    return std::max(max1, max2);
}


int main() {
    fin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fin >> a[i][j];
            maxim[i][j][0] = a[i][j];
        }
    }

    for (int k = 1; (1 << k) <= n; k++) {
        for (int i = 0; i + (1 << k) - 1 < n; i++) {
            for (int j = 0; j + (1 << k) - 1 < n; j++) {
                maxim[i][j][k] = std::max(
                        std::max(maxim[i][j][k-1], maxim[i + (1 << (k-1))][j][k-1]),
                        std::max(maxim[i][j + (1 << (k-1))][k-1], maxim[i + (1 << (k-1))][j + (1 << (k-1))][k-1])
                );
            }
        }
    }

    for (int q = 0; q < m; q++) {
        int x, y, k;
        fin >> x >> y >> k;
        x--;
        y--;
        fout << query(x, y, k) << std::endl;
    }

    return 0;
}
