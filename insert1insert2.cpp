#include <iostream>
#include <vector>

int main(){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int q,type,p,val;
    int lastRed, lastBlack;
    std::vector<int> v;
    long long sol = 0;

    std::cin >> q;
    for (int i = 0; i < q; i++) {
        std::cin >> type;
        if(type == 1) {
            std::cin >> p >> val;
            lastRed = p;
            if (lastBlack >= lastRed) {
                lastBlack++;
            }
            v.insert(v.begin() + p, val);
        }
        else if(type == 2) {
            std::cin >> p >> val;
            lastBlack = p;
            if (lastRed >= lastBlack) {
                lastRed++;
            }
            v.insert(v.begin() + p, val);
        }
        else if(type==3) {
            int l,r, sum=0;
            if(lastRed<lastBlack){
                l = lastRed;
                r = lastBlack;
            }
            else{
                l = lastBlack;
                r = lastRed;
            }
            for(int j = l; j <= r; j++){
                sum += v[j];
                sum %= 666013;
            }
            sol += sum;
            sol %= 666013;
        }
    }
    std::cout << sol << std::endl;
}