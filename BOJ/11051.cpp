#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N,K;
    cin >> N >> K;

    vector<vector<int>> vec(N+1,vector<int>(N+1,0));
    for(int i=0; i<N+1;i++){
        vec[0][i]=1;
    }

    for(int i=1;i<N+1;i++){
        for(int j=0;j<N+1-i;j++) {
            if (j == 0)
                vec[i][j] = 1;
            else
                vec[i][j] += (vec[i][j - 1] + vec[i - 1][j])%10007;
        }
    }
    cout << vec[N-K][K]%10007 << endl;
    return 0;
}
