#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> input;
int arr[1001] = {0,};

void init(){
    cin >> N;
    for(int i=0; i<N; i++){
        int n;
        cin >> n;
        input.push_back(n);
    }
}

void solve(){
    arr[1] = 1;
    for(int i=2; i<33; i++){
        if(arr[i]==1)
            continue;
        for(int j=i*i; j<=1000; j+=i){
            if(arr[j])
                continue;
            arr[j] = 1;
        }
    }

    int cnt=0;
    for(int i=0; i<N; i++){
        if(arr[input[i]]==0)
            cnt++;
    }

    cout << cnt << "\n";
}

int main(){
    init();
    solve();
    return 0;
}