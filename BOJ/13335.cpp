#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n,w,L;
    cin >> n >> w >> L;

    vector<int> truck(n,0);
    vector<int> timeVec;
    for(int i=0; i<n;i++){
        cin >> truck[i];
    }

    for(int i=0; i<w;i++){
        timeVec.push_back(truck[0]);
    }

    int timeIndex=1;
    for(int i=1; i<n;i++){
        int cnt=0;
        int truckW = truck[i];

        for(int j=0; j<w-1;j++){
            int index = timeIndex+j;
            if(timeVec[index]+truckW<=L)
                timeVec[index]+=truckW;
            else{
                timeVec.push_back(truckW);
                cnt++;
            }
        }
        timeVec.push_back(truckW);
        cnt++;
        timeIndex+=cnt;
    }

    cout << timeVec.size() + 1 << "\n";

    return 0;
}
