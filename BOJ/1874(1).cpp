#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<char> ans;
    stack<int> s;
    int index=0;
    for(int i=1; i<n+1;i++){
        int num;
        cin >> num;

        if(s.empty() || s.top()<num){
            for(int j=index+1;j<num+1;j++){
                s.push(j);
                ans.push_back('+');
            }
            index = num;
        }

        if(s.top()==num){
            s.pop();
            ans.push_back('-');
        }
        else{
            cout << "NO"<< "\n";
            return 0;
        }
    }

    for(char a : ans){
        cout << a << "\n";
    }

    return 0;
}
