#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1000

using namespace std;

int solution(vector<vector<int>> jobs) {
    int size = jobs.size();   
    sort(jobs.begin(), jobs.end());
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    int idx = 0, total = 0, time = 0;
    
    while(idx < size || !pq.empty()){        
        if(idx < size && jobs[idx][0] <= time ){
            pq.push({jobs[idx][1], jobs[idx][0]});
            idx++;
            continue;
        }
        
        if(!pq.empty()){
            pair<int,int> cur = pq.top(); pq.pop();
            
            time += cur.first;
            total += time - cur.second;
        }
        else{
            time = jobs[idx][0];
        }
    }

    
    return total/size;
}