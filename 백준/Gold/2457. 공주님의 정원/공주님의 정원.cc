//
// Created by yooki on 2024/03/09.
//
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <tuple>
#define START_LIMIT 94
#define END_LIMIT 371

using namespace std;

struct Flower{
    tuple<int,int,int> start;
    tuple<int,int,int> end;

    Flower(pair<int,int> start, pair<int,int> end){
        this->start = make_tuple(start.first,start.second,calDays(start));
        this->end = make_tuple(end.first,end.second,calDays(end));;
    }

    int calDays(pair<int,int> a){
        return a.first*31 + a.second;
    }
};

int N;
vector<Flower> flowers;
bool cmp(Flower a, Flower b){
    if(a.start == b.start)
        return a.end > b.end;
    return a.start < b.start;
}

void init(){
    cin >> N;
    for(int i=0; i<N; i++){
        int sm,sd,em,ed;

        cin >> sm >> sd >> em >> ed;
        flowers.push_back(Flower({sm,sd},{em,ed}));
    }

    sort(flowers.begin(), flowers.end(), cmp);
}

stack<Flower> result;
void solve(){
    Flower maxF = flowers[0];
    int initCnt = 0;
    bool complete = false;
    for(auto fl : flowers){
        //1. 첫번째 꽃 정하기
        if(result.empty()){
            //case 1: 꽃이 피고 있는 기간에 3/1이 포함된 경우
            if(get<2>(fl.end) > START_LIMIT && get<2>(fl.start) <= START_LIMIT){
                if(get<2>(maxF.end) < get<2>(fl.end))
                    maxF = fl;
                initCnt++;
            }
            //case 2: 꽃이 피는 날이 3월 1일 초과일 경우
            else if(get<2>(fl.start) > START_LIMIT){
                if(initCnt==0)
                    break;
                result.push(maxF);
            }
        }
        //2. 중간 꽃들 정하기
        if(!result.empty()){
            tuple<int,int,int> topEnd = result.top().end;
            //case 1 : 확정된 꽃과 겹치는 구간이 있을 경우
            if(get<2>(fl.start) <= get<2>(topEnd)){
                if(get<2>(maxF.end) < get<2>(fl.end)){
                    maxF = fl;
                }

            }
            //case 2 : 겹치는 구간이 없을 경우
            else {
                result.push(maxF);
                if(get<2>(fl.start) <=get<2>(maxF.end) && get<2>(maxF.end) < get<2>(fl.end))
                    maxF = fl;
            }
        }

        //3. 마지막 꽃 정하기
        //case 1 : 꽃이 지는 날짜가 11/30 이상일 경우 바로 종료
        if(get<2>(maxF.end) > END_LIMIT){
            result.push(maxF);
            complete = true;
            break;
        }
    }
    if(complete)
        cout << result.size() << "\n";
    else
        cout << 0 << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    solve();
    return 0;
}