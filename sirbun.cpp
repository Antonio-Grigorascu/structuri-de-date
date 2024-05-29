#include<fstream>
#include<vector>

std::ifstream fin("sirbun.in");
std::ofstream fout("sirbun.out");

long long sol;

int main(){
    int n;
    fin >> n;
    std::vector<int> a(n);
    for(int i = 0; i < n; i++){
        fin >> a[i];
    }

    int left = 0;
    std::vector<int> freq(100001, 0);
    for(int right = 0; right < n; right++){
        freq[a[right]]++;
        while (freq[a[right]] > a[right]) {
            freq[a[left]]--;
            left++;
        }
        sol += (right - left + 1);
    }

    fout << sol << std::endl;
    return 0;
}
