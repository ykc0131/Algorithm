#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    queue<int> q;
    
    int pre = arr[0];
    q.push(pre);
    for(int i : arr){
        if(pre != i){
            q.push(i);
        }
        pre = i;
    }
    
    vector<int> answer;
    while(!q.empty()){
        answer.push_back(q.front()); q.pop();
    }
    
    return answer;
}