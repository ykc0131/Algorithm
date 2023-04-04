#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<long long> v(N+1,0);
    vector<long long> f(N+1,0);
    v[1]=3,v[2]=7,f[1]=3;

    for(int i=3;i<N+1;i++){
        v[i]=(v[i-1]+2*f[i-2]+4)%9901;
        f[i-1]=(f[i-2]+v[i-1])%9901;
    }
    cout << v[N]%9901 << endl;

    return 0;
}