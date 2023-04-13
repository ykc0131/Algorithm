#include <iostream>
#include <queue>

using namespace std;

int main() {
    int N;
    cin >> N;

    queue<int> q;
    for(int i=1; i<N+1;i++){
        q.push(i);
    }

    int cnt=0;
    while(!q.empty()){
        if(q.size()==1)
            break;
        int value = q.front(); q.pop();
        if(cnt%2)
            q.push(value);
        cnt=(cnt+1)%2;
    }

    cout << q.front()<< endl;
    q.pop();

    return 0;
}
