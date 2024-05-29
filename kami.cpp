#include<fstream>
#include<vector>

#define MAX 1000000000

std::ifstream fin("kami.in");
std::ofstream fout("kami.out");

int main(){
    int n;
    fin>>n;
    std::vector<int> z(n+1,0);
    for(int i = 1; i <= n; i++){
        fin>>z[i];
    }
    int m;
    fin>>m;
    int op;
    for(int i = 0; i < m; i++){
        fin>>op;
        if(op == 0){
            int x,val;
            fin>>x>>val;
            z[x] = val;
        }
        else{
            int b;
            fin>>b;

            int sum = z[b];
            while (b > 0){
                if (sum > z[b - 1]) {
                    sum += z[b - 1];
                    if (sum > MAX){
                        b = 0;
                        break;
                    }
                    b--;
                }
                else {
                    b--;
                    break;
                }
            }
            fout<<b<<std::endl;
        }
    }
    return 0;
}