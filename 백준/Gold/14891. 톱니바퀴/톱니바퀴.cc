#include <iostream>
#include <vector>

using namespace std;

int K;
vector<vector<int>> wheel(4);
int top[] = {0,0,0,0};
void init(){
    for(int i=0; i<4; i++) {
        string s;
        cin >> s;
        for(char c: s)
            wheel[i].push_back(c - '0');
    }
    cin >> K;
}

vector<int> change;
void clear(){
    change.clear();
    change.resize(4,0);
}

void check(int n, int d){
    change[n] = d;
    int lIdx = (top[n] + 2) % 8, rIdx = (top[n] + 6) % 8;

    if(n!=3 && !change[n+1] && wheel[n][lIdx]^wheel[n+1][((top[n+1] + 6) % 8)]){
        check(n+1, -d);
    }

    if(n!=0 && !change[n-1] && wheel[n][rIdx]^wheel[n-1][((top[n-1] + 2) % 8)]){
        check(n-1, -d);
    }
}

void solve(){
    while(K--){
        int n, d;
        cin >> n >> d;
        clear();
        check(n-1, -d);

        for(int i=0; i<4; i++){
            top[i] = (top[i] + change[i] + 8) % 8;
        }
    }

    int result = 0;
    for(int i=0; i<4; i++){
        result += wheel[i][top[i]] << i;
    }
    cout << result << "\n";
}

int main(){
    init();
    solve();
    return 0;
}