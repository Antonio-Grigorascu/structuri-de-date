#include<fstream>
#include<vector>

const int N_MAX = 250001;
const int LOG_MAX = 18;

std::ifstream fin("stramosi.in");
std::ofstream fout("stramosi.out");

int s[N_MAX][LOG_MAX];

int main(){
    int n,m;
    fin>>n>>m;
    std::vector<int> a(n+1,0);
    for(int i = 1; i <= n; i++){
        fin>>a[i];
        s[i][0] = a[i];
    }
    for (int j = 1; j < LOG_MAX; j++) {
        for (int i = 1; i <= n; i++) {
            if (s[i][j - 1] != 0) {
                s[i][j] = s[s[i][j - 1]][j - 1];
            } else {
                s[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        int node, k;
        fin >> node >> k;
        int current = node;

        for (int j = 0; j < LOG_MAX; j++) {
            if (k & (1 << j)) {
                current = s[current][j];
                if (current == 0){
                    break;
                }
            }
        }

        fout << current << std::endl;
    }


    return 0;
}