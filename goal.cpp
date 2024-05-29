#include<iostream>
#include<vector>
#include<queue>

const int N_MAX = 1000001;
std::vector<int> aib;

void add(int i, int k){
    while(i < N_MAX){
        aib[i] +=k;
        i += i & -i;
    }
}


int main(){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);


    int n;
    std::cin>>n;

    std::priority_queue<int,std::vector<int>, std::greater<int>> pq;


    for(int i=0; i<n; i++){
        int op,k;
        std::cin>>op>>k;

        if(op == 1){
            pq.push(k);
        }
        else if(op == 2){
            std::vector<int> aux;
            for (int j = 0; j < k; j++) {
                aux.push_back(pq.top());
                pq.pop();
            }

            int sum = 0;
            for (int val : aux) {
                sum += val;
                pq.push(val);
            }
            std::cout<<sum<<std::endl;
        }
    }


    return 0;
}