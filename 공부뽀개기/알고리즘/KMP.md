# KMP알고리즘

문자열 중에 특정 패턴을 찾아내는 문자열 검색 알고리즘 중 하나

- Knuth, Morris, Pratt 세 사람이 만든 알고리즘

### 모든 문자열을 일일이 비교하는 경우 : 브루트포스

텍스트길이 : N, 찾고자 하는 패턴 : M

|  시간복잡도 | O(NM)  |
| --- | --- |

하지만 KMP 알고리즘을 사용하면 O(N+M)에 패턴을 찾을 수 있다. 

### 접두부 & 접미부
ABCABCAC
| 접두부 | 접미부 |
| :--- | ---: |
| A | C |
| AB | AC |
| ABC | CAC |
| ABCA | BCAC |
| ABCAB | ABCAC |
| ABCABC | CABCAC |
| ABCABCA | BCABCAC |

이때 접두부와 접미부는 전체 문자열은 될 수 없음을 주의하자. 

### failure 함수 구하기

1. 문자열 s = a0a1…an-1 이라고 할 때, a0부터 an-1까지 늘려가면서 접두부와 접미부가 같은지 파악
    - 접두부와 접미부가 같지 않으면, -1
    - 접두부와 접미부가 같으면, 접두부와 접미부가 최대의 길이로 같을 때 접두부의 마지막 인덱스를 저장

**예시)**

ABCABCAC

1. failure[0] 구하기 
    
    
    |  | A | B | C | A | B | C | A | C |
    | --- | --- | --- | --- | --- | --- | --- | --- | --- |
    | f[] | -1 |  |  |  |  |  |  |  |
    | index | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
2. failure[1] 구하기 
    
    
    |  | A | B | C | A | B | C | A | C |
    | --- | --- | --- | --- | --- | --- | --- | --- | --- |
    | f[] | -1 | -1 |  |  |  |  |  |  |
    | index | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
3. failure[2] 구하기 
    
    
    |  | A | B | C | A | B | C | A | C |
    | --- | --- | --- | --- | --- | --- | --- | --- | --- |
    | f[] | -1 | -1 | -1 |  |  |  |  |  |
    | index | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
4. failure[3] 구하기
    
    
    |  | A | B | C | A | B | C | A | C |
    | --- | --- | --- | --- | --- | --- | --- | --- | --- |
    | f[] | -1 | -1 | -1 | 0 |  |  |  |  |
    | index | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
5. failure[4] 구하기
    
    
    |  | A | B | C | A | B | C | A | C |
    | --- | --- | --- | --- | --- | --- | --- | --- | --- |
    | f[] | -1 | -1 | -1 | 0 | 1 |  |  |  |
    | index | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
6. failure[5] 구하기
    
    
    |  | A | B | C | A | B | C | A | C |
    | --- | --- | --- | --- | --- | --- | --- | --- | --- |
    | f[] | -1 | -1 | -1 | 0 | 1 | 2 |  |  |
    | index | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
7. failure[6] 구하기
    
    
    |  | A | B | C | A | B | C | A | C |
    | --- | --- | --- | --- | --- | --- | --- | --- | --- |
    | f[] | -1 | -1 | -1 | 0 | 1 | 2 | 3 |  |
    | index | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
8. failure[7] 구하기
    
    
    |  | A | B | C | A | B | C | A | C |
    | --- | --- | --- | --- | --- | --- | --- | --- | --- |
    | f[] | -1 | -1 | -1 | 0 | 1 | 2 | 3 | -1 |
    | index | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
    

### KMP 계산하기

1. 본문과 패턴을 처음부터 비교한다. 
2. 본문과 패턴을 비교해서 같으면 본문과 패턴 모두 한 글자씩 뒤로 계속 비교한다. 
    1. 만약 패턴의 첫 글자부터 다르다면 비교할 본문의 글자를 하나 미룬다. 
    2. 만약 패턴이 일치하는 부분이 있다면, 불일치하는 부분 직전까지의 failure[]값 +1 부터 패턴을 다시 비교한다. 

**예시)**

ABCABABCABCAC

|  | A | B | C | A | B | C | A | C |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| f[] | -1 | -1 | -1 | 0 | 1 | 2 | 3 | -1 |
| index | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |

1. 본문과 패턴을 처음부터 비교한다. 
2. 본문과 패턴을 비교해서 같으면 본문과 패턴 모두 한 글자씩 뒤로 계속 비교한다. 
    
    A와 C 불일치! 
    
     불일치하는 부분 직전의 패턴의 index의 값을 이용하여 failure에서 값을 가져온다. 
    
    |  | A | B | C | A | B | A | B | C | A | B | C | A | C |
    | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
    |  | A | B | C | A | B | C | A | C |  |  |  |  |  |
    |  | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |  |  |  |  |  |
    |  | -1 | -1 | -1 | 0 | 1 | 2 | 3 | -1 |  |  |  |  |  |
    
    failure[4] = 1 이므로, failure[]값 + 1 인 2부터 패턴을 다시 비교한다. 
    
    |  | A | B | C | A | B | A | B | C | A | B | C | A | C |
    | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
    |  |  |  |  | A | B | C | A | B | C | A | C |  |  |
    |  |  |  |  | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |  |  |
    
    이어서 계속하면, 
    
    |  | A | B | C | A | B | A | B | C | A | B | C | A | C |
    | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
    |  |  |  |  | A | B | C | A | B | C | A | C |  |  |
    |  |  |  |  | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |  |  |
    
    인덱스2에서 불일치! failure[2-1] + 1 = 0 
    
    |  | A | B | C | A | B | A | B | C | A | B | C | A | C |
    | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
    |  |  |  |  |  |  | A | B | C | A | B | C | A | C |
    |  |  |  |  |  |  | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |

<br>
**코드**

```cpp
int kmp(char* str, char* pat){
	int i=0; 
	int j=0;
	int lens = strlen(str);
	int lenp = strlen(str);

	while(i<lens && j<lenp){
		if(str[i]==pat[j]){
			i++;j++;
		}
		else if(j==0)
			i++;
		else{
			j = failure[j-1]+1;
		}
	}
	return (j==lenp ? i-lenp:-1);
}
```

### KMP를 사용하여 failure 함수 구하기

```cpp
void fail(char *pat){
	int j,n = strlen(pat);
	failure[0]=-1;
		
	for(int i=1;i<n;i++){
		j = failure[i-1];
		while((pat[i]!=pat[j+1]) && (j>=0))
				j=failure[j];
		if(pat[i] == pat[j+1])
				failure[i] = j+1;
		else
				failure[i] = -1;
}
```
