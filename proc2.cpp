#include<fstream>
#include<queue>

std::ifstream fin("proc2.in");
std::ofstream fout("proc2.out");


struct Task{
    int start, duration;
};

struct Processor{
    int number;
    long long endTime;

    bool operator<(const Processor& other) const{
        if(endTime == other.endTime){
            return number > other.number;
        }
        return endTime > other.endTime;
    }
};



int main(){
    int n, m;
    fin>>n>>m;

    std::vector<Task> tasks(m);
    for(int i = 0; i < m; i++){
        int s, d;
        fin >> s >> d;
        tasks[i].start = s;
        tasks[i].duration = d;
    }

    std::priority_queue<int> available;
    std::priority_queue<Processor> busy;

    for(int i = 1; i <= n; i++){
        available.push(-i);
    }

    for(int i = 0; i < m; i++){
        int Si, Di;
        Si = tasks[i].start;
        Di = tasks[i].duration;

        while(!busy.empty() && busy.top().endTime <= Si){
            available.push(-(busy.top().number));
            busy.pop();
        }

        int proc = -(available.top());
        available.pop();

        long long endTime = Si + Di;

        busy.push({proc, endTime});

        fout<<proc<<std::endl;
    }


    fin.close();
    fout.close();
    return 0;
}