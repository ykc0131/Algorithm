//
// Created by yooki on 2024/07/20.
//
#include <iostream>
#include <string>

using namespace std;

string s;
int main(){
    cin >> s;

    int result=0;
    for(char c : s){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
            result++;
    }

    cout << result << endl;
    return 0;
}