#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int K;
vector<vector<int>> wheel(4);
vector<pair<int,int>> inputs;
int top[] = {0,0,0,0};
void init(){
    for(int i=0; i<4; i++){
        string s;
        cin >> s;
        for(char c : s)
            wheel[i].push_back(c-'0');
    }

    cin >> K;
    for(int i=0; i<K; i++){
        int n, direction;
        cin >> n >> direction;
        inputs.push_back({n-1, direction});
    }
}

vector<int> change;
void clear(){
    change.clear();
    change.resize(4,0);
}

void check(int n, int direction){
    change[n] = direction;
    int lIdx = (top[n] + 2) % 8;
    int rIdx = (top[n] + 6) % 8;

    if(n!=3 && !change[n+1] && wheel[n][lIdx]^wheel[n+1][((top[n+1] + 6) % 8)]){
        check(n+1, direction*(-1));
    }

    if(n!=0 && !change[n-1] && wheel[n][rIdx]^wheel[n-1][((top[n-1] + 2) % 8)]){
        check(n-1, direction*(-1));
    }
}

void solve(){
    for(auto p : inputs){
        clear();
        check(p.first, p.second*(-1));
        for(int i=0; i<4; i++){
            top[i] = (top[i] + change[i] + 8) % 8;
        }
    }

    int result = 0;
    for(int i=0; i<4; i++){
        if(wheel[i][top[i]])
            result += pow(2,i);
    }
    cout << result << "\n";
}

int main(){
    init();
    solve();
    return 0;
}