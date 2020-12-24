# Selection Sort(선택정렬) 정리🛠
## Selection Sort란?
- selection Sort는 **Bubble Sort** 와 유사한 알고리즘이다.
- Bubble Sort와의 차이점은 원소값을 바꿔줄 위치가 이미 정해진 상태에서 어떤 원소를 넣은지 선택한다는 것이다.

## 과정(오름차순)
- 조건: i=0, 배열사이즈=n
1. i부터 n까지 가장 작은 값을 찾는다.
2. 1번에서 찾은 가장 작은 값을 i번째 값과 바꾼다.
  2-1. i<n이 만족하지 않으면 종료
  2-2. 만족하면 i=i+1 이후에 1번으로 돌아간다.

## C++ 코드
```c
void selectionSort(vector arr){
	int minIdx, temp;
    for(int i=0; i<arr.size();i++){
    	minIdx = i;
    	for(int j=i+1; j<arr.size();j++){
        	if(arr[minIdx] > arr[j]){
            	minIdx = j;
            }
        }
        temp = arr[minIdx];
        arr[minIdx] = arr[i];
        arr[i] = temp;
    }
}
```


## 시간복잡도
- 총 반복횟수는
  - (n-1) + (n-2) + ... + 2 + 1 => n(n-1)/2 => O(n^2)

## 공간복잡도
- 하나의 배열안에서 변경(Swap)이 이뤄지므로 O(n)이다.

## 장점
- 실제로 값을 교환하는 횟수는 적기 때문에 교환(Swap)이 많이 필요한 것에서는 효율적인 알고리즘이다.
- 상당히 단순한 알고리즘이어서 구현이 쉽다.
- 제자리 정렬(in-place sorting)으로 다른 메모리 공간이 필요하지 않다.

## 단점
- 불안정정렬이다.
- 시간복잡도가 O(n^2)으로 비효율적이다.
