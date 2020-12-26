# Merge Sort(합병정렬) 정리
## Merge Sort란?
- 분할 정복 방법을 통해 구현하는 정렬
  - 분할 정복: 큰문제를 작은 문제 단위로 쪼개면서 해결하는 방식이다.

## 과정 (오름차순)
- 배열을 작은크기로 쪼개는 과정을 통해 전체 길이가 8이라고하면,
  1. 전체8길이의 배열에서 `재귀호출`을 통해 왼쪽 4, 오른쪽 4로 배열을 나누고
      1. 왼쪽4길이의 배열에서 왼쪽 2, 오른쪽 2로 배열을 나눠 왼쪽, 오른쪽 배열의 대소를 비교해서 `왼쪽4길이의 배열`을 정렬한다.
      2. 오른쪽4길이의 배열에서 왼쪽2, 오른쪽 2로 배열을 나눠 왼쪽, 오른쪽 배열의 대소를 비교해서 `오른쪽4길이의 배열`을 정렬한다.
  2. 왼쪽4, 오른쪽4의 배열의 대소를 비교해서 전체8길이의 배열을 정렬한다.

## 코드
```c
int main(){
  int arr[8] = { 123, 1, 441, 221, 6 ,-3, 16, 110 };
  mergeSort(arr, 0, 7);
  for(int i=0;i<8;i++){
    cout<<arr[i]<<' ';
  }
  return 0;
}

void mergeSort(int arr[], int left, int right) {
  if(left<right){
    int mid = (left + right) /2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid+1, right);
    merge(arr, left, mid, right);
  }
}

void merge(int arr[], int left, int mid, int right){
  int leftArr[8] = {0}, rightArr[8]= {0};
  memcpy(leftArr, arr+left, sizeof(int)*(mid-left+1));
  memcpy(rightArr, arr+mid+1, sizeof(int)*(right-(mid+1)+1));

  int i=0, j=0, k=left;
  int ll=mid-left+1, rl=right-mid;

  while(i < ll && j < rl) {
    if(leftArr[i] <=rightArr[j])
      arr[k] = leftArr[i++];
    else
      arr[k] = rightArr[j++];
    k++;
  }
  while(i < ll)
    arr[k++] = leftArr[i++];
  while(j < rl)
    arr[k++] = rightArr[j++];
}
```

## 시간복잡도
- 최선: O(nLogn)
- 평균: O(nLogn)
- 최악: O(nLogn)
- 분할정복으로 정렬을 이어나가기 때문에 log의 시간이 걸린다.

## 공간복잡도
- 하나의 배열을 사용하고, 비교할 때 생성하는 Left, Right 배열은 함수가 종료되면 메모리에서 사라지므로 O(n)의 공간복잡도를 갖는다.

## 장점
- 분할정복을 이용해서 병합하기 때문에 속도가 빠르다.
- 순차적으로 정렬하며, 안정정렬이다.
- 합병정력은 순차적으로 비교하며 정렬하기 때문에, `LinkedList`의 정렬이 필요할 때 사용하면 효율적이다.
  - 퀵정렬을 LinkedList정렬로 사용한다면 임의의 접근을 하기 때문에, 오베헤드가 발생하여 좋지않다.

## Quick Sort 차이점
- 퀵정렬은 피벗을 통해 정렬 -> 영역을 쪼갠다
- 합병정렬은 영역을 최대한 쪼개고 -> 정렬한다
