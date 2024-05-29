#include<fstream>
#include<queue>

std::ifstream fin("bleach.in");
std::ofstream fout("bleach.out");

int main(){

    int n, k;
    fin>>n>>k;
    long long startPower=0, sum=0, currentPower, dif;

    std::priority_queue<int> pq;

    for(int i = 0; i<std::min(k + 1, n); i++){
        int x;
        fin>>x;
        pq.push(-x);
    }

    for(int i = k + 1; i < n; i++){
        currentPower = -pq.top();
        pq.pop();

        if(currentPower > sum){
            dif = currentPower - sum;
            if(dif > startPower){
                startPower = dif;
            }
        }
        sum += currentPower;
        int x;
        fin >> x;
        pq.push(-x);
    }

    while(!pq.empty()){
        currentPower = -pq.top();
        pq.pop();

        if(currentPower > sum){
            dif = currentPower - sum;
            if(dif > startPower){
                startPower = dif;
            }

        }
        sum += currentPower;
    }

    fout << startPower;

    return 0;
}