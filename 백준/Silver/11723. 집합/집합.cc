//
// Created by yooki on 2024/03/07.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int M;
vector<int> arr;
void init(){
    cin >> M;
    arr.clear();
    arr.resize(21,0);
}

void solve(){
    while(M--){
        string s;
        cin >> s;

        int num;
        if(s=="add"){
            cin >> num;
            arr[num]=1;
        }
        else if(s=="remove"){
            cin >> num;
            if(arr[num]>0)
                arr[num]-=1;
        }
        else if(s=="check"){
            cin >> num;
            if(arr[num]>0)
                cout << 1 << "\n";
            else
                cout << 0 << "\n";
        }
        else if(s=="toggle"){
            cin >> num;
            if(arr[num]>0)
                arr[num]-=1;
            else
                arr[num]=1;
        }
        else if(s=="all"){
            arr.clear();
            arr.resize(21,1);
        }
        else if(s=="empty"){
            arr.clear();
            arr.resize(21,0);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    solve();
    return 0;
}