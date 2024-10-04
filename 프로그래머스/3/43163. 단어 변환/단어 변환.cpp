#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int N, bIdx=-1, tIdx=-1;
bool posi(string a, string b){
    int cnt=0;
    for(int i=0; i<a.length(); i++){
        if(a[i]!=b[i]) cnt++;
    }
    
    if(cnt==1)
        return true;
    return false;
}

int solution(string begin, string target, vector<string> words) { 
    queue<pair<string,int>> q;
    q.push({begin,0});
    
    int result = 0;
    vector<int> vst(words.size(), 0);
    while(!q.empty()){
        pair<string,int> temp = q.front(); q.pop();
        string cur = temp.first;
        int num = temp.second;

        if(cur == target){
            result = num;
            break;
        }
        
        for(int i=0; i<words.size(); i++){
            if(posi(cur, words[i]) &&  vst[i]==0){
                vst[i] = 1;
                q.push({words[i], num+1});
            }
        }
    }
    
    return result;
}
