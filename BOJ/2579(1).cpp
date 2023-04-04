#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> v(N,0);
    for(int i=0;i<N;i++){
        cin >> v[i];
    }

    vector<int> maxScore(N,0);
    vector<vector<int>> sumScore(N,vector<int>(2,0));
    sumScore[0][0]=v[0];
    sumScore[0][1]=0;
    maxScore[0]=v[0];

    for(int i=1;i<N;i++){
        if(i==1)
            sumScore[i][0]=v[i];
        else
            sumScore[i][0]=maxScore[i-2]+v[i];
        sumScore[i][1]=sumScore[i-1][0]+v[i];
        maxScore[i] = sumScore[i][0]>sumScore[i][1]?sumScore[i][0]:sumScore[i][1];
    }
    cout << maxScore[N-1]<< endl;

    return 0;
}
