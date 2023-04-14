#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N,K;
    cin >> N >> K;
    vector<int> W(N+1,0);
    vector<int> V(N+1,0);
    vector<vector<int>> vec(N+1,vector<int>(K+1,0));

    for(int i=1; i<N+1;i++){
       cin >> W[i] >> V[i];
    }

    for(int i=1; i<N+1;i++){
        for(int j=1; j<K+1;j++){
            if(j-W[i]>=0)
               vec[i][j] = max(vec[i-1][j],vec[i-1][j-W[i]]+V[i]);
            else
                vec[i][j] = vec[i-1][j];
        }
    }

    cout << vec[N][K] << "\n";
    return 0;
}
