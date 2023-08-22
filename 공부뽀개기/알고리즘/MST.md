# MST (최소 신장 트리)

- Minimun Spanning Tree

### 신장트리

신장 트리(Spanning Tree)란 무방향(Undirected) 그래프의 최소 연결 부분 그래프이다. 

N개의 정점을 가지는 그래프 중 최소 간선의 수인 N-1개의 간선으로 연결된 그래프를 뜻한다. 

⇒ N개의 정점이 N-1개의 간선으로 연결되어 있으면 이것은 필연적으로 트리 형태를 이루게 되기 때문에 신장 트리라고 불린다. 

### 크루스칼 알고리즘

크루스칼 알고리즘은 그리디 알고리즘의 일종으로 최소 신장 트리를 구하는 대표적인 알고리즘 중 하나이다. 

1. 간선의 가중치를 `오름차순`으로 정렬한다. 
2. 오름차순으로 정렬된 간선들을 탐색하며 해당 간선을 신장 트리에 포함할 때
    
    1) 사이클이 발생한 경우 신장 트리에 포함하지 않고 넘어간다. 
    
    2) 사이클이 발생하지 않는 경우 신장 트리에 포함한다.
    
3. 모든 정점을 연결할 때까지 위 과정을 반복한다. 

#### 코드
```cpp
class Edge{
public :
	int node[2];
	int distance;
	Edage(int a, int b, int distance){
		this->node[0] = a;
		this->node[1] = b;
		this->distance = distance;
	}

	//오름차순
	bool operator<(Edge &edge){
		return this->distance < edge.distance;
	}
};
```

```cpp
int findParent(int node){
		if(parent[node]==node)
				return node;
		return findParend(parent[node]);
}
```

```cpp
bool isCycle(int node1, int node2){
	node1 = findParent(node1);
	node2 = findParent(node2);

	if(node1<node2) 
			return true;
	else 
			return false;
```

```cpp
int main(){
  ...
  vector<Edge> edges;
	...
	long long sum=0;
	for(int i=0; i<edges.size();i++){
		if(!isCycle(edges[i].node[0], edges[i].node[1]){
			sum+=edges[i].distance;
			unionParent(edges[i].node[0],edges[i].node[1]);
	}
}
```
