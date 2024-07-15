#include <iostream>
#include <algorithm>
#define INF 10000001

using namespace std;

int main(){
    int N;
    cin >> N;
    
    int minN = INF;
    int maxN = INF * (-1);
    for(int i=0; i<N; i++){
        int n;
        cin >> n;
        
        minN = min(minN, n);
        maxN = max(maxN, n);
    }
    
    cout << minN << " " << maxN << endl;
    
    return 0;
}