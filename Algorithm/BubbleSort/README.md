# Bubble Sort(거품정렬)💦
## Bubble Sort란?
- `서로 인접한 두 원소의 대소를 비교하고, 조건에 맞지 않는다면 자리를 바꿔가면서 정렬하는 알고리즘`이다.

## 과정 (오름차순)
- 조건 i=0, 배열의길이 = n
1. i부터 i번째 값과 i+1번째 값을 비교한다.
2. i번째 값이 더 크다면 i+1번째 값과 바꾼다.
3. n-1 번째까지 비교하고,
  3-1. i<n이 만족하지 않다면 종료
  3-2. 만족한다면 n = n-1, 이후 다시 1번으로 돌아간다.


## C++ 코드 (오름차순)
```c
void bubbleSort(vector<int> arr){
  int temp = 0;
  for(int i=0;i<arr.size();i++){
    for(int j=0;j<arr.size()-i-1;j++){
      if(arr[j] > arr[j+1]){
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
}
```

## JavaScript 코드 (오름차순)
```javascript
const bubbleSort = (arr) =>{
  let temp = 0;
  for(let i = 0; i<arr.length;i++){
    for(let j = 0;j<arr.length-i-1;j++){
      temp = arr[j];
      arr[j] = arr[j+1];
      arr[j+1] = temp;
    }
  }
}
```

## 시간복잡도
- Time Complex = (n-1) + (n-2) + (n-3) + ... + 2 + 1 => n(n-1)/2
- => O(n^2)
- ** 개선된 거품정렬 ** 의 시간복잡도 확인하기

## 공간복잡도
- Temp 변수가 있다면 하나의 배열로도 충분하다 => O(n)

## 장점
- 구현이 매우 간단하고, 소스코드가 직관적이다.
- 하나의 배열안에서 정렬이 가능하다. => 제자리정렬
- 안정 정렬이다.(Stable Sort)

## 단점
- 시간복잡도가 모두 O(n^2)이다.
- Swap이 많이 일어난다.
