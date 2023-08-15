# 우선순위 큐 (Priority_queue) (ING)

## 1. Intro. About Priority_queue

- 우선순위 큐 : 우선순위의 개념을 큐에 도입한 자료구조

| 자료구조 | 삭제되는 요소 |
| --- | --- |
| 스택(Stack) | 가장 최근에 들어온 데이터 |
| 큐(Queue) | 가장 먼저 들어온 데이터 |
| 우선순위 큐(Priority Queue) | 가장 우선순위가 높은 데이터 |
- 우선순위 큐는 배열, 연결리스트, 힙으로 구현이 가능하다. → 그 중 힙(Heap)이 효율적

| 표현방법 | 삽입 | 삭제 |
| --- | --- | --- |
| 순서 없는 배열 | O(1) | O(n) |
| 순서 없는 연결리스트 | O(1) | O(n) |
| 정렬된 배열 | O(n) | O(1) |
| 정렬된 연결리스트 | O(n) | O(1) |
| 힙(heap) | O(logn) | O(logn) |
- Queue 헤더파일에서 priority_queue를 제공한다.
- 우선순위 큐는 Max Heap으로 설정되어 있다.
    - Max Heap에서는 큰 값이 우선순위가 크므로 Heap으로 구성되어 있다.

## 2. How to use

### 우선순위 큐(Priority_queue) : 선언

1) 우선순위 큐에 Container를 작성하는 경우

- Container는 벡터 같은 컨테이너를 말하고, Compare는 비교함수이다.
- priority_queue는 기본적으로 Max Heap이므로 기본형을 사용했을 때, default로 내림차순으로 적용이된다.

```cpp
priority_queue<T> pq; //기본형
priority_queue<T, Container<T>, Compare> pq; // 3가지 parameter 작성
```

- 실제 선언 예시

```cpp
priority_queue<int> pq; //사용법
priority_queue<int, vector<int>, less<int>> pq;  //내림차순
priority_queue<int, vector<int>, greater<int>> pq;  //오름차순
```

2) 우선순위 큐에 pair가 들어가게 작성할 경우

- pair에서 first 값을 기준으로 Max-Heap 동작을 한다.

```cpp
priority_queue<pair<int,int>> pq;
```

- pair<int,int> 형을 우선순위 큐에서 사용하고 Min-Heap으로 동작하게 하는 방법

```cpp
priority_queue<<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
```

### 우선순위 큐(Priority_queue) :  push()

- 우선순위 큐에 원소를 추가한다.

```cpp
pq.push(1); // int
pq.push({first, second}); //pair
```

### 우선순위 큐(Priority_queue) : pop()

- 우선순위 큐에서 top의 원소를 제거한다.

```cpp
pq.pop();
```

### 우선순위 큐(Priority_queue) : top()

- 우선순위 큐에서 top에 있는 원소를 반환한다.

```cpp
pq.top(); 
pq.top().first; //pair first
pq.top().second; //pair second
```
