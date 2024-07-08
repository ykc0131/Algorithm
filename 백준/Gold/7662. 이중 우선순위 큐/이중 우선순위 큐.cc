//
// Created by yooki on 2024/07/08.
//
#include <iostream>
#include <queue>

using namespace std;

priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> greaterPQ; // 오름차순
priority_queue<pair<int,int>, vector<pair<int,int>>, less<pair<int,int>>> lessPQ; // 내림차순

int Q;
vector<bool> vec;
void init(){
    cin >> Q;
    vec.clear();
    vec.resize(Q,false);
    greaterPQ = priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>();
    lessPQ = priority_queue<pair<int,int>, vector<pair<int,int>>, less<pair<int,int>>>();
}

void solve(){
    int idx = 0;

    while(Q--){
        char cmd;
        int n;
        cin >> cmd >> n;

        if(cmd=='I'){
            greaterPQ.push({n,idx});
            lessPQ.push({n,idx});
            idx++;
        }
        else if(cmd=='D'){
            if(n < 0 ){ // 최솟값 삭제 연산
                while(!greaterPQ.empty()){
                    pair<int,int> p = greaterPQ.top();
                    
                    if(vec[p.second]==true)
                        greaterPQ.pop();
                    else{
                        vec[p.second] = true;
                        greaterPQ.pop();
                        break;
                    }
                }
            }
            else { // 최댓값 삭제 연산
                while(!lessPQ.empty()){
                    pair<int,int> p = lessPQ.top();
                    
                    if(vec[p.second]==true)
                        lessPQ.pop();
                    else {
                        vec[p.second] = true;
                        lessPQ.pop();
                        break;
                    }
                }
            }
        }
    }

    while(!greaterPQ.empty()){
        pair<int,int> p = greaterPQ.top();

        if(vec[p.second]==true)
            greaterPQ.pop();
        else
            break;
    }

    while(!lessPQ.empty()){
        pair<int,int> p = lessPQ.top();

        if(vec[p.second]==true)
            lessPQ.pop();
        else
            break;
    }

    if(lessPQ.empty() || greaterPQ.empty()){
        cout << "EMPTY\n";
    }
    else {
        cout << lessPQ.top().first << " " << greaterPQ.top().first << "\n";
    }
}

int main(){
    int T;
    cin >> T;

    while(T--){
        init();
        solve();
    }

    return 0;
}