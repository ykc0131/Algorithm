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

    //방법-1
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

    //방법-2
    //시간 1/2 줄이기
    int value;
    while(!q.empty()){
        value = q.front();q.pop();
        if(q.empty())
            break;
        q.push(q.front());
        q.pop();
    }

    cout << value << endl;

    return 0;
}