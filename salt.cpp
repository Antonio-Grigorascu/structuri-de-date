#include<iostream>
#include<cmath>
#include <vector>

const int SIZE = 100001;
const int MOD = 1000000007;

int a[SIZE];
int m[SIZE][17]; // log2(100000) = 16.61


int query(int l, int r){
    int len = r - l + 1;
    int k = 31 - __builtin_clz(len); // log2(len)
    return std::max(m[l][k], m[r-(1<<k)+1][k]);
}

int main(){

    int n;
    std::cin>>n;
    for(int i=0; i<n; i++){
        std::cin>>a[i];
        m[i][0] = a[i];
    }


    for(int k = 1; k <= std::log2(n); k++){
        for(int i = 0; i + (1<<k) - 1 <= n; i++){
            m[i][k] = std::max(m[i][k-1], m[i + (1<<(k-1)) ][k-1]);
        }
    }

    std::vector<long long> powers_of_two(n + 1);
    powers_of_two[0] = 1;
    for (int i = 1; i <= n; i++) {
        powers_of_two[i] = (powers_of_two[i - 1] * 2) % MOD;
    }


    int q;
    std::cin>>q;
    for(int i = 0; i<q;i++){
        int l,r;
        std::cin>>l>>r;
        int max_val = query(l - 1, r - 1);
        int subset_count = r - l;

        long long result = (max_val * powers_of_two[subset_count]) % MOD;

        std::cout << result << std::endl;
    }

    return 0;
}
