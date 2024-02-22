//
// Created by yooki on 2024/02/22.
//
#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack<char> st;
string s;

void init(){
    cin >> s;
}

void solve(){
    int result = 0;
    for(int i=0; i<s.size(); i++){
        char c = s[i];

        if(c=='('){
            if(s[i+1]==')') { // 레이저
                result += st.size();
                i++;
            }
            else
                st.push('(');
        }
        else{
            st.pop();
            result++;
        }
    }
    cout << result << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    solve();
    return 0;
}