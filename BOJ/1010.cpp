#include <iostream>
#include <vector>

using namespace std;
int main(){
    int T;
    cin >> T;
    while(T--){
        int N,M;
        cin>> N>>M;
        int n = M-N;
        vector<vector<int>> vec(N,vector<int>(n,0));

        int pastSum=0,rowSum=0,total=0;
        for(int i=0;i<N;i++){
            for(int j=0; j<n;j++){
                if(i==0){
                    vec[i][j]=1;
                    rowSum+=1;
                }
                else{
                    vec[i][j]=pastSum;
                    rowSum+=pastSum;
                    pastSum-=vec[i-1][j];
                }
            }
            total+=rowSum;
            pastSum = rowSum;
            rowSum=0;
        }
        cout << total+1 << endl;
    }
    return 0;
}
