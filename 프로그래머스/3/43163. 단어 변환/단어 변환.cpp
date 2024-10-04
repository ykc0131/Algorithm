#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int N, bIdx=-1, tIdx=-1;
vector<vector<int>> vec;
map<string,int> m;
void init(string begin, string target, vector<string> words){
    words.push_back(begin);
    N = words.size();
    vec.clear();
    vec.resize(N);
    
    for(int i=0; i<N; i++){
        m[words[i]] = i;
        for(int j=i+1; j<N; j++){
            if(i!=j) {
                int cnt=0;
                for(int k=0; k<words[i].size(); k++){
                    if(words[i][k] != words[j][k])
                        cnt++;
                }
                if(cnt==1){
                    vec[i].push_back(j);
                    vec[j].push_back(i);
                }
            }
        }
    }
    
    auto bIter = m.find(begin);
    if(bIter!=m.end())
        bIdx = bIter->second;

    auto tIter = m.find(target);
    if(tIter!=m.end())
        tIdx = tIter->second;
}

int result = 0;
void bfs(){
    queue<int> q;
    q.push(bIdx);
    vector<int> vst(N,-1);
    vst[bIdx] = 0;
    
    while(!q.empty()){
        int cur = q.front(); q.pop();

        if(cur==tIdx)
            break;
        
        for(int i=0; i<vec[cur].size(); i++){
            int next = vec[cur][i];
            
            if(vst[next]==-1){
                vst[next] = vst[cur] + 1;
                q.push(next);
            }
        }
    }
    
    result = vst[tIdx];
}

void solve(){
    if(tIdx==-1)
        return;
    bfs();
}

int solution(string begin, string target, vector<string> words) { 
    init(begin, target, words);
    solve();
    return result;
}
