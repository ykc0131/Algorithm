#include <iostream>
#include <vector>
#include <algorithm>
#define INF 100002
using namespace std;

int N;
vector<int> vec;
void init(){
    cin >> N;
    vec.resize(N+1,INF);
}

// 0 - -1
// 1 - -1
// 2 - 1
// 3 - -1
// 4 - 2
// 5 - 1
// 6 - 3
// 7 - 2
void solve(){
    for(int i=2; i<N+1; i++){
        if(i%2==0)
            vec[i] = min(vec[i], i/2);
        if(i%5==0)
            vec[i] = min(vec[i], i/5);
        if(i-2>=0 && vec[i-2]!=INF)
            vec[i] = min(vec[i], vec[i-2]+1);
        if(i-5>=0 && vec[i-5]!=INF)
            vec[i] = min(vec[i], vec[i-5]+1);
    }

    if(vec[N]==INF)
        cout << -1 << "\n";
    else
        cout << vec[N] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    solve();
    return 0;
}
