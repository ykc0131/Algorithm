#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> inputs;
vector<int> parent;
vector<bool> visited;

int findParent(int n){
    if(parent[n] == n)
        return n;
    return findParent(parent[n]);
}

void unionParent(int n1, int n2){
    n1 = findParent(n1);
    n2 = findParent(n2);
    
    
    if(n1 < n2)
        parent[n2] = n1;
    else
        parent[n1] = n2;
}

bool isCycle(int n1, int n2){
    n1 = findParent(n1);
    n2 = findParent(n2);
    if(n1==n2)
        return true;
    else
        return false;
}

int cal(int i, int n){
    if(i > N)
        return n;
    visited[i]=true;
    int c = inputs[i];
    if(!isCycle(i,c)){
        unionParent(i, c);
        return cal(c, n+1);
    }
    return n;
}

void init(vector<int> cards){
    N = cards.size();
    inputs.clear();
    parent.clear();
    visited.clear();
    inputs.resize(N+2,0);
    parent.resize(N+2,0);
    visited.resize(N+2,false);

    for(int i=1; i<N+1;i++){
        parent[i] = i;
    }
    
    for(int i=1;i<N+1;i++){
        inputs[i] = cards[i-1];
    }
}

int cmp(int a, int b){
    return a>b;
}

int solution(vector<int> cards) { //size = 8
    init(cards);
    
    vector<int> output;
    for(int i=1; i<N+1;i++){ //1~8
        if(!visited[i]){
            output.push_back(cal(i,0)+1);
        }
    }
    
    if(output.size()==1)
        return 0;
    sort(output.begin(),output.end(),cmp);
    return output[0]*output[1];
}
