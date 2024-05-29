#include<fstream>
#include<vector>
#include<cmath>
#include<climits>

std::ifstream fin("pikachu.in");
std::ofstream fout("pikachu.out");

int k, n;
long long int result = LLONG_MAX;
std::vector<int> heights(n,0);

long long int check(int h) {
    long long int r;
    long long int sum = 0;
    for(int i = 1; i <= k; i++) {
        sum += std::abs(heights[i] - h);
    }
    r = sum;
    for (int i = k + 1; i <= n; i++) {
        sum = sum - std::abs(heights[i - k] - h) + abs(heights[i] - h);
        r = std::min(r, sum);
    }
    result = std::min(r, result);
    return r;
}


int main(){

    fin>>n>>k;
    int h;

    int maxim = 0;

    for(int i = 0; i<n; i++){
        fin>>h;
        heights.push_back(h);
        maxim = std::max(maxim, heights[i]);
    }
    int minim = 0;
    while (maxim > minim) {
        int mid = minim + (maxim - minim) / 2;
        if (check(mid) < check(mid + 1)) {
            maxim = mid;
        }
        else {
            minim = mid + 1;
        }
    }
    fout << result;


    return 0;
}