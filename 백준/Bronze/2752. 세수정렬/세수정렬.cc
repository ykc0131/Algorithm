#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vec;
int main(){
    for(int i=0; i<3; i++){
        int n;
        cin >> n;
        vec.push_back(n);
    }
    
    sort(vec.begin(), vec.end());
    
    for(int v : vec){
        cout << v << " ";
    }
    cout << endl;
    return 0;
}