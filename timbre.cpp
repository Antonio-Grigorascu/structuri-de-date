#include<fstream>
#include<vector>
#include<queue>
#include<algorithm>

std::ifstream fin("timbre.in");
std::ofstream fout("timbre.out");

struct Interval {
    int margin, cost;
};

bool comp(Interval A, Interval B){
    return A.margin > B.margin;
}

int main() {

    int n,m,k;
    fin>>n>>m>>k;
    std::vector<Interval> a(m);
    for(int i = 0; i < m; i++){
        fin>>a[i].margin>>a[i].cost;
    }

    std::priority_queue <int, std::vector<int>, std::greater<int> > pq;

    std::sort(a.begin(),a.end(), comp);
    int cost = 0;
    int x = n;
    int i = 0;

    while(x > 0){
        while(i < m && a[i].margin >= x){
            pq.push(a[i].cost);
            i++;
        }
        if(!pq.empty()){
            cost += pq.top();
            pq.pop();
        }
        x -= k;
    }

    fout<<cost<<std::endl;

    return 0;
}
