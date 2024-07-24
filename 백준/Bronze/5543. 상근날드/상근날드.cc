#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int b=2000, c=2000;
    
    for(int i=0; i<3; i++){
        int n;
        cin >> n;
        b = min(b,n);
    }
    
    for(int i=0; i<2; i++){
        int n;
        cin >> n;
        c = min(c,n);
    }
    
    cout << b+c-50 << endl;
    
    return 0;
}