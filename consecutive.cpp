#include<iostream>
const int N_MAX = 100001;

int n, a[N_MAX], rminq[N_MAX][18], rmaxq[N_MAX][18];
int P[N_MAX];
int fr[N_MAX];

void buildP(){
    int j,x;
    j = 1;
    for(int i = 0; i <= n; i++){
        x = a[i];
        while(fr[x] != 0){
            fr[ a[j] ]--;
            j++;
        }
        fr[x]++;
        P[i] = j;
    }
}

int log_2[N_MAX];
void computeLog2(){
    log_2[1] = 0;

    for(int i = 2; i <= n; i++){
        log_2[i] = log_2[i/2] + 1;
    }

}

void rmq(){
    computeLog2();
    int k, i, j;
    for(i = 1; i <= n; i++){
        rminq[i][0] = a[i];
    }
    for(i = 1; (1<<i) <= n; i++) {
        for (j = (1 << i); j <= n; j++) {
            k = 1 << (i - 1);
            rminq[j][i] = std::min(rminq[j][i - 1], rminq[j - k][i - 1]);
        }
    }

    for(i = 1; i<= n; i++){
        rmaxq[i][0] = a[i];
    }
    for(i = 1; (1<<i) <= n; i++){
        for(j = (1<<i); j <= n; j++){
            k = 1 << (i-1);
            rmaxq[j][i] = std::max(rmaxq[j][i-1], rmaxq[j-k][i-1]);
        }
    }

}

void queries(){
    int q,x,y,k,mini,maxi;
    std::cin>>q;
    for(int i = 0; i < q; i++){
        std::cin>>x>>y;
        if(P[y] <= x){
            k = log_2[y-x+1];
            mini = std::min(rminq[x+(1<<k)-1][k], rminq[y][k]);
            maxi = std::max(rmaxq[x+(1<<k)-1][k], rmaxq[y][k]);
            if(maxi - mini == y - x){
                std::cout<<"1";
            }
            else{
                std::cout<<"0";
            }
        }
        else{
            std::cout<<"0";
        }
    }
}

int main(){

    std::cin>>n;
    for(int i = 1; i<= n; i++){
        std::cin>>a[i];
    }

    buildP();
    rmq();
    queries();

    return 0;
}