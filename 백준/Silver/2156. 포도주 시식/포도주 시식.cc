#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> inputs;
vector<vector<int>> vec;
void init(){
    cin >> N;

    for(int i=0; i<N; i++){
        int n;
        cin >> n;
        inputs.push_back(n);
    }

    vec.resize(N+1,vector<int>(3));
}

void solve(){
    for(int i=0; i<N; i++){
        vec[i][0] = vec[i][1] = inputs[i];
        if(i>=2)
            vec[i][0] += vec[i-2][2];

        if(i>=1)
            vec[i][1] += vec[i-1][0];

        vec[i][2] = max(vec[i][0], vec[i][1]);
        if(i>=1)
            vec[i][2] = max(vec[i][2], vec[i-1][2]);
    }

    cout << vec[N-1][2] << "\n";
}

int main() {
    init();
    solve();
    return 0;
}
