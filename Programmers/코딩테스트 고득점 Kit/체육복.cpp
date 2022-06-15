#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = lost.size();
    vector<int> r(n+1,0),not_mine;
    for(int i : reserve)
        r[i]=1;
    
    for(int i : lost){
        if(r[i]!=1){
            not_mine.push_back(i);
            continue;
        }
        r[i]--;
        answer--;
    }
    
    sort(not_mine.begin(),not_mine.end());
    for(int i : not_mine){ 
        if(i>1 && r[i-1]==1){
            r[i-1]--;
            answer--;
        }
        else if(i< n && r[i+1]==1){
            r[i+1]--;
            answer--;
        }
    }
    
    return n-answer;
}
