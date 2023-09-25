#include <string>
#include <vector>
#include <queue>

using namespace std;

int N,K;
vector<int> enemy;
priority_queue<int,vector<int>,greater<>> pq;

void init(int n, int k, vector<int> e){
    N=n;
    K=k;
    enemy=e; 
}

int cal(){
    int sum = 0;
    for(int i=0; i<enemy.size();i++){
        int e = enemy[i];
        if(pq.size()<K)
            pq.push(e);
        else if(pq.size()==K){
            if(e>pq.top()){
                sum+=pq.top();pq.pop();
                pq.push(e);
            }
            else
                sum+=e;
            
            if(sum>N)
                return i;
        }
    }
}

int solution(int n, int k, vector<int> e) {
    init(n,k,e);
    int answer = cal();
    return answer;
}
