#include <string>
#include <vector>
#include <queue>
#include <iostream>
#define INF 50001

using namespace std;

int N;
vector<vector<int>> vec;

void init(int n, vector<vector<int>> edge){
    N = n;
    vec.resize(N+1);
    
    for(int i=0; i<edge.size(); i++){
        int u = edge[i][0];
        int v = edge[i][1];
        
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
}

vector<int> dij(){
    vector<int> dist(N+1,INF);
    dist[1] = 0;
    
    priority_queue<pair<int,int>> pq;
    pq.push({0,1});
    
    int cnt = 1;
    while(!pq.empty()){
        int cur = pq.top().second;
        int cost = -pq.top().first; pq.pop();
        
        cnt+=1;
        if(cnt==N)
            break;
        
        for(int i=0; i<vec[cur].size(); i++){
            int next = vec[cur][i];

            if(dist[next] > cost + 1){
                dist[next] = cost + 1;
                pq.push({-dist[next], next});
            }
        }
    }
    
    return dist;
}

int solution(int n, vector<vector<int>> edge) {
    init(n, edge);
    vector<int> dist = dij();
    
    int maxN=0, answer = 0;
    for(int i=1; i<N+1; i++){
        if(maxN < dist[i]){
            maxN = dist[i];
            answer=1;
        }
        else if(maxN==dist[i])
            answer++;
    }

    return answer;
}