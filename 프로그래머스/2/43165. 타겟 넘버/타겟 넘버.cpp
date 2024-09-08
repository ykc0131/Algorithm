#include <string>
#include <vector>

using namespace std;

int N, result = 0, target;
vector<int> vec;
void solve(int cnt, int n){
    if(cnt==N){
        if(n == target)
            result++;
        return;
    }
    solve(cnt+1, n+vec[cnt]);
    solve(cnt+1, n-vec[cnt]);
}

int solution(vector<int> numbers, int t) {
    vec = numbers;
    N = numbers.size();
    target = t;
    
    solve(0, 0);
    
    return result;
}