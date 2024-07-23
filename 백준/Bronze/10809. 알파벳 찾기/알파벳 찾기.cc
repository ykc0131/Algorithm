#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    vector<int> vec(26,-1);

    string s;
    cin >> s;

    for(int i=0; i<s.size(); i++){
        if(vec[s[i]-'a']==-1)
            vec[s[i]-'a']=i;
    }

    for(int v : vec){
        cout << v << " ";
    }
    cout << endl;

    return 0;
}