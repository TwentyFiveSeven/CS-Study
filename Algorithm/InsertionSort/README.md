# Insertion Sort(삽입 정렬) 정리🤸‍♂️
## Insertion Sort 란?
- 현재의 위치에서 값들을 비교하면서 본인보다 큰값 or 작은값을 찾을 때까지 값들의 위치를 변경하면서 진행하는 정렬이다.
- Insertion Sort는 Selection Sort보다 효율적인 정렬 알고리즘이다.
- 앞서 확인한 정렬(Bubble, Selection) 과 다르게 최선의 경우 O(n)이 될 수 있는 효율적인 알고리즘이다.

## 과정
- 조건 i=1, 배열사이즈=n, prev=i-1, temp=arr[i]
1. prev >= 0 && arr[prev] > temp
	1-1. arr[prev]가 크면 arr[prev+1] = arr[prev], prev--, 다시 1번으로간다.
    1-2. 만족하지 않으면 arr[prev+1] = temp, i = i+1 이후에
    	1-2-1. i >= n 이면 종료
        1-2-2. i < n 이면 1번부터 다시 진행

## 코드
```c
void insertionSort(vector<int> arr){
	int prev, temp;
    for(int i=1; i<arr.size();i++){
    	prev = i-1;
        temp = arr[i];
    	while( (prev >=0) && (arr[prev] > temp)){
        	arr[prev+1] = arr[prev];
            prev--;
        }
        arr[prev+1] = temp;
    }
}
```

## 시간복잡도
- 최악의 경우는 (n-1) + (n-2) + ... + 2 + 1 = n(n-1)/2 => O(n^2) 이다.
- 하지만 최선의 경우( 이미 정렬 되어있을 때 )는 배열을 한번만 순회하면 되기 때문에 => O(n)의 효율적인 시간복잡도를 가지게 된다.
- 또한 이미 정렬되어있는 배열에 삽입/제거를 할 때는 탐색을 제외한 오버헤드가 매우 적기 때문에 가장 좋은 정렬 알고리즘이 될 수 있다.

## 공간복잡도
- 하나의 배열안에서 이루어질 수 있으므로 O(n)이다.

## 장점
- 앞서 말했든 배열이 정렬되어있으면 매우 효율적인 정렬이 된다.
- 제자리 정렬, 안정 정렬이다.
- 알고리즘이 단순하고, 최선의 경우 Bubble, Selection보다 효율적이다.

## 단점
- 배열이 길어질수록 효율성이 떨어지고, Bubble, Selection과 마찬가지로 최악의 경우는 O(n^2)이다.
